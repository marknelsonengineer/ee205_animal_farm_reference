///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// Random number utilities
///
/// @file   Random.cpp
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Random.h"

using namespace std;

/// NOLINTNEXTLINE(cert-err58-cpp): Suppress `Initialization of genderRNG with static storage duration may throw an exception that cannot be caught`
std::random_device trueRNG;          ///< This is a real random number generator (if available)

/// NOLINTNEXTLINE(cert-err58-cpp, cert-msc32-c,cert-msc51-cpp): Suppress `Initialization of genderRNG with static storage duration may throw an exception that cannot be caught` warning.  Suppress `pseudorandom sequence` warning
std::mt19937 mersenneTwisterPRNG(0); ///< This is a seeded pseudorandom number generator
