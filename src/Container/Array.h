///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// A general-purpose Array based collection class.
///
/// @file Array.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   26_May_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"
#include "Container.h"

/// A generic Array based collection class without a concrete implementation.
///
/// #### Internal
/// There's no easy way to create an array of Animal objects because Animal,
/// Mammal and Bird are abstract classes.  There's no easy way to create a
/// union of Cat, Dog, Chicken and Finch because all have non-trivial
/// constructors.
///
/// There are ways to do it, but it's beyond the scope of this class.  Two
/// ways to do it that are in the scope of the class is:
///
///   - A specialized static Array of Cats (CatPride)
///   - A dynamic Array of Node pointers (DynamicArray)
///
/// The counter for Array (the number of valid elements in the Array) is
/// Container::count.
///
/// The maximum size of the Array is in Array::maxSize.
class Array : public Container {
public:   ///////////////////// Constructors & Destructors /////////////////////
   explicit Array() = delete;   ///< Default constructor (allowed)
   explicit Array( size_t newMaxSize );  ///< Partially construct an Array of up to newMaxSize elements

protected:  ////////////////////// Protected Members ///////////////////////////
   size_t maxSize = 0;   ///< The maximum size of the Array

public:  /////////////////////////// Public Methods ////////////////////////////
   void removeAll() noexcept override;  ///< Remove all of the Nodes from the Container
   void dump() const noexcept override;  ///< Output the member variables in this object
   bool validate() const noexcept override;  ///< Ensure the object is valid

public:  ////////////////////////// Abstract Methods ///////////////////////////
   virtual void add( Node* newNode, size_t index ) = 0;  ///< Replace the Node at index with newNode
   virtual Node* remove( size_t index ) = 0;             ///< Remove a Node from the Container
   void swap( size_t index1, size_t index2 );  ///< Swap `node1` and `node2`

public:  ///////////////////////// Operator Overrides //////////////////////////

   virtual Node& operator[](size_t index) = 0;  ///< An Array requires a [] operator
};
