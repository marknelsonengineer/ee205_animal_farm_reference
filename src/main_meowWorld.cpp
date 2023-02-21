///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Generic Hello World application
///
/// @file    main_meowWorld.cpp
/// @author  Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "config.h"  // For PROGRAM_NAME

#include <cstdlib>   // For EXIT_SUCCESS
#include <iostream>  // For cout & endl


/// A Hello World program
///
/// @see https://en.wikipedia.org/wiki/%22Hello%2C_World!%22_program
///
/// @return The exit value for the program
int main() {
   std::cout << PROGRAM_NAME << ":  Meow, World!" << std::endl;
   return EXIT_SUCCESS;
}
