///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// A general-purpose Array based collection class.
///
/// @file   Array.h
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Container.h"
#include "Node.h"

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
   explicit Array( Container::t_size newMaxSize );  ///< Partially construct an Array of up to `newMaxSize` Nodes

protected:  ////////////////////// Protected Members ///////////////////////////
   Container::t_size maxSize = 0;   ///< The maximum size of the Array.  This is set in the constructor and never changes.

public:  /////////////////////////// Public Methods ////////////////////////////
   Container::t_size getMaxSize() const noexcept;  ///< Return the maximum size of the Array
   bool isFull() const noexcept;  ///< Return `true` if the Array is full

public:  ///////////////// Inherited Methods from Container ////////////////////
   void removeAll() noexcept override;       ///< Remove all of the Nodes from the Container
   void dump() const noexcept override;      ///< Output the member variables in this object
   bool validate() const noexcept override;  ///< Ensure the object is valid

public:  ////////////////////////// Abstract Methods ///////////////////////////
   virtual void add( Node* newNode, Container::t_size index ) = 0;  ///< Replace the Node at `index` with `newNode`
   virtual Node* remove( Container::t_size index ) = 0;             ///< Remove a Node from the Container
   virtual void swap( Container::t_size index1, const Container::t_size index2 ) = 0;  ///< Swap `node1` and `node2`

public:  ///////////////////////// Operator Overrides //////////////////////////
   virtual Node& operator[](Container::t_size index) = 0;  ///< An Array requires a [] operator
};
