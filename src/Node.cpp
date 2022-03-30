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
   // Print ===================================================================
   cout << setw(80) << setfill( '=' ) << "" << endl ;
   cout << setfill( ' ' ) ;   // Space pad
   cout << left ;             // Left justify
   cout << boolalpha ;        // Print `true` and `false` for `bool`s

   FORMAT_LINE( "Node", "this" ) << this << endl ;
   FORMAT_LINE( "Node", "next" ) << next << endl ;

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


/// This method checks the Node.  If something is not right, it will
/// dump out a message and stop the validation.  It will not throw an
/// exception.
///
/// @internal There's really no validation for `next` or `prev`.  Both
///
///
/// @return True if the Node is healthy
bool Node::validate() const noexcept {
   ///  Nothing to validate right now.
   ///  @todo Consider how we might validate `next` and `prev`.
   return true;
}
