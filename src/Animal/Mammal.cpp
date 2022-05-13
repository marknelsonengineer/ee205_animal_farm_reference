///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// Mammals have more fun
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


/// Output the contents of this object (and its parents).
///
/// #### Sample Output
/**@verbatim
======================================================
Mammal              color               Unknown color
@endverbatim */
void Mammal::dump() const noexcept {
   assert( validate() ) ;

   Animal::dump() ;

   FORMAT_LINE_FOR_DUMP( "Mammal", "color" ) << color << endl ;
}
