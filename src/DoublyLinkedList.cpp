///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// A generic DoublyLinkedList collection class.
///
/// @file DoublyLinkedList.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   26_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>

#include "DoublyLinkedList.h"

using namespace std;

bool DoublyLinkedList::empty() const {
   return (head == nullptr);
}


// Replaced by an inline function in list.hpp
//
//unsigned int DoublyLinkedList::size() const {
//	return count;
//}


void DoublyLinkedList::push_front(Node *newNode) {
   if( newNode == nullptr )
      return;  /// If newNode is nothing, then quietly return

   validate();

   // GENERAL CASE:  The list is not empty
   if( head != nullptr ) {
      newNode->next = head;
      newNode->prev = nullptr;
      head->prev = newNode;
      head = newNode;
   } else {	 // SPECIAL CASE:  The list is empty.
      newNode->next = nullptr;
      newNode->prev = nullptr;
      head = newNode;
      tail = newNode;
   }

   count++;
   validate();
}


void DoublyLinkedList::push_back(Node *newNode) {
   if( newNode == nullptr )
      return;  /// If newNode is nothing, then quietly return

   validate();

   // GENERAL CASE:  The list is not empty
   if( tail != nullptr ) {
      newNode->next = nullptr;
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
   } else {	 // SPECIAL CASE:  The list is empty.
      newNode->next = nullptr;
      newNode->prev = nullptr;
      head = newNode;
      tail = newNode;
   }

   count++;
   validate();
}


Node *DoublyLinkedList::pop_front() {
   if( head == nullptr )  // SPECIAL CASE:  The list is empty
      return nullptr;

   validate();

   Node* returnValue = head;

   // GENERAL CASE:  Not the last node
   if( head != tail ) {
      head->next->prev = nullptr;
      head = head->next;
   } else {  // SPECIAL CASE:  This is the last node
      head = nullptr;
      tail = nullptr;
   }

   returnValue->next = nullptr;
   returnValue->prev = nullptr;

   count--;
   validate();

   return returnValue;
}


Node *DoublyLinkedList::pop_back() {
   if( tail == nullptr )  // SPECIAL CASE:  The list is empty
      return nullptr;

   validate();

   Node* returnValue = tail;

   // GENERAL CASE:  Not the last node
   if( head != tail ) {
      tail->prev->next = nullptr;
      tail = tail->prev;
   } else {  // SPECIAL CASE:  This is the last node
      head = nullptr;
      tail = nullptr;
   }

   returnValue->next = nullptr;
   returnValue->prev = nullptr;

   count--;
   validate();

   return returnValue;
}


void DoublyLinkedList::insert_after(Node *currentNode, Node *newNode) {
   // SPECIAL CASE:  The list is empty
   if( currentNode == nullptr && head == nullptr ) {
      push_front( newNode );
      return;
   }

   //  LOGIC ERROR:  Can't have a currentNode if the list is empty!
   /// @todo consider throwing an exception
   if( currentNode != nullptr && head == nullptr) {
      assert( false );
   }

   //  LOGIC ERROR:  Something's not right
   /// @todo consider throwing an exception
   if( currentNode == nullptr && head != nullptr ) {
      assert( false ) ;
   }

   // At this point, currentNode != null && head != null
   assert( currentNode != nullptr && head != nullptr );

   // Now, make sure that currentNode is in the list
   assert( isIn( currentNode ));

   // And make sure that newNode is not in the list
   assert( !isIn( newNode ));

   validate();

   // GENERAL CASE:  Not inserting at the end of the list
   if( tail != currentNode ) {
      newNode->next = currentNode->next;
      currentNode->next = newNode;
      newNode->prev = currentNode;
      newNode->next->prev = newNode;
   } else {	 // SPECIAL CASE:  Inserting at the end of the list... we already know how to do that!
      push_back( newNode );
   }

   validate();
}


void DoublyLinkedList::insert_before(Node *currentNode, Node *newNode) {
   // SPECIAL CASE:  The list is empty
   if( currentNode == nullptr && head == nullptr ) {
      push_front( newNode );
      return;
   }

   //  LOGIC ERROR:  Can't have a currentNode if the list is empty!
   /// @todo consider throwing an exception
   if( currentNode != nullptr && head == nullptr) {
      assert( false );
   }

   //  LOGIC ERROR:  Something's not right
   /// @todo consider throwing an exception
   if( currentNode == nullptr && head != nullptr ) {
      assert( false ) ;
   }

   // At this point, currentNode != null && head != null
   assert( currentNode != nullptr && head != nullptr );

   // Now, make sure that currentNode is in the list
   assert( isIn( currentNode ));

   // And make sure that newNode is not in the list
   assert( !isIn( newNode ));

   validate();

   // GENERAL CASE:  Not inserting at the beginning of the list
   if( head != currentNode ) {
      newNode->prev = currentNode->prev;
      currentNode->prev = newNode;
      newNode->next = currentNode;
      newNode->prev->next = newNode;
   } else {	 // SPECIAL CASE:  Inserting at the end of the list... we already know how to do that!
      push_front( newNode );
   }

   validate();
}


bool DoublyLinkedList::isIn(Node *aNode) const {
   Node* currentNode = head;

   while( currentNode != nullptr ) {
      if( aNode == currentNode )
         return true;
      currentNode = currentNode->next;
   }

   return false;  // Never found aNode in the list
}

void DoublyLinkedList::swap(Node *node1, Node *node2) {
   assert( !empty() );

   assert( node1 != nullptr );
   assert( node2 != nullptr );

   assert( isIn( node1 ));
   assert( isIn( node2 ));

   validate();

   if( node1 == node2 ) { /// If they are the same, do nothing
      return;
   }

   /// @todo In the list, we need to make sure that node1 is to the left of node2

   /// @internal We will divide this into 4 separate operations... each with a general & special case
   Node* node1_left  = node1->prev;
   Node* node1_right = node1->next;
   Node* node2_left  = node2->prev;
   Node* node2_right = node2->next;

   bool isAdjoining = (node1_right == node2);

   // Fixup node1_left
   if( !isAdjoining )  // GENERAL CASE: The nodes are not adjoining
      node1->prev = node2->prev;
   else                // SPECIAL CASE: The two nodes are next to each other
      node1->prev = node2;

   if( node1 != head ) {  // GENERAL CASE: node1 is not the first in the list
      node1_left->next = node2;
      node2->prev = node1_left;
   } else {               // SPECIAL CASE: node1 is the first in the list
      head = node2;
      node2->prev = nullptr;
   }

   // Fixup node2_right
   if( !isAdjoining )  // GENERAL CASE:  The nodes are not adjoining
      node2->next = node1_right;
   else                // SPECIAL CASE:  The two nodes are next to each other
      node2->next = node1;

   if( node2 != tail ) { // GENERAL CASE: node2 is not the last in the list
      node2_right->prev = node1;
      node1->next = node2_right;
   } else {              // SPECIAL CASE: node2 is the last in the list
      tail = node1;
      node1->next = nullptr;
   }

   // Fixup inside connectors
   if( !isAdjoining ) {
      node1_right->prev = node2;
      node2_left->next = node1;
   }

   validate();
} // swap


/// This function depends on Node's < operator
bool DoublyLinkedList::isSorted() const {
   if( count <= 1 ) // SPECIAL CASE:  The list is empty or only has one item...
      return true;

   for( Node* i = head ; i->next != nullptr ; i = i->next ) {
      if( *i > *i->next )  // If the previous is greater than the next
         return false;     // ...then the list is *not* sorted
   }

   return true;  // Everything looks kosher
}


void DoublyLinkedList::insertionSort() {
   validate();

   if( count <= 1 ) // SPECIAL CASE:  The list is empty or only has one item...
      return;

   // dump();

   for( Node* i = head ; i->next != nullptr ; i = i->next ) {  // Outer loop
      Node* minNode = i;

      for( Node* j = i->next ; j != nullptr ; j = j->next ) {  // Inner loop
         if( *minNode > *j )
            minNode = j;
      }
      // The minimum node is...
      // cout << "minNode = [" << minNode << "]" << endl;

      swap( i, minNode );
      i = minNode;  // This fixes up i so i->next will work
      // dump();
   }

   validate();
}


Node *DoublyLinkedList::get_first() const {
   return head;
}


Node *DoublyLinkedList::get_last() const {
   return tail;
}


Node *DoublyLinkedList::get_next(const Node *currentNode) const {
   return currentNode->next;
}


Node *DoublyLinkedList::get_prev(const Node *currentNode) const {
   return currentNode->prev;
}


void DoublyLinkedList::dump() const {
   cout << "DoubleLinkedList:  head=[" << head << "]   tail=[" << tail << "]" << endl;
   for( Node* currentNode = head ; currentNode != nullptr ; currentNode = currentNode->next ) {
      cout << "  ";
      currentNode->dump();
   }
}


bool DoublyLinkedList::validate() const {
   if( head == nullptr ) {
      assert( tail == nullptr );
      assert( count == 0 );
      assert( empty() );
   } else {
      assert( tail != nullptr );
      assert( count != 0 );
      assert( !empty() );
   }

   if( tail == nullptr ) {
      assert( head == nullptr );
      assert( count == 0 );
      assert( empty() );
   } else {
      assert( head != nullptr );
      assert( count != 0 );
      assert( !empty() );
   }

   if( head != nullptr && tail == head ) {
      assert( count == 1 );
   }

   unsigned int forwardCount = 0;
   Node* currentNode = head;
   // Count forward through the list
   while( currentNode != nullptr ) {
      forwardCount++;
      if( currentNode->next != nullptr ) {
         assert( currentNode->next->prev == currentNode );
      }
      currentNode = currentNode->next;
   }
   assert( count == forwardCount );

   // Count backward through the list
   unsigned int backwardCount = 0;
   currentNode = tail;
   while( currentNode != nullptr ) {
      backwardCount ++;
      if( currentNode->prev != nullptr ) {
         assert( currentNode->prev->next == currentNode );
      }
      currentNode = currentNode->prev;
   }
   assert( count == backwardCount );

   // cout << "List is valid" << endl;

   return true;
}
