///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
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

#include "../config.h"

namespace test_Container { struct test_Node; } // Forward declaration for friending & testing

/// A generic Node class.
///
/// May be used as a base class for a number of data structures (see Friends).
///
/// According to the Rule of Three, this class has a:
///   - Copy constructor
///   - Assignment overload
///   - Destructor
///
/// ...all three of which will reset the pointers in the Node.  This ensures
/// that other classes can't copy a Node and then later take over a data
/// structure.
///
/// This class is defined as a header-only class.
///
/// @see https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)
class Node {
   friend class List;
   friend class SinglyLinkedList;
   friend class DoublyLinkedList;
   friend class Tree;
   friend class CatEmpire;
   friend struct test_Container::test_Node;  // This is a test case

public:   ///////////////////// Constructors & Destructors /////////////////////
   Node() = default;   ///< Default constructor
   constexpr Node(const Node&) : next(nullptr), prev(nullptr),left( nullptr), right(nullptr) {}   ///< Copy constructor zeros out pointers
   constexpr Node& operator=( const Node& copyFrom ) {  /// Assignment constructor zeros out pointers
      if( this != &copyFrom ) { // Protects from self-assignment
         next = nullptr;
         prev = nullptr;
         left = nullptr;
         right = nullptr;
      }

      return *this;
   }

   /// Zero out the Node before destroying it
   virtual ~Node() { Node::reset(); };


protected:  ////////////////////// Protected Members ///////////////////////////
   Node* next = nullptr;  ///< Point to the next Node in the list or `nullptr`
                          ///< if it's the last Node in the list.
                          ///<
                          ///< If it's used in a Tree... it can be used to iterate
                          ///< through the tree.

   Node* prev = nullptr;  ///< Point to the previous Node in the list or
                          ///< `nullptr` if it's the first Node in the list.
                          ///<
                          ///< If it's used in a Tree... it can be used to iterate
                          ///< through the tree.

   Node* left = nullptr;  ///< Point to the left Node in the tree or `nullptr`

   Node* right = nullptr; ///< Point to the right Node in the tree or `nullptr`

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
   /// allow the descendants of Node to override `>` to implement their own
   /// ordering.
   ///
   /// @return true if `node1 > node2`
   static bool compareByAddress ( const Node* node1, const Node* node2 ) {
      if( node1 > node2 )
         return true;
      return false;
   }


public:  /////////////////////////// Public Methods ////////////////////////////

   /// Reset the Node... as if it's never been in a Container or it's just
   /// been removed from a Container.
   virtual void reset() noexcept {
      next = nullptr;
      prev = nullptr;
      left = nullptr;
      right = nullptr;
   }

   /// Output the contents of this object
   ///
   /// #### Sample Output
   /**@verbatim
   ======================================================
   Node                this                0x7ffd0befed60
   Node                next                0x7ffd0befee10
   Node                prev                0x7ffd0befef70
   Node                left                0
   Node                right               0
   @endverbatim */
   virtual void dump() const {
      FORMAT_LINE_FOR_DUMP( "Node", "this" )  << this  << std::endl ;
      FORMAT_LINE_FOR_DUMP( "Node", "next" )  << next  << std::endl ;
      FORMAT_LINE_FOR_DUMP( "Node", "prev" )  << prev  << std::endl ;
      FORMAT_LINE_FOR_DUMP( "Node", "left" )  << left  << std::endl ;
      FORMAT_LINE_FOR_DUMP( "Node", "right" ) << right << std::endl ;
   }


   /// Check the Node.
   ///
   /// This method checks the Node.  If something is not right,
   /// print out a message and stop the validation.  It will not throw an
   /// exception.
   ///
   /// @return True if the Node is healthy
   virtual bool validate() const noexcept {
      /// @internal Iterate along the next (and prev) pointers and verify that
      ///           they do not refer back to themselves.  This also has the
      ///           benefit of dereferencing all of the downstream next/prev
      ///           pointers and ensuring they point to valid addresses.
      if( next != nullptr ) {
         Node* currentPointer = next->next;
         while( currentPointer != nullptr ) {
            if( next == currentPointer ) {
               std::cout << PROGRAM_NAME << ": Recursive loop detected along next!";
               return false;
            }
            currentPointer = currentPointer->next;
         }
      }

      if( prev != nullptr ) {
         Node* currentPointer = prev->prev;
         while( currentPointer != nullptr ) {
            if( prev == currentPointer ) {
               std::cout << PROGRAM_NAME << ": Recursive loop detected along prev!";
               return false;
            }
            currentPointer = currentPointer->prev;
         }
      }

      if( left != nullptr ) {
         /// @todo Recursively check the left & right sides
      }

      return true;
   }


public:  ///////////////////////// Operator Overrides //////////////////////////

   /// Compare two Nodes with `<`
   ///
   /// The `this` member is the left side of the operator.
   /// @param rhs_node `rhs` stands for Right Hand Side and is the right side of the operator.
   /// @return `true` if this < `rhs_node`
   virtual bool operator<( const Node& rhs_node ) const {
      /// By default, we will compare two Nodes by the only thing we can...
      /// their addresses.
      return compareByAddress( this, &rhs_node );
   }


   /// Compare two Nodes with `<=`
   ///
   /// The actual implementation is in Node::operator<
   virtual bool operator<=( const Node& rhs_node ) const {
      return !( rhs_node < *this );
   }


   /// Compare two Nodes with `>`
   ///
   /// The actual implementation is in Node::operator<
   virtual bool operator>( const Node& rhs_node ) const {
      return rhs_node < *this;
   }


   /// Compare two Nodes with `>=`
   ///
   /// The actual implementation is in Node::operator<
   virtual bool operator>=( const Node& rhs_node ) const {
      return !( *this < rhs_node );
   }
} ; // class Node
