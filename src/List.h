///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// A generic list-based collection class.
///
/// @todo Implement thing get( index ) // Get via index
/// @todo Implement thing get( key )   // Get via key
/// @todo Implement void put ( index, thing ) // Replace an existing value
/// @todo Implement void put ( thing ) // Replace an existing value
/// @todo Implement thing find( criteria ) // Find a thing (or NULL)
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

   virtual Node* pop_front() noexcept = 0 ;  ///< Remove and return the first Node in the List

   Node* get_first() const noexcept ;  ///< Get the first Node in the List
   static Node* get_next( const Node* currentNode ) ;  ///< Get the next Node in the List

   void deleteAllNodes() noexcept ;  ///< Delete all of the nodes in the List

public:  ////////////////////////// Abstract Methods ///////////////////////////
   virtual void dump() const noexcept = 0;      ///< Output the contents of this container
   virtual bool validate() const noexcept = 0;  ///< Check to see if the container is valid
};
