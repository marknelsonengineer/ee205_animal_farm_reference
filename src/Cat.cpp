///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   17_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cstring>
#include <stdexcept>

#include "Cat.h"

using namespace std ;

Cat::Cat() {
   memset( name, 0, MAX_CAT_NAME );
   gender = UNKNOWN_GENDER ;
   breed = UNKNOWN_BREED ;
   isFixed = false ;
   weight = UNKNOWN_WEIGHT ;
   collarColor1 = UNKNOWN_COLOR ;
   collarColor2 = UNKNOWN_COLOR ;
   license = UNKNOWN_LICENSE ;
}

Cat::Cat(const char *newName, const Gender newGender, const Breed newBreed) : Cat() {
   setName( newName ) ;
   gender = newGender ;
   breed = newBreed ;
}

const char *Cat::getName() const {
   return name;
}

/// @throws invalid_argument if newName is NULL
/// @throws length_error if newName is empty or the length is >= MAX_CAT_NAME
void Cat::setName(const char *newName) {
   if( newName == nullptr ) {
      throw invalid_argument(PROGRAM_NAME ": name must not be NULL");
   }

   if( strlen( newName ) <= 0 ) {
      throw length_error( PROGRAM_NAME ": name length must be > 0");
   }

   if( strlen( newName ) >= MAX_CAT_NAME ) {
      throw length_error( PROGRAM_NAME ": name must be < MAX_CAT_NAME" );
   }

   memset( name, 0, MAX_CAT_NAME );  /// @internal Thoroughly erase the old name
                                     ///           before setting a new name.
   strcpy( name, newName );
}
