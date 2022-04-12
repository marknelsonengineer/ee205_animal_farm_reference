///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// Orchestrates the entire program:
///    Starting Animal Farm 2
/// ...and end by printing
///    Done with Animal Farm 2
///
/// @file main.cpp
/// @version 2.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   14_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cstdlib>  // For EXIT_SUCCESS / EXIT_FAILURE
#include <iostream>

#include "config.h"
#include "Cat.h"
#include "SinglyLinkedList.h"

using namespace std ;


/// The entry point for Animal Farm
int main() {
   cout << "Starting " << PROGRAM_TITLE << endl ;

   SinglyLinkedList catDB ;

   Cat aCat( "Chili", Color::GINGER, true, Gender::MALE, 18 );

   catDB.push_front( new Cat( "Loki",  Color::CREAM, true,  Gender::MALE,   1.0 ) ) ;
   catDB.push_front( new Cat( "Milo",  Color::BLACK, true,  Gender::MALE,   1.1 ) ) ;
   catDB.push_front( new Cat( "Bella", Color::BROWN, true,  Gender::FEMALE, 1.2 ) ) ;
   catDB.push_front( new Cat( "Kali",  Color::CALICO, true, Gender::FEMALE, 1.3 ) ) ;
   catDB.push_front( new Cat( "Trin",  Color::WHITE, true,  Gender::FEMALE, 1.4 ) ) ;
   catDB.push_front( new Cat( "Chili", Color::GINGER, true, Gender::MALE,   1.5 ) ) ;

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
