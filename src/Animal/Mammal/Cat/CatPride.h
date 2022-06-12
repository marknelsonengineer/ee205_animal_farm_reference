///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// A specialized static Array that holds Cats
///
/// @file CatPride.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_May_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Cat.h"
#include "../../../Container/Array.h"
#include "CatContainer.h"

/// A specialized static Array that holds Cats
class CatPride : public Array, CatContainer {
public:  ///////////////////////// Constants ///////////////////////////////////
   static const constexpr Container::t_size MAX_CATS { 4 };  ///< The maximum number of Cats in a pride

public:  //////////////////////////// Constructors /////////////////////////////
   explicit CatPride();  ///< Create a new CatPride[#MAX_CATS] Array

protected:  ///////////////////////// Member Variables /////////////////////////
   Cat catArray[MAX_CATS];  ///< Holds the Cat database

public:  ////////// Inherited Methods from Container and CatContainer //////////
   void add( Node* newNode ) override { add( (Cat*) newNode ); };  ///< Add a Node (always a Cat) to the Container
   void add( Cat* newCat ) override;  ///< Add `newCat` to the end of the Array
   inline void add( Node* newNode, const Container::t_size index ) override { add( (Cat*) newNode, index ); };  ///< Replace the Node (always a Cat) at `index` with `newNode`
   void add( Cat* newCat, const Container::t_size index );  ///< Replace the Cat at `index` with `newCat`

   inline bool isIn( const Node* aNode ) const override { return isIn( (Cat*) aNode ); };  ///< `true` if `aNode` (always a Cat) is in CatPride
   bool isIn( const Cat* aCat ) const override;  ///< `true` if `aCat` is in CatPride

   Cat* getRandomNode() const noexcept override;  ///< Get a random Cat from the Container

   Cat* remove( Cat* catToRemove );  ///< Remove `catToRemove` from the Array
   inline Node* remove( Node* nodeToRemove ) override { return remove( (Cat*) nodeToRemove ); };  ///< Remove a Node (always a Cat) from the Container
   Cat* remove( const Container::t_size index ) override;  ///< Remove Cat at `index` from the Array

   void swap( const Container::t_size index1, const Container::t_size index2 ) override;  ///< Swap two Cats in the Array

   void dump() const noexcept override;  ///< Output the member variables in this object
   bool validate() const noexcept override;  ///< Ensure the object is valid

public:  ///////////////////////// Operator Overrides //////////////////////////
   Cat& operator[]( Container::t_size index ) override;  ///< Get a Cat from the Array
};
