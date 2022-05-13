///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// All things Cat
///
/// @file Cat.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   17_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>

#include "../config.h"
#include "Mammal.h"
#include "../Utility/Name.h"

/// Felis Catus
///
class Cat : public Mammal {
public:   //////////////////////// Constants ///////////////////////////////////
   static const std::string      SPECIES_NAME;  ///< The scientific name for Cats
   static const Weight::t_weight MAX_WEIGHT;    ///< The maximum weight for Cats

public:  ////////////////////////// Static Members /////////////////////////////
   static Name names;                ///< A list of potential Cat names

protected:  ///////////////////////// Member Variables /////////////////////////
   std::string name ;                ///< The name of the Cat
   bool        isCatFixed = false ;  ///< `true` if the Cat is fixed/neutered

public:  //////////////////////////// Constructors /////////////////////////////

   /// Create a Cat with the minimum fields necessary to have a valid Cat
   explicit Cat( const std::string& newName ) ;

   /// Create a Cat, populating *all* of the member variables
   Cat( const std::string&     newName
       ,const Color            newColor
       ,const bool             newIsFixed
       ,const Gender           newGender
       ,const Weight::t_weight newWeight
   );


   /// Delete a Cat object
   virtual ~Cat();

public:  ////////////////////////// Getters & Setters //////////////////////////
   std::string getName() const noexcept ;        ///< Get the Cat's name
   void setName( const std::string& newName );   ///< Set the Cat's name.

   bool isFixed() const noexcept ;      ///< Return `true` if the Cat is fixed/neutered
   void fixCat() noexcept ;             ///< Spay or neuter the Cat

public:  /////////////////////////// Public Methods ////////////////////////////
   std::string speak() const noexcept override;  ///< Say `Meow`.
   void dump() const noexcept override;          ///< Output the contents of this object (and its parents)
   bool validate() const noexcept override;      ///< Check to see if the Cat object is valid

public:  /////////////////////// Static Public Methods /////////////////////////
   // Static methods are `const` by default
   static Cat& generateCat() ;   ///< Generate a new, random Cat

public:  ///////////////////////// Operator Overrides //////////////////////////
   bool operator< ( const Cat& rhs_cat ) const;  ///< Compare two Cats with `<`
   bool operator<=( const Cat& rhs_cat ) const;  ///< Compare two Cats with `<=`
   bool operator> ( const Cat& rhs_cat ) const;  ///< Compare two Cats with `>`
   bool operator>=( const Cat& rhs_cat ) const;  ///< Compare two Cats with `>=`

   bool operator< ( const Node& rhs_node ) const override;  ///< Override the virtual `<` comparison between two Nodes
   bool operator> ( const Node& rhs_node ) const override;  ///< Override the virtual `>` comparison between two Nodes
   bool operator<=( const Node& rhs_node ) const override;  ///< Override the virtual `<=` comparison between two Nodes
   bool operator>=( const Node& rhs_node ) const override;  ///< Override the virtual `>=` comparison between two Nodes
};
