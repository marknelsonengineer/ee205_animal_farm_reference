///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Mammal.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   09_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <string>
#include <cassert>

#include "../config.h"
#include "Mammal.h"

using namespace std;


const std::string Mammal::MAMMAL_NAME = "Mammilian";


void Mammal::dump() const noexcept {
   assert( validate() ) ;

   Animal::dump() ;

   FORMAT_LINE_FOR_DUMP( "Mammal", "color" ) << color << endl ;
}
