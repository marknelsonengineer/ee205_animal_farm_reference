///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// A gender class... for educational use only.
/// This is not intended to be inclusive of all possible genders.
///
/// @file   Gender.cpp
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <random>       // For uniform_int_distribution<>

#include "../config.h"  // For ANIMAL_FARM_RNG
#include "Gender.h"     // Just cuz

using namespace std;

/// Define a long-lasting (static) Random Number Generator (RNG) from the first
/// Gender (#Gender::UNKNOWN_GENDER) to the last Gender (#Gender::FEMALE)
///
/// NOLINTNEXTLINE(cert-err58-cpp): Suppress `Initialization of genderRNG with static storage duration may throw an exception that cannot be caught` warning
static uniform_int_distribution<> genderRNG( (int) Gender::UNKNOWN_GENDER, (int) Gender::FEMALE );


Gender newRandomGender() {
   return (Gender) genderRNG( ANIMAL_FARM_RNG ) ;
}
