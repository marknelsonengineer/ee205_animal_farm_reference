///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// A generic DoublyLinkedList collection class.
///
/// @file DoublyLinkedList.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   26_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "List.h"


/// A generic DoublyLinkedList collection class.
///
class DoublyLinkedList : public List {
protected:  ////////////////////// Protected Members ///////////////////////////
   Node* tail = nullptr ;     ///< The tail pointer for the List

public:  ///////////////////////// Public Constructors /////////////////////////
   DoublyLinkedList();        ///< Make a new DoublyLinkedList

public:  /////////////////////////// Public Methods ////////////////////////////
   void  push_front( Node* newNode ) override; ///< Insert `newNode` to the beginning of the List
   void  push_back( Node* newNode )  ;         ///< Append `newNode` to the end of the List
   Node* pop_front() noexcept override ;       ///< Remove and return the first NodeWithPrev in the List
   Node* pop_back() noexcept ;                 ///< Remove and return the last NodeWithPrev in the List

   void insert_after( Node* currentNode, Node* newNode ) ;  ///< Insert `newNode` after `currentNode`
   void insert_before( Node* currentNode, Node* newNode ) ; ///< Insert `newNode` before `currentNode`

   void swap( Node* node1, Node* node2 ) ;  ///< Swap `node1` and `node2`

   void insertionSort() noexcept ;  ///< Runs the insertion sort algorithm on the List

   Node* get_last() const noexcept ;                   ///< Get the last NodeWithPrev in the List
   static Node* get_prev( const Node* currentNode ) ;  ///< Get the previous NodeWithPrev in the List

   void dump() const noexcept override ;      ///< Output the member variables in this object
   bool validate() const noexcept override ;  ///< Ensure the object is valid
} ;  // class DoubleLinkedList
