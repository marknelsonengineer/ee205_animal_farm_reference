///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// A scratch program for testing things
///
/// @file main_test.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   06_May_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "Animal/Cat.h"

using namespace std;

/// Entry point for the program
int main() {
   Cat a( "Boo" );

   a.dump();

   return 0;
}
