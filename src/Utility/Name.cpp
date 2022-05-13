///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// A utility class for managing lists of Animal names
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
   :nameType ( FROM_FILE )
   ,fileName( move(newFilename) ) {
   reset();
}


Name::Name( string newSerialPrefix, string newSerialSuffix )
   :nameType( FROM_SERIAL )
   ,serialPrefix( move(newSerialPrefix) )
   ,serialSuffix( move(newSerialSuffix) ) {

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
         if( !Name::validateName( line ) )   /// As the names are loaded from the file, verify that each name is valid
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
///   - The name should be trimmed (both left and right whitespace should be removed).
///   - The interior whitespace of the name should be trimmed.
///   - The name should not have any special characters except for a -.  Allowed
///     characters are `A`-`Z`, `a`-`z`, `0`-`9`, space and `-`.
///   - The name should not start with a number or `-`.
///
/// @param newName The name to check
/// @return `true` if the name is valid.  `false` if it's not.
bool Name::validateName( const std::string& newName ) {
   if( newName.empty() ) {
      cout << PROGRAM_NAME << ": The name should not be empty" << endl;
      return false;
   }

   if( isspace( *newName.begin() ) || isspace( *(newName.end()-1) ) ) {
      cout << PROGRAM_NAME << ": The name should be trimmed for whitespace" << endl;
      return false;
   }

   if( !isalpha( *newName.begin() ) ) {
      cout << PROGRAM_NAME << ": The name should not start with a number or -" << endl;
      return false;
   }

   for( auto i = newName.begin() ; i != newName.end() ; i++ ) {
      if( isalnum( *i ) || *i == ' ' || *i == '-' )
         continue;
      else { // It is not a valid character...
         cout << PROGRAM_NAME << ": The name should not have any special characters" << endl;
         return false;
      }
   }

   // This is a little subtle.  At this point, the only "whitespace" allowed is
   // a space ' ' and a '-', so let's just look for them...
   for( auto i = newName.begin() ; i+1 != newName.end() ; i++ ) {
      bool isCurrentWhitespace = (*i == ' ' || *i == '-' ) ? true : false;
      bool isNextWhitespace = (*(i+1) == ' ' || *(i+1) == '-' ) ? true : false;

      if( isCurrentWhitespace && isNextWhitespace ) {
         cout << PROGRAM_NAME << ": The interior whitespace of the name should be trimmed" << endl;
         return false;
      }
   }

   return true;
}
