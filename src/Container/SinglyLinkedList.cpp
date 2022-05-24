///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// A SinglyLinkedList collection class.
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

#include "../config.h"
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
void SinglyLinkedList::addFront( Node *newNode) {
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
      // cout << PROGRAM_NAME << ": " << __PRETTY_FUNCTION__ << endl;
      // dump();
      // newNode->dump();
   #endif

   TRACE_END
} // addFront


/// @return The first Node in the List or `nullptr` if the List is empty
Node *SinglyLinkedList::removeFront() noexcept {
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

   returnValue->reset();  // Unlink all pointers in the Node

   count--;
   assert( validate() );
   assert( returnValue->validate() );

   TRACE_END

   return returnValue;
} // removeFront


Node* SinglyLinkedList::remove( Node* nodeToRemove ) {
   TRACE_START

   /// @throws invalid_argument If `nodeToRemove` is `nullptr`.
   if( nodeToRemove == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": nodeToRemove can't be nullptr" );
   }

   /// @throws domain_error If `nodeToRemove` is not valid.
   if( !nodeToRemove->validate() ) {
      throw domain_error( PROGRAM_NAME ": nodeToRemove is not valid" );
   }

   assert( validate() );

   if( head == nullptr )  // SPECIAL CASE:  The List is empty
      return nullptr;

   if( head == nodeToRemove )  // SPECIAL CASE:  Remove the head node
      return removeFront();

   // It's an interior node or the last node

   Node* prevOfNodeToRemove = head;

   assert( prevOfNodeToRemove != nullptr );

   while( prevOfNodeToRemove->next != nodeToRemove && prevOfNodeToRemove->next != nullptr ) {
      prevOfNodeToRemove = prevOfNodeToRemove->next;  // Iterate through the List
   }

   /// @throws logic_error If `nodeToRemove` is not in the List.
   if( prevOfNodeToRemove->next == nullptr ) {
      throw logic_error( PROGRAM_NAME ": Node is not in the list!" );
   }

   assert( prevOfNodeToRemove->next == nodeToRemove );

   Node* returnValue = prevOfNodeToRemove->next;
   prevOfNodeToRemove->next = returnValue->next;  // Unlink the node

   returnValue->reset();  // Unlink the pointers in Node

   count--;
   assert( validate() );
   assert( returnValue->validate() );

   TRACE_END

   return returnValue;
} // remove


/// Use addFront() to add to an empty List.
///
/// @param currentNode Insert `newNode` after this Node.  Must not be `nullptr`.
///                    Must be in the List.
/// @param newNode The Node to add to the List.  Must not be `nullptr`.
///                Must not be in the List.
void SinglyLinkedList::addAfter( Node *currentNode, Node *newNode) {
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

   // GENERAL CASE: This function can't insert into the first node, so
   //               every case is the general case.
   newNode->next = currentNode->next;
   currentNode->next = newNode;

   count++;
   assert( validate() );

   #ifdef DEBUG
      // cout << PROGRAM_NAME << ": " << __PRETTY_FUNCTION__ << endl;
      // newNode->dump();
   #endif

   TRACE_END
} // addAfter


/// @todo Add better documentation
void SinglyLinkedList::dump() const noexcept {
   List::dump();

   PRINT_HEADING_FOR_DUMP ;

   for( Node* currentNode = head ; currentNode != nullptr ; currentNode = currentNode->next ) {
      currentNode->dump();
   }
}
