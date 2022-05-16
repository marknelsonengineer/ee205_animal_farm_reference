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


/// @param newMaxWeight Must be a valid weight per Weight::isWeightValid
/// @param newSpecies Must be a valid name per Name::validateName
Mammal::Mammal( const Weight::t_weight newMaxWeight
              , const std::string_view newSpecies )
              : Animal( newMaxWeight, MAMMAL_NAME, newSpecies )  // Delegating constructor
   {}  // Nothing else to do


/// @param newColor The Mammal's primary color
/// @param newGender The Gender of the Animal
/// @param newWeight Must be a valid weight per Weight::isWeightValid
/// @param newMaxWeight Must be a valid weight per Weight::isWeightValid
/// @param newSpecies Must be a valid name per Name::validateName
Mammal::Mammal( const Color            newColor
              , const Gender           newGender
              , const Weight::t_weight newWeight
              , const Weight::t_weight newMaxWeight
              , const std::string_view newSpecies )
              : Animal( newGender, newWeight, newMaxWeight, MAMMAL_NAME, newSpecies )  // Delegating constructor
              , color { newColor }  // Member initializer list
   {}  // Nothing else to do


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
