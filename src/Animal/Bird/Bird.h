///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// Birds are feathered theropods and constitute the only known living dinosaurs.
///
/// @file Bird.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   18_May_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <random>

#include "../../config.h"
#include "../Animal.h"
#include "../../Utility/Name.h"


/// Feathered theropods that constitute the only known living dinosaurs
///
/// Comparing two Birds is done at the Animal level using Classification.
class Bird : public Animal {
public:  ////////////////////////// Type Definitions ///////////////////////////

   /// How should we instantiate this Bird?
   enum ConstructorType {
      RANDOM       ///< The properties of the Bird are set to random values
   };

public:   //////////////////////// Constants ///////////////////////////////////
   static const constexpr std::string_view CLASSIFICATION_NAME { "Aves" };  ///< The scientific name for Birds

public:   /////////////////////// Constructors ////////////////////////////////

   /// Create a Bird, populating *all* of the member variables
   explicit
   Bird( const std::string_view newSpecies
        ,const Weight::t_weight newMaxWeight
        ,const std::string_view newName
        ,const Gender           newGender    = Gender::UNKNOWN_GENDER
        ,const Weight::t_weight newWeight    = Weight::UNKNOWN_WEIGHT
   );

   /// Delete a Bird
   ~Bird() override;

protected:  ///////////////////////// Member Variables /////////////////////////
   std::string name ;  ///< The name of the Bird

public:  ////////////////////////// Getters & Setters //////////////////////////
   std::string_view getName() const noexcept override;  ///< Get the Bird's name

public:  /////////////////////////// Public Methods ////////////////////////////
   std::string_view speak() const noexcept override;  ///< Say `Tweet`.
   void dump() const noexcept override;      ///< Output the contents of this object (and its parents)
   bool validate() const noexcept override;  ///< Check to see if the Bird object is valid

public:  ///////////////////////// Operator Overrides //////////////////////////
   bool operator< ( const Bird& rhs_bird ) const;  ///< Compare two Birds with `<`

   bool operator< ( const Node& rhs_node ) const override;  ///< Override the virtual `<` comparison between two Nodes
};
