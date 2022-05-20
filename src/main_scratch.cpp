///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// A scratch program for testing things
///
/// Practice tagging for:  Animal Farm 2 - Modified
///
/// @file main_scratch.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   06_May_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "Animal/Bird/Finch.h"

using namespace std;

/// Entry point for the program
int main() {
//   Weight myWeight { Weight::UNKNOWN_WEIGHT, Weight::UNKNOWN_WEIGHT };
//   myWeight.dump();

   // Finch myFinch("Boo", Gender::UNKNOWN_GENDER, 0.00001 );
   for( int i = 0 ; i < 10 ; i++ ) {
      Finch myFinch { Bird::ConstructorType::RANDOM };
      // cout << myFinch.speak() << endl;
      cout << myFinch.info() << endl;
      myFinch.dump();
   }
   return 0;
}
