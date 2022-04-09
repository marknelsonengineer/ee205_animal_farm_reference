///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// A generic Node class.  May be used as a base class for a number of data
/// structures.  Not all of the fields need to be used.
///
/// @file Node.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include "config.h"
#include "Node.h"

using namespace std;


/// @returns `true` if everything worked correctly.  `false` if something went
///          wrong
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
bool Node::dump() const {
   PRINT_HEADING_FOR_DUMP ;

   FORMAT_LINE_FOR_DUMP( "Node", "this" ) << this << endl ;
   FORMAT_LINE_FOR_DUMP( "Node", "next" ) << next << endl ;

   return true ;
}


/// A generic comparison based on the memory address of the object.
///
/// @return true if `node1 > node2`
bool Node::compareByAddress ( const Node* node1, const Node* node2 ) {
   if( node1 > node2 )
      return true;
   return false;
}


/// @param rightSide The `this` member is the left side of the `>` operator.
///                  `rightSide` is the right side of the `>` operator.
/// @return `true` if `leftSide > rightSide`
bool Node::operator>(const Node &rightSide) {
   // `this` is the leftSide of the operator, so compare:
   // leftSide > rightSide

   return compareByAddress( this, &(Node&)rightSide );
}


/// This method checks the Node.  If something is not right,
/// print out a message and stop the validation.  It will not throw an
/// exception.
///
/// @return True if the Node is healthy
bool Node::validate() const noexcept {
   if( next == nullptr ) {
      return true;  /// `nullptr` is a valid value for the next pointer.
   }

   /// @internal Perform a rudimentary recursive loop test and ensure
   ///           the next pointer does not refer back to itself.
   ///           This also has the benefit of dereferencing the
   ///           next pointer and ensuring it points to a valid address.
   if( next == next->next ) {
      cout << PROGRAM_NAME << ": Recursive loop detected:  next points to itself!" ;
      return false;
   }

   return true;
}
