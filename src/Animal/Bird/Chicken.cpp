///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// Hawaiian Chicken
///
/// @file Chicken.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   19_May_2022
///////////////////////////////////////////////////////////////////////////////

#include <random>
#include <cassert>
#include <cfloat>   // For FLT_TRUE_MIN

#include "Chicken.h"
#include "../../Utility/Trim.h"
#include "Bird.h"

using namespace std;

// Statically declared, so it can be available for any and all Chicken to use (but nobody else).
Name Chicken::names( "Chicken ", "" );

/// Generate a random weight from `FLT_TRUE_MIN` to `Chicken::MAX_WEIGHT`
static uniform_real_distribution<> weightRNG( FLT_TRUE_MIN, Chicken::MAX_WEIGHT );


Chicken::Chicken( const std::string_view newName
        ,const Gender                    newGender
        ,const Weight::t_weight          newWeight
)
        : Bird( SPECIES_NAME, MAX_WEIGHT, newName, newGender, newWeight )  // Delegating constructor
{} // Nothing else to do


/// I'm deliberately not using a Factory Method pattern here, just to demonstrate
/// that there's other ways to do this.
Chicken::Chicken( [[maybe_unused]] const Bird::ConstructorType newBirdType )
         : Bird ( SPECIES_NAME, MAX_WEIGHT, names.getNextName(), newRandomGender(), (Weight::t_weight) weightRNG( ANIMAL_FARM_RNG ) )
{
   assert( newBirdType == Bird::ConstructorType::RANDOM );  // This may generate a warning in Release mode, but it's OK
}


string_view Chicken::speak() const noexcept {
   return "Cluck"sv;
}
