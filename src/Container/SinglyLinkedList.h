///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// A SinglyLinkedList collection class.
///
/// @file SinglyLinkedList.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "List.h"
#include "Node.h"

/// A generic SinglyLinkedList collection class.
///
class SinglyLinkedList : public List {
public:  ///////////////////////// Public Constructors /////////////////////////
   SinglyLinkedList();        ///< Make a new SinglyLinkedList

public:  /////////////////////////// Public Methods ////////////////////////////
   // Use the most efficient add/remove methods to override pure methods declared in Container
   // These will be used for performance measurement
   inline void add( Node* newNode ) override { addFront( newNode ); }  ///< Implemented by addFront()
   Node* remove( Node* nodeToRemove ) override;  ///< Remove `nodeToRemove` from the List

   void  addFront( Node* newNode ) override ;  ///< Insert `newNode` to the beginning of the List
   Node* removeFront() noexcept override;      ///< Remove and return the first Node in the List

   void addAfter( Node* currentNode, Node* newNode ) ;  ///< Add `newNode` after `currentNode`

   void dump() const noexcept override;  ///< Output the member variables in this object
}; // class SinglyLinkedList
