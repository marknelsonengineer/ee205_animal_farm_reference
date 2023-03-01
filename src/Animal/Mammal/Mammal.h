///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// Mammals have more fun
///
/// @file   Mammal.h
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../../Utility/Color.h"
#include "../Animal.h"


/// Mammals have more fun.
///
/// Mammals don't have anything to validate.
/// Comparing two Mammals is done at the Animal level using Classification.
class Mammal : public Animal {
public:   //////////////////////// Constants ///////////////////////////////////
   static const constexpr std::string_view CLASSIFICATION_NAME { "Mammalia" };  ///< The scientific name for Mammals

protected:  ///////////////////////// Member Variables /////////////////////////
   Color color = Color::UNKNOWN_COLOR;  ///< The primary color of the Mammal

public:   /////////////////////// Constructors ////////////////////////////////
   /// Create a Mammal with the *minimum* required fields
   Mammal( Weight::t_weight newMaxWeight
          ,std::string_view newSpecies
   );

   /// Create a Mammal, populating *all* of the member variables
   Mammal( Color            newColor
          ,Gender           newGender
          ,Weight::t_weight newWeight
          ,Weight::t_weight newMaxWeight
          ,std::string_view newSpecies
   );

public:  ////////////////////////// Getters & Setters //////////////////////////
   [[nodiscard]] Color getColor() const noexcept { return color; }  ///< Get the color
   void  setColor( const Color newColor ) noexcept { color = newColor; }  ///< Set the color

public:  /////////////////////////// Public Methods ////////////////////////////
   void dump() const noexcept override;  ///< Output the contents of this object (and its parents)
};
