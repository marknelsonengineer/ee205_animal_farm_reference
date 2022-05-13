///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// A scratch program for testing things
///
/// @file main_test.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   06_May_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "Animal/Cat.h"
#include "Container/DoublyLinkedList.h"

using namespace std;

/// Entry point for the program
int main() {
   DoublyLinkedList aa;

   Cat a( "Alice" );
   Cat b( "Boo" );
   Cat c( "Chili" );

   aa.push_back( &a );
   aa.push_back( &b );
   aa.push_back( &c );

   cout << "b:  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
   b.dump();
   cout << "b: ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;

   return 0;
}
