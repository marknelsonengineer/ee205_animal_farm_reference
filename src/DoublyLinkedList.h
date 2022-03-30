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

#include "Node.h"
#include "List.h"

/*
bool isEmpty()       // true if Collection is empty
void add( thing )    // Insert into the beginning
void append( thing ) // Add to the end
void addAt( index, thing )  // Add at a location
int size()   // Number of items in the collection
thing get( index ) // Get via index
thing get( key )   // Get via key
void put ( index, thing ) // Replace an existing value
void put ( thing ) // Replace an existing value
thing find( criteria ) // Find a thing (or NULL)
iterator getIterator() // Loop over a bunch of things
void delete ( index )  // Delete an index…
void delete ( key )    // by key
void delete ( thing )  // Delete the thing
 */



/// A generic DoublyLinkedList collection class.
///
class DoublyLinkedList : List {
protected:  ////////////////////// Protected Members ///////////////////////////
   Node* tail = nullptr ;     ///< The tail pointer for the List

public:  ///////////////////////// Public Constructors /////////////////////////
   DoublyLinkedList();        ///< Make a new DoublyLinkedList

public:  /////////////////////////// Public Methods ////////////////////////////
   void  push_front( Node* newNode ) ; ///< Insert `newNode` to the beginning of the List
   void  push_back( Node* newNode )  ; ///< Append `newNode` to the end of the List
   Node* pop_front() noexcept ;                 ///< Remove and return the first Node in the List
   Node* pop_back() noexcept ;                  ///< Remove and return the last Node in the List

   void insert_after( Node* currentNode, Node* newNode ) ;  ///< Insert `newNode` after `currentNode`
   void insert_before( Node* currentNode, Node* newNode ) ; ///< Insert `newNode` before `currentNode`

   void swap( Node* node1, Node* node2 ) ;  ///< Swap `node1` and `node2`

   void insertionSort() noexcept ;  ///< Runs the insertion sort algorithm on the List

   Node* get_last() const noexcept ;                   ///< Get the last Node in the List
   static Node* get_prev( const Node* currentNode ) ;  ///< Get the previous Node in the List

   void dump() const noexcept override ;      ///< Output the contents of this container
   bool validate() const noexcept override ;  ///< Check to see if the container is valid
} ;  // class DoubleLinkedList
