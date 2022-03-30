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
#include <cassert>

#include "Cat.h"

using namespace std ;

void Cat::zeroOutMemberData() {
   memset( name, 0, MAX_CAT_NAME );
   gender = Gender::UNKNOWN_GENDER ;
   breed = Breed::UNKNOWN_BREED ;
   isCatFixed = false ;
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

   assert( Cat::validate() ) ;
}

Cat::~Cat() {
   zeroOutMemberData() ;
}


const char *Cat::getName() const noexcept {
   return name;
}

void Cat::setName(const char *newName) {
   validateName( newName ) ;  // Throws an exception if there's a problem.

   memset( name, 0, MAX_CAT_NAME );  /// @internal Thoroughly erase the old name
                                     ///           before setting a new name.
   strcpy( name, newName );
}

Gender Cat::getGender() const noexcept {
   return gender;
}

Breed Cat::getBreed() const noexcept {
   return breed;
}

bool Cat::isFixed() const noexcept {
   return isCatFixed;
}

Weight Cat::getWeight() const noexcept {
   return weight;
}

/// @returns true if everything worked correctly.  false if something went
///          wrong
///
/// #### Sample Output
///
///     Cat     name                Kali
///     Cat     gender              Female
///     Cat     breed               Shorthair
///     Cat     isFixed             false
///     Cat     weight              1.3
///
bool Cat::dump() const noexcept {
   assert( validate() ) ;

   Node::dump() ;

   FORMAT_LINE( "Cat", "name" )    << getName()                     << endl ;
   FORMAT_LINE( "Cat", "gender" )  << genderToString( getGender() ) << endl ;
   FORMAT_LINE( "Cat", "breed" )   << breedToString( getBreed() )   << endl ;
   FORMAT_LINE( "Cat", "isFixed" ) << isFixed()                     << endl ;
   FORMAT_LINE( "Cat", "weight" )  << getWeight()                   << endl ;

   return true ;
}

/// This method checks the Cat object.  If something is not right, it will
/// dump out a message and stop the validation.  It will not throw an
/// exception.
bool Cat::validate() const noexcept {
   Node::validate() ;

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
   if( newGender == Gender::UNKNOWN_GENDER ) {
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
   if( newBreed == Breed::UNKNOWN_BREED ) {
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
   Cat::isCatFixed = true;
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
   if( gender != Gender::UNKNOWN_GENDER ) {
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
   if( breed != Breed::UNKNOWN_BREED ) {
      throw logic_error( PROGRAM_NAME ": The breed is already set, you can't change it" ) ;
   }

   // At this point, the breed must be UNKNOWN_BREED
   validateBreed( newBreed ) ;
   Cat::breed = newBreed;
}
