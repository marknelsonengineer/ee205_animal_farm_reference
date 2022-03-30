///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// A generic list-based collection class.
///
/// @file List.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   29_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>

#include "config.h"
#include "List.h"

using namespace std;


/// @return `true` if the List is empty.  `false` if the List has Nodes in it.
bool List::empty() const noexcept {
   return (head == nullptr);
}


/// @return The number of Nodes in the List
unsigned int List::size() const noexcept {
   return count ;
}


/// @param aNode Check this Node to see if it's in the List
///
/// @return `true` if `aNode` is in the List.  `false` if it's not.
bool List::isIn(Node *aNode) const {

   /// @throws invalid_argument If `aNode` is `nullptr`
   if( aNode == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": aNode must have a value." );
   }

   Node* currentNode = head;

   while( currentNode != nullptr ) {
      if( aNode == currentNode )
         return true;
      currentNode = currentNode->next;
   }

   return false;  // Never found aNode in the List
}


/// This method depends on the Node's > operator.
///
/// @return `true` if the List is sorted.  `false` if it's not.
bool List::isSorted() const noexcept {
   assert( validate() );

   if( count <= 1 ) // SPECIAL CASE:  The List is empty or only has one item...
      return true;

   for( Node* i = head ; i->next != nullptr ; i = i->next ) {
      if( *i > *i->next )  // If the previous is greater than the next
         return false;     // ...then the List is *not* sorted
   }

   return true;  // Everything looks kosher
}


/// @return The first Node in the List.  If the List is empty, return `nullptr`.
Node* List::get_first() const noexcept {
   return head;
}


/// @param currentNode Start here
///
/// @return Return the Node that follows `currentNode` in the List
Node* List::get_next(const Node *currentNode) {
   /// @throws invalid_argument If `currentNode` is `nullptr`
   if( currentNode == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": currentNode must have a value." );
   }

   return currentNode->next;
}
