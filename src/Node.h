///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// A generic Node class.  May be used as a base class for a number of data
/// structures.
///
/// This class is defined as a header-only class.
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
   /// A generic comparison based on the memory address of the object.
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
   ///
   /// @return true if `node1 > node2`
   static bool compareByAddress ( const Node* node1, const Node* node2 ) {
      if( node1 > node2 )
         return true;
      return false;
   }


public:  /////////////////////////// Public Methods ////////////////////////////
   /// Output the contents of this object
   ///
   /// #### Sample Output
   /// @code
   ///     ==============================================
   ///     Node    this                0x7ffeeaa7e580
   ///     Node    next                0
   /// @endcode
   ///
   virtual void dump() const {
      FORMAT_LINE_FOR_DUMP( "Node", "this" ) << this << std::endl ;
      FORMAT_LINE_FOR_DUMP( "Node", "next" ) << next << std::endl ;
   }


   /// Check the Node.
   ///
   /// This method checks the Node.  If something is not right,
   /// print out a message and stop the validation.  It will not throw an
   /// exception.
   ///
   /// @return True if the Node is healthy
   virtual bool validate() const noexcept {
      if( next == nullptr ) {
         return true;  /// `nullptr` is a valid value for the next pointer.
      }

      /// @internal Perform a rudimentary recursive loop test and ensure
      ///           the next pointer does not refer back to itself.
      ///           This also has the benefit of dereferencing the
      ///           next pointer and ensuring it points to a valid address.
      if( next == next->next ) {
         std::cout << PROGRAM_NAME << ": Recursive loop detected:  next points to itself!" ;
         return false;
      }

      return true;
   }


   /// Compare two nodes:  Is the left greater than the right?
   ///
   /// @param rightSide The `this` member is the left side of the `>` operator.
   ///                  `rightSide` is the right side of the `>` operator.
   /// @return `true` if `leftSide > rightSide`
   virtual bool operator>(const Node& rightSide) {
      // `this` is the leftSide of the operator, so compare:
      // leftSide > rightSide

      return compareByAddress( this, &(Node&)rightSide );
   }

}; // class Node
