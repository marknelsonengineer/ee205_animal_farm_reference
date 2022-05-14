///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// A utility class for managing Animal names
///
/// @file Name.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   10_May_2022
///////////////////////////////////////////////////////////////////////////////

#include <fstream>    // For ifstream
#include <stdexcept>  // For runtime_error
#include <iostream>   // For cout
#include <limits>     // For numeric_limits
#include <ctype.h>    // For isspace
#include <cassert>    // For assert

#include "../config.h"
#include "Name.h"
#include "Trim.h"

using namespace std;


Name::serial_t Name::maxSerial = numeric_limits<Name::serial_t>::max();


Name::Name( string newFilename )
   : nameType { FROM_FILE }           // Member initializer list
   , fileName { move(newFilename) }   // Member initializer list w/ move semantics
   {
   reset();
}


Name::Name( string newSerialPrefix, string newSerialSuffix )
   : nameType { FROM_SERIAL }               // Member initializer list
   , serialPrefix { move(newSerialPrefix) } // Member initializer list w/ move semantics
   , serialSuffix { move(newSerialSuffix) } // Member initializer list w/ move semantics
   {
   reset();
}


std::string Name::getNextName() noexcept {
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
/// data structures (like Tree) can't handle Nodes with the same name.
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
         if( !Name::validateName( line ) )   /// As the names are loaded from the file, verify that each name is valid with validateName()
            continue;
         names.push_back( move( line ));  // Use move semantics
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
bool Name::validateName( const std::string& newName ) {

   if( !validateNotEmpty( newName ))
      return false;

   if( !validateTrimmed( newName ))
      return false;

   if( !validateStartsWithAlpha( newName ))
      return false;

   if( !validateNoSpecialChars( newName ))
      return false;

   // This is a little subtle.  At this point, the only "whitespace" allowed is
   // a space ' ' and a '-', so let's just look for them...
   if( !validateInteriorWhitespaceTrimmed( newName ))
      return false;

   return true;
}


/// @hidecallergraph @hidecallgraph
bool Name::validateNotEmpty( const string& newName ) {
   if( newName.empty() ) {
      ///   If not valid, print `The name should not be empty` and return `false`
      cout << PROGRAM_NAME << ": The name should not be empty" << endl;
      return false;
   }

   return true;
}


/// @hidecallergraph @hidecallgraph
bool Name::validateTrimmed( const string& newName ) {
   if( newName.empty() )
      return true;  /// Empty strings are considered trimmed

   if( isspace( *newName.begin() ) || isspace( *(newName.end()-1) ) ) {
      ///   If not valid, print `The name should be trimmed for whitespace` and return `false`
      cout << PROGRAM_NAME << ": The name should be trimmed for whitespace" << endl;
      return false;
   }

   return true;
}


/// @hidecallergraph @hidecallgraph
bool Name::validateStartsWithAlpha( const string& newName ) {
   if( !isalpha( *newName.begin() ) ) {
      ///   If not valid, print `The name should not start with a number or -` and return `false`
      cout << PROGRAM_NAME << ": The name should not start with a number or -" << endl;
      return false;
   }

   return true;
}


/// @hidecallergraph @hidecallgraph
bool Name::validateNoSpecialChars( const string& newName ) {
   for( auto i = newName.begin() ; i != newName.end() ; i++ ) {
      if( isalnum( *i ) || *i == ' ' || *i == '-' )
         continue;
      else { // *i is not a valid character...
         ///   If not valid, print `The name should not have any special characters` and return `false`
         cout << PROGRAM_NAME << ": The name should not have any special characters" << endl;
         return false;
      }
   }

   return true;
}


/// @hidecallergraph @hidecallgraph
bool Name::validateInteriorWhitespaceTrimmed( const string& newName ) {
   string trialName = trim( newName );  // Trim whitespace

   for( auto i = trialName.begin() ; i+1 != trialName.end() ; i++ ) {
      bool isCurrentWhitespace = (*i == ' ' || *i == '-' ) ? true : false;
      bool isNextWhitespace = (*(i+1) == ' ' || *(i+1) == '-' ) ? true : false;

      if( isCurrentWhitespace && isNextWhitespace ) {
         ///   If not valid, print `The interior whitespace of the name should be trimmed` and return `false`
         cout << PROGRAM_NAME << ": The interior whitespace of the name should be trimmed" << endl;
         return false;
      }
   }

   return true;
}
