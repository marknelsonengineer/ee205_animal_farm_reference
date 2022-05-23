///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// A DoublyLinkedList collection class.
///
/// @file DoublyLinkedList.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   26_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>

// Set to trace the flow of execution through this code
// #define TRACE

#include "../config.h"
#include "DoublyLinkedList.h"

using namespace std;


DoublyLinkedList::DoublyLinkedList() {
   assert( DoublyLinkedList::validate() );

   #ifdef DEBUG
      // cout << PROGRAM_NAME << ": " << __PRETTY_FUNCTION__ << ": initialized" << endl ;
   #endif
}


/// @param newNode The Node to add to the List.  It must be a valid Node.
///                `newNode` can not be `nullptr`.
void DoublyLinkedList::addFront( Node* newNode ) {
   TRACE_START

   /// @throws invalid_argument If `newNode` is `nullptr`.
   if( newNode == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": newNode can't be nullptr" );
   }

   /// @throws domain_error If `newNode` is not valid.
   if( !newNode->validate() ) {
      throw domain_error( PROGRAM_NAME ": newNode is not valid" );
   }

   /// @throws logic_error If `newNode` is already in the container.
   if( isIn( newNode ) ) {
      throw logic_error( PROGRAM_NAME ": Node is already in container!" );
   }

   assert( validate() );

   // GENERAL CASE:  The List is not empty
   if( head != nullptr ) {
      newNode->next = head;
      newNode->prev = nullptr;
      head->prev = newNode;
      head = newNode;
   } else {	 // SPECIAL CASE:  The List is empty.
      newNode->next = nullptr;
      newNode->prev = nullptr;
      head = newNode;
      tail = newNode;
   }

   count++;
   assert( validate() );

   #ifdef DEBUG
      // cout << PROGRAM_NAME << ": " << __PRETTY_FUNCTION__ << endl;
      // newNode->dump();
   #endif

   TRACE_END
} // addFront


/// @param newNode The Node to add to the List.  It must be a valid Node.
///                `newNode` can not be `nullptr`.
void DoublyLinkedList::addBack( Node* newNode) {
   TRACE_START

   /// @throws invalid_argument If `newNode` is `nullptr`.
   if( newNode == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": newNode can't be nullptr" );
   }

   /// @throws domain_error If `newNode` is not valid.
   if( !newNode->validate() ) {
      throw domain_error( PROGRAM_NAME ": newNode is not valid" );
   }

   /// @throws logic_error If `newNode` is already in the container.
   if( isIn( newNode ) ) {
      throw logic_error( PROGRAM_NAME ": Node is already in container!" );
   }

   assert( validate() );

   // GENERAL CASE:  The List is not empty
   if( tail != nullptr ) {
      newNode->next = nullptr;
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
   } else {	 // SPECIAL CASE:  The List is empty.
      newNode->next = nullptr;
      newNode->prev = nullptr;
      head = newNode;
      tail = newNode;
   }

   count++;
   assert( validate() );

   #ifdef DEBUG
      // cout << PROGRAM_NAME << ": " << __PRETTY_FUNCTION__ << endl;
      // newNode->dump();
   #endif

   TRACE_END
} // addBack


/// @return The first Node in the List or `nullptr` if the List is empty
Node* DoublyLinkedList::removeFront() noexcept {
   TRACE_START

   if( head == nullptr )  // SPECIAL CASE:  The List is empty
      return nullptr;

   assert( validate() );

   Node* returnValue = head;

   // GENERAL CASE:  The List has 2 or more nodes
   if( head != tail ) {
      head->next->prev = nullptr;
      head = head->next;
   } else {  // SPECIAL CASE:  This is the last node in the List
      head = nullptr;
      tail = nullptr;
   }

   returnValue->reset();  // Unlink the pointers in Node

   count--;
   assert( validate() );
   assert( returnValue->validate() );

   TRACE_END

   return returnValue;
} // removeFront


/// @return The last Node in the List or `nullptr` if the List is empty
Node* DoublyLinkedList::removeBack() noexcept {
   TRACE_START

   if( tail == nullptr )  // SPECIAL CASE:  The List is empty
      return nullptr;

   assert( validate() );

   Node* returnValue = tail;

   // GENERAL CASE:  The List has 2 or more nodes
   if( head != tail ) {
      tail->prev->next = nullptr;
      tail = tail->prev;
   } else {  // SPECIAL CASE:  This is the last node in the List
      head = nullptr;
      tail = nullptr;
   }

   returnValue->reset();  // Unlink the pointers in Node

   count--;
   assert( validate() );
   assert( returnValue->validate() );

   TRACE_END

   return returnValue;
} // removeBack


/// Use addFront() to add to an empty List.
///
/// @param currentNode Insert `newNode` after this Node.  Must not be `nullptr`.
///                    Must be in the List.
/// @param newNode The Node to add to the List.  Must not be `nullptr`.
///                Must not be in the List.
void DoublyLinkedList::addAfter( Node* currentNode, Node* newNode) {
   TRACE_START

   /// @throws logic_error If the List is empty
   if( head == nullptr) {
      throw logic_error( PROGRAM_NAME ": Can't addAfter() with an empty List." );
   }

   /// @throws invalid_argument If `currentNode` is `nullptr`
   if( currentNode == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": currentNode must have a value." );
   }

   /// @throws logic_error If currentNode is not in the List.
   if( !isIn( currentNode )) {
      throw logic_error( PROGRAM_NAME ": currentNode must be in the List." );
   }

   /// @throws invalid_argument If `newNode` is `nullptr`
   if( newNode == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": newNode must have a value." );
   }

   /// @throws domain_error If `newNode` is not valid.
   if( !newNode->validate() ) {
      throw domain_error( PROGRAM_NAME ": newNode is not valid" );
   }

   /// @throws logic_error If `newNode` is already in the List.
   if( isIn( newNode )) {
      throw logic_error( PROGRAM_NAME ": newNode is already in the List." );
   }

   assert( validate() );

   // GENERAL CASE:  Not inserting at the end of the List
   if( tail != currentNode ) {
      newNode->next = currentNode->next;
      currentNode->next = newNode;
      newNode->prev = currentNode;
      newNode->next->prev = newNode;
      count++;
   } else {	 // SPECIAL CASE:  Insert at the end of the List... we already know how to do that!
      addBack( newNode );
   }

   assert( validate() );

   #ifdef DEBUG
      // cout << PROGRAM_NAME << ": " << __PRETTY_FUNCTION__ << endl;
      // newNode->dump();
   #endif

   TRACE_END
} // addAfter


/// Use addFront() to add to an empty List.
///
/// @param currentNode Insert `newNode` before this Node.  Must not be `nullptr`.
///                    Must be in the List.
/// @param newNode The Node to add to the List.  Must not be `nullptr`.
///                Must not be in the List.
void DoublyLinkedList::addBefore( Node* currentNode, Node* newNode) {
   TRACE_START

   /// @throws logic_error If the List is empty
   if( head == nullptr) {
      throw logic_error( PROGRAM_NAME ": Can't addBefore() with an empty List." );
   }

   /// @throws invalid_argument If `currentNode` is `nullptr`
   if( currentNode == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": currentNode must have a value." );
   }

   /// @throws logic_error If currentNode is not in the List.
   if( !isIn( currentNode )) {
      throw logic_error( PROGRAM_NAME ": currentNode must be in the List." );
   }

   /// @throws invalid_argument If `newNode` is `nullptr`
   if( newNode == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": newNode must have a value." );
   }

   /// @throws domain_error If `newNode` is not valid.
   if( !newNode->validate() ) {
      throw domain_error( PROGRAM_NAME ": newNode is not valid" );
   }

   /// @throws logic_error If `newNode` is already in the List.
   if( isIn( newNode )) {
      throw logic_error( PROGRAM_NAME ": newNode is already in the List." );
   }

   assert( validate() );

   // GENERAL CASE:  Not inserting at the beginning of the List
   if( head != currentNode ) {
      newNode->prev = currentNode->prev;
      currentNode->prev = newNode;
      newNode->next = currentNode;
      newNode->prev->next = newNode;
      count++;
   } else {	 // SPECIAL CASE:  Insert at the beginning of the List... we already know how to do that!
      addFront( newNode );
   }
   assert( validate() );

   #ifdef DEBUG
      // cout << PROGRAM_NAME << ": " << __PRETTY_FUNCTION__ << endl;
      // newNode->dump();
   #endif

   TRACE_END
} // addBefore


/// @param node1 Must not be `nullptr` and must be in the List
/// @param node2 Must not be `nullptr` and must be in the List
void DoublyLinkedList::swap( Node* node1, Node* node2 ) {
   assert( !isEmpty() );

   /// @throws invalid_argument If either `node1` or `node2` is `nullptr`
   if( node1 == nullptr || node2 == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": Either node1 or node2 is nullptr." );
   }

   /// @throws logic_error If either `node1` or `node2` are not in the List.
   if( !isIn( node1 ) || !isIn( node2 ) ) {
      throw logic_error( PROGRAM_NAME ": Both node1 and node2 must be in the List." );
   }

   assert( validate() );

   if( node1 == node2 ) { /// If `node1` and `node2` are the same, do nothing
      return;
   }

   /// @todo In the List, we need to make sure that node1 is to the left of node2.
   ///       If they aren't, we may be in for some unpredictable behavior.

   /// #### Internal
   /// We will divide this into 4 separate operations... each with a general & special case.
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

   if( node1 != head ) {  // GENERAL CASE: node1 is not the first in the List
      node1_left->next = node2;
      node2->prev = node1_left;
   } else {               // SPECIAL CASE: node1 is the first in the List
      head = node2;
      node2->prev = nullptr;
   }

   // Fixup node2_right
   if( !isAdjoining )  // GENERAL CASE:  The nodes are not adjoining
      node2->next = node1_right;
   else                // SPECIAL CASE:  The two nodes are next to each other
      node2->next = node1;

   if( node2 != tail ) { // GENERAL CASE: node2 is not the last in the List
      node2_right->prev = node1;
      node1->next = node2_right;
   } else {              // SPECIAL CASE: node2 is the last in the List
      tail = node1;
      node1->next = nullptr;
   }

   // Fixup inside connectors
   if( !isAdjoining ) {
      node1_right->prev = node2;
      node2_left->next = node1;
   }

   assert( validate() );
} // swap


/// @see https://en.wikipedia.org/wiki/Insertion_sort
///
/// @post `isSorted()` is `true`
///
/// This method depends on Node's > operator.
///
void DoublyLinkedList::insertionSort() noexcept {
   assert( validate() );

   if( count <= 1 ) // SPECIAL CASE:  The List is empty or only has one item...
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

   assert( isSorted() ) ;

   assert( validate() );
}


/// @return The last Node in the List.  If the List is empty, return `nullptr`.
Node *DoublyLinkedList::getLast() const noexcept {
   return tail;
}


/// @param currentNode Start here
///
/// @return Return the Node that's before `currentNode` in the DoublyLinkedList
Node* DoublyLinkedList::getPrev( const Node* currentNode) {
   /// @throws invalid_argument If `currentNode` is `nullptr`
   if( currentNode == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": currentNode must have a value." );
   }

   return currentNode->prev;
}


/// @todo add better documentation
void DoublyLinkedList::dump() const noexcept {
   List::dump();

   FORMAT_LINE_FOR_DUMP( "DoublyLinkedList", "tail" )  << tail  << std::endl ;

   PRINT_HEADING_FOR_DUMP ;

   for( Node* currentNode = head ; currentNode != nullptr ; currentNode = currentNode->next ) {
      currentNode->dump();
   }
}


/// If something is not right, print a message and stop the validation.
/// It will not throw an exception.
///
/// @note This method calls `validate()` on each Node.
///
/// @return `true` if the List is healthy.  `false` if otherwise.
bool DoublyLinkedList::validate() const noexcept {
   assert( List::validate() );

   if( head == nullptr ) {
      assert( tail == nullptr );
      assert( count == 0 );
      assert( isEmpty() );
   } else {
      assert( tail != nullptr );
      assert( count != 0 );
      assert( !isEmpty() );
   }

   if( tail == nullptr ) {
      assert( head == nullptr );
      assert( count == 0 );
      assert( isEmpty() );
   } else {
      assert( head != nullptr );
      assert( count != 0 );
      assert( !isEmpty() );
   }

   if( head != nullptr && tail == head ) {
      assert( count == 1 );
   }

   Container::t_size forwardCount = 0;
   Node* currentNode = head;
   // Count forward through the List
   while( currentNode != nullptr ) {
      assert( currentNode->validate() ) ;
      forwardCount++;
      if( currentNode->next != nullptr ) {
         assert( currentNode->next->prev == currentNode );
      }
      currentNode = currentNode->next;
   }
   assert( size() == forwardCount );

   // Count backward through the List
   Container::t_size backwardCount = 0;
   currentNode = tail;
   while( currentNode != nullptr ) {
      assert( currentNode->validate() ) ;
      backwardCount ++;
      if( currentNode->prev != nullptr ) {
         assert( currentNode->prev->next == currentNode );
      }
      currentNode = currentNode->prev;
   }
   assert( size() == backwardCount );

   #ifdef DEBUG
      // cout << PROGRAM_NAME ": List is valid" << endl;
   #endif

   return true;
} // validate()
