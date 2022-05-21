///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// Generate random Animal classes
///
/// @file AnimalFactory.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   06_May_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Animal.h"

/// Generate Animal classes
///
/// @pattern Abstract Factory
/// Abstract Factories encapsulate a group of individual factories
/// (like Cat::generateCat()) that have a common theme without specifying
/// their concrete class.  Users of this class don't care which concrete object
/// it gets, because the users only use the generic interface (Animal).
///
/// #### Internal
/// This could have also been a static method in Animal.  However, if we did that, then
/// every class that has an Animal, also needs Mammal, Bird, Cat, Dog, et.al.
/// A better way is to have a dedicated AnimalFactory class and only link all
/// of the other Animals when they are needed.
class AnimalFactory {
public:  /////////////////////// Static Public Methods /////////////////////////
   static Animal& generateAnimal() ;  ///< Generate a new, random Animal
};
