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
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   14_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include <cstdlib>  // For EXIT_SUCCESS / EXIT_FAILURE
#include <cassert>  // For assert()
#include <cstring>  // For strcmp()

#include "config.h"
#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "updateCats.h"
#include "deleteCats.h"

/// @internal Used to test the largest possible name
#define MAX_NAME1    "1234567890123456789012345678901234567890123456789"

/// @internal Used to test the largest possible name
#define MAX_NAME2    "DIFFERENT 123456789012345678901234567890123456789"

/// @internal Used to test an illegal name (because it's too large by
///           one character
#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"


/// The entry point for Animal Farm
int main() {
   printf( "Starting %s\n", PROGRAM_TITLE ) ;

   initializeDatabase() ;

   #ifdef DEBUG
      // Verify that a cat's default values are set
      Cat testCat = Cat();
      assert( testCat.getName() != NULL ) ;
      assert( strcmp( testCat.getName(), "" ) == 0 ) ;
      assert( testCat.getGender() == UNKNOWN_GENDER ) ;
      assert( testCat.getBreed() == UNKNOWN_BREED ) ;
      assert( testCat.isFixed() == false ) ;
      assert( testCat.getWeight() == UNKNOWN_WEIGHT ) ;
      assert( testCat.getCollarColor1() == UNKNOWN_COLOR ) ;
      assert( testCat.getCollarColor2() == UNKNOWN_COLOR ) ;
      assert( testCat.getLicense() == UNKNOWN_LICENSE ) ;

      testCat.print() ;
      assert( !testCat.validate() ) ;  // The default cat is invalid
   #endif
/*
   assert( addCat( "Loki",  MALE,           PERSIAN,    true,   8.5, BLACK, WHITE, 101 ) != BAD_CAT ) ;
   assert( addCat( "Milo",  MALE,           MANX,       true,   7.0, BLACK, RED,   102 ) != BAD_CAT ) ;
   assert( addCat( "Bella", FEMALE,         MAINE_COON, true,  18.2, BLACK, BLUE,  103 ) != BAD_CAT ) ;
   assert( addCat( "Kali",  FEMALE,         SHORTHAIR,  false,  9.2, BLACK, GREEN, 104 ) != BAD_CAT ) ;
   assert( addCat( "Trin",  FEMALE,         MANX,       true,  12.2, BLACK, PINK,  105 ) != BAD_CAT ) ;
   assert( addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR,  false, 19.0, WHITE, BLACK, 106 ) != BAD_CAT ) ;

#ifdef DEBUG
   // Test for NULL name
		assert( addCat( NULL, UNKNOWN_GENDER, SHORTHAIR,  false, 19.0, BLACK, WHITE, 101 ) == BAD_CAT ) ;
		// Test for empty name
		assert( addCat( "", UNKNOWN_GENDER, SHORTHAIR,  false, 19.0, BLACK, WHITE, 101 ) == BAD_CAT ) ;
		// Test for max name
		assert( addCat( MAX_NAME1, UNKNOWN_GENDER, SHORTHAIR,  false, 19.0, WHITE, RED, 107 ) != BAD_CAT ) ;
		// Test for name too long
		assert( addCat( ILLEGAL_NAME, UNKNOWN_GENDER, SHORTHAIR,  false, 19.0, WHITE, BLUE, 108 ) == BAD_CAT ) ;
		// Test for duplicate cat name
		assert( addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR,  false, 0, WHITE, GREEN, 109 ) == BAD_CAT ) ;
		// Test for Weight <= 0
		assert( addCat( "Neo", UNKNOWN_GENDER, SHORTHAIR,  false, 0, WHITE, PINK, 110 ) == BAD_CAT ) ;
		// Test same collar colors
      assert( addCat( "Neo", UNKNOWN_GENDER, SHORTHAIR,  false, 3, WHITE, WHITE, 111 ) == BAD_CAT ) ;

		// Test for printCat( -1 ) ;
		assert( !printCat( -1 ) ) ;
		// Test for out of bounds
		assert( !printCat( MAX_CATS )) ;

		// Test finding a cat...
		assert( findCatByName( "Bella" ) == 2 ) ;
		// Test not finding a cat
		assert( findCatByName( "Bella's not here" ) == BAD_CAT ) ;

		// Test addCat details
		size_t testCat = addCat( "Oscar", UNKNOWN_GENDER, SHORTHAIR,  false, 1.1, RED, BLACK, 111 ) ;
		assert( testCat != BAD_CAT );
		assert( testCat < MAX_CATS );

		// Test setting a large name
		assert( updateCatName( testCat, MAX_NAME2 ) == true ) ;
		assert( printCat( testCat )) ;

		// Test setting an out-of-bounds name
		assert( updateCatName( testCat, ILLEGAL_NAME ) == false ) ;
		assert( printCat( testCat )) ;

		// Test setting an illegal cat Weight
		assert( updateCatWeight( testCat, -1 ) == false ) ;

		// Test setting an illegal cat collar (both colors are the same)
      assert( updateCatCollar1( testCat, BLACK ) == false ) ;
      assert( updateCatCollar2( testCat, RED ) == false ) ;

      // Test setting an illegal cat collar (duplicates the collar of another cat)
      assert( addCat( "Oscar II", UNKNOWN_GENDER, SHORTHAIR,  false, 1.1, RED, BLACK, 112 ) == BAD_CAT ) ;
      assert( updateCatCollar1( testCat, WHITE ) == false ) ;
      assert( updateCatCollar1( testCat, GREEN ) == true ) ;  // This should succeed
      assert( updateCatCollar2( testCat, WHITE ) == true ) ;  // This should succeed
      assert( updateCatCollar2( testCat, WHITE ) == false ) ;

      // Test adding a cat with a duplicate license
      assert( addCat( "Oscar II", UNKNOWN_GENDER, SHORTHAIR,  false, 1.1, RED, BLUE, 101 ) == BAD_CAT ) ;
      assert( updateLicense( testCat, 101 ) == false ) ;
#endif

   printAllCats() ;

   size_t kali = findCatByName( "Kali" ) ;
   assert( kali != BAD_CAT );
   assert( updateCatName( kali, "Chili" ) == false ) ; // duplicate cat name should fail
   assert( printCat( kali )) ;
   assert( updateCatName( kali, "Capulet" ) == true ) ;
   assert( updateCatWeight( kali, 9.9 ) == true ) ;
   assert( fixCat( kali ) == true ) ;
   assert( updateCatCollar1( kali, WHITE ) == true ) ;
   assert( updateCatCollar2( kali, PINK ) == true ) ;
   assert( updateLicense( kali, 201 ) == true ) ;

   assert( printCat( kali )) ;

   printAllCats() ;

   deleteAllCats() ;
   printAllCats() ;
*/
   printf( "Done with %s\n", PROGRAM_TITLE ) ;

   return( EXIT_SUCCESS ) ;
}
