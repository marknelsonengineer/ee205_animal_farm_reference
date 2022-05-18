///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// Demonstrate virtual binding and exercise a SinglyLinkedList
///
/// @file main_animalFarm.cpp
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

   // Put some Animals in the list
   for( int i = 0 ; i < NUMBER_OF_ANIMALS ; i++ ) {
      animalDB.push_front( &AnimalFactory::generateAnimal() );
   }

   for( Animal* animal = (Animal*) animalDB.get_first() ; animal != nullptr ; animal = (Animal*) SinglyLinkedList::get_next( animal ) ) {
      cout << animal->info() << endl;  /// @todo Replace speak() with info() when we have it available
   }

   cout << "Done with " << PROGRAM_TITLE ;

   return( EXIT_SUCCESS ) ;
}