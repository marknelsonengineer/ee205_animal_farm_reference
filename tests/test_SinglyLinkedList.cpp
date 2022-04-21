///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab14a_animal_farm_4 - EE 205 - Spr 2022
///
/// Comprehensive test of the SinglyLinkedList class
///
/// @file test_SinglyLinkedList.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   19_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

#include <stdexcept> // For logic_error

#include "../src/SinglyLinkedList.h"

using namespace std;

BOOST_AUTO_TEST_CASE( test_SinglyLinkedList_simple_insert_and_delete ) {
   Node node1;             // Instantiate a node
   SinglyLinkedList list;  // Instantiate a SinglyLinkedList

   BOOST_CHECK_EQUAL( list.empty(), true );
   BOOST_CHECK_EQUAL( list.size(), 0 );
   BOOST_CHECK_EQUAL( list.isIn( &node1 ), false );
   BOOST_CHECK_EQUAL( list.isSorted(), true );  // An empty list should be sorted
   BOOST_CHECK_EQUAL( list.get_first(), nullptr );
   BOOST_CHECK_NO_THROW( list.dump() );
   BOOST_CHECK( list.validate() );

   BOOST_CHECK_NO_THROW( list.push_front( &node1 ) );
   BOOST_CHECK_THROW( list.push_front( &node1 ), logic_error );  // Can't insert a node that's already in the list

   BOOST_CHECK_EQUAL( list.empty(), false );
   BOOST_CHECK_EQUAL( list.size(), 1 );
   BOOST_CHECK_EQUAL( list.isIn( &node1 ), true );
   BOOST_CHECK_EQUAL( list.isSorted(), true );  // A list with only one thing should be sorted
   BOOST_CHECK_EQUAL( list.get_first(), &node1 );
   BOOST_CHECK_NO_THROW( list.dump() );
   BOOST_CHECK( list.validate() );

   Node* node2;
   BOOST_CHECK_NO_THROW( node2 = list.pop_front() );

   BOOST_CHECK_EQUAL( list.empty(), true );
   BOOST_CHECK_EQUAL( list.size(), 0 );
   BOOST_CHECK_EQUAL( list.isIn( node2 ), false );
   BOOST_CHECK_EQUAL( list.isSorted(), true );  // An empty list should be sorted
   BOOST_CHECK_EQUAL( list.get_first(), nullptr );
   BOOST_CHECK_NO_THROW( list.dump() );
   BOOST_CHECK( list.validate() );

   BOOST_CHECK_NO_THROW( list.deleteAllNodes() ); // This is OK even if the list is empty
}


BOOST_AUTO_TEST_CASE( test_SinglyLinkedList_multi_insert_and_delete ) {
   SinglyLinkedList list;  // Instantiate a SinglyLinkedList
   BOOST_CHECK( list.validate() );

   for( int i = 0 ; i < 100 ; i++ ) {
      Node* node = new Node();

      BOOST_CHECK_EQUAL( list.size(), i );
      BOOST_CHECK_EQUAL( list.isIn( node ), false );

      BOOST_CHECK_NO_THROW( list.push_front( node ) );
      BOOST_CHECK_THROW( list.push_front( node ), logic_error );  // Can't insert a node that's already in the list

      BOOST_CHECK_EQUAL( list.empty(), false );
      BOOST_CHECK_EQUAL( list.isIn( node ), true );
      BOOST_CHECK_EQUAL( list.get_first(), node );
      BOOST_CHECK( list.validate() );
   }

   for( int i = 99 ; i >= 0 ; i-- ) {
      BOOST_CHECK_EQUAL( list.size(), i+1 );

      Node* nodeBefore = list.get_first();
      Node* nodeAfter;
      BOOST_CHECK_EQUAL( list.isIn( nodeBefore ), true );
      BOOST_CHECK_NO_THROW( nodeAfter = list.pop_front() );
      BOOST_CHECK_EQUAL( nodeBefore, nodeAfter );
      BOOST_CHECK_EQUAL( list.isIn( nodeBefore), false );
      BOOST_CHECK_EQUAL( list.size(), i );
      BOOST_CHECK_EQUAL( list.get_next( nodeAfter ), nullptr );
   }

   // BOOST_CHECK_NO_THROW( list.dump() );

   BOOST_CHECK_EQUAL( list.empty(), true );
   BOOST_CHECK_EQUAL( list.size(), 0 );
   BOOST_CHECK_EQUAL( list.isSorted(), true );  // An empty list should be sorted
   BOOST_CHECK_EQUAL( list.get_first(), nullptr );
   BOOST_CHECK_NO_THROW( list.dump() );
   BOOST_CHECK( list.validate() );

   BOOST_CHECK_NO_THROW( list.deleteAllNodes() );  // Make sure you can delete an empty list
   BOOST_CHECK( list.validate() );
}


BOOST_AUTO_TEST_CASE( test_SinglyLinkedList_insert_after ) {
   SinglyLinkedList list;  // Instantiate a SinglyLinkedList
   Node nodeFirst;         // Instantiate a node
   list.push_front( &nodeFirst ) ;

   BOOST_CHECK( list.validate() );

   for( int i = 0 ; i < 100 ; i++ ) {  // Test insert_after() 100 times
      Node* node = new Node();  // This is the node we are going to insert

      int position = rand() % list.size();
      Node* insertAt = list.get_first();
      for( int j = 0 ; j < position ; j++ ) {
         insertAt = list.get_next( insertAt );
      }

      BOOST_CHECK_NO_THROW( list.insert_after( insertAt, node ) );
      BOOST_CHECK_THROW( list.insert_after( insertAt, node ), logic_error );  // Can't insert a node that's already in the list
      BOOST_CHECK_THROW( list.insert_after( node, node ), logic_error );  // Can't insert a node that's already in the list

      BOOST_CHECK_EQUAL( list.size(), i+2 );
      BOOST_CHECK_EQUAL( list.empty(), false );
      BOOST_CHECK_EQUAL( list.isIn( node ), true );
      BOOST_CHECK( list.validate() );
   }

   BOOST_CHECK_NO_THROW( list.deleteAllNodes() ); // This does a lot of work

   BOOST_CHECK_EQUAL( list.empty(), true );
   BOOST_CHECK_EQUAL( list.size(), 0 );
   BOOST_CHECK_EQUAL( list.isSorted(), true );  // An empty list should be sorted
   BOOST_CHECK_EQUAL( list.get_first(), nullptr );
   BOOST_CHECK_NO_THROW( list.dump() );
   BOOST_CHECK( list.validate() );
}
