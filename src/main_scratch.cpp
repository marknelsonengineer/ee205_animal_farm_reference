///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// A scratch program for testing things
///
/// Practice tagging for:  Animal Farm 2 - Modified
///
/// @file main_scratch.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   06_May_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "Animal/Bird/Finch.h"
#include "Container/BinarySearchTree.h"

using namespace std;

/// Entry point for the program
int main() {

   BinarySearchTree bst;

   for( int i = 0 ; i < 10 ; i++ ) {
      Finch* myFinch = new Finch ( Bird::ConstructorType::RANDOM );
      cout << myFinch->info() << endl;
      // myFinch.dump();
      bst.add( myFinch );
   }

   bst.dump();
   return 0;
}
