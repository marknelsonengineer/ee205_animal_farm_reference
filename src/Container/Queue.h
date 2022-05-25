///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// Implement a general-purpose FIFO Queue from a DoublyLinkedList.
///
/// This is a header-only class.
///
/// @file Queue.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   05_May_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "DoublyLinkedList.h"

/// A First In First Out (FIFO) data structure.
///
/// This is a header-only class.
///
/// #### Internal
/// This is implemented by inheriting a DoublyLinkedList and then exposing only
/// the methods that are appropriate for a Queue.
class Queue : private DoublyLinkedList {
public:  //////////////// Enumerations & Type Definitions //////////////////////

   /// The native datatype of the Container's count/size
   typedef unsigned int t_size;

public:  /////////////////////////// Public Methods ////////////////////////////
   // From Container
   bool              isEmpty() const noexcept override { return DoublyLinkedList::isEmpty(); }  ///< DoublyLinkedList::isEmpty()
   Container::t_size size()  const noexcept override { return DoublyLinkedList::size(); }       ///< DoublyLinkedList::size()

   // From List
   bool isIn( const Node* aNode ) const override { return DoublyLinkedList::isIn( aNode ); }  ///< DoublyLinkedList::isIn( aNode )
   void removeAll() noexcept override { DoublyLinkedList::removeAll(); }  ///< DoublyLinkedList::removeAll()
   static Node* getNext( const Node* currentNode ) { return DoublyLinkedList::getNext( currentNode ); }  ///< DoublyLinkedList::getNext()

   // From DoublyLinkedList
   void  enqueue( Node* newNode ) { DoublyLinkedList::addFront( newNode ); } ///< Insert `newNode` to the beginning of the Queue
   Node* dequeue() noexcept { return DoublyLinkedList::removeBack(); }       ///< Remove and return a Node from the Queue
   Node* peek() const noexcept { return DoublyLinkedList::getLast(); }       ///< Peek at the next Node in the Queue
   Node* last() const noexcept { return DoublyLinkedList::getFirst(); }      ///< Peek at the last Node in the Queue

   void dump() const noexcept override { DoublyLinkedList::dump(); }  ///< Output the member variables in this object
   bool validate() const noexcept override { return DoublyLinkedList::validate(); }  ///< Ensure the object is valid
};
