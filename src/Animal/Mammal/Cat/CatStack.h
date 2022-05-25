///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// A Stack that's been specialized to store Cats
///
/// @file CatStack.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   24_May_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Cat.h"
#include "../../../Container/Stack.h"

/// A Stack that's been specialized to store Cats
class CatStack : private Stack {

public:  /////////////////// Inherited Methods from Stack //////////////////////

   inline void  push( Node* newCat ) { Stack::push( newCat ); }        ///< Push a new Cat onto CatStack
   inline Cat* pop() noexcept { return (Cat*) Stack::pop(); }          ///< Pop a Cat off of CatStack
   inline Cat* peek() const noexcept { return (Cat*) Stack::peek(); }  ///< Take a peek at the top of CatStack

   inline bool isEmpty() const noexcept { return Stack::isEmpty(); }   ///< Stack::isEmpty()
   inline Stack::t_size size() const noexcept { return Stack::size(); }  ///< Stack::size()
   bool isIn( const Cat* aCat ) const { return Stack::isIn( aCat ); }  ///< Stack::isIn()

   inline void removeAll() noexcept { Stack::removeAll(); }  ///< Remove all of the Cats from CatStack

   inline void dump() const noexcept { return Stack::dump(); }  ///< Output the member variables in this object
   inline bool validate() const noexcept { return Stack::validate(); }  ///< Ensure the object is valid
};
