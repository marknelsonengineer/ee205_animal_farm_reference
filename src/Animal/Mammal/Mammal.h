///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// Mammals have more fun
///
/// @file Mammal.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   09_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../Animal.h"
#include "../../Utility/Color.h"


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
   Mammal( const Weight::t_weight newMaxWeight
          ,const std::string_view newSpecies
   );

   /// Create a Mammal, populating *all* of the member variables
   Mammal( const Color            newColor
          ,const Gender           newGender
          ,const Weight::t_weight newWeight
          ,const Weight::t_weight newMaxWeight
          ,const std::string_view newSpecies
   );

public:  ////////////////////////// Getters & Setters //////////////////////////
   Color getColor() const noexcept { return color; }  ///< Get the color
   void  setColor( const Color newColor ) noexcept { color = newColor; }  ///< Set the color

public:  /////////////////////////// Public Methods ////////////////////////////
   void dump() const noexcept override;  ///< Output the contents of this object (and its parents)
};
