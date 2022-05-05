///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// Print a family tree of cats by generation
///
/// @file catGenerations.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   30_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "config.h"
#include "Animal/CatEmpire.h"

using namespace std;

/// Number of cats to process
const int NUMBER_OF_CATS = 100;

/// The entry point for catGenerations
int main() {
   cout << "Welcome to catGenerations of Cat Empire!" << endl;

   CatEmpire catEmpire;

   for( int i = 0 ; i < NUMBER_OF_CATS ; i++ ) {
      Cat& newCat = Cat::generateCat();

      catEmpire.insert( &newCat );
   }

   cout << "List of " << NUMBER_OF_CATS << " cats by generation" << endl;

   catEmpire.catGenerations();
}
