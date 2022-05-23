///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// Print a reverse alphabetized list of cats in a Binary Search Tree
///
/// @file main_catTail.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   30_Apr_2022
///////////////////////////////////////////////////////////////////////////////


#include <iostream>

#include "config.h"
#include "Animal/Mammal/Cat/CatEmpire.h"

using namespace std;

/// Number of cats to process
const int NUMBER_OF_CATS = 20;

/// The entry point for catList
int main() {
   cout << "Welcome to catTail of Cat Empire!" << endl;

   CatEmpire catEmpire;
   CatEmpire catTail;

   for( int i = 0 ; i < NUMBER_OF_CATS ; i++ ) {
      Cat& newCat = Cat::newRandomCat();

      catEmpire.add( &newCat );
   }

   cout << "Print a reverse alphabetized list of " << NUMBER_OF_CATS << " cats in a binary search tree" << endl;
   catEmpire.catTail( &catTail );
   catTail.catFamilyTree();
}
