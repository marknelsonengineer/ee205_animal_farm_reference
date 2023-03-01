///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// Generate random Animal classes
///
/// @file   AnimalFactory.cpp
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <cassert> // For assert
#include <random>  // For uniform_int_distribution

#include "../config.h"
#include "AnimalFactory.h"
#include "Bird/Chicken.h"
#include "Bird/Finch.h"
#include "Mammal/Cat/Cat.h"
#include "Mammal/Dog/Dog.h"

using namespace std;

/// #### Internal
/// This function uses `new` to create an Animal on the heap.  Be sure to
/// `delete` it when it's no longer needed
Animal& AnimalFactory::newRandomAnimal() {
   uniform_int_distribution<> animalRNG( 0, 3 );

   Animal* newAnimal = nullptr;

   switch( animalRNG( ANIMAL_FARM_RNG ) ) {
      case 0: newAnimal = &( Cat::newRandomAnimal()) ; break;
      case 1: newAnimal = &( Dog::newRandomAnimal()) ; break;
      case 2: newAnimal = new Finch( Bird::ConstructorType::RANDOM ) ; break;
      case 3: newAnimal = new Chicken( Bird::ConstructorType::RANDOM ) ; break;
      default: assert ( false );  // We should never get here
   }

   assert( newAnimal != nullptr );

   return *newAnimal;
}
