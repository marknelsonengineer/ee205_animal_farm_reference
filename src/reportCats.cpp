///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   14_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include <cstring>  // For strncmp
#include <stdexcept> // To throw if the enumName functions are bad
#include <iostream>
#include <cassert>

#include "config.h"
#include "reportCats.h"
#include "catDatabase.h"
#include "Cat.h"

using namespace std;

/// @returns true if it was successful
bool printAllCats() {
   int numCats = 0 ;

   for( Cat* iCat = catDBheadPtr ; iCat != nullptr ; iCat = iCat->next ) {
      iCat->print() ;
      numCats++ ;
   }
#ifdef DEBUG
   cout << "numCats = [" << numCats << "]" << endl ;
#endif
   return true;
}

/// @return The Cat or nullptr if the cat can't be found
Cat* findCatByName( const char* name ) {
   assert( Cat().validateName( name ) );

   for( Cat* iCat = catDBheadPtr ; iCat != nullptr ; iCat = iCat->next ) {
      if( strcmp( name, iCat->getName() ) == 0 ) {
         return iCat ;
      }
   }

   return nullptr ; // No name matched
}


/// @throws logic_error if the enum is not mapped to a string.
const char* genderName( const enum Gender gender ) {
   switch( gender ) {
      case UNKNOWN_GENDER: return "Unknown" ;
      case MALE:           return "Male"    ;
      case FEMALE:         return "Female"  ;
   }
   throw logic_error(PROGRAM_NAME ": Gender name not mapped to a string value");
}


/// @throws logic_error if the enum is not mapped to a string.
const char* breedName( const enum Breed breed ) {
   switch( breed ) {
      case UNKNOWN_BREED: return "Unknown"    ;
      case MAINE_COON   : return "Maine Coon" ;
      case MANX         : return "Manx"       ;
      case SHORTHAIR    : return "Shorthair"  ;
      case PERSIAN      : return "Persian"    ;
      case SPHYNX       : return "Sphynx"     ;
   }
   throw logic_error(PROGRAM_NAME ": Breed name not mapped to a string value");
}


/// @throws logic_error if the enum is not mapped to a string.
const char* colorName ( const enum Color color ) {
   switch( color ) {
      case UNKNOWN_COLOR: return "Unknown color" ;
      case BLACK        : return "Black" ;
      case WHITE        : return "White" ;
      case RED          : return "Red"   ;
      case BLUE         : return "Blue"  ;
      case GREEN        : return "Green" ;
      case PINK         : return "Pink"  ;
   }
   throw logic_error(PROGRAM_NAME ": Color name not mapped to a string value");
}
