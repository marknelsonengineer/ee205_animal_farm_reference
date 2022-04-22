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
   assert( SinglyLinkedList::validate() );

   #ifdef DEBUG
      // cout << PROGRAM_NAME << ": " << __PRETTY_FUNCTION__ << ": initialized" << endl ;
   #endif
}


/// @param newNode The Node to add to the List.  It must be a valid Node.
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

   // GENERAL CASE:  The List is not empty
   if( head != nullptr ) {
      newNode->next = head;
      head = newNode;
   } else {	 // SPECIAL CASE:  The List is empty.
      newNode->next = nullptr;
      head = newNode;
   }

   count++;
   assert( validate() );

   #ifdef DEBUG
      // cout << PROGRAM_NAME << ": " << __FUNCTION__ << endl;
      // newNode->dump();
   #endif

   TRACE_END
} // push_front


/// @return The first Node in the List or `nullptr` if the List is empty
Node *SinglyLinkedList::pop_front() noexcept {
   TRACE_START

   if( head == nullptr )  // SPECIAL CASE:  The List is empty
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


/// Use push_front() to add to an empty List.
///
/// @param currentNode Insert `newNode` after this Node.  Must not be `nullptr`.
///                    Must be in the List.
/// @param newNode The Node to add to the List.  Must not be `nullptr`.
///                Must not be in the List.
void SinglyLinkedList::insert_after(Node *currentNode, Node *newNode) {
   TRACE_START

   /// @throws logic_error If the List is empty
   if( head == nullptr) {
      throw logic_error( PROGRAM_NAME ": Can't insert_after() with an empty List." );
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

   // GENERAL CASE: This function can't insert into the first node, so
   //               every case is the general case.
   newNode->next = currentNode->next;
   currentNode->next = newNode;

   count++;
   assert( validate() );

   #ifdef DEBUG
      // cout << PROGRAM_NAME << ": " << __FUNCTION__ << endl;
      // newNode->dump();
   #endif

   TRACE_END
} // insert_after


void SinglyLinkedList::dump() const noexcept {
   cout << "SinglyLinkedList:  head=[" << head << "]" << endl;
   for( Node* currentNode = head ; currentNode != nullptr ; currentNode = currentNode->next ) {
      currentNode->dump();
   }
}


/// If something is not right, it will print a message and stop the validation.
/// It will not throw an exception.
///
/// @note This method calls `validate()` on each Node.
///
/// @return `true` if the List is healthy.  `false` if otherwise.
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
   // Count forward through the List
   while( currentNode != nullptr ) {
      assert( currentNode->validate() ) ;
      forwardCount++;
      currentNode = currentNode->next;
   }
   assert( size() == forwardCount );

   #ifdef DEBUG
      // cout << PROGRAM_NAME ": List is valid" << endl;
   #endif

   return true;
} // validate()
