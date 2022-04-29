///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// A generic list-based collection class.
///
/// @todo Implement get( index ) // Get via index
/// @todo Implement get( key )   // Get via key
/// @todo Implement find( criteria ) // Find a thing (or NULL)
/// @todo Implement Cat* findCatByName( const char* name ) ;
/// @todo Implement iterator getIterator() // Loop over a bunch of things
/// @todo Implement void delete ( index )  // Delete an index…
/// @todo Implement void delete ( key )    // by key
/// @todo Implement void delete ( thing )  // Delete the thing
///
/// @file List.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   29_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"
#include "Container.h"

/// A generic list-based collection class.  This is a type of container that
/// has a `head` Node and `get_first()` and `get_next()` methods -- which
/// can be used to traverse a list.
///
class List : public Container {
protected:  ////////////////////// Protected Members ///////////////////////////
   Node* head = nullptr ;     ///< The head pointer for the collection

public:  /////////////////////////// Static Methods ////////////////////////////
   static Node* get_next( const Node* currentNode ) ;  ///< Get the next Node in the List

public:  /////////////////////////// Public Methods ////////////////////////////
   bool isIn( Node* aNode ) const override ;  ///< `true` if `aNode` is in the List
   bool isSorted() const noexcept ;          ///< `true` if the List is sorted

   Node* get_first() const noexcept ;    ///< Get the first Node in the List

   void deleteAllNodes() noexcept ;      ///< Delete all of the nodes in the List

   void dump() const noexcept override;      ///< Output the member variables in this object
   bool validate() const noexcept override;  ///< Ensure the object is valid

public:  ////////////////////////// Abstract Methods ///////////////////////////
   virtual void push_front( Node* newNode ) = 0 ;  ///< Insert `newNode` at the beginning of the List
   virtual Node* pop_front() noexcept = 0 ;     ///< Remove and return the first Node in the List
};
