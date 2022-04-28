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

#include "../src/Container/SinglyLinkedList.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_SinglyLinkedList )


/// All of the tests will use this one test_list, which must always remain valid.
///
/// Delete all nodes before and after each of the test cases in this module.
struct SinglyLinkedListTestFixture {
   SinglyLinkedListTestFixture()   {
      test_list.deleteAllNodes();
      BOOST_TEST_MESSAGE( "setup fixture" );
   }
   ~SinglyLinkedListTestFixture()  {
      test_list.deleteAllNodes();
      BOOST_TEST_MESSAGE( "teardown fixture" );
   }

   SinglyLinkedList test_list;  // Instantiate a SinglyLinkedList
} ;


BOOST_FIXTURE_TEST_CASE( test_SinglyLinkedList_simple_insert_and_delete, SinglyLinkedListTestFixture ) {
   Node node1;             // Instantiate a node

   BOOST_CHECK_EQUAL( test_list.empty(), true );
   BOOST_CHECK_EQUAL( test_list.size(), 0 );
   BOOST_CHECK_EQUAL( test_list.isIn( &node1 ), false );
   BOOST_CHECK_EQUAL( test_list.isSorted(), true );  // An empty test_list should be sorted
   BOOST_CHECK_EQUAL( test_list.get_first(), nullptr );
   BOOST_CHECK_NO_THROW( test_list.dump() );
   BOOST_CHECK( test_list.validate() );

   BOOST_CHECK_NO_THROW( test_list.push_front( &node1 ) );
   BOOST_CHECK_THROW( test_list.push_front( &node1 ), logic_error );  // Can't insert a node that's already in the test_list

   BOOST_CHECK_EQUAL( test_list.empty(), false );
   BOOST_CHECK_EQUAL( test_list.size(), 1 );
   BOOST_CHECK_EQUAL( test_list.isIn( &node1 ), true );
   BOOST_CHECK_EQUAL( test_list.isSorted(), true );  // A test_list with only one thing should be sorted
   BOOST_CHECK_EQUAL( test_list.get_first(), &node1 );
   BOOST_CHECK_NO_THROW( test_list.dump() );
   BOOST_CHECK( test_list.validate() );

   Node* node2;
   BOOST_CHECK_NO_THROW( node2 = test_list.pop_front() );

   BOOST_CHECK_EQUAL( test_list.empty(), true );
   BOOST_CHECK_EQUAL( test_list.size(), 0 );
   BOOST_CHECK_EQUAL( test_list.isIn( node2 ), false );
   BOOST_CHECK_EQUAL( test_list.isSorted(), true );  // An empty test_list should be sorted
   BOOST_CHECK_EQUAL( test_list.get_first(), nullptr );
   BOOST_CHECK_NO_THROW( test_list.dump() );
   BOOST_CHECK( test_list.validate() );

   BOOST_CHECK_NO_THROW( test_list.deleteAllNodes() ); // This is OK even if the test_list is empty
   BOOST_CHECK( test_list.validate() );
}


BOOST_FIXTURE_TEST_CASE( test_SinglyLinkedList_multi_insert_and_delete, SinglyLinkedListTestFixture ) {
   BOOST_CHECK( test_list.validate() );

   for( int i = 0 ; i < 100 ; i++ ) {
      Node* node = new Node();

      BOOST_CHECK_EQUAL( test_list.size(), i );
      BOOST_CHECK_EQUAL( test_list.isIn( node ), false );

      BOOST_CHECK_NO_THROW( test_list.push_front( node ) );
      BOOST_CHECK_THROW( test_list.push_front( node ), logic_error );  // Can't insert a node that's already in the test_list

      BOOST_CHECK_EQUAL( test_list.empty(), false );
      BOOST_CHECK_EQUAL( test_list.isIn( node ), true );
      BOOST_CHECK_EQUAL( test_list.get_first(), node );
      BOOST_CHECK( test_list.validate() );
   }

   for( int i = 99 ; i >= 0 ; i-- ) {
      BOOST_CHECK_EQUAL( test_list.size(), i + 1 );

      Node* nodeBefore = test_list.get_first();
      Node* nodeAfter;
      BOOST_CHECK_EQUAL( test_list.isIn( nodeBefore ), true );
      BOOST_CHECK_NO_THROW( nodeAfter = test_list.pop_front() );
      BOOST_CHECK_EQUAL( nodeBefore, nodeAfter );
      BOOST_CHECK_EQUAL( test_list.isIn( nodeBefore), false );
      BOOST_CHECK_EQUAL( test_list.size(), i );
      BOOST_CHECK_EQUAL( test_list.get_next( nodeAfter ), nullptr );
   }

   // BOOST_CHECK_NO_THROW( test_list.dump() );

   BOOST_CHECK_EQUAL( test_list.empty(), true );
   BOOST_CHECK_EQUAL( test_list.size(), 0 );
   BOOST_CHECK_EQUAL( test_list.isSorted(), true );  // An empty test_list should be sorted
   BOOST_CHECK_EQUAL( test_list.get_first(), nullptr );
   BOOST_CHECK_NO_THROW( test_list.dump() );
   BOOST_CHECK( test_list.validate() );

   BOOST_CHECK_NO_THROW( test_list.deleteAllNodes() );  // Make sure you can delete an empty test_list
   BOOST_CHECK( test_list.validate() );
}


BOOST_FIXTURE_TEST_CASE( test_SinglyLinkedList_insert_after, SinglyLinkedListTestFixture ) {
   Node nodeFirst;         // Instantiate a node
   test_list.push_front( &nodeFirst ) ;

   BOOST_CHECK( test_list.validate() );

   for( int i = 0 ; i < 100 ; i++ ) {  // Test insert_after() 100 times
      Node* node = new Node();  // This is the node we are going to insert

      int position = rand() % test_list.size();
      Node* insertAt = test_list.get_first();
      for( int j = 0 ; j < position ; j++ ) {
         insertAt = test_list.get_next( insertAt );
      }

      BOOST_CHECK_NO_THROW( test_list.insert_after( insertAt, node ) );
      BOOST_CHECK_THROW( test_list.insert_after( insertAt, node ), logic_error );  // Can't insert a node that's already in the test_list
      BOOST_CHECK_THROW( test_list.insert_after( node, node ), logic_error );  // Can't insert a node that's already in the test_list

      BOOST_CHECK_EQUAL( test_list.size(), i + 2 );
      BOOST_CHECK_EQUAL( test_list.empty(), false );
      BOOST_CHECK_EQUAL( test_list.isIn( node ), true );
      BOOST_CHECK( test_list.validate() );
   }

   BOOST_CHECK_NO_THROW( test_list.deleteAllNodes() ); // This does a lot of work

   BOOST_CHECK_EQUAL( test_list.empty(), true );
   BOOST_CHECK_EQUAL( test_list.size(), 0 );
   BOOST_CHECK_EQUAL( test_list.isSorted(), true );  // An empty test_list should be sorted
   BOOST_CHECK_EQUAL( test_list.get_first(), nullptr );
   BOOST_CHECK_NO_THROW( test_list.dump() );
   BOOST_CHECK( test_list.validate() );
}

BOOST_AUTO_TEST_SUITE_END()
