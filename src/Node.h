///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// A generic Node class.  May be used as a base class for a number of data
/// structures.  Not all of the fields need to be used.
///
/// @file Node.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>   // For cout
#include <iomanip>    // For setw() & setfill()

/// Format a line for dumping the members of a class to the console
#define FORMAT_LINE( className, member ) std::cout \
                                      << std::setw(8) << (className) \
                                      << std::setw(20) << (member)   \
                                      << std::setw(52)  /* (data) */


/// A generic Node class.
///
/// May be used as a base class for a number of data
/// structures.  Not all of the fields/methods need to be used.
class Node {
   friend class SinglyLinkedList;
   friend class DoublyLinkedList;


protected:  ////////////////////// Protected Members ///////////////////////////
   Node* next = nullptr;  ///< Point to the next node in the list or `nullptr`
                          ///< if it's the last Node in the list.
   Node* prev = nullptr;  ///< Point to the previous node in the list or
                          ///< `nullptr` if it's the first Node in the list.
                          ///< This may not always be used

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
   bool compareByAddress ( const Node* node1, const Node* node2 ) ;

public:  /////////////////////////// Public Methods ////////////////////////////
   bool dump() const;  ///< Output the contents of this object

   /// Compare two nodes.
   virtual bool operator>(const Node& rightSide);
}; // class Node
