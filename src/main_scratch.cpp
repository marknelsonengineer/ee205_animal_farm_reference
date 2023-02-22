///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// A scratch program for testing things
///
/// @file   main_scratch.cpp
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <cstdlib>   // For EXIT_SUCCESS
#include <iostream>  // For cout

#include "Utility/Name.h"


using namespace std;

/// Entry point for the program
///
/// NOLINTNEXTLINE(bugprone-exception-escape): Suppress `An exception may be thrown in main warning`
int main() {

   Name aName = Name( "A", "B" );

   return EXIT_SUCCESS;
}
