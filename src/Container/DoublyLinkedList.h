///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// A DoublyLinkedList collection class.
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
   // Use the most efficient add/remove methods to override pure methods declared in Container
   // These will be used for performance measurement
   inline void add( Node* newNode ) override { addBack( newNode ); }            ///< Implemented by addBack()
   inline Node* remove( Node* nodeToRemove ) override { return removeBack(); }  ///< Implemented by removeBack()

   void          addFront( Node* newNode ) override;  ///< Insert `newNode` to the beginning of the List
   virtual void  addBack( Node* newNode )  ;          ///< Append `newNode` to the end of the List
   Node*         removeFront() noexcept override ;    ///< Remove and return the first Node in the List
   virtual Node* removeBack() noexcept ;              ///< Remove and return the last Node in the List

   void addAfter( Node* currentNode, Node* newNode ) ;  ///< Insert `newNode` after `currentNode`
   void addBefore( Node* currentNode, Node* newNode ) ; ///< Insert `newNode` before `currentNode`

   void swap( Node* node1, Node* node2 ) ;  ///< Swap `node1` and `node2`

   void insertionSort() noexcept ;  ///< Runs the insertion sort algorithm on the List

   Node* getLast() const noexcept ;                   ///< Get the last Node in the List
   static Node* getPrev( const Node* currentNode ) ;  ///< Get the previous Node in the List

   void dump() const noexcept override ;      ///< Output the member variables in this object
   bool validate() const noexcept override ;  ///< Ensure the object is valid
} ;  // class DoubleLinkedList
