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

#include <cstdio>
#include <cassert>
#include <iostream>

#include "config.h"
#include "deleteCats.h"
#include "catDatabase.h"

using namespace std ;

/// \param deleteThisCat The cat to delete.  Must not be `nullptr`.
/// \return
bool deleteCat( Cat* deleteThisCat ) {
   assert( deleteThisCat != nullptr ) ;

   assert( validateDatabase() ) ;

   // Handle the special case first...
   if(deleteThisCat == catDatabaseHeadPointer ) {
      catDatabaseHeadPointer = catDatabaseHeadPointer->next ;
      delete deleteThisCat ;
      assert( validateDatabase() ) ;
      return true ;
   }

   // If it's not the first cat, then let's go find it
   Cat* iCat = catDatabaseHeadPointer ;
   while( iCat != nullptr ) {
      if( iCat->next == deleteThisCat ) {
         iCat->next = deleteThisCat->next ;
         delete deleteThisCat ;

         assert( validateDatabase() ) ;

         return true ;
      }
      iCat = iCat->next ;
   }

   assert( validateDatabase() ) ;

   return false ;  // We never found deleteThisCat!
}


bool deleteAllCats() {
   // Keep deleting cats until there are no more cats...
   while(catDatabaseHeadPointer != nullptr ) {
      deleteCat(catDatabaseHeadPointer ) ;
   }

//	numCats = 0 ;            // ...and just like that...

#ifdef DEBUG
   cout << PROGRAM_NAME << ": All cats have beel deleted" << endl ;
#endif

   return true ;
}
