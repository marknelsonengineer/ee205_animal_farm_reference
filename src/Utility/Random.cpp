///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Random.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   03_May_2022
///////////////////////////////////////////////////////////////////////////////

#include "Random.h"

using namespace std;

std::random_device trueRNG;          ///< This is a real random number generator (if available)
std::mt19937 mersenneTwisterPRNG(0); ///< This is a seeded pseudorandom number generator
