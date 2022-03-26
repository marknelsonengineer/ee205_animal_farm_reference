///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 2.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   14_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>

#include "config.h"
#include "catDatabase.h"
#include "addCats.h"

using namespace std;

/// @param newCat The cat to add.  Must not be `nullptr`
/// @return True if successful.  False if something bad happens.
/// @throws logic_error if newCat is already in database
bool addCat(Cat* newCat) {
   assert( newCat != nullptr ) ;
   newCat->validate() ;

   if( isCatInDatabase( newCat ) ) {
      throw logic_error( PROGRAM_NAME ": Cat is already in database!" );
   }

   assert( validateDatabase() ) ;

   // Everything looks good, so add the cat

   newCat->next = catDatabaseHeadPointer ;
   catDatabaseHeadPointer = newCat ;
   numberOfCats++;

   assert( validateDatabase() ) ;

   #ifdef DEBUG
      cout << PROGRAM_NAME << ": Added cat [" << newCat->getName() << "]" << endl ;
   #endif

   return true;
}
