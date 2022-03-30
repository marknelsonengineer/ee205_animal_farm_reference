///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// A generic list-based collection class.
///
/// @file List.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   29_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"
#include "List.h"

/// A generic list-based collection class.
///
class List {
protected:  ////////////////////// Protected Members ///////////////////////////
   Node* head = nullptr ;     ///< The head pointer for the collection
   unsigned int count = 0 ;   ///< Maintain a count of the number of Node objects in the collection

public:  /////////////////////////// Public Methods ////////////////////////////
   bool empty() const noexcept ;         ///< `true` if the List is empty
   unsigned int size() const noexcept ;  ///< Get the number of Node objects in the List

   bool isIn( Node* aNode ) const ; ///< `true` if `aNode` is in the List
   bool isSorted() const noexcept ; ///< `true` if the List is sorted

   Node* get_first() const noexcept ;  ///< Get the first Node in the List
   static Node* get_next( const Node* currentNode ) ;  ///< Get the next Node in the List

public:  ////////////////////////// Abstract Methods ///////////////////////////
   virtual void dump() const noexcept = 0;      ///< Output the contents of this container
   virtual bool validate() const noexcept = 0;  ///< Check to see if the container is valid
};


