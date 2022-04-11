///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// A generic Node class.  May be used as a base class for a number of data
/// structures.
///
/// @file Node.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>   // For cout

#include "config.h"

/// A generic Node class.
///
/// May be used as a base class for a number of data
/// structures.
///
/// @todo Consider making a destructor that sets node = nullptr;
class Node {
   friend class List;
   friend class SinglyLinkedList;

protected:  ////////////////////// Protected Members ///////////////////////////
   Node* next = nullptr;  ///< Point to the next Node in the list or `nullptr`
                          ///< if it's the last Node in the list.

protected:  //////////////////////// Static Methods ////////////////////////////
   /// Compare two nodes by their address in memory.
   ///
   /// Functions (like sorting) may want to compare two nodes.
   /// This is a good default comparison.  Other functions may choose to
   /// implement their own, more interesting, comparison functions and they can
   /// override the `>` operator.
   ///
   /// This allows us to separate the algorithm from the data.
   /// We can code an algorithm to operate on a virtual Node > operator and
   /// allow the descendants of Node to override `>` and implement their own
   /// ordering.
   static bool compareByAddress ( const Node* node1, const Node* node2 ) ;

public:  /////////////////////////// Public Methods ////////////////////////////
   virtual void dump() const;  ///< Output the contents of this object
   virtual bool validate() const noexcept;  ///< Check the Node

   /// Compare two nodes:  Is the left greater than the right?
   virtual bool operator>(const Node& rightSide);
}; // class Node
