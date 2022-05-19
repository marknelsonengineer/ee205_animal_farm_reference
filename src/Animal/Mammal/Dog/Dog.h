///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// Some of my favorite cats are dogs
///
/// @file Dog.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   18_May_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>

#include "../../../config.h"
#include "../Mammal.h"
#include "../../../Utility/Name.h"

/// Canis Familiaris
///
class Dog : public Mammal {
public:   //////////////////////// Constants ///////////////////////////////////
   static const constexpr std::string_view SPECIES_NAME { "Canis Familiaris" };  ///< The scientific name for a Dog
   static const constexpr Weight::t_weight MAX_WEIGHT { 315 };  ///< The maximum weight for a Dog (an English Mastiff)

public:  ////////////////////////// Static Members /////////////////////////////
   static Name names;                ///< A list of potential Dog names

protected:  ///////////////////////// Member Variables /////////////////////////
   std::string name ;                ///< The name of the Dog

public:  //////////////////////////// Constructors /////////////////////////////

   /// Create a Dog
   Dog( const std::string_view newName
       ,const Color            newColor  = Color::UNKNOWN_COLOR
       ,const Gender           newGender = Gender::UNKNOWN_GENDER
       ,const Weight::t_weight newWeight = Weight::UNKNOWN_WEIGHT
   );

   /// Delete a Dog
   virtual ~Dog();

public:  ////////////////////////// Getters & Setters //////////////////////////
   std::string_view getName() const noexcept override;  ///< Get the Dog's name

public:  /////////////////////////// Public Methods ////////////////////////////
   std::string_view speak() const noexcept override;  ///< Say `Woof`.
   void dump() const noexcept override;      ///< Output the contents of this object (and its parents)
   bool validate() const noexcept override;  ///< Check to see if the Dog object is valid

public:  /////////////////////// Static Public Methods /////////////////////////
   // Static methods are `const` by default
   static Dog& generateDog() ;   ///< Generate a new, random Dog

public:  ///////////////////////// Operator Overrides //////////////////////////
   bool operator< ( const Dog& rhs_dog ) const;  ///< Compare two Dogs with `<`

   bool operator< ( const Node& rhs_node ) const override;  ///< Override the virtual `<` comparison between two Nodes
};
