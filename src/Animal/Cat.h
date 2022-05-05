///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_2 - EE 205 - Spr 2022
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


/// Felis Catus
///
class Cat : public Mammal {
public:   //////////////////////// Constants ///////////////////////////////////
   static const std::string      SPECIES_NAME;  ///< The scientific name for this species
   static const Weight::t_weight MAX_WEIGHT;    ///< The maximum weight for this species

protected:  ///////////////////////// Member Variables /////////////////////////
   std::string name ;        ///< The name of the cat
   bool        isCatFixed ;  ///< `true` if the cat is fixed/neutered

public:  //////////////////////////// Constructors /////////////////////////////
   /// Create a Cat with the minimum fields necessary to have a valid Cat
   /// @todo Why can't this be defined in the .cpp file??
   explicit Cat( const std::string& newName ) : Mammal( MAX_WEIGHT, SPECIES_NAME ) {
      if( !validateName( newName) ) {
         /// @throws out_of_range If the Cat doesn't have a name
         throw std::out_of_range( "Cats must have a name" );
      }
      name = newName;
      isCatFixed = false;

      Cat::validate();
   }

   /// Create a Cat, populating *all* of the member variables
   Cat( const std::string&     newName
       ,const Color            newColor
       ,const bool             newIsFixed
       ,const Gender           newGender
       ,const Weight::t_weight newWeight
   ) : Mammal( newColor, newGender, newWeight, MAX_WEIGHT, SPECIES_NAME ) {
      if( !validateName( newName) ) {
         /// @throws out_of_range If the Cat doesn't have a name
         throw std::out_of_range( "Cats must have a name" );
      }
      name = newName;
      isCatFixed = newIsFixed;

      Cat::validate();
   }


   /// Delete a Cat object
   virtual ~Cat();

public:  ////////////////////////// Getters & Setters //////////////////////////
   std::string getName() const noexcept ;  ///< Get the Cat's name
   void setName( const std::string& newName );   ///< Set the Cat's name.  The name
                                                 ///< must not be empty.

   bool isFixed() const noexcept ;      ///< Return `true` if the cat is fixed/neutered
   void fixCat() noexcept ;             ///< Spay or neuter the cat

public:  /////////////////////////// Public Methods ////////////////////////////
   std::string speak() const noexcept override;  ///< Say `Meow`.
   void dump() const noexcept override;          ///< Print the contents of this object (and its parents)
   bool validate() const noexcept override;      ///< Check to see if the Cat object is valid

public:  /////////////////////// Static Public Methods /////////////////////////
   // Static methods are `const` by default
   static bool validateName( const std::string& newName ) ;  ///< Check if `newName` is valid
   static Cat& generateCat() ;   ///< Generate a new, random Cat
   static void resetCatNames();  ///< Erase and then re-load the Cat names database
   static unsigned int remaningCatNames() noexcept;  ///< Return the number of unique cat names left

public:  ///////////////////////// Operator Overrides //////////////////////////
   bool operator< ( const Cat& rhs_cat ) const;  ///< Compare two Cats with the < operator
   bool operator> ( const Cat& rhs_cat ) const;  ///< Compare two Cats with the > operator
   bool operator<=( const Cat& rhs_cat ) const;  ///< Compare two Cats with the <= operator
   bool operator>=( const Cat& rhs_cat ) const;  ///< Compare two Cats with the >= operator

   bool operator< ( const Node& rhs_node ) const override;  ///< Override the virtual `<` comparison operator between two Nodes
   bool operator> ( const Node& rhs_node ) const override;  ///< Override the virtual `>` comparison operator between two Nodes
   bool operator<=( const Node& rhs_node ) const override;  ///< Override the virtual `<=` comparison operator between two Nodes
   bool operator>=( const Node& rhs_node ) const override;  ///< Override the virtual `>=` comparison operator between two Nodes
};
