///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// Print a pedigree of cats
///
/// @file main_catBegat.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   30_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "Animal/CatEmpire.h"

using namespace std;

/// Number of cats to process
const int NUMBER_OF_CATS = 20;

/// The entry point for catBegat
///
/// Print a Family Tree of 20 Cats
int main() {
   cout << "Welcome to catBegat of Cat Empire!" << endl;

   CatEmpire catEmpire;

   for( int i = 0 ; i < NUMBER_OF_CATS ; i++ ) {
      Cat& newCat = Cat::generateCat();

      catEmpire.insert( &newCat );
   }

   cout << "Print a pedigree of " << NUMBER_OF_CATS << " cats" << endl;

   catEmpire.catBegat();
}
