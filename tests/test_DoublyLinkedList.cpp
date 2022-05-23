///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// Comprehensive test of the DoublyLinkedList class
///
/// @file test_DoublyLinkedList.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   15_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

#include <stdexcept>  // For logic_error

#include "../src/Container/DoublyLinkedList.h"
#include "../src/Animal/Animal.h"
#include "../src/Animal/Mammal/Cat/Cat.h"
#include "../src/Animal/Mammal/Dog/Dog.h"
#include "../src/Animal/AnimalFactory.h"


using namespace std;

BOOST_AUTO_TEST_SUITE( test_DoublyLinkedList )


    /// All of the tests will use this one test_list, which must always remain valid.
   static DoublyLinkedList test_list;

    /// Delete all nodes before and after each of the test cases in this module.
   struct DoublyLinkedListTestFixture {
      DoublyLinkedListTestFixture()   {
         test_list.removeAll();
         Cat::names.reset();  // We don't want to have duplicate Cat & Dog names
         Dog::names.reset();
         BOOST_TEST_MESSAGE( "setup fixture" );
      }
      ~DoublyLinkedListTestFixture()  {
         test_list.removeAll();
         Cat::names.reset();
         Dog::names.reset();
         BOOST_TEST_MESSAGE( "teardown fixture" );
      }
   } ;


   BOOST_FIXTURE_TEST_CASE( test_DoublyLinkedList_simple_push_and_pop_front, DoublyLinkedListTestFixture ) {
      Node node1;             // Instantiate a node

      BOOST_CHECK_EQUAL( test_list.isEmpty(), true );
      BOOST_CHECK_EQUAL( test_list.size(), 0 );
      BOOST_CHECK_EQUAL( test_list.isIn( &node1 ), false );
      BOOST_CHECK_EQUAL( test_list.isSorted(), true );  // An empty test_list should be sorted
      BOOST_CHECK_EQUAL( test_list.get_first(), nullptr );
      // BOOST_CHECK_NO_THROW( test_list.dump() );
      BOOST_CHECK( test_list.validate() );

      BOOST_CHECK_NO_THROW( test_list.push_front( &node1 ) );
      BOOST_CHECK_THROW( test_list.push_front( &node1 ), logic_error );  // Can't insert a node that's already in the test_list

      BOOST_CHECK_EQUAL( test_list.isEmpty(), false );
      BOOST_CHECK_EQUAL( test_list.size(), 1 );
      BOOST_CHECK_EQUAL( test_list.isIn( &node1 ), true );
      BOOST_CHECK_EQUAL( test_list.isSorted(), true );  // A test_list with only one thing should be sorted
      BOOST_CHECK_EQUAL( test_list.get_first(), &node1 );
      // BOOST_CHECK_NO_THROW( test_list.dump() );
      BOOST_CHECK( test_list.validate() );

      Node* node2;
      BOOST_CHECK_NO_THROW( node2 = test_list.pop_front() );

      BOOST_CHECK_EQUAL( test_list.isEmpty(), true );
      BOOST_CHECK_EQUAL( test_list.size(), 0 );
      BOOST_CHECK_EQUAL( test_list.isIn( node2 ), false );
      BOOST_CHECK_EQUAL( test_list.isSorted(), true );  // An empty test_list should be sorted
      BOOST_CHECK_EQUAL( test_list.get_first(), nullptr );
      // BOOST_CHECK_NO_THROW( test_list.dump() );
      BOOST_CHECK( test_list.validate() );

      BOOST_CHECK_NO_THROW( test_list.removeAll() ); // This is OK even if the test_list is empty
   }


   BOOST_FIXTURE_TEST_CASE( test_DoublyLinkedList_simple_push_and_pop_back, DoublyLinkedListTestFixture ) {
      Node node1;             // Instantiate a node

      BOOST_CHECK_EQUAL( test_list.isEmpty(), true );
      BOOST_CHECK_EQUAL( test_list.size(), 0 );
      BOOST_CHECK_EQUAL( test_list.isIn( &node1 ), false );
      BOOST_CHECK_EQUAL( test_list.isSorted(), true );  // An empty test_list should be sorted
      BOOST_CHECK_EQUAL( test_list.get_first(), nullptr );
      BOOST_CHECK_EQUAL( test_list.get_last(), nullptr );
      // BOOST_CHECK_NO_THROW( test_list.dump() );
      BOOST_CHECK( test_list.validate() );

      BOOST_CHECK_NO_THROW( test_list.push_back( &node1 ) );
      BOOST_CHECK_THROW( test_list.push_back( &node1 ), logic_error );  // Can't insert a node that's already in the test_list

      BOOST_CHECK_EQUAL( test_list.isEmpty(), false );
      BOOST_CHECK_EQUAL( test_list.size(), 1 );
      BOOST_CHECK_EQUAL( test_list.isIn( &node1 ), true );
      BOOST_CHECK_EQUAL( test_list.isSorted(), true );  // A test_list with only one thing should be sorted
      BOOST_CHECK_EQUAL( test_list.get_first(), &node1 );
      BOOST_CHECK_EQUAL( test_list.get_last(), &node1 );
      // BOOST_CHECK_NO_THROW( test_list.dump() );
      BOOST_CHECK( test_list.validate() );

      Node* node2;
      BOOST_CHECK_NO_THROW( node2 = test_list.pop_back() );

      BOOST_CHECK_EQUAL( test_list.isEmpty(), true );
      BOOST_CHECK_EQUAL( test_list.size(), 0 );
      BOOST_CHECK_EQUAL( test_list.isIn( node2 ), false );
      BOOST_CHECK_EQUAL( test_list.isSorted(), true );  // An empty test_list should be sorted
      BOOST_CHECK_EQUAL( test_list.get_first(), nullptr );
      BOOST_CHECK_EQUAL( test_list.get_last(), nullptr );
      // BOOST_CHECK_NO_THROW( test_list.dump() );
      BOOST_CHECK( test_list.validate() );

      BOOST_CHECK_NO_THROW( test_list.removeAll() ); // This is OK even if the test_list is empty
   }


   BOOST_FIXTURE_TEST_CASE( test_DoublyLinkedList_multi_insert_and_delete, DoublyLinkedListTestFixture ) {
      BOOST_CHECK( test_list.validate());

      for( int i = 0 ; i < 20 ; i++ ) {  // Test push_front() 20 times
         Node* node = new Node();

         BOOST_CHECK_EQUAL( test_list.size(), i );
         BOOST_CHECK_EQUAL( test_list.isIn( node ), false );

         BOOST_CHECK_NO_THROW( test_list.push_front( node ));
         BOOST_CHECK_THROW( test_list.push_front( node ), logic_error );  // Can't insert a node that's already in the test_list

         BOOST_CHECK_EQUAL( test_list.isEmpty(), false );
         BOOST_CHECK_EQUAL( test_list.isIn( node ), true );
         BOOST_CHECK_EQUAL( test_list.get_first(), node );
         BOOST_CHECK( test_list.validate());
      }

      for( int i = 19 ; i >= 0 ; i-- ) {  // Test pop_front() 20 times
         BOOST_CHECK_EQUAL( test_list.size(), i + 1 );

         Node* nodeBefore = test_list.get_first();
         Node* nodeAfter;
         BOOST_CHECK_EQUAL( test_list.isIn( nodeBefore ), true );
         BOOST_CHECK_NO_THROW( nodeAfter = test_list.pop_front() );
         BOOST_CHECK_EQUAL( nodeBefore, nodeAfter );
         BOOST_CHECK_EQUAL( test_list.isIn( nodeBefore), false );
         BOOST_CHECK_EQUAL( test_list.size(), i );
         BOOST_CHECK_EQUAL( test_list.get_next( nodeAfter ), nullptr );
         BOOST_CHECK_EQUAL( test_list.get_prev( nodeAfter ), nullptr );
      }

      for( int i = 0 ; i < 20 ; i++ ) {  // Test push_back() 20 times
         Node* node = new Node();

         BOOST_CHECK_EQUAL( test_list.size(), i );
         BOOST_CHECK_EQUAL( test_list.isIn( node ), false );

         BOOST_CHECK_NO_THROW( test_list.push_back( node ));
         BOOST_CHECK_THROW( test_list.push_back( node ), logic_error );  // Can't insert a node that's already in the test_list

         BOOST_CHECK_EQUAL( test_list.isEmpty(), false );
         BOOST_CHECK_EQUAL( test_list.isIn( node ), true );
         BOOST_CHECK_EQUAL( test_list.get_last(), node );
         BOOST_CHECK( test_list.validate());
      }

      for( int i = 19 ; i >= 0 ; i-- ) {  // Test pop_back() 20 times
         BOOST_CHECK_EQUAL( test_list.size(), i + 1 );

         Node* nodeBefore = test_list.get_last();
         Node* nodeAfter;
         BOOST_CHECK_EQUAL( test_list.isIn( nodeBefore ), true );
         BOOST_CHECK_NO_THROW( nodeAfter = test_list.pop_back() );
         BOOST_CHECK_EQUAL( nodeBefore, nodeAfter );
         BOOST_CHECK_EQUAL( test_list.isIn( nodeBefore), false );
         BOOST_CHECK_EQUAL( test_list.size(), i );
         BOOST_CHECK_EQUAL( test_list.get_next( nodeAfter ), nullptr );
         BOOST_CHECK_EQUAL( test_list.get_prev( nodeAfter ), nullptr );
      }

      // BOOST_CHECK_NO_THROW( test_list.dump());

      BOOST_CHECK_EQUAL( test_list.isEmpty(), true );
      BOOST_CHECK_EQUAL( test_list.size(), 0 );
      BOOST_CHECK_EQUAL( test_list.isSorted(), true );  // An empty test_list should be sorted
      BOOST_CHECK_EQUAL( test_list.get_first(), nullptr );
      BOOST_CHECK_EQUAL( test_list.get_last(), nullptr );
      // BOOST_CHECK_NO_THROW( test_list.dump());
      BOOST_CHECK( test_list.validate());

      BOOST_CHECK_NO_THROW( test_list.removeAll());
      BOOST_CHECK( test_list.validate());
   }


   BOOST_FIXTURE_TEST_CASE( test_DoublyLinkedList_insert_before_and_after, DoublyLinkedListTestFixture ) {
      Node nodeFirst;         // Instantiate a node
      test_list.push_front( &nodeFirst ) ;

      BOOST_CHECK( test_list.validate() );

      for( int i = 0 ; i < 20 ; i++ ) {  // Test insert_after() 20 times
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
         BOOST_CHECK_EQUAL( test_list.isEmpty(), false );
         BOOST_CHECK_EQUAL( test_list.isIn( node ), true );
         BOOST_CHECK( test_list.validate() );
      }

      {
         Node* node = new Node();  // This is the node we are going to insert

         BOOST_CHECK_NO_THROW( test_list.insert_after( test_list.get_last(), node ));  // Try an insert_after at the end of the test_list
      }

      BOOST_CHECK( test_list.validate() );

      for( int i = 0 ; i < 20 ; i++ ) {  // Test insert_before() 20 times
         Node* node = new Node();  // This is the node we are going to insert

         int position = rand() % test_list.size();
         Node* insertAt = test_list.get_last();
         for( int j = 0 ; j < position ; j++ ) {
            insertAt = test_list.get_prev( insertAt );
         }

         BOOST_CHECK_NO_THROW( test_list.insert_before( insertAt, node ) );
         BOOST_CHECK_THROW( test_list.insert_before( insertAt, node ), logic_error );  // Can't insert a node that's already in the test_list
         BOOST_CHECK_THROW( test_list.insert_before( node, node ), logic_error );  // Can't insert a node that's already in the test_list

         BOOST_CHECK_EQUAL( test_list.size(), i + 23 );  // Initial node + 20 new nodes + 1 node at the end + this node
         BOOST_CHECK_EQUAL( test_list.isEmpty(), false );
         BOOST_CHECK_EQUAL( test_list.isIn( node ), true );
         BOOST_CHECK( test_list.validate() );
      }

      {
         Node* node = new Node();  // This is the node we are going to insert

         BOOST_CHECK_NO_THROW( test_list.insert_before( test_list.get_first(), node ));  // Try an insert_before at the beginning of the test_list
      }

      BOOST_CHECK_NO_THROW( test_list.removeAll() ); // This is the primary / big test for removeAll()

      BOOST_CHECK_EQUAL( test_list.isEmpty(), true );
      BOOST_CHECK_EQUAL( test_list.size(), 0 );
      BOOST_CHECK_EQUAL( test_list.isSorted(), true );  // An empty test_list should be sorted
      BOOST_CHECK_EQUAL( test_list.get_first(), nullptr );
      // BOOST_CHECK_NO_THROW( test_list.dump() );
      BOOST_CHECK( test_list.validate() );

      BOOST_CHECK_NO_THROW( test_list.removeAll());  // Doesn't break on an empty test_list
      BOOST_CHECK( test_list.validate() );
   }


   BOOST_FIXTURE_TEST_CASE( test_DoublyLinkedList_swap, DoublyLinkedListTestFixture ) {
      Node* cat1 = new Node();
      Node* cat2 = new Node();
      Node* cat3 = new Node();
      Node* cat4 = new Node();
      Node* cat5 = new Node();

      // One item in test_list
      BOOST_CHECK_NO_THROW( test_list.push_front( cat1 ) );
      BOOST_CHECK_NO_THROW( test_list.swap( cat1, cat1 ) );
      BOOST_CHECK( test_list.validate() );

      // Two items in test_list
      BOOST_CHECK_NO_THROW( test_list.push_back( cat2 ) );
      BOOST_CHECK_EQUAL( test_list.get_first(), cat1 );
      BOOST_CHECK_EQUAL( test_list.get_last(), cat2 );
      // test_list.dump();
      BOOST_CHECK_NO_THROW( test_list.swap( cat1, cat2 ) );
      // test_list.dump();
      BOOST_CHECK( test_list.validate() );
      BOOST_CHECK_EQUAL( test_list.get_first(), cat2 );
      BOOST_CHECK_EQUAL( test_list.get_last(), cat1 );
      BOOST_CHECK_NO_THROW( test_list.swap( test_list.get_first(), test_list.get_last() ));
      BOOST_CHECK_EQUAL( test_list.get_first(), cat1 );
      BOOST_CHECK_EQUAL( test_list.get_last(), cat2 );

      // Three items in test_list
      BOOST_CHECK_NO_THROW( test_list.push_back( cat3 ) );   // 1 2 3
      BOOST_CHECK_NO_THROW( test_list.swap( test_list.get_first(), test_list.get_next( test_list.get_first() ))) ;  // 2 1 3
      BOOST_CHECK( test_list.validate() );
      BOOST_CHECK_NO_THROW( test_list.swap( test_list.get_first(), test_list.get_last() ));  // 3 1 2
      BOOST_CHECK( test_list.validate() );
      BOOST_CHECK_NO_THROW( test_list.swap( test_list.get_next( test_list.get_first() ), test_list.get_last() ));  // 3 2 1
      BOOST_CHECK( test_list.validate() );
      BOOST_CHECK_NO_THROW( test_list.swap( test_list.get_first(), test_list.get_last() ));  // 1 2 3
      BOOST_CHECK( test_list.validate() );
      BOOST_CHECK_EQUAL( test_list.get_first(), cat1 );
      BOOST_CHECK_EQUAL( test_list.get_next( test_list.get_first()), cat2 );
      BOOST_CHECK_EQUAL( test_list.get_last(), cat3 );

      // Four items in test_list
      BOOST_CHECK_NO_THROW( test_list.push_back( cat4 ) );  // 1 2 3 4
      BOOST_CHECK_NO_THROW( test_list.swap( test_list.get_first(), test_list.get_next( test_list.get_first() ))) ;  // 2 1 3 4
      BOOST_CHECK( test_list.validate() );
      BOOST_CHECK_NO_THROW( test_list.swap( test_list.get_prev( test_list.get_last() ), test_list.get_last() ));    // 2 1 4 3
      BOOST_CHECK( test_list.validate() );
      BOOST_CHECK_NO_THROW( test_list.swap( test_list.get_first(), test_list.get_last() ));                    // 3 1 4 2
      BOOST_CHECK( test_list.validate() );
      BOOST_CHECK_NO_THROW( test_list.swap( test_list.get_next( test_list.get_first() ), test_list.get_prev( test_list.get_last() ))); // 3 4 1 2
      BOOST_CHECK( test_list.validate() );
      BOOST_CHECK_EQUAL( test_list.get_first(), cat3 );
      BOOST_CHECK_EQUAL( test_list.get_next( test_list.get_first()), cat4 );
      BOOST_CHECK_EQUAL( test_list.get_prev( test_list.get_last()), cat1 );
      BOOST_CHECK_EQUAL( test_list.get_last(), cat2 );

      // Five items in test_list
      BOOST_CHECK_NO_THROW( test_list.push_back( cat5 ) );  // 3 4 1 2 5
      BOOST_CHECK_NO_THROW( test_list.swap( test_list.get_first(), test_list.get_next( test_list.get_first() ))) ;  // 4 3 1 2 5
      BOOST_CHECK( test_list.validate() );
      BOOST_CHECK_NO_THROW( test_list.swap( test_list.get_next( test_list.get_first() ), test_list.get_next( test_list.get_next( test_list.get_first() )) )); // 4 1 3 2 5
      BOOST_CHECK( test_list.validate() );
      BOOST_CHECK_NO_THROW( test_list.swap( test_list.get_next( test_list.get_next( test_list.get_first() )), test_list.get_prev( test_list.get_last() ) ));  // 4 1 2 3 5
      BOOST_CHECK( test_list.validate() );
      BOOST_CHECK_NO_THROW( test_list.swap( test_list.get_prev( test_list.get_last() ), test_list.get_last() ));    // 4 1 2 5 3
      BOOST_CHECK( test_list.validate() );
      BOOST_CHECK_EQUAL( test_list.get_first(), cat4 );
      BOOST_CHECK_EQUAL( test_list.get_next( test_list.get_first()), cat1 );
      BOOST_CHECK_EQUAL( test_list.get_next( test_list.get_next( test_list.get_first() )), cat2 );
      BOOST_CHECK_EQUAL( test_list.get_prev( test_list.get_last()), cat5 );
      BOOST_CHECK_EQUAL( test_list.get_last(), cat3 );

      BOOST_CHECK_NO_THROW( test_list.removeAll());  // Doesn't break on an empty test_list
      BOOST_CHECK( test_list.validate() );
   }


   BOOST_FIXTURE_TEST_CASE( test_DoublyLinkedList_insertion_sort, DoublyLinkedListTestFixture ) {
      Node* cat1 = new Node();
      Node* cat2 = new Node();
      Node* cat3 = new Node();
      Node* cat4 = new Node();
      Node* cat5 = new Node();

      // Sort an empty list
      BOOST_CHECK_NO_THROW( test_list.insertionSort() );
      BOOST_CHECK( test_list.isSorted() );

      // Sort one item in list
      BOOST_CHECK_NO_THROW( test_list.push_front( cat1 ) );
      BOOST_CHECK( test_list.isSorted() );
      BOOST_CHECK_NO_THROW( test_list.insertionSort() );
      BOOST_CHECK( test_list.isSorted() );

      // Two items in list
      BOOST_CHECK_NO_THROW( test_list.push_front( cat2 ) );
      BOOST_CHECK_NO_THROW( test_list.insertionSort() );
      BOOST_CHECK( test_list.isSorted() );

      // Three items in list
      BOOST_CHECK_NO_THROW( test_list.push_front( cat3 ) );
      BOOST_CHECK_NO_THROW( test_list.insertionSort() );
      BOOST_CHECK( test_list.isSorted() );

      // Four items in list
      BOOST_CHECK_NO_THROW( test_list.push_front( cat4 ) );
      BOOST_CHECK_NO_THROW( test_list.insertionSort() );
      BOOST_CHECK( test_list.isSorted() );

      // Five items in list
      BOOST_CHECK_NO_THROW( test_list.push_front( cat5 ) );
      BOOST_CHECK_NO_THROW( test_list.insertionSort() );
      BOOST_CHECK( test_list.isSorted() );

      for( int i = 0 ; i < 10 ; i++ ) {  // Outer loop
         DoublyLinkedList dll;
         for( int j = 0 ; j < 100 ; j++ ) {
            dll.push_front( &AnimalFactory::generateAnimal() );
            // BOOST_CHECK_NO_THROW( dll.push_front( &Cat::newRandomAnimal() ));
         }
         BOOST_CHECK( dll.validate() );
         BOOST_CHECK_EQUAL( dll.size(), 100 );
         BOOST_CHECK( !dll.isSorted() );

         BOOST_CHECK_NO_THROW( dll.insertionSort() );
         BOOST_CHECK( dll.isSorted() );

         for( int j = 0 ; j < 50 ; j++ ) {
            delete dll.pop_front();
            delete dll.pop_back();
         }

         // cout << ".";
         // cout << std::flush;
      }
      // cout << endl;
   }

BOOST_AUTO_TEST_SUITE_END()
