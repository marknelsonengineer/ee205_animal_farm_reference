///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// Orchestrates the entire program:
///    Starting Animal Farm 2
/// ...and end by printing
///    Done with Animal Farm 2
///
/// @file main_DoublyLinkedList.cpp
/// @version 2.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   14_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cstdlib>  // For EXIT_SUCCESS / EXIT_FAILURE
#include <iostream>

#include "config.h"
#include "Animal/Cat.h"
#include "Container/DoublyLinkedList.h"

using namespace std ;


/// The entry point for Animal Farm
int main() {
   cout << "Starting " << PROGRAM_TITLE << endl ;

   DoublyLinkedList catDB ;

   Cat newCat = Cat::generateCat();

   newCat.dump();
   cout << "========" << endl;

   // Put 16 cats in my list
   for( int i = 0 ; i < 8 ; i++ ) {
      catDB.push_front( &Cat::generateCat() );
      catDB.push_back( &Cat::generateCat() );
   }

   for( Animal* pAnimal = (Animal*)catDB.get_first() ; pAnimal != nullptr ; pAnimal = (Animal*)List::get_next( (Node*)pAnimal ) ) {
      cout << pAnimal->speak() << endl;
   }

   catDB.validate() ;
   catDB.dump() ;
   catDB.deleteAllNodes() ;
   catDB.dump() ;

   cout << "Done with " << PROGRAM_TITLE ;

   return( EXIT_SUCCESS ) ;
}
