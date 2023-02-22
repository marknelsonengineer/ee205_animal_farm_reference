///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// A utility class for managing Animal names
///
/// @file   Name.cpp
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <cassert>    // For assert
#include <cctype>     // For isspace
#include <fstream>    // For ifstream
#include <iostream>   // For cout
#include <limits>     // For numeric_limits
#include <stdexcept>  // For runtime_error

#include "../config.h"
#include "Name.h"
#include "Trim.h"

using namespace std;


Name::serial_t Name::maxSerial = numeric_limits<Name::serial_t>::max();


Name::Name( string_view newFilename )
   : nameType { FROM_FILE }    // Member initializer list
   , fileName { newFilename }  // Member initializer list
   {
      reset();
}


/// NOLINTNEXTLINE(bugprone-easily-swappable-parameters): Suppress `2 adjacent parameters of similar type are easily swapped by mistake`
Name::Name( string_view newSerialPrefix, string_view newSerialSuffix )
   : nameType { FROM_SERIAL }         // Member initializer list
   , serialPrefix { newSerialPrefix } // Member initializer list
   , serialSuffix { newSerialSuffix } // Member initializer list
   {
      reset();
}


std::string Name::getNextName() {
   if( nameType == FROM_FILE ) {
      if( names.empty() ) {
         reset();
      }

      /// Remove names as they get used
      uniform_int_distribution<>  nameRNG( 0, (int) names.size()-1 );
      int nameIndex = nameRNG( ANIMAL_FARM_RNG );
      string theName = names[nameIndex];
      names.erase( names.begin()+nameIndex );

      return theName;
   }

   if( nameType == FROM_SERIAL ) {
      return serialPrefix + to_string(serial++) + serialSuffix;
   }

   assert( false );
   return string(); // Should never get here.
}


/// This method should be used with care... several Animal Farm
/// data structures (like BinarySearchTree) can't handle Nodes with the same name.
///
/// This has been added to facilitate unit testing.
void Name::reset() {
   if( nameType == FROM_FILE ) {
      names.clear();

      #ifdef DEBUG
         cout << "Loading names from [" << fileName << "]:  " ;
      #endif

      ifstream file( fileName, ios::in );
      if( !file.is_open() ) {
         throw( runtime_error( "Unable to open [" + fileName + "] for reading" ));
      }

      string line;
      while( getline( file, line )) {
         line = trim_in( line );
         if( !Name::validateName( line ) ) {  /// As the names are loaded from the file, verify that each name is valid with validateName()
            continue;
         }
         names.push_back( std::move( line ));  // Use move semantics
      }

      #ifdef DEBUG
         cout << "Loaded " << to_string( names.size() ) << " names" << endl;
      #endif
   }

   if( nameType == FROM_SERIAL ) {
      serial = 0;
   }
}


/// @return If the nameType is:
///
///   - #FROM_FILE: Return the size of the names vector.
///   - #FROM_SERIAL: Return `max(serial_t) - serial` (the number of serial numbers left, which should be a very large number)
Name::serial_t Name::remainingNames() noexcept {
   switch( nameType ) {
      case FROM_FILE: return names.size();
      case FROM_SERIAL: return maxSerial - serial;
   }

   assert( false );
   return 0;  // Should never get here
}


/// newName should have had ::trim_in run on it before it's validated here.
///
/// The validation rules are:
///
///   - The name should not be empty.
///   - The name should be trimmed for whitespace (both left and right whitespace should be removed).
///   - The name should not start with a number or `-`.
///   - The name should not have any special characters except a `-`.  Allowed
///     characters are `A`-`Z`, `a`-`z`, `0`-`9`, space and `-`.
///   - The interior whitespace of the name should be trimmed.
///
/// If the name is not valid, print an explanation and return `false`
///
/// @param newName The name to check
/// @return `true` if the name is valid.  `false` if it's not.
bool Name::validateName( const std::string_view newName ) {

   if( !validateNotEmpty( newName )) {
      return false;
   }

   if( !validateTrimmed( newName )) {
      return false;
   }

   if( !validateStartsWithAlpha( newName )) {
      return false;
   }

   if( !validateNoSpecialChars( newName )) {
      return false;
   }

   // This is a little subtle.  At this point, the only "whitespace" allowed is
   // a space ' ' and a '-', so let's just look for them...
   if( !validateInteriorWhitespaceTrimmed( newName )) {
      return false;
   }

   return true;
}


/// @hidecallergraph @hidecallgraph
bool Name::validateNotEmpty( const string_view newName ) {
   if( newName.empty() ) {
      ///   If not valid, print `The name should not be empty` and return `false`
      cout << PROGRAM_NAME << ": The name should not be empty" << endl;
      return false;
   }

   return true;
}


/// @hidecallergraph @hidecallgraph
bool Name::validateTrimmed( const string_view newName ) {
   if( newName.empty() ) {
      return true;  /// Empty strings are considered trimmed
   }

   if( isspace( *newName.begin() ) || isspace( *(newName.end()-1) ) ) {
      ///   If not valid, print `The name should be trimmed for whitespace` and return `false`
      cout << PROGRAM_NAME << ": The name should be trimmed for whitespace" << endl;
      return false;
   }

   return true;
}


/// @hidecallergraph @hidecallgraph
bool Name::validateStartsWithAlpha( const string_view newName ) {
   if( !isalpha( *newName.begin() ) ) {
      ///   If not valid, print `The name should not start with a number or -` and return `false`
      cout << PROGRAM_NAME << ": The name should not start with a number or -" << endl;
      return false;
   }

   return true;
}


/// @hidecallergraph @hidecallgraph
bool Name::validateNoSpecialChars( const string_view newName ) {
   for( const auto *i = newName.begin() ; i != newName.end() ; i++ ) {
      if( isalnum( *i ) || *i == ' ' || *i == '-' ) {
         continue;
      }
      // *i is not a valid character...
      ///   If not valid, print `The name should not have any special characters` and return `false`
      cout << PROGRAM_NAME << ": The name should not have any special characters" << endl;
      return false;
   }

   return true;
}


/// @hidecallergraph @hidecallgraph
bool Name::validateInteriorWhitespaceTrimmed( const string_view newName ) {
   string trialName { trim( newName ) };  // Trim whitespace

   for( auto i = trialName.begin() ; i+1 != trialName.end() ; i++ ) {
      const bool isCurrentWhitespace = *i == ' ' || *i == '-';
      const bool isNextWhitespace = *( i+1 ) == ' ' || *( i+1 ) == '-';

      if( isCurrentWhitespace && isNextWhitespace ) {
         ///   If not valid, print `The interior whitespace of the name should be trimmed` and return `false`
         cout << PROGRAM_NAME << ": The interior whitespace of the name should be trimmed" << endl;
         return false;
      }
   }

   return true;
}
