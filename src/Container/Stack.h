///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// A generic Stack collection class.
///
/// @file   Stack.h
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "SinglyLinkedList.h"

/// A generic Stack collection class.
class Stack : private SinglyLinkedList {
public:  //////////////// Enumerations & Type Definitions //////////////////////

   /// The native datatype of the Container's count/size
   typedef unsigned int t_size;

public:  /////////////////////////// Public Methods ////////////////////////////
   inline void  push( Node* newNode ) { SinglyLinkedList::addFront( newNode ); }  ///< Push a new Node onto the Stack
   inline Node* pop() noexcept { return SinglyLinkedList::removeFront(); }        ///< Pop a Node off of the Stack
   inline Node* peek() const noexcept { return SinglyLinkedList::getFirst(); }    ///< Take a peek at the top of the Stack

   inline bool isEmpty() const noexcept { return SinglyLinkedList::isEmpty(); }   ///< SinglyLinkedList::isEmpty()
   inline Container::t_size size() const noexcept { return SinglyLinkedList::size(); }  ///< SinglyLinkedList::size()
   bool isIn( const Node* aNode ) const { return SinglyLinkedList::isIn( aNode ); }  ///< SinglyLinkedList::isIn( aNode )

   inline void  removeAll() noexcept { SinglyLinkedList::removeAll(); }  ///< Remove all of the Nodes from the Stack

   inline void dump() const noexcept { return SinglyLinkedList::dump(); }  ///< Output the member variables in this object
   inline bool validate() const noexcept { return SinglyLinkedList::validate(); }  ///< Ensure the object is valid
};
