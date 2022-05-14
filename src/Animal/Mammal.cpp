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


Mammal::Mammal( const Weight::t_weight newMaxWeight
               ,const std::string&     newSpecies
              ) : Animal( newMaxWeight, MAMMAL_NAME, newSpecies ) {};


Mammal::Mammal( const Color            newColor
               ,const Gender           newGender
               ,const Weight::t_weight newWeight
               ,const Weight::t_weight newMaxWeight
               ,const std::string&     newSpecies
              ) : Animal( newGender, newWeight, newMaxWeight, MAMMAL_NAME, newSpecies )
                , color { newColor } {};


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
