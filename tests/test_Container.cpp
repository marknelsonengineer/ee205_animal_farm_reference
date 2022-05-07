///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// Comprehensive test of the Container class
///
/// @file test_Container.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <stdexcept>

#include "../src/Container/Container.h"
#include "../src/Container/SinglyLinkedList.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_Container )

   BOOST_AUTO_TEST_CASE( test_Node ) {
      Node aNode;
      BOOST_CHECK_EQUAL( aNode.next, nullptr );
      BOOST_CHECK_EQUAL( aNode.prev, nullptr );
      BOOST_CHECK_EQUAL( aNode.left, nullptr );
      BOOST_CHECK_EQUAL( aNode.right, nullptr );

      aNode.next = &aNode;
      aNode.prev = &aNode;
      aNode.left = &aNode;
      aNode.right = &aNode;

      BOOST_CHECK_EQUAL( aNode.next, &aNode );
      BOOST_CHECK_EQUAL( aNode.prev, &aNode );
      BOOST_CHECK_EQUAL( aNode.left, &aNode );
      BOOST_CHECK_EQUAL( aNode.right, &aNode );

      aNode.reset();

      BOOST_CHECK_EQUAL( aNode.next, nullptr );
      BOOST_CHECK_EQUAL( aNode.prev, nullptr );
      BOOST_CHECK_EQUAL( aNode.left, nullptr );
      BOOST_CHECK_EQUAL( aNode.right, nullptr );
   }

   BOOST_AUTO_TEST_CASE( test_Container ) {
      Container testContainer;
      Node aNode;

      BOOST_CHECK_EQUAL( testContainer.empty(), true );
      BOOST_CHECK_EQUAL( testContainer.size(), 0 );
      BOOST_CHECK_EQUAL( testContainer.isIn( &aNode ), false );
      BOOST_CHECK_THROW( testContainer.isIn( nullptr ), invalid_argument );
      BOOST_CHECK_EQUAL( testContainer.validate(), true );
      // BOOST_CHECK_NO_THROW( testContainer.dump() );
   }

   BOOST_AUTO_TEST_CASE( test_Container_constructor_semantics ) {
      // Code that is commented out should not compile
      BOOST_CHECK_NO_THROW( SinglyLinkedList a; );    /// Default constructor
      // BOOST_CHECK_NO_THROW( SinglyLinkedList a = SinglyLinkedList(); );  /// Actual Copy constructor
      BOOST_CHECK_NO_THROW( const SinglyLinkedList a; );  /// Basic const constructor
      // BOOST_CHECK_NO_THROW( const SinglyLinkedList a; Cat b = a; );  /// Copy a const
      // BOOST_CHECK_NO_THROW( SinglyLinkedList a;
      //                       SinglyLinkedList b;
      //                       b = a;             );  /// Yet another copy constructor
   }

BOOST_AUTO_TEST_SUITE_END()
