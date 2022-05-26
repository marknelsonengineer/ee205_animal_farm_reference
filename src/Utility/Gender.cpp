///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// A gender class... for educational use only.
/// This is not intended to be inclusive of all possible genders
///
/// @file Gender.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   26_May_2022
///////////////////////////////////////////////////////////////////////////////

#include <random>

#include "../config.h"
#include "Gender.h"

using namespace std;

/// Define a long-lasting (static) Random Number Generator (RNG) from the first
/// Gender (#Gender::UNKNOWN_GENDER) to the last Gender (#Gender::FEMALE)
static uniform_int_distribution<> genderRNG( (int) Gender::UNKNOWN_GENDER, (int) Gender::FEMALE );


Gender newRandomGender() {
   return (Gender) genderRNG( ANIMAL_FARM_RNG ) ;
}
