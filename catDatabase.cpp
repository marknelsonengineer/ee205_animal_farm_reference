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

#include <cstring>   // For memset
#include <cassert>   // For the assert function
#include <cstdio>

#include "config.h"
#include "catDatabase.h"
#include "reportCats.h"


/// The array that holds all of our cats
struct Cat cats[MAX_CATS];

size_t numCats = 0 ;  ///< This is top of the cat array


/// Zeros out a cat's information from the database
/// No bounds checking
void wipeCatInternal( const size_t index ) {
   memset( &cats[index], 0, sizeof( struct Cat ) );
}


/// Zeros out a cat's information from the database
void wipeCat( const size_t index ) {
   assert( isIndexValid( index ) ) ;

   wipeCatInternal( index ) ;
}


/// Initialize the catabase
void initializeDatabase() {
   numCats = 0 ;  // Zero out the cats in the database

   memset( &cats, 0, sizeof( cats ) ) ;
}


/// Return true if the database is full
///
/// Various modules should check if the database is full before
/// adding data.  This function will also verify the database
/// is healthy first.
bool isFull() {
   validateDatabase() ;  // Make sure things are healthy first

   if( numCats >= MAX_CATS ) {  // The database is full
      return true ;
   }

   return false ;  // The database is not full
}


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


/// Verify the index is a valid value for this database
extern bool isIndexValid( const size_t index ) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
   if( index < 0 ) {
      fprintf( stderr, "%s: %s(): Index is < 0\n", PROGRAM_NAME, __FUNCTION__ ) ;
      return false ;
   }
#pragma GCC diagnostic pop

   if( index >= numCats ) {
      fprintf( stderr, "%s: %s(): index [%lu] is >= the number of cats in the database [%lu]\n", PROGRAM_NAME, __FUNCTION__, index, numCats ) ;
      return false ;
   }

   return true ;
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
      fprintf( stderr, "%s: Cat name [%s] is too long.  The maximum allowed length is [%d]\n", PROGRAM_NAME, name, MAX_CAT_NAME - 1 ) ;
      return false ;
   }

   return true ;
}


/// Verify the weight is valid
bool isWeightValid( const float weight ) {
   if( weight <= 0 ) {
      fprintf( stderr, "%s: Cat's weight is [%f].  It must be > 0\n", PROGRAM_NAME, weight ) ;
      return false ;
   }

   return true ;
}


bool areCatCollarsValid(enum Color collarColor1, enum Color collarColor2 ) {
   if(collarColor1 == collarColor2 ) {
      fprintf( stderr, "%s: The two colors on a cat's collar can't be the same\n", PROGRAM_NAME ) ;
      return false ;
   }

   if( findCatByCollars( collarColor1, collarColor2 ) != BAD_CAT ) {
      fprintf( stderr, "%s: Two cats can't have the same collar color\n", PROGRAM_NAME ) ;
      return false;
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
   struct Cat oldCat ;

   memcpy( &oldCat,  &cats[a], sizeof( struct Cat ) );
   memcpy( &cats[a], &cats[b], sizeof( struct Cat ) );
   memcpy( &cats[b], &oldCat,  sizeof( struct Cat ) );

   return true ;
}
