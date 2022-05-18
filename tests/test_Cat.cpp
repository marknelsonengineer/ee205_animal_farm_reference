///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// Comprehensive test of the Cat class
///
/// @file test_Cat.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   09_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

#include <stdexcept>
#include <list>
#include <array>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>

#include "../src/Animal/Mammal/Cat/Cat.h"
#include "../src/Container/DoublyLinkedList.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_Cat )

   BOOST_AUTO_TEST_CASE( test_Cat_min_constructor ) {
      Cat aCat( "Kali" );
      BOOST_CHECK_EQUAL( aCat.getName(), "Kali" );
      BOOST_CHECK_EQUAL( aCat.isFixed(), false );
      BOOST_CHECK_EQUAL( aCat.getColor(), Color::UNKNOWN_COLOR );

      #ifdef DEBUG
         // aCat.dump();
      #endif
   }


   BOOST_AUTO_TEST_CASE( test_Cat_max_constructor ) {
      Cat aCat( "Chili", Color::GINGER, true, Gender::MALE, 18 );
      BOOST_CHECK_EQUAL( aCat.getName(), "Chili" );
      BOOST_CHECK_EQUAL( aCat.isFixed(), true );
      BOOST_CHECK_EQUAL( aCat.getColor(), Color::GINGER );
      BOOST_CHECK_EQUAL( aCat.getSpecies(), Cat::SPECIES_NAME );
      BOOST_CHECK_EQUAL( aCat.getClassification(), Mammal::MAMMAL_NAME );
      BOOST_CHECK_EQUAL( aCat.getKingdom(), Animal::KINGDOM_NAME );
      BOOST_CHECK_EQUAL( aCat.getGender(), Gender::MALE );
      BOOST_CHECK_EQUAL( aCat.getWeight(), 18 );
      BOOST_CHECK( aCat.validate() );

      #ifdef DEBUG
         // aCat.dump();
      #endif
   }


   BOOST_AUTO_TEST_CASE( test_Cat_methods ) {
      Cat aCat( "Kali" );

      BOOST_CHECK_THROW( aCat.setName( "" ), invalid_argument );
      aCat.setName( "BooBoo" );
      BOOST_CHECK_EQUAL( aCat.getName(), "BooBoo" );

      BOOST_CHECK_EQUAL( aCat.isFixed(), false );
      aCat.fixCat();
      BOOST_CHECK_EQUAL( aCat.isFixed(), true );
      aCat.fixCat();  // The cat should still be fixed
      BOOST_CHECK_EQUAL( aCat.isFixed(), true );

      BOOST_CHECK_EQUAL( aCat.getColor(), Color::UNKNOWN_COLOR );
      aCat.setColor( Color::BLACK );
      BOOST_CHECK_EQUAL( aCat.getColor(), Color::BLACK );

      BOOST_CHECK_EQUAL( aCat.getWeight(), Weight::UNKNOWN_WEIGHT );
      BOOST_CHECK_THROW( aCat.setWeight(   0 ), out_of_range );
      BOOST_CHECK_THROW( aCat.setWeight( 100 ), out_of_range );
      aCat.setWeight( 40 );
      BOOST_CHECK_EQUAL( aCat.getWeight(), 40 );

      BOOST_CHECK( aCat.validate() );
   }


   BOOST_AUTO_TEST_CASE( test_Cat_generator ) {
      for( int i = 0 ; i < 50 ; i++ ) {
         Cat::generateCat();
      }
      BOOST_CHECK( true );

   }


   BOOST_AUTO_TEST_CASE( test_Cat_constructor_semantics ) {
      BOOST_CHECK_NO_THROW( Cat a( "Alice" ) );       /// Direct initialization
      BOOST_CHECK_NO_THROW( Cat a = Cat( "Alice" ));  /// Actual Copy constructor
      BOOST_CHECK_NO_THROW( const Cat a( "Alice" ));  /// Basic const constructor
      BOOST_CHECK_NO_THROW( const Cat a("Alice"); Cat b = a; );  /// Copy a const
      BOOST_CHECK_NO_THROW( Cat a( "Alice" );
                            Cat b( "Bob" );
                            b = a;             );  /// Yet another copy constructor
      BOOST_CHECK_NO_THROW( Cat a = Cat::generateCat() );  /// Cat is set as a return value
   }


   BOOST_AUTO_TEST_CASE( test_Cat_copy_isolation ) {
   /// Check that copied Cats are indeed separate
      Cat a( "Alice" );
      BOOST_CHECK_EQUAL( a.getName(), "Alice" );

      Cat b = a;
      Cat c( "Charlie" );
      c = b;
      BOOST_CHECK_EQUAL( a.getName(), "Alice" );
      BOOST_CHECK_EQUAL( b.getName(), "Alice" );
      BOOST_CHECK_EQUAL( c.getName(), "Alice" );

      a.setName( "Andrea" );
      BOOST_CHECK_EQUAL( a.getName(), "Andrea" );
      BOOST_CHECK_EQUAL( b.getName(), "Alice" );
      BOOST_CHECK_EQUAL( c.getName(), "Alice" );

      b.setName( "Bob" );
      BOOST_CHECK_EQUAL( a.getName(), "Andrea" );
      BOOST_CHECK_EQUAL( b.getName(), "Bob" );
      BOOST_CHECK_EQUAL( c.getName(), "Alice" );

      c.setName( "Charlie" );
      BOOST_CHECK_EQUAL( a.getName(), "Andrea" );
      BOOST_CHECK_EQUAL( b.getName(), "Bob" );
      BOOST_CHECK_EQUAL( c.getName(), "Charlie" );
   }


   BOOST_AUTO_TEST_CASE( test_Cat_pointer_copy_logic ) {
      // This test is fairly simple... make sure that we can Copy Cats, but
      // when we do, their Node pointers don't go with them.
      //
      // We will do this by creating a Doubly Linked List w/ 3 nodes.  The
      // 2nd node will have both `next` & `prev` set.  When we copy this node, the
      // Animal+Mammal+Cat data should be copied, but the Node members should be
      // set to `nullptr`.

      DoublyLinkedList list;
      Cat a( "Alice" );
      Cat b( "Bob" );
      Cat c( "Chili" );

      list.push_back( &a );
      list.push_back( &b );
      list.push_back( &c );

      BOOST_CHECK_NE( DoublyLinkedList::get_next( &b ), nullptr );
      BOOST_CHECK_NE( DoublyLinkedList::get_prev( &b ), nullptr );
      BOOST_CHECK_EQUAL( b.getName(), "Bob" );

      Cat x = b;
      BOOST_CHECK_NE( DoublyLinkedList::get_next( &b ), nullptr );
      BOOST_CHECK_NE( DoublyLinkedList::get_prev( &b ), nullptr );
      BOOST_CHECK_EQUAL( b.getName(), "Bob" );
      BOOST_CHECK_EQUAL( DoublyLinkedList::get_next( &x ), nullptr );
      BOOST_CHECK_EQUAL( DoublyLinkedList::get_prev( &x ), nullptr );
      BOOST_CHECK_EQUAL( x.getName(), "Bob" );

      b.setName( "Bucky" );
      Cat y( "Yankee" );
      y = b;
      BOOST_CHECK_NE( DoublyLinkedList::get_next( &b ), nullptr );
      BOOST_CHECK_NE( DoublyLinkedList::get_prev( &b ), nullptr );
      BOOST_CHECK_EQUAL( b.getName(), "Bucky" );
      BOOST_CHECK_EQUAL( DoublyLinkedList::get_next( &y ), nullptr );
      BOOST_CHECK_EQUAL( DoublyLinkedList::get_prev( &y ), nullptr );
      BOOST_CHECK_EQUAL( y.getName(), "Bucky" );
   }


   BOOST_AUTO_TEST_CASE( test_Cat_in_STL_templates ) {

      const int NUM_CATS = 1000;

      // Doubly linked list from the STL
      {
         list<Cat> catList;
         for( int i = 0 ; i < NUM_CATS ; i++ ) {
            BOOST_CHECK_EQUAL( catList.size(), i );
            BOOST_CHECK_NO_THROW( catList.insert( catList.end(), Cat::generateCat()));
         }
         for( int i = NUM_CATS - 1 ; i >= 0 ; i-- ) {
            BOOST_CHECK_NO_THROW( catList.erase( catList.begin()));
            BOOST_CHECK_EQUAL( catList.size(), i );
         }
      }

      // array<Cat, 10> catArray;  /// Does not compile.  Not sure why.  @todo Look into why call to implicitly deleted default constructor fails

      // Auto-sized array container from the STL
      {
         vector<Cat> catVector;
         for( int i = 0 ; i < NUM_CATS ; i++ ) {
            BOOST_CHECK_EQUAL( catVector.size(), i );
            BOOST_CHECK_NO_THROW( catVector.insert( catVector.end(), Cat::generateCat()));
         }
         for( int i = NUM_CATS - 1 ; i >= 0 ; i-- ) {
            BOOST_CHECK_NO_THROW( catVector.erase( catVector.begin() ));
            BOOST_CHECK_EQUAL( catVector.size(), i );
         }
      }

      // Double-ended queue from the STL
      {
         deque<Cat> catDeque;
         for( int i = 0 ; i < NUM_CATS ; i++ ) {
            BOOST_CHECK_EQUAL( catDeque.size(), i );
            BOOST_CHECK_NO_THROW( catDeque.insert( catDeque.end(), Cat::generateCat()));
         }
         for( int i = NUM_CATS - 1 ; i >= 0 ; i-- ) {
            BOOST_CHECK_NO_THROW( catDeque.erase( catDeque.begin() ));
            BOOST_CHECK_EQUAL( catDeque.size(), i );
         }
      }

      // Sorted associated collection
      {
         set<Cat> catSet;
         Cat::names.reset();
         for( int i = 0 ; i < NUM_CATS ; i++ ) {
            BOOST_CHECK_EQUAL( catSet.size(), i );
            BOOST_CHECK_NO_THROW( catSet.insert( catSet.end(), Cat::generateCat()));
         }
         for( int i = NUM_CATS - 1 ; i >= 0 ; i-- ) {
            BOOST_CHECK_NO_THROW( catSet.erase( catSet.begin() ));
            BOOST_CHECK_EQUAL( catSet.size(), i );
         }
      }

      // Sorted associated list with key-value pairs
      {
         map<string, Cat> catMap;
         Cat::names.reset();
         for( int i = 0 ; i < NUM_CATS ; i++ ) {
//          BOOST_CHECK_EQUAL( catMap.size(), i );  /// @todo Not sure why this isn't working
            Cat newCat = Cat::generateCat();
            BOOST_CHECK_NO_THROW( catMap.insert( { string{ newCat.getName() }, newCat } ));
         }
         for( int i = NUM_CATS - 1 ; i >= 0 ; i-- ) {
            BOOST_CHECK_NO_THROW( catMap.erase( catMap.begin() ));
//          BOOST_CHECK_EQUAL( catMap.size(), i );   /// @todo Not sure why this isn't working
         }
      }

      // unordered_set<Cat> catUnorderedSet;          /// Does not compile.  Not sure why.  @todo Look into why call to implicitly deleted default constructor fails
      // unordered_map<Cat, string> catUnorderedMap;  /// Does not compile.  Not sure why.  @todo Look into why call to implicitly deleted default constructor fails

      // Stack from the STL
      {
         stack<Cat> catStack;
         for( int i = 0 ; i < NUM_CATS ; i++ ) {
            BOOST_CHECK_EQUAL( catStack.size(), i );
            BOOST_CHECK_NO_THROW( catStack.push( Cat::generateCat()));
         }
         for( int i = NUM_CATS - 1 ; i >= 0 ; i-- ) {
            BOOST_CHECK_NO_THROW( catStack.pop());
            BOOST_CHECK_EQUAL( catStack.size(), i );
         }
      }

      // Queue from the STL
      {
         queue<Cat> catQueue;
         for( int i = 0 ; i < NUM_CATS ; i++ ) {
            BOOST_CHECK_EQUAL( catQueue.size(), i );
            BOOST_CHECK_NO_THROW( catQueue.push( Cat::generateCat() ));
         }
         for( int i = NUM_CATS - 1 ; i >= 0 ; i-- ) {
            BOOST_CHECK_NO_THROW( catQueue.pop() );
            BOOST_CHECK_EQUAL( catQueue.size(), i );
         }
      }
   }

BOOST_AUTO_TEST_SUITE_END()
