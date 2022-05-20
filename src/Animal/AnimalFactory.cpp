///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// Generate random Animal classes
///
/// @file AnimalFactory.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   06_May_2022
///////////////////////////////////////////////////////////////////////////////

#include <random>  // For uniform_int_distribution
#include <cassert> // For assert

#include "../config.h"
#include "AnimalFactory.h"
#include "Mammal/Cat/Cat.h"
#include "Mammal/Dog/Dog.h"
#include "Bird/Finch.h"
#include "Bird/Chicken.h"

using namespace std;

/// @internal This function uses `new` to create an Animal on the heap
///           Be sure to `delete` it when it's no longer needed
Animal& AnimalFactory::generateAnimal() {
   uniform_int_distribution<> animalRNG( 0, 3 );

   Animal* newAnimal = nullptr;

   switch( animalRNG( ANIMAL_FARM_RNG ) ) {
      case 0: newAnimal = &(Cat::generateCat()) ; break;
      case 1: newAnimal = &(Dog::generateDog()) ; break;
      case 2: newAnimal = new Finch( Bird::ConstructorType::RANDOM ) ; break;
      case 3: newAnimal = new Chicken( Bird::ConstructorType::RANDOM ) ; break;
      default: assert ( false );  // We should never get here
   }

   assert( newAnimal != nullptr );

   return *newAnimal;
}
