///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// Comprehensive test of the Tree class
///
/// @file test_Tree.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <stdexcept>

#include "../src/Container/Tree.h"
#include "../src/Animal/Cat.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_Tree )

   BOOST_AUTO_TEST_CASE( test_empty_Tree ) {
   	Tree testTree;  /// @todo Move into a test fixture

   	BOOST_CHECK_EQUAL( testTree.empty(), true );
   	BOOST_CHECK_EQUAL( testTree.size(), 0 );
   	BOOST_CHECK_EQUAL( testTree.validate(), true );
   	BOOST_CHECK_NO_THROW( testTree.dump());
   }


   BOOST_AUTO_TEST_CASE( test_insert_Tree ) {
   	Tree testTree;

   	BOOST_CHECK_THROW( testTree.insert( nullptr ), invalid_argument );

   	for( int i = 0 ; i < 100 ; i++ ) {
   		Cat& aCat = Cat::generateCat();
   		BOOST_CHECK_NO_THROW( testTree.insert( &aCat ));
   		BOOST_CHECK_THROW( testTree.insert( &aCat ), logic_error );
   		BOOST_CHECK_EQUAL( testTree.empty(), false );
   		BOOST_CHECK_EQUAL( testTree.size(), i+1 );
   		BOOST_CHECK_EQUAL( testTree.isIn( &aCat ), true );
   		BOOST_CHECK_EQUAL( testTree.validate(), true );
   	}

   	// testTree.dump();
   }


   BOOST_AUTO_TEST_CASE( test_erase_from_Tree ) {
      Tree testTree;  /// @todo Move into a test fixture

   }

BOOST_AUTO_TEST_SUITE_END()
