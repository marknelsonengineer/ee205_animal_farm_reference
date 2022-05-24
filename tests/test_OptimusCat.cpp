///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// Comprehensive test of the OptimusCat performance analyzer
///
/// @file test_OptimusCat.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   23_May_2022
///////////////////////////////////////////////////////////////////////////////
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include "../src/Animal/AnimalFactory.h"
#include "../src/Container/SinglyLinkedList.h"
#include "../src/Container/DoublyLinkedList.h"
#include "../src/Container/BinarySearchTree.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_OptimusCat )

   BOOST_AUTO_TEST_CASE( test_Basic_add_and_remove ) {
      SinglyLinkedList singlyLinkedList;
      DoublyLinkedList doublyLinkedList;
      BinarySearchTree binarySearchTree;

      for( int i = 0 ; i < 255 ; i++ ) {
         BOOST_CHECK_NO_THROW( singlyLinkedList.add( &AnimalFactory::newRandomAnimal() ));
         BOOST_CHECK_NO_THROW( doublyLinkedList.add( &AnimalFactory::newRandomAnimal() ));
         BOOST_CHECK_NO_THROW( binarySearchTree.add( &AnimalFactory::newRandomAnimal() ));
      }

      BOOST_CHECK_EQUAL( singlyLinkedList.size(), 255 );
      BOOST_CHECK_EQUAL( doublyLinkedList.size(), 255 );
      BOOST_CHECK_EQUAL( binarySearchTree.size(), 255 );

      for( int i = 0 ; i < 200 ; i++ ) {
         /// @todo Add getRandomAnimal()
         BOOST_CHECK_NO_THROW( singlyLinkedList.remove( singlyLinkedList.getRandomNode() ));
         BOOST_CHECK_NO_THROW( doublyLinkedList.remove( doublyLinkedList.getRandomNode() ));
         BOOST_CHECK_NO_THROW( binarySearchTree.remove( binarySearchTree.getRandomNode() ));
      }

      BOOST_CHECK_NO_THROW( singlyLinkedList.removeAll() );
      BOOST_CHECK_NO_THROW( doublyLinkedList.removeAll() );
      BOOST_CHECK_NO_THROW( binarySearchTree.removeAll() );

      BOOST_CHECK_EQUAL( singlyLinkedList.size(), 0 );
      BOOST_CHECK_EQUAL( doublyLinkedList.size(), 0 );
      BOOST_CHECK_EQUAL( binarySearchTree.size(), 0 );
   }

BOOST_AUTO_TEST_SUITE_END()
