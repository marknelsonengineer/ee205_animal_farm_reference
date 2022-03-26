///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.h
/// @version 2.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   14_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "config.h"
#include "Cat.h"

/// Print all cats in the database
extern bool   printAllCats() ;

/// Find a cat
extern Cat* findCatByName( const char* name ) ;

/// Return a string for the name of the gender
extern const char* genderName( enum Gender gender ) ;

/// Return a string for the name of the breed
extern const char* breedName( enum Breed breed ) ;

// Return a string for the name of the color
// extern const char* colorName ( enum Color color ) ;
