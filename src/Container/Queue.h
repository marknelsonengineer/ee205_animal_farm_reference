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
/// @internal This is implemented by inheriting a DoublyLinkedList and
///           then exposing only the methods that are appropriate for a Queue.
class Queue : private DoublyLinkedList {
public:  /////////////////////////// Public Methods ////////////////////////////
   // From Container
   bool         empty() const noexcept override { return DoublyLinkedList::empty(); };  ///< `true` if the Queue is empty
   Container::t_size size()  const noexcept override { return DoublyLinkedList::size(); };   ///< Return the number of Nodes in the Queue

   // From List
   bool isIn( Node* aNode ) const override { return DoublyLinkedList::isIn( aNode ); };  ///< `true` if `aNode` is in the Queue
   void deleteAllNodes() noexcept override { DoublyLinkedList::deleteAllNodes(); };      ///< Delete all of the Nodes in the Queue
   static Node* get_next( const Node* currentNode ) { return DoublyLinkedList::get_next( currentNode ); };  ///< Get the next Node in the Queue

   // From DoublyLinkedList
   void push( Node* newNode ) { DoublyLinkedList::push_front( newNode ); };  ///< Insert `newNode` to the beginning of the Queue
   Node* pop() noexcept { return DoublyLinkedList::pop_back(); };            ///< Remove and return a Node from the Queue
   Node* front() const noexcept { return DoublyLinkedList::get_last(); };    ///< Peek at the next Node in the Queue
   Node* last() const noexcept { return DoublyLinkedList::get_first(); };    ///< Peek at the last Node in the Queue
   static Node* get_prev( const Node* currentNode ) { return DoublyLinkedList::get_prev( currentNode ); };  ///< Get the previous Node in the Queue

   void dump() const noexcept override { DoublyLinkedList::dump(); };  ///< Output the member variables in this object
   bool validate() const noexcept override { return DoublyLinkedList::validate(); };  ///< Ensure the object is valid
};
