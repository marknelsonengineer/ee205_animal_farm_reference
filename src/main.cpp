///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// Orchestrates the entire program:
///    Starting Animal Farm 2
/// ...and end by printing
///    Done with Animal Farm 2
///
/// @file main.cpp
/// @version 2.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   14_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cstdlib>  // For EXIT_SUCCESS / EXIT_FAILURE
#include <cassert>  // For assert()
#include <cstring>  // For strcmp()
#include <exception>  // For try/catch blocks
#include <iostream>

#include "config.h"
#include "Cat.h"
#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "deleteCats.h"

using namespace std ;

/// @internal Used to test the largest possible name
#define MAX_NAME1    "1234567890123456789012345678901234567890123456789"

/// @internal Used to test an illegal name (because it's too large by
///           one character)
#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"


/// The entry point for Animal Farm
int main() {
   cout << "Starting " << PROGRAM_TITLE << endl ;

   initializeDatabase() ;

   #ifdef DEBUG
   {
      // Verify that a cat's default values are set
      Cat testCat = Cat();
      assert(testCat.getName() != nullptr );
      assert(strcmp(testCat.getName(), "") == 0);
      assert(testCat.getGender() == UNKNOWN_GENDER);
      assert(testCat.getBreed() == UNKNOWN_BREED);
      assert(testCat.isFixed() == false);
      assert(testCat.getWeight() == UNKNOWN_WEIGHT);
      assert(!testCat.isFixed());
      assert(!testCat.validate());  // The default cat is invalid

      // Test for NULL name
      try {
         testCat.setName(nullptr);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      // Test for empty name
      try {
         testCat.setName("");
         assert(false); // We should never get here
      } catch (exception const &e) {}

      // Test valid names
      testCat.setName("A");       // A 1 character name is valid
      testCat.setName(MAX_NAME1); // A MAX_NAME1 name is valid

      // Test for name too large
      try {
         testCat.setName(ILLEGAL_NAME);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.setGender(FEMALE);

      try {
         testCat.setGender(MALE);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.setBreed(MAINE_COON);

      try {
         testCat.setBreed(MANX);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.fixCat();
      assert(testCat.isFixed());

      // Test for Weight <= 0
      try {
         testCat.setWeight(0);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.setWeight(1.0 / 1024);
      assert(testCat.getWeight() == 1.0 / 1024);

      assert(testCat.validate());  // The cat should now be valid
      testCat.print() ;

      assert(!isCatInDatabase(&testCat)) ;
   }
   #endif

   bool result ;
   result = addCat( new Cat( "Loki", MALE, PERSIAN, 1.0 )) ;
   assert( result ) ;
   if( !result ) throw logic_error (PROGRAM_NAME ": addCat() failed" ) ;
   result = addCat( new Cat( "Milo", MALE, MANX , 1.1 )) ;
   assert( result ) ;
   result = addCat( new Cat( "Bella", FEMALE, MAINE_COON, 1.2 )) ;
   assert( result ) ;
   result = addCat( new Cat( "Kali", FEMALE, SHORTHAIR, 1.3 )) ;
   assert( result ) ;
   result = addCat( new Cat( "Trin", FEMALE, MANX, 1.4 )) ;
   assert( result ) ;
   result = addCat( new Cat( "Chili", MALE, SHORTHAIR, 1.5 )) ;
   assert( result ) ;

   #ifdef DEBUG
   {
      // Test finding a cat...
      Cat *bella = findCatByName("Bella");
      assert(bella != nullptr);
      // Test not finding a cat
      assert(findCatByName("Bella's not here") == nullptr);

      // Test deleting a cat...
      assert(deleteCat(bella) == true);
      try {
         deleteCat(bella); // Verify that Bella's not there
      } catch (exception const &e) {}

      bella = nullptr;
   }
   #endif

   printAllCats() ;

   deleteAllCats() ;

   printAllCats() ;

   cout << "Done with " << PROGRAM_TITLE ;

   return( EXIT_SUCCESS ) ;
}
