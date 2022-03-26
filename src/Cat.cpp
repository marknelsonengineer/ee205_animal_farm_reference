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
#include "reportCats.h"

using namespace std ;

void Cat::zeroOutMemberData() {
   memset( name, 0, MAX_CAT_NAME );
   gender = UNKNOWN_GENDER ;
   breed = UNKNOWN_BREED ;
   amIfixed = false ;
   weight = UNKNOWN_WEIGHT ;
   next = nullptr ;
}

Cat::Cat() {
   zeroOutMemberData() ;
}

Cat::Cat(const char *newName, const Gender newGender, const Breed newBreed, const Weight newWeight) : Cat() {
   setName( newName ) ;
   setGender( newGender ) ;
   setBreed( newBreed ) ;
   setWeight( newWeight ) ;
}


/// Zero out all of the member data (it's super secret!)
///
/// @todo Consider consolidating this with the constructor
Cat::~Cat() {
   zeroOutMemberData() ;
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

/// Format a line for printing the members of a class
#define FORMAT_LINE( className, member ) cout << setw(8) << className << setw(20) << member << setw(52)

/// @returns true if everything worked correctly.  false if something goes
///          wrong
bool Cat::print() const {
   cout << setw(80) << setfill( '=' ) << "" << endl ;
   cout << setfill( ' ' ) ;
   cout << left ;
   cout << boolalpha ;
   FORMAT_LINE( "Cat", "name" )         << getName()   << endl ;
   FORMAT_LINE( "Cat", "gender" )       << genderName( getGender() ) << endl ;
   FORMAT_LINE( "Cat", "breed" )        << breedName( getBreed() )   << endl ;
   FORMAT_LINE( "Cat", "isFixed" )      << isFixed()   << endl ;
   FORMAT_LINE( "Cat", "weight" )       << getWeight() << endl ;

   return true ;
}

/// This method checks the Cat object.  If something is not right, it will
/// print out a message and stop the validation.  It will not throw an
/// exception.
bool Cat::validate() const noexcept {
   try {
      validateName( name ) ;
      validateGender( gender ) ;
      validateBreed( breed ) ;
      validateWeight( weight ) ;
   } catch (exception const& e) {
      cout << e.what() << endl ;
      return false ;
   }

   return true;
}

/// If `newName` is valid, the method returns true and does *not* throw
/// an exception.  If it's invalid, it will throw an exception.
///
/// @param newName The name to test
/// @return True if `newName` is not nullptr and has a length > 0
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

/// If `newGender` is valid, the method returns true and does *not* throw
/// an exception.  If it's invalid, it will throw an exception.
///
/// @param newGender The gender to test
/// @return True if `newGender` is not UNKNOWN_GENDER
/// @throws invalid_argument if `newGender` is UNKNOWN_GENDER
bool Cat::validateGender(const Gender newGender) {
   if( newGender == UNKNOWN_GENDER ) {
      throw invalid_argument( PROGRAM_NAME ": Gender must be known") ;
   }

   return true;
}


/// If `newBreed` is valid, the method returns true and does *not* throw
/// an exception.  If it's invalid, it will throw an exception.
///
/// @param newBreed The breed to test
/// @return True if `newBreed` is not UNKNOWN_BREED
/// @throws invalid_argument if `newBreed` is UNKNOWN_BREED
bool Cat::validateBreed(const Breed newBreed) {
   if( newBreed == UNKNOWN_BREED ) {
      throw invalid_argument( PROGRAM_NAME ": Breed must be known" ) ;
   }

   return true;
}


/// If `newWeight` is > 0, the method returns true and does *not* throw
/// an exception.  If it <= 0, it will throw an exception.
///
/// @param newWeight The weight to test
/// @return True if > 0
/// @throws invalid_argument if `newWeight` <= 0
bool Cat::validateWeight(const Weight newWeight) {
   if( newWeight <= 0 ) {
      throw invalid_argument( PROGRAM_NAME ": Weight must be > 0" ) ;
   }

   return true;
}

/// Once the cat is fixed, it can never be un-fixed.
void Cat::fixCat() noexcept {
   Cat::amIfixed = true;
}

/// The newWeight must be > 0.
///
/// @param newWeight The new weight
void Cat::setWeight(Weight newWeight) {
   validateWeight( newWeight ) ;
   Cat::weight = newWeight;
}

/// This is not normally called as you can't change a cat's gender, therefore
/// this method is protected.
///
/// You can only change the gender if it's currently UNKNOWN_GENDER.
///
/// @param newGender The new gender
/// @throws logic_error If you try to change the gender of a cat
void Cat::setGender(Gender newGender) {
   if( gender != UNKNOWN_GENDER ) {
      throw logic_error( PROGRAM_NAME ": The gender is already set, you can't change it" ) ;
   }

   // At this point, the gender must be UNKNOWN_GENDER
   validateGender( newGender );
   Cat::gender = newGender ;
}

/// This is not normally called as you can't change a cat's breed, therefore
/// this method is protected.
///
/// You can only change the breed if it's currently UNKNOWN_BREED.
///
/// @param newBreed The new breed
/// @throws logic_error If you try to change the breed of a cat
void Cat::setBreed(Breed newBreed) {
   if( breed != UNKNOWN_BREED ) {
      throw logic_error( PROGRAM_NAME ": The breed is already set, you can't change it" ) ;
   }

   // At this point, the breed must be UNKNOWN_BREED
   validateBreed( newBreed ) ;
   Cat::breed = newBreed;
}
