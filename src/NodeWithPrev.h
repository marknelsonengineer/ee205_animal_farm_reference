///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// A Node with a previous member.  This can be used with a DoublyLinkedList.
///
/// @file NodeWithPrev.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   30_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"

/// A Node with a previous member.
///
/// This can be used with a DoublyLinkedList.
class NodeWithPrev : public Node {
   friend class DoublyLinkedList;

protected:  ////////////////////// Protected Members ///////////////////////////
   NodeWithPrev* next = nullptr;  ///< Point to the next Node in the list or `nullptr`
                                  ///< if it's the last Node in the list.

   NodeWithPrev* prev = nullptr;  ///< Point to the previous Node in the list or
                                  ///< `nullptr` if it's the first Node in the list.

public:  /////////////////////////// Public Methods ////////////////////////////

   /// Output the contents of this object
   ///
   /// #### Sample Output
   /// @code
   ///     ==============================================
   ///     Cat     name                Kali
   ///     Cat     gender              Female
   ///     Cat     breed               Shorthair
   ///     Cat     isFixed             false
   ///     Cat     weight              1.3
   /// @endcode
   /// @todo update this output
   ///
   void dump() const override {
      Node::dump();
      FORMAT_LINE_FOR_DUMP( "NodeWithPrev", "prev" ) << prev << std::endl ;
   }


   /// Check the Node.  If something is not right, print out a message and
   /// stop the validation.  It will not throw an exception.
   ///
   /// @return `true` if the Node is healthy
   bool validate() const noexcept override {
      Node::validate();

      if( prev == nullptr ) {
         return true;  /// `nullptr` is a valid value for the previous pointer.
      }

      /// @internal Perform a rudimentary recursive loop test and ensure
      ///           the prev pointer does not refer back to itself.
      ///           This also has the benefit of dereferencing the
      ///           pointer and ensuring it points to a valid address.
      if( prev == prev->prev ) {
         std::cout << PROGRAM_NAME << ": Recursive loop detected:  prev points to itself!" ;
         return false;
      }

      return true;
   }

};
