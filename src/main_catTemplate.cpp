///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// Demonstrate the use of the STL `list` template (and potentially others)
///
/// @file main_catTemplate.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   05_May_2022
///////////////////////////////////////////////////////////////////////////////


#include <cstdlib>  // For EXIT_SUCCESS / EXIT_FAILURE
#include <iostream>
#include <list>     // For the list template
//#include <set>     // For the set template

#include "config.h"
#include "Animal/Mammal/Cat/Cat.h"

using namespace std ;

/// Number of Cats to process
const int NUMBER_OF_CATS = 20;


/// The entry point for Animal Farm
int main() {
   cout << "Starting " << PROGRAM_TITLE << endl ;

   list<Cat> catDB ;
   // set<Animal> animalDB;  // @todo Consider exploring several STL data structures

   // Put some Animals in the list
   for( int i = 0 ; i < NUMBER_OF_CATS ; i++ ) {
      catDB.push_back( Cat::newRandomCat() );
   }

   for( const Cat& aCat : catDB ) {
      cout << aCat.info() << endl;

   }

   cout << "Done with " << PROGRAM_TITLE ;

   return( EXIT_SUCCESS ) ;
}
