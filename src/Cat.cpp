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
#include <iostream>
#include <iomanip>

#include "Cat.h"

using namespace std ;

Cat::Cat() {
   memset( name, 0, MAX_CAT_NAME );
   gender = UNKNOWN_GENDER ;
   breed = UNKNOWN_BREED ;
   amIfixed = false ;
   weight = UNKNOWN_WEIGHT ;
   collarColor1 = UNKNOWN_COLOR ;
   collarColor2 = UNKNOWN_COLOR ;
   license = UNKNOWN_LICENSE ;
   nextCat = nullptr ;
}

Cat::Cat(const char *newName, const Gender newGender, const Breed newBreed) : Cat() {
   setName( newName ) ;
   gender = newGender ;
   breed = newBreed ;
}

const char *Cat::getName() const {
   return name;
}

void Cat::setName(const char *newName) {
   validateName( newName ) ;  // Throws an exception if there's a problem.

   memset( name, 0, MAX_CAT_NAME );  /// @internal Thoroughly erase the old name
                                     ///           before setting a new name.
   strcpy( name, newName );
}

Gender Cat::getGender() const {
   return gender;
}

Breed Cat::getBreed() const {
   return breed;
}

bool Cat::isFixed() const {
   return amIfixed;
}

Weight Cat::getWeight() const {
   return weight;
}

Color Cat::getCollarColor1() const {
   return collarColor1;
}

Color Cat::getCollarColor2() const {
   return collarColor2;
}

License Cat::getLicense() const {
   return license;
}

/// Format a line for printing the members of a class
#define FORMAT_LINE( className, member ) cout << setw(8) << className << setw(20) << member << setw(52)

void Cat::print() const {
   cout << setw(80) << setfill( '=' ) << "" << endl;
   cout << setfill( ' ' ) ;
   cout << left;
   FORMAT_LINE( "Cat", "name" )         << getName() << endl ;
   FORMAT_LINE( "Cat", "gender" )       << getGender() << endl ;
   FORMAT_LINE( "Cat", "gender" )       << getGender() << endl ;
   FORMAT_LINE( "Cat", "breed" )        << getBreed() << endl ;
   FORMAT_LINE( "Cat", "isFixed" )      << isFixed() << endl ;
   FORMAT_LINE( "Cat", "weight" )       << getWeight() << endl ;
   FORMAT_LINE( "Cat", "collarColor1" ) << getCollarColor1() << endl ;
   FORMAT_LINE( "Cat", "collarColor2" ) << getCollarColor2() << endl ;
   FORMAT_LINE( "Cat", "license" )      << getLicense() << endl ;
}

/// This method checks the Cat object.  If something is not right, it will
/// print out a message and stop the validation.  It will not throw an
/// exception.
bool Cat::validate() const noexcept {
   try {
      validateName( name ) ;
   } catch (exception const& e) {
      cout << e.what() << endl ;
      return false ;
   }

   if( gender == UNKNOWN_GENDER ) {
      cout << PROGRAM_NAME << ": The gender is unknown" << endl ;
      return false ;
   }

   if( breed == UNKNOWN_BREED ) {
      cout << PROGRAM_NAME << ": The breed is unknown" << endl ;
      return false ;
   }

   if( weight <= 0 ) {
      cout << PROGRAM_NAME << ": The weight is <= 0" << endl ;
      return false ;
   }

   if( collarColor1 == UNKNOWN_COLOR || collarColor2 == UNKNOWN_COLOR ) {
      cout << PROGRAM_NAME << ": One of the collar colors is unknown" << endl ;
      return false ;
   }

   if( collarColor1 == collarColor2 ) {
      cout << PROGRAM_NAME << ": The collar colors are equal" << endl ;
      return false ;
   }

   if( license == UNKNOWN_LICENSE ) {
      cout << PROGRAM_NAME << ": The license is unknown" << endl ;
      return false ;
   }

   return true;
}

/// If `newName` is valid, the method returns true and does *not* throw
/// an exception.  If it's invalid, it will throw an exception.
///
/// @throws invalid_argument if `newName` is `nullptr` or the length is 0
/// @throws length_error if `newName` is >= `MAX_CAT_NAME`
bool Cat::validateName(const char *newName) {
   if( newName == nullptr ) {
      throw invalid_argument(PROGRAM_NAME ": name must not be NULL");
   }

   if( strlen( newName ) <= 0 ) {
      throw length_error( PROGRAM_NAME ": name length must be > 0");
   }

   if( strlen( newName ) >= MAX_CAT_NAME ) {
      throw length_error( PROGRAM_NAME ": name must be < MAX_CAT_NAME" );
   }

   return true;
}
