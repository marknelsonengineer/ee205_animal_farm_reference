///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// Color class enumeration
///
/// @file Color.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   26_May_2022
///////////////////////////////////////////////////////////////////////////////

#include <random>

#include "../config.h"
#include "Color.h"

using namespace std;

/// Define a long-lasting (static) Random Number Generator (RNG) from the first
/// Color (Color::UNKNOWN_COLOR) to the last Color (Color::CALICO)
static uniform_int_distribution<> colorRNG( (int) Color::UNKNOWN_COLOR, (int) Color::CALICO );


Color newRandomColor() {
   return (Color) colorRNG( ANIMAL_FARM_RNG ) ;
}
