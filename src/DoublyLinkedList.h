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


class DoublyLinkedList {
protected:
   Node* head = nullptr;
   Node* tail = nullptr;
   unsigned int count = 0;

public:
   bool empty() const ;  ///< Is the list empty?
   inline unsigned int size() const { return count; };  ///< The size of the list

   void  push_front( Node* newNode );
   void  push_back( Node* newNode );
   Node* pop_front() ;
   Node* pop_back() ;

   void insert_after( Node* currentNode, Node* newNode );
   void insert_before( Node* currentNode, Node* newNode );

   bool isIn( Node* aNode ) const; // True if aNode is in the list

   void swap(Node* node1, Node* node2);

   bool isSorted() const;
   void insertionSort();         // This function depends on Node's < operator

   Node* get_first() const;
   Node* get_last() const;
   Node* get_next( const Node* currentNode ) const ;
   Node* get_prev( const Node* currentNode ) const ;

   void dump() const;
   bool validate() const;

} ;

// class DoubleLinkedList
