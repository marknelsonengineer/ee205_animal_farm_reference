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
/// This could be a static method in Animal.  However, if we did that, then
/// every class that wants an Animal, also needs Mammal, Cat, Dog, Bird, et.al.
/// A better way is to have a dedicated AnimalFactory class and only link all
/// of the other Animals when we really need them.
class AnimalFactory {
public:  /////////////////////// Static Public Methods /////////////////////////
   static Animal& generateAnimal() ;  ///< Generate a new, random Animal
};
