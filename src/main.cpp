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
#include "SinglyLinkedList.h"

using namespace std ;

/// @internal Used to test the largest possible name
#define MAX_NAME1    "1234567890123456789012345678901234567890123456789"

/// @internal Used to test an illegal name (because it's too large by
///           one character)
#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"


/// The entry point for Animal Farm
int main() {
   cout << "Starting " << PROGRAM_TITLE << endl ;

   SinglyLinkedList catDB ;

   #ifdef DEBUG
   {
      // Verify that a cat's default values are set
      Cat testCat = Cat();
      assert(testCat.getName() != nullptr );
      assert(strcmp(testCat.getName(), "") == 0);
      assert(testCat.getGender() == Gender::UNKNOWN_GENDER);
      assert(testCat.getBreed() == Breed::UNKNOWN_BREED);
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

      testCat.setGender(Gender::FEMALE);

      try {
         testCat.setGender(Gender::MALE);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.setBreed(Breed::MAINE_COON);

      try {
         testCat.setBreed(Breed::MANX);
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
      testCat.dump() ;

      // assert(!isCatInDatabase(&testCat)) ;
   }
   #endif

   catDB.push_front( new Cat( "Loki",  Gender::MALE,   Breed::PERSIAN,    1.0 ) ) ;
   catDB.push_front( new Cat( "Milo",  Gender::MALE,   Breed::MANX,       1.1 ) ) ;
   catDB.push_front( new Cat( "Bella", Gender::FEMALE, Breed::MAINE_COON, 1.2 ) ) ;
   catDB.push_front( new Cat( "Kali",  Gender::FEMALE, Breed::SHORTHAIR,  1.3 ) ) ;
   catDB.push_front( new Cat( "Trin",  Gender::FEMALE, Breed::MANX,       1.4 ) ) ;
   catDB.push_front( new Cat( "Chili", Gender::MALE,   Breed::SHORTHAIR,  1.5 ) ) ;

   /*
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
   */

   catDB.validate() ;
   catDB.dump() ;

   catDB.deleteAllNodes();

   catDB.dump() ;

   cout << "Done with " << PROGRAM_TITLE ;

   return( EXIT_SUCCESS ) ;
}
