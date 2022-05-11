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
#include <iostream>
#include <limits>
#include <utility>

#include "../config.h"
#include "Name.h"

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
         /// @todo as we are loading, verify that each name is valid
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
}


bool Name::validateName( const std::string& newName ) {
   @todo Need to implement
   return false;
}
