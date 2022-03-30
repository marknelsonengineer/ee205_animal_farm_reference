///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 2.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   14_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdexcept>  // For logic_error
#include <iostream>
#include <cassert>

#include "config.h"
#include "catDatabase.h"
#include "Cat.h"
#include "reportCats.h"

using namespace std;

/// The head pointer to a linked list of cats
//Cat* catDatabaseHeadPointer = nullptr ;



/// If the database is valid, this should be silent.  If the database is not
/// valid, it should print a message as to why and then return false.  It
/// should not throw an exception.
///
/// @todo When this becomes a collection class, make sure it's `const noexcept`
///
/// @return True if the database is healthy
/*
extern bool validateDatabase() {
   int validCats = 0 ;

   for(Cat* iCat = catDatabaseHeadPointer ; iCat != nullptr ; iCat = iCat->next ) {
      if( !iCat->validate() ) {
         return false ;
      }

      Cat* foundCat = findCatByName( iCat->getName() ) ;
      if( foundCat != iCat ) {
         cout << PROGRAM_NAME ": Warning:  Found a duplicate cat name [" << iCat->getName() << "]" << endl ;
      }

      validCats++ ;
   }

   if( validCats != numberOfCats ) {
      cout << PROGRAM_NAME << ": Error:  numberOfCats [" << numberOfCats
           << "] does not equal [" << validCats << "]" << endl ;
      return false ;
   }

   #ifdef DEBUG
      cout << PROGRAM_NAME << ": The database is valid." << endl ;
   #endif

   return true ;  // The database is healthy
}
*/
