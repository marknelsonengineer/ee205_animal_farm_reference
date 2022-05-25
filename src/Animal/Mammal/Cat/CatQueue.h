///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// A Queue that's been specialized to store Cats
///
/// @file CatQueue.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   24_May_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Cat.h"
#include "../../../Container/Queue.h"

/// A Queue that's been specialized to store Cats
class CatQueue : private Queue {
public:  /////////////////// Inherited Methods from Queue //////////////////////
   bool isEmpty() const noexcept override { return Queue::isEmpty(); }      ///< Queue::isEmpty()
   Queue::t_size size()  const noexcept override { return Queue::size(); }  ///< Queue::size()

   // From List
   bool isIn( const Node* aNode ) const override { return Queue::isIn( aNode ); }  ///< Queue::isIn( aNode )
   void removeAll() noexcept override { Queue::removeAll(); }  ///< Queue::removeAll()
   static Node* getNext( const Node* currentNode ) { return Queue::getNext( currentNode ); }  ///< Queue::getNext()

   // From DoublyLinkedList
   void  enqueue( Cat* newCat ) { Queue::enqueue( newCat ); }   ///< Insert `newCat` to the beginning of the Queue
   Cat* dequeue() noexcept { return (Cat*) Queue::dequeue(); }  ///< Remove and return a Cat from the Queue
   Cat* peek() const noexcept { return (Cat*) Queue::peek(); }  ///< Peek at the next Cat in the Queue
   Cat* last() const noexcept { return (Cat*) Queue::last(); }  ///< Peek at the last Cat in the Queue

   void dump() const noexcept override { Queue::dump(); }  ///< Output the member variables in this object
   bool validate() const noexcept override { return Queue::validate(); }  ///< Ensure the object is valid
};
