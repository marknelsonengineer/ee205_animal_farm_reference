///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
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

#include "Node.h"
#include "List.h"

/// A generic SinglyLinkedList collection class.
///
class SinglyLinkedList : public List {
public:  ///////////////////////// Public Constructors /////////////////////////
   SinglyLinkedList();        ///< Make a new SinglyLinkedList

public:  /////////////////////////// Public Methods ////////////////////////////
   void  push_front( Node* newNode ) override ;  ///< Insert `newNode` to the beginning of the List
   Node* pop_front() noexcept override; ///< Remove and return the first Node in the List

   void insert_after( Node* currentNode, Node* newNode ) ;  ///< Insert `newNode` after `currentNode`

   void dump() const noexcept override;      ///< Output the member variables in this object
}; // class SinglyLinkedList
