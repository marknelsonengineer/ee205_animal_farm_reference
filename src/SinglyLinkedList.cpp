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

// Set to trace the flow of execution through this code
// #define TRACE

#include "config.h"
#include "SinglyLinkedList.h"

using namespace std;


SinglyLinkedList::SinglyLinkedList() {
   assert( validate() );

   #ifdef DEBUG
      cout << PROGRAM_NAME << ": " << __FUNCTION__ << ": initialized" << endl ;
   #endif
}


/// @return `true` if the list is empty.  `false` if the list has Nodes in it.
bool SinglyLinkedList::empty() const noexcept {
   return (head == nullptr);
}


/// @return The number of Nodes in the list
unsigned int SinglyLinkedList::size() const noexcept {
   return count ;
}


/// @param newNode The Node to add to the list.  It must be a valid Node.
///                `newNode` can not be `nullptr`.
void SinglyLinkedList::push_front(Node *newNode) {
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

   #ifdef DEBUG
      cout << PROGRAM_NAME << ": " << __FUNCTION__ << endl;
      newNode->dump();
   #endif

   TRACE_END
} // push_front


/// @return The first Node in the list or `nullptr` if the list is empty
Node *SinglyLinkedList::pop_front() noexcept {
   TRACE_START

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
   assert( returnValue->validate() );

   TRACE_END

   return returnValue;
} // pop_front


/// Use push_front() to add to an empty list.
///
/// @param currentNode Insert `newNode` after this Node.  Must not be `nullptr`.
///                    Must be in the list.
/// @param newNode The Node to add to the list.  Must not be `nullptr`.
///                Must not be in the list.
void SinglyLinkedList::insert_after(Node *currentNode, Node *newNode) {
   TRACE_START

   /// @throws logic_error If the list is empty
   if( head == nullptr) {
      throw logic_error( PROGRAM_NAME ": Can't insert_after() with an empty list." );
   }

   /// @throws invalid_argument If `currentNode` is `nullptr`
   if( currentNode == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": currentNode must have a value." );
   }

   /// @throws logic_error If currentNode is not in the list.
   if( !isIn( currentNode )) {
      throw logic_error( PROGRAM_NAME ": currentNode must be in the list." );
   }

   /// @throws invalid_argument If `newNode` is `nullptr`
   if( newNode == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": newNode must have a value." );
   }

   /// @throws domain_error If `newNode` is not valid.
   if( !newNode->validate() ) {
      throw domain_error( PROGRAM_NAME ": newNode is not valid" );
   }

   /// @throws logic_error If `newNode` is already in the list.
   if( isIn( newNode )) {
      throw logic_error( PROGRAM_NAME ": newNode is already in the list." );
   }

   assert( validate() );

   // GENERAL CASE: This function can't insert into the first node, so
   //               every case is the general case.
   newNode->next = currentNode->next;
   currentNode->next = newNode;

   assert( validate() );

   #ifdef DEBUG
      cout << PROGRAM_NAME << ": " << __FUNCTION__ << endl;
      newNode->dump();
   #endif

   TRACE_END
} // insert_after



/// @param aNode Check this Node to see if it's in the list
///
/// @return `true` if `aNode` is in the list.  `false` if it's not.
bool SinglyLinkedList::isIn(Node *aNode) const {

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

   return false;  // Never found aNode in the list
}


/// This method depends on the Node's > operator.
///
/// @return `true` if the list is sorted.  `false` if it's not.
bool SinglyLinkedList::isSorted() const noexcept {
   assert( validate() );

   if( count <= 1 ) // SPECIAL CASE:  The list is empty or only has one item...
      return true;

   for( Node* i = head ; i->next != nullptr ; i = i->next ) {
      if( *i > *i->next )  // If the previous is greater than the next
         return false;     // ...then the list is *not* sorted
   }

   return true;  // Everything looks kosher
}


/// @return The first Node in the list.  If the list is empty, return `nullptr`.
Node *SinglyLinkedList::get_first() const noexcept {
   return head;
}


/// @param currentNode Start here
///
/// @return Return the Node that follows `currentNode` in the list
Node *SinglyLinkedList::get_next(const Node *currentNode) {
   /// @throws invalid_argument If `currentNode` is `nullptr`
   if( currentNode == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": currentNode must have a value." );
   }

   return currentNode->next;
}

void SinglyLinkedList::dump() const noexcept {
   cout << "SinglyLinkedList:  head=[" << head << "]" << endl;
   for( Node* currentNode = head ; currentNode != nullptr ; currentNode = currentNode->next ) {
      cout << "  ";
      currentNode->dump();
   }
}


/// If something is not right, it will print a message and stop the validation.
/// It will not throw an exception.
///
/// @note This method calls `validate()` on each Node.
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
      assert( currentNode->validate() ) ;
      forwardCount++;
      currentNode = currentNode->next;
   }
   assert( count == forwardCount );

   #ifdef DEBUG
      cout << PROGRAM_NAME ": List is valid" << endl;
   #endif

   return true;
} // validate()
