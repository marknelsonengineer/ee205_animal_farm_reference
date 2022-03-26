///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   14_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cstring>    // For memset
#include <cassert>    // For the assert function
#include <cstdio>
#include <stdexcept>  // For logic_error
#include <iostream>

#include "config.h"
#include "catDatabase.h"
#include "Cat.h"
#include "reportCats.h"

using namespace std;

/// The head pointer to a linked list of cats
Cat* catDBheadPtr = nullptr ;


/// Initialize the catabase
///
/// @todo Delete the old database if one exists
void initializeDatabase() {
   if( catDBheadPtr != nullptr ) {
      throw logic_error( "@todo delete the old database...") ;
   }

   #ifdef DEBUG
      cout << PROGRAM_NAME << ": Database initialized" << endl ;
   #endif
}


/// Scan the database looking for the cat.
///
/// @param aCat The cat to search for
/// @return True if aCat was found.  False if not.
bool isCatInDatabase( Cat* aCat ) {
   for( Cat* iCat = catDBheadPtr ; iCat != nullptr ; iCat = iCat->next ) {
      if( iCat == aCat ) {
         return true ;
      }
   }

   return false ;  // The cat wasn't found
}




/*
/// Verify that the database is healthy
extern bool validateDatabase() {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
   assert( numCats >= 0 ) ;  // Make sure numCats isn't corrupt (negative)
#pragma GCC diagnostic pop

   for( size_t i = 0 ; i < numCats ; i++ ) {
      size_t foundCat ;

      if( !isIndexValid( i )) {
         // isIndexValid() prints an error message
         return false ;
      }

      if( !isNameValid( cats[i].name )) {
         // isNameValid() prints an error message
         return false ;
      }

      foundCat = findCatByName( cats[i].name ) ;
      if( foundCat != i ) {
         fprintf( stderr, "%s: Found a duplicate cat name [%s] at indexes [%zu] and [%zu].\n", PROGRAM_NAME, cats[i].name, i, foundCat ) ;
         return false ;
      }

      foundCat = findCatByCollars( cats[i].collarColor1, cats[i].collarColor2 ) ;
      if( foundCat != i ) {
         fprintf( stderr, "%s: Found a duplicate cat collar [%s] and [%s] at indexes [%zu] and [%zu].\n", PROGRAM_NAME, colorName( cats[i].collarColor1 ), colorName( cats[i].collarColor2), i, foundCat ) ;
         return false ;
      }

      foundCat = findCatByLicense( cats[i].license ) ;
      if( foundCat != i ) {
         fprintf( stderr, "%s: Found a duplicate cat license [%llu] at indexes [%zu] and [%zu].\n", PROGRAM_NAME, cats[i].license, i, foundCat ) ;
         return false ;
      }

      if( cats[i].collarColor1 == cats[i].collarColor2 ) {
         fprintf( stderr, "%s: Found a cat with a bad collar.\n", PROGRAM_NAME ) ;
         return false;
      }

      if( !isWeightValid( cats[i].weight )) {
         // isWeightValid() prints the error message
         return false;
      }
   }

   // printf( "%s: The database is valid.\n", PROGRAM_NAME ) ;

   return true ;  // The database is healthy
}



/// Verify the name is valid
///
/// Note:  It does not check for duplicate names...
bool isNameValid( const char* name ) {
   if( name == nullptr ) {
      fprintf( stderr, "%s: The cat's name can't be NULL.\n", PROGRAM_NAME ) ;
      return false ;
   }

   if( strlen( name ) <= 0 ) { // The name is empty...
      fprintf( stderr, "%s: The cat's name can't be empty.\n", PROGRAM_NAME ) ;
      return false ;
   }

   if( strlen( name ) > MAX_CAT_NAME - 1 ) { // The name is too large...
      fprintf( stderr, "%s: CatStruct name [%s] is too long.  The maximum allowed length is [%d]\n", PROGRAM_NAME, name, MAX_CAT_NAME - 1 ) ;
      return false ;
   }

   return true ;
}


/// Swap the cats in the indexes
/// Return true if successful
bool swapCat( const size_t a, const size_t b ) {
   if( !isIndexValid( a ) ) {
      fprintf( stderr, "%s: %s(): Bad cat!\n", PROGRAM_NAME, __FUNCTION__ ) ;
      return false ;
   }

   if( !isIndexValid( b ) ) {
      fprintf( stderr, "%s: %s(): Bad cat!\n", PROGRAM_NAME, __FUNCTION__ ) ;
      return false ;
   }

   if( a == b ) {
      return true ; // a and b are the same... so a swap is successful (and does nothing)
   }

   // Swap a and b
   struct CatStruct oldCat ;

   memcpy( &oldCat,  &cats[a], sizeof( struct CatStruct ) );
   memcpy( &cats[a], &cats[b], sizeof( struct CatStruct ) );
   memcpy( &cats[b], &oldCat,  sizeof( struct CatStruct ) );

   return true ;
}
*/
