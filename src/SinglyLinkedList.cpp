///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// A generic SinglyLinkedList collection class.
///
/// @file SinglyLinkedList.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>

#include "config.h"
#include "SinglyLinkedList.h"

using namespace std;

/// @return `true` if the list is empty.  `false` if the list has Nodes in it.
bool SinglyLinkedList::empty() const noexcept {
   return (head == nullptr);
}


/// @return The number of Nodes in the list
unsigned int SinglyLinkedList::size() const noexcept {
   return count ;
}


/// @param newNode The node to add to the list
void SinglyLinkedList::push_front(Node *newNode) noexcept {
   if( newNode == nullptr )
      return;  /// If newNode is `nullptr`, then quietly return

   assert( validate() );

   // GENERAL CASE:  The list is not empty
   if( head != nullptr ) {
      newNode->next = head;
      head = newNode;
   } else {	 // SPECIAL CASE:  The list is empty.
      newNode->next = nullptr;
      head = newNode;
   }

   count++;
   assert( validate() );
} // push_front


/// @return The first Node in the list or `nullptr` if the list is empty
Node *SinglyLinkedList::pop_front() noexcept {
   if( head == nullptr )  // SPECIAL CASE:  The list is empty
      return nullptr;

   assert( validate() );

   Node* returnValue = head;

   // GENERAL CASE:  Not the last node
   if( head->next != nullptr ) {
      head = head->next;
   } else {  // SPECIAL CASE:  This is the last node
      head = nullptr;
   }

   returnValue->next = nullptr;  // Unlink the next pointer

   count--;
   assert( validate() );

   return returnValue;
} // pop_front


/// @param currentNode Insert `newNode` after this node.  If it's `nullptr` and
///                    the list is empty, call `push_front( newNode )`
/// @param newNode The node to add to the list.  This can not be `nullptr`
void SinglyLinkedList::insert_after(Node *currentNode, Node *newNode) {
   // SPECIAL CASE:  The list is empty
   if( currentNode == nullptr && head == nullptr ) {
      push_front( newNode );   // We already know how to do this...
      return;
   }

   /// @throws invalid_argument If `currentNode` is not null and the list is empty
   if( currentNode != nullptr && head == nullptr) {
      throw( invalid_argument( PROGRAM_NAME ": Can't have a currentNode if the list is empty!" ));
   }

   /// @throws invalid_argument If `currentNode` is `nullptr` and the list is not empty
   if( currentNode == nullptr && head != nullptr ) {
      throw( invalid_argument( PROGRAM_NAME ": Need to supply a currentNode for a non-empty list" ));
   }

   // At this point, currentNode != null && head != null
   assert( currentNode != nullptr && head != nullptr );

   // Now, make sure that currentNode is in the list
   assert( isIn( currentNode ));

   // Make sure newNode is not null
   assert( newNode != nullptr );

   // And make sure that newNode is not in the list
   assert( !isIn( newNode ));

   assert( validate() );

   // GENERAL CASE:  Not inserting at the beginning of the list
      newNode->next = currentNode->next;
      currentNode->next = newNode;

   assert( validate() );
} // insert_after


/// @param aNode Check this node to see if it's in the list
/// @return `true` if `aNode` is in the list.  `false` if it's not.
bool SinglyLinkedList::isIn(Node *aNode) const noexcept {
   Node* currentNode = head;

   while( currentNode != nullptr ) {
      if( aNode == currentNode )
         return true;
      currentNode = currentNode->next;
   }

   return false;  // Never found aNode in the list
}


/// This method depends on Node's < operator
/// @return `true` if the list is sorted.  `false` if it's not.
bool SinglyLinkedList::isSorted() const noexcept {
   if( count <= 1 ) // SPECIAL CASE:  The list is empty or only has one item...
      return true;

   for( Node* i = head ; i->next != nullptr ; i = i->next ) {
      if( *i > *i->next )  // If the previous is greater than the next
         return false;     // ...then the list is *not* sorted
   }

   return true;  // Everything looks kosher
}


/// @return The first node in the list.  If the list is empty, return `nullptr`.
Node *SinglyLinkedList::get_first() const noexcept {
   return head;
}


/// @param currentNode Start here
/// @return Return the Node that follows `currentNode` in the list
Node *SinglyLinkedList::get_next(const Node *currentNode) noexcept {
   assert( currentNode != nullptr ) ;
   return currentNode->next;
}


void SinglyLinkedList::dump() const noexcept {
   cout << "SinglyLinkedList:  head=[" << head << "]" << endl;
   for( Node* currentNode = head ; currentNode != nullptr ; currentNode = currentNode->next ) {
      cout << "  ";
      currentNode->dump();
   }
}


/// This method checks the list.  If something is not right, it will
/// dump out a message and stop the validation.  It will not throw an
/// exception.
///
/// @note This method does not call validate() on its Nodes.
///
/// @return `true` if the list is healthy.  `false` if otherwise.
bool SinglyLinkedList::validate() const noexcept {
   if( head == nullptr ) {
      assert( count == 0 );
      assert( empty() );
   } else {
      assert( count != 0 );
      assert( !empty() );
   }

   if( head != nullptr ) {
      if( head->next == nullptr ) {
         assert( count == 1 );
      }
   }

   unsigned int forwardCount = 0;
   Node* currentNode = head;
   // Count forward through the list
   while( currentNode != nullptr ) {
      forwardCount++;
      currentNode = currentNode->next;
   }
   assert( count == forwardCount );

   // cout << PROGRAM_NAME ": List is valid" << endl;

   return true;
} // validate()
