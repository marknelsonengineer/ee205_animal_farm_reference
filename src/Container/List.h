///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// A general-purpose List based collection class.
///
/// @file List.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   29_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"
#include "Container.h"

/// A generic List based collection class.  This is a type of container that
/// has a `head` Node and `getFirst()` and `getNext()` methods -- which
/// can be used to traverse a list.
///
class List : public Container {
protected:  ////////////////////// Protected Members ///////////////////////////
   Node* head = nullptr ;  ///< The head pointer for the collection

public:  /////////////////////////// Static Methods ////////////////////////////
   static Node* getNext( const Node* currentNode ) ;  ///< Get the next Node in the List

public:  /////////////////////////// Public Methods ////////////////////////////
   bool isIn( const Node* aNode ) const override ;  ///< `true` if `aNode` is in the List
   virtual bool isSorted() const noexcept ;   ///< `true` if the List is sorted

   virtual Node* getFirst() const noexcept ;  ///< Get the first Node in the List

   void  removeAll() noexcept override;        ///< Remove all of the Nodes in the List
   Node* getRandomNode() const noexcept override;  ///< Get a random Node from the List

   void dump() const noexcept override;       ///< Output the member variables in this object
   bool validate() const noexcept override;   ///< Ensure the object is valid

public:  ////////////////////////// Abstract Methods ///////////////////////////
   virtual void addFront( Node* newNode ) = 0 ;  ///< Insert `newNode` at the beginning of the List
   virtual Node* removeFront() noexcept = 0 ;    ///< Remove and return the first Node in the List
};
