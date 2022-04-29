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

#include "../config.h"
#include "List.h"

using namespace std;


/// @param aNode Check this Node to see if it's in the List
///
/// @return `true` if `aNode` is in the List.  `false` if it's not.
bool List::isIn(Node *aNode) const {

   if( !Container::isIn( aNode ) ) {
      return false;
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


void List::deleteAllNodes() noexcept {
   assert( validate() );

   while( head != nullptr ) {
      pop_front();
   }

   #ifdef DEBUG
      cout << PROGRAM_NAME << ": All Nodes have been deleted" << endl ;
   #endif

   assert( validate() );
}

/// @todo Add better documentation
void List::dump() const noexcept {
   Container::dump();

   FORMAT_LINE_FOR_DUMP( "List", "head" )  << this  << std::endl ;
}


/// If something is not right, print a message and stop the validation.
/// It will not throw an exception.
///
/// @note This method calls `validate()` on each Node.
///
/// @return `true` if the List is healthy.  `false` if otherwise.
bool List::validate() const noexcept {
   assert( Container::validate() );

   /// If `head` is `nullptr`, then `count == 0`.
   if( head == nullptr ) {
      assert( count == 0 );
      assert( empty() );
   } else {
      assert( count != 0 );
      assert( !empty() );
   }

   /// If the list only has 1 Node, ensure the count == 1.
   if( head != nullptr ) {
      if( head->next == nullptr ) {
         assert( count == 1 );
      }
   }

   /// Count the number of nodes and ensure `count` is correct.
   unsigned int forwardCount = 0;
   Node* currentNode = head;
   // Count forward through the List
   while( currentNode != nullptr ) {
      assert( currentNode->validate() ) ;  /// Validate every node in the list.
      forwardCount++;
      currentNode = currentNode->next;
   }
   assert( size() == forwardCount );

   #ifdef DEBUG
   // cout << PROGRAM_NAME ": List is valid" << endl;
   #endif

   return true;
} // validate()
