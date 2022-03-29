///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// A generic SinglyLinkedList collection class.
///
/// @file SinglyLinkedList.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"

/// A generic SinglyLinkedList collection class.
///
class SinglyLinkedList {
protected:  ////////////////////// Protected Members ///////////////////////////
   Node* head = nullptr ;     ///< The head pointer for the list
   unsigned int count = 0 ;   ///< Maintain a count of the number of Nodes in the list

public:  ///////////////////////// Public Constructors /////////////////////////
   SinglyLinkedList();        ///< Make a new SinglyLinkedList

public:  /////////////////////////// Public Methods ////////////////////////////
   bool empty() const noexcept ;         ///< `true` if the list is empty
   unsigned int size() const noexcept ;  ///< Return the number of Nodes in the list

   void  push_front( Node* newNode ) ;  ///< Insert `newNode` to the beginning of the list
   Node* pop_front() noexcept ;         ///< Remove and return the first Node in the list

   void insert_after( Node* currentNode, Node* newNode ) ;  ///< Insert `newNode` after `currentNode`

   bool isIn( Node* aNode ) const ; ///< `true` if `aNode` is in the list
   bool isSorted() const noexcept ; ///< `true` if the list is sorted

   Node* get_first() const noexcept ;  ///< Get the first Node in the list
   static Node* get_next( const Node* currentNode ) ;  ///< Get the next Node in the list

   void dump() const noexcept ;      ///< Output the contents of this container
   bool validate() const noexcept ;  ///< Check to see if the container is valid

}; // class SingleLinkedList



