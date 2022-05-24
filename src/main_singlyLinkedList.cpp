///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// Demonstrate virtual binding and exercise a SinglyLinkedList
///
/// @file main_singlyLinkedList.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   05_May_2022
///////////////////////////////////////////////////////////////////////////////

#include <cstdlib>  // For EXIT_SUCCESS / EXIT_FAILURE
#include <iostream>

#include "config.h"
#include "Container/SinglyLinkedList.h"
#include "Animal/Animal.h"
#include "Animal/AnimalFactory.h"

using namespace std ;

/// Number of Animals to process
const int NUMBER_OF_ANIMALS = 20;


/// The entry point for Animal Farm
int main() {
   cout << "Starting " << PROGRAM_TITLE << endl ;

   SinglyLinkedList animalDB ;

   // Put some Animals in the List
   for( int i = 0 ; i < NUMBER_OF_ANIMALS ; i++ ) {
      animalDB.addFront( &AnimalFactory::newRandomAnimal() );
   }

   for( Animal* animal = (Animal*) animalDB.getFirst() ; animal != nullptr ; animal = (Animal*) SinglyLinkedList::getNext( animal ) ) {
      cout << animal->info() << endl;
   }

   cout << "Done with " << PROGRAM_TITLE ;

   return( EXIT_SUCCESS ) ;
}
