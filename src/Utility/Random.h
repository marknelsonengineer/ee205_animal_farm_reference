///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// Random number utilities
///
/// @file   Random.h
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <random>

/// Create 2 Random Number Generators (RNGs):
///    1. A true RNG           - Truly random
///    2. A pseudo-RNG or PRNG - Seems random, but the results are consistent
extern std::random_device trueRNG;          ///< This is a real random number generator (if available)
extern std::mt19937 mersenneTwisterPRNG;    ///< This is a seeded pseudorandom number generator
