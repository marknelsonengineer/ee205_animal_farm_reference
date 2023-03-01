///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// Where the Wild Things Are
///
/// @file   Animal.h
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>

#include "../Container/Node.h"
#include "../Utility/Gender.h"
#include "../Utility/Weight.h"
#include "../config.h"


/// A class that encompasses all Animals on the farm.
///
/// This class should be the parent class of all of the Animals on the farm.
/// It contains 1 abstract method `speak()` that each Animal must implement
/// before it can be instantiated.
///
/// Animals understand things I don't know -- and they know languages which are not made of words.”
///
/// @see https://en.wikipedia.org/wiki/Animal
/// @see https://en.wikipedia.org/wiki/Taxonomy_(biology)
class Animal : public Node {
public:   //////////////////////// Constants ///////////////////////////////////
   static const constexpr std::string_view KINGDOM_NAME { "Animalia" } ;  ///< The scientific name of the Animal Kingdom.

private:  ///////////////////// Member Variables //////////////////////////////
   std::string species;                     ///< The Animal's biological species
   std::string classification;              ///< The Animal's biological classification
   Gender gender = Gender::UNKNOWN_GENDER;  ///< The Animal's gender.  Scientifically, not all Animals have a gender, but all Animals on Animal Farm have a gender.
   Weight weight;                           ///< The weight of the Animal

public:   // //////////////////// Constructors ////////////////////////////////

   /// Create an Animal with the *minimum* required fields
   Animal( Weight::t_weight newMaxWeight       ///< Must be a valid weight per Weight::isWeightValid
          ,std::string_view newClassification  ///< Must be a valid name per Name::validateName
          ,std::string_view newSpecies         ///< Must be a valid name per Name::validateName
          );

    /// Create an Animal, populating *all* of the member variables
   Animal( Gender           newGender           ///< The Gender of the Animal
          ,Weight::t_weight newWeight           ///< Must be a valid weight per Weight::isWeightValid
          ,Weight::t_weight newMaxWeight        ///< Must be a valid weight per Weight::isWeightValid
          ,std::string_view newClassification   ///< Must be a valid name per Name::validateName
          ,std::string_view newSpecies          ///< Must be a valid name per Name::validateName
          );

public:   // ////////////////// Getters & Setters /////////////////////////////
   [[nodiscard]] std::string_view getKingdom()        const noexcept;  ///< Get the kingdom, which is `Animalia`
   [[nodiscard]] std::string_view getClassification() const noexcept;  ///< Get the classification
   [[nodiscard]] std::string_view getSpecies()        const noexcept;  ///< Get the species

   [[nodiscard]] Gender           getGender()         const noexcept;  ///< Get the Animal's Gender

   [[nodiscard]] Weight::t_weight getWeight() const noexcept;  ///< Get the Animal's Weight
   void             setWeight( Weight::t_weight newWeight );  ///< Set the Animal's Weight

protected:  ////////////////////// Protected Methods ///////////////////////////
   void setGender( Gender newGender );   ///< Set the Animal's Gender

public:   ////////////////////////// Abstract Methods //////////////////////////
   [[nodiscard]] virtual std::string_view speak() const noexcept = 0;    ///< Ask the Animal to say something.  This method is virtual and abstract.
   [[nodiscard]] virtual std::string_view getName() const noexcept = 0;  ///< Get the Cat's name

public:   /////////////////////////// Public Methods ///////////////////////////
   [[nodiscard]] std::string info() const noexcept;         ///< Return one-line of information about this Animal
   void dump()     const noexcept override;   ///< Output the contents of this object (and its parents).
   [[nodiscard]] bool validate() const noexcept override;   ///< Check to see if the Animal object is valid

public:  ///////////////////////// Operator Overrides //////////////////////////
   bool operator< ( const Animal& rhs_animal ) const;  ///< Compare two Animals with `<`
   bool operator<=( const Animal& rhs_animal ) const;  ///< Compare two Animals with `<=`
   bool operator> ( const Animal& rhs_animal ) const;  ///< Compare two Animals with `>`
   bool operator>=( const Animal& rhs_animal ) const;  ///< Compare two Animals with `>=`

   bool operator< ( const Node& rhs_node ) const override;  ///< Override the virtual `<` comparison between two Nodes
   bool operator<=( const Node& rhs_node ) const override;  ///< Override the virtual `<=` comparison between two Nodes
   bool operator> ( const Node& rhs_node ) const override;  ///< Override the virtual `>` comparison between two Nodes
   bool operator>=( const Node& rhs_node ) const override;  ///< Override the virtual `>=` comparison between two Nodes
};
