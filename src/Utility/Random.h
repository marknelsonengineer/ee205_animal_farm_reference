///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file RandomNumbers.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   03_May_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <random>

/// Create 2 Random Number Generators (RNGs):
///    1. A true RNG           - Truly random
///    2. A pseudo-RNG or PRNG - Seems random, but the results are consistent
extern std::random_device trueRNG;          ///< This is a real random number generator (if available)
extern std::mt19937 mersenneTwisterPRNG;    ///< This is a seeded pseudorandom number generator
