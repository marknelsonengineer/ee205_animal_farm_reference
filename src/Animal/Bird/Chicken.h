///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// Hawaiian Chicken
///
/// @file Chicken.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   19_May_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>

#include "Bird.h"

/// Hawaiian Chicken
class Chicken : public Bird {
public:   //////////////////////// Constants ///////////////////////////////////
   static const constexpr std::string_view SPECIES_NAME { "Gallus domesticus" };         ///< The scientific name for a Chicken
   static const constexpr Weight::t_weight MAX_WEIGHT { 22 };  ///< The maximum weight for a Chicken.  @see https://www.guinnessworldrecords.com/world-records/70789-heaviest-breed-of-chicken

public:  ////////////////////////// Static Members /////////////////////////////
   static Name names;   ///< A serialized list of Bird names

public:  //////////////////////////// Constructors /////////////////////////////

   /// Create a Chicken, populating *all* of the member variables
   explicit
   Chicken( const std::string_view newName   = names.getNextName()
           ,const Gender           newGender = Gender::UNKNOWN_GENDER
           ,const Weight::t_weight newWeight = Weight::UNKNOWN_WEIGHT
   );

   /// Create a random Chicken
   explicit Chicken( const ConstructorType  newBirdType );

public:   /////////////////////////// Public Methods ///////////////////////////

   std::string_view speak() const noexcept override;  ///< Chickens "Cluck"
};
