///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// ʻIʻiwi (Drepanis coccinea)
///
/// @file   Finch.h
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>

#include "Bird.h"

/// ʻIʻiwi (Drepanis coccinea)
class Finch : public Bird {
public:   //////////////////////// Constants ///////////////////////////////////
   static const constexpr std::string_view SPECIES_NAME { "Vestiaria coccinea" };         ///< The scientific name for a ʻIʻiwi (Hawaiian Finch)
   static const constexpr Weight::t_weight MAX_WEIGHT { Weight::fromGramToPound( 27 ) };  ///< The maximum weight for a Finch

public:  ////////////////////////// Static Members /////////////////////////////
   static Name names;   ///< A serialized list of Bird names

public:  //////////////////////////// Constructors /////////////////////////////

   /// Create a Finch, populating *all* of the member variables
   explicit
   Finch( std::string_view newName   = names.getNextName()
         ,Gender           newGender = Gender::UNKNOWN_GENDER
         ,Weight::t_weight newWeight = Weight::UNKNOWN_WEIGHT
   );

   /// Create a random Finch
   explicit Finch( ConstructorType  newBirdType );
};
