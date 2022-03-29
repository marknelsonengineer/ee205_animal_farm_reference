///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 2.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   14_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>
#include <stdexcept>

#include "config.h"
#include "deleteCats.h"
#include "catDatabase.h"
#include "Cat.h"

using namespace std ;

/// @param deleteThisCat The cat to delete.  Must not be `nullptr`.
/// @return True if the delete is successful.
/// @throws invalid_argument if the cat is not in the database
bool deleteCat( Cat* deleteThisCat ) {
/*
   assert( deleteThisCat != nullptr ) ;

   assert( validateDatabase() ) ;

   // Handle the special case first...
   if( deleteThisCat == catDatabaseHeadPointer ) {
      catDatabaseHeadPointer = catDatabaseHeadPointer->next ;
      delete deleteThisCat ;
      numberOfCats--;

      assert( validateDatabase() ) ;
      return true ;
   }

   // If it's not the first cat, then let's go find it
   Cat* iCat = catDatabaseHeadPointer ;
   while( iCat != nullptr ) {
      if( iCat->next == deleteThisCat ) {
         iCat->next = deleteThisCat->next ;
         delete deleteThisCat ;
         numberOfCats--;

         assert( validateDatabase() ) ;

         return true ;
      }
      iCat = iCat->next ;
   }

   assert( validateDatabase() ) ;

   throw invalid_argument( PROGRAM_NAME ": Unable to delete cat.  Not in database" );
   */
return true;
}


/// @returns true if the cats were successfully deleted.
///          false if something bad happened
bool deleteAllCats() {
   /*
   // Keep deleting cats until there are no more cats...
   while(catDatabaseHeadPointer != nullptr ) {
      deleteCat(catDatabaseHeadPointer ) ;
   }

//	numCats = 0 ;            // ...and just like that...

#ifdef DEBUG
   cout << PROGRAM_NAME << ": All cats have been deleted" << endl ;
#endif
*/
   return true ;
}
