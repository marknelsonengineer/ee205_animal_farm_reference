///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// Color class enumeration
///
/// @file   Color.cpp
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "../config.h"  // For ANIMAL_FARM_RNG
#include "Color.h"      // Just cuz

#include <random>       // For uniform_int_distribution<>

using namespace std;

/// Define a long-lasting (static) Random Number Generator (RNG) from the first
/// Color (Color::UNKNOWN_COLOR) to the last Color (Color::CALICO)
///
/// NOLINTNEXTLINE(cert-err58-cpp): Suppress `Initialization of genderRNG with static storage duration may throw an exception that cannot be caught`
static uniform_int_distribution<> colorRNG( (int) Color::UNKNOWN_COLOR, (int) Color::CALICO );


Color newRandomColor() {
   return (Color) colorRNG( ANIMAL_FARM_RNG ) ;
}
