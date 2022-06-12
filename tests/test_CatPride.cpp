///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// Comprehensive test of the CatPride static Array class
///
/// @file test_CatPride.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_May_2022
///////////////////////////////////////////////////////////////////////////////
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include "../src/Animal/Mammal/Cat/CatPride.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_CatPride )

   BOOST_AUTO_TEST_CASE( test_constructor ) {
      CatPride testArray;

      BOOST_CHECK_EQUAL( testArray.size(), 0 );
      BOOST_CHECK_EQUAL( testArray.isEmpty(), true );
      BOOST_CHECK_EQUAL( testArray.isFull(), false );
      BOOST_CHECK_EQUAL( testArray.getMaxSize(), CatPride::MAX_CATS );
      BOOST_CHECK_EQUAL( testArray.validate(), true );
      BOOST_CHECK_NO_THROW( testArray.removeAll() );
      BOOST_CHECK_THROW( testArray[0], out_of_range );
   }

   // cat1 is the cat we are testing
   // cat2 is a reference cat
   void compareCat( Cat* cat1, Cat* cat2 ) {
      BOOST_CHECK_EQUAL( cat1->getName(), cat2->getName() );
      BOOST_CHECK_EQUAL( cat1->getKingdom(), Animal::KINGDOM_NAME );
      BOOST_CHECK_EQUAL( cat1->getClassification(), Mammal::CLASSIFICATION_NAME );
      BOOST_CHECK_EQUAL( cat1->getSpecies(), Cat::SPECIES_NAME );
      BOOST_CHECK_EQUAL( cat1->getWeight(), cat2->getWeight() );
      BOOST_CHECK_EQUAL( cat1->getGender(), cat2->getGender() );
      BOOST_CHECK_EQUAL( cat1->getColor(), cat2->getColor() );
   }

   void validateArray( CatPride* testArray, Cat* cat1, Cat* cat2, Cat* cat3, Cat* cat4 ) {
      Cat catX { "Xander", Color::CALICO, true, Gender::FEMALE, 1.2 };
      BOOST_CHECK_EQUAL( testArray->isIn( &catX ), false );
      BOOST_CHECK_EQUAL( testArray->validate(), true );

      if( cat1 == nullptr && cat2 == nullptr && cat3 == nullptr && cat4 == nullptr ) {
         BOOST_CHECK_EQUAL( testArray->size(), 0 );
         BOOST_CHECK_EQUAL( testArray->isEmpty(), true );
         BOOST_CHECK_EQUAL( testArray->isFull(), false );
         return;
      }

      if( cat1 != nullptr && cat2 == nullptr && cat3 == nullptr && cat4 == nullptr ) {
         BOOST_CHECK_EQUAL( testArray->size(), 1 );
         BOOST_CHECK_EQUAL( testArray->isEmpty(), false );
         BOOST_CHECK_EQUAL( testArray->isFull(), false );
         compareCat( &(*testArray)[0], cat1 );
         BOOST_CHECK_EQUAL( testArray->isIn( &(*testArray)[0] ), true );

         BOOST_CHECK_THROW( (*testArray)[1], out_of_range );
         BOOST_CHECK_THROW( (*testArray)[2], out_of_range );
         BOOST_CHECK_THROW( (*testArray)[3], out_of_range );
         return;
      }

      if( cat1 != nullptr && cat2 != nullptr && cat3 == nullptr && cat4 == nullptr ) {
         BOOST_CHECK_EQUAL( testArray->size(), 2 );
         BOOST_CHECK_EQUAL( testArray->isEmpty(), false );
         BOOST_CHECK_EQUAL( testArray->isFull(), false );
         compareCat( &(*testArray)[0], cat1 );
         BOOST_CHECK_EQUAL( testArray->isIn( &(*testArray)[0] ), true );
         compareCat( &(*testArray)[1], cat2 );
         BOOST_CHECK_EQUAL( testArray->isIn( &(*testArray)[1] ), true );

         BOOST_CHECK_THROW( (*testArray)[2], out_of_range );
         BOOST_CHECK_THROW( (*testArray)[3], out_of_range );
         return;
      }

      if( cat1 != nullptr && cat2 != nullptr && cat3 != nullptr && cat4 == nullptr ) {
         BOOST_CHECK_EQUAL( testArray->size(), 3 );
         BOOST_CHECK_EQUAL( testArray->isEmpty(), false );
         BOOST_CHECK_EQUAL( testArray->isFull(), false );
         compareCat( &(*testArray)[0], cat1 );
         BOOST_CHECK_EQUAL( testArray->isIn( &(*testArray)[0] ), true );
         compareCat( &(*testArray)[1], cat2 );
         BOOST_CHECK_EQUAL( testArray->isIn( &(*testArray)[1] ), true );
         compareCat( &(*testArray)[2], cat3 );
         BOOST_CHECK_EQUAL( testArray->isIn( &(*testArray)[2] ), true );

         BOOST_CHECK_THROW( (*testArray)[3], out_of_range );
         return;
      }

      if( cat1 != nullptr && cat2 != nullptr && cat3 != nullptr && cat4 != nullptr ) {
         BOOST_CHECK_EQUAL( testArray->size(), 4 );
         BOOST_CHECK_EQUAL( testArray->isEmpty(), false );
         BOOST_CHECK_EQUAL( testArray->isFull(), true );
         compareCat( &(*testArray)[0], cat1 );
         BOOST_CHECK_EQUAL( testArray->isIn( &(*testArray)[0] ), true );
         compareCat( &(*testArray)[1], cat2 );
         BOOST_CHECK_EQUAL( testArray->isIn( &(*testArray)[1] ), true );
         compareCat( &(*testArray)[2], cat3 );
         BOOST_CHECK_EQUAL( testArray->isIn( &(*testArray)[2] ), true );
         compareCat( &(*testArray)[3], cat4 );
         BOOST_CHECK_EQUAL( testArray->isIn( &(*testArray)[3] ), true );
         return;
      }

      BOOST_FAIL( "The test should never get here" );
   }

   BOOST_AUTO_TEST_CASE( test_add_cat ) {
      CatPride testArray;

      validateArray( &testArray, nullptr, nullptr, nullptr, nullptr );

      Cat cat1 { "Abel", Color::CALICO, true, Gender::FEMALE, 1.2 };
      BOOST_CHECK_NO_THROW( testArray.add( &cat1 ) );
      validateArray( &testArray, &cat1, nullptr, nullptr, nullptr );

      Cat cat2 { "Beno", Color::BLACK, false, Gender::MALE, 2.2 };
      BOOST_CHECK_NO_THROW( testArray.add( &cat2 ) );
      validateArray( &testArray, &cat1, &cat2, nullptr, nullptr );

      Cat cat3 { "Coco", Color::WHITE, true, Gender::FEMALE, 3.2 };
      BOOST_CHECK_NO_THROW( testArray.add( &cat3 ) );
      validateArray( &testArray, &cat1, &cat2, &cat3, nullptr );

      Cat cat4 { "Duke", Color::CREAM, false, Gender::UNKNOWN_GENDER, 4.2 };
      BOOST_CHECK_NO_THROW( testArray.add( &cat4 ) );
      validateArray( &testArray, &cat1, &cat2, &cat3, &cat4 );

      Cat cat5 { "Erin", Color::BROWN, true, Gender::FEMALE, 5.2 };

      BOOST_CHECK_THROW( testArray.add( &cat5 ), length_error );
      BOOST_CHECK_EQUAL( testArray.validate(), true );

      for( int i = 0 ; i < 64 ; i++ ) {
         BOOST_CHECK_NO_THROW( testArray.isIn( testArray.getRandomNode() ));
      }
   }

   BOOST_AUTO_TEST_CASE( test_errors ) {
      CatPride testArray;
      Cat* not_a_cat = nullptr;

      BOOST_CHECK_EQUAL( testArray.getRandomNode(), nullptr );

      BOOST_CHECK_THROW( testArray.add( not_a_cat ), invalid_argument );
      BOOST_CHECK_THROW( testArray[-1], out_of_range );
      BOOST_CHECK_THROW( testArray[0], out_of_range );

      BOOST_CHECK_NO_THROW( testArray.add( &Cat::newRandomCat() ));
      BOOST_CHECK_THROW( testArray.add( not_a_cat, 0 ), invalid_argument );

      BOOST_CHECK_THROW( testArray[-1], out_of_range );
      BOOST_CHECK_NO_THROW( testArray[0] );
      BOOST_CHECK_THROW( testArray[1], out_of_range );

      for( int i = 0; i < 10 ; i++ ) {
         BOOST_CHECK_EQUAL( testArray.getRandomNode(), &testArray[0] );
      }

      BOOST_CHECK_NO_THROW( testArray.add( &Cat::newRandomCat() ));
      BOOST_CHECK_NO_THROW( testArray.add( &Cat::newRandomCat() ));
      BOOST_CHECK_NO_THROW( testArray.add( &Cat::newRandomCat() ));
      BOOST_CHECK_EQUAL( testArray.size(), 4 );

      BOOST_CHECK_THROW( testArray.swap( -1, -1 ), out_of_range );
      BOOST_CHECK_THROW( testArray.swap( 0, 4 ), out_of_range );
      BOOST_CHECK_THROW( testArray.swap( 4, 0 ), out_of_range );
      BOOST_CHECK_NO_THROW( testArray.swap( 0, 3 ) );
      BOOST_CHECK_NO_THROW( testArray.swap( 3, 0 ) );

      validateArray( &testArray, &testArray[0], &testArray[1], &testArray[2], &testArray[3] );

      BOOST_CHECK_THROW( testArray.remove( (Cat*) nullptr ), invalid_argument );
      BOOST_CHECK_THROW( testArray.remove( (Node*) nullptr ), invalid_argument );
      BOOST_CHECK_THROW( testArray.remove( 4 ), out_of_range );
      validateArray( &testArray, &testArray[0], &testArray[1], &testArray[2], &testArray[3] );

      BOOST_CHECK_NO_THROW( testArray.remove( 3 ) );
      BOOST_CHECK_THROW( testArray.remove( 3 ), out_of_range );
      validateArray( &testArray, &testArray[0], &testArray[1], &testArray[2], nullptr );

      BOOST_CHECK_NO_THROW( testArray.remove( 2 ) );
      BOOST_CHECK_THROW( testArray.remove( 2 ), out_of_range );
      validateArray( &testArray, &testArray[0], &testArray[1], nullptr, nullptr );

      BOOST_CHECK_NO_THROW( testArray.remove( 1 ) );
      BOOST_CHECK_THROW( testArray.remove( 1 ), out_of_range );
      validateArray( &testArray, &testArray[0], nullptr, nullptr, nullptr );

      BOOST_CHECK_NO_THROW( testArray.remove( (Container::t_size) 0 ) );
      BOOST_CHECK_THROW( testArray.remove( (Container::t_size) 0 ), out_of_range );
      validateArray( &testArray, nullptr, nullptr, nullptr, nullptr );
   }

   BOOST_AUTO_TEST_CASE( test_add_index ) {
      CatPride testArray;
      BOOST_CHECK_NO_THROW( testArray.add( &Cat::newRandomCat() ));
      BOOST_CHECK_NO_THROW( testArray.add( &testArray[0] ));
      BOOST_CHECK_NO_THROW( testArray.add( &testArray[0] ));
      BOOST_CHECK_NO_THROW( testArray.add( &testArray[0] ));
      BOOST_CHECK_THROW( testArray.add( &testArray[0] ), length_error );
      BOOST_CHECK_EQUAL( testArray.validate(), true );
      validateArray( &testArray, &testArray[0], &testArray[1], &testArray[2], &testArray[3] );


      Cat cat1 { "Abel", Color::CALICO, true, Gender::FEMALE, 1.2 };
      Cat cat2 { "Beno", Color::BLACK, false, Gender::MALE, 2.2 };
      Cat cat3 { "Coco", Color::WHITE, true, Gender::FEMALE, 3.2 };
      Cat cat4 { "Duke", Color::CREAM, false, Gender::UNKNOWN_GENDER, 4.2 };

      BOOST_CHECK_NO_THROW( testArray.add( &cat1, 0 ));
      validateArray( &testArray, &cat1, &testArray[1], &testArray[2], &testArray[3] );

      BOOST_CHECK_NO_THROW( testArray.add( &cat2, 1 ));
      validateArray( &testArray, &cat1, &cat2, &testArray[2], &testArray[3] );

      BOOST_CHECK_NO_THROW( testArray.add( &cat3, 2 ));
      validateArray( &testArray, &cat1, &cat2, &cat3, &testArray[3] );

      BOOST_CHECK_NO_THROW( testArray.add( &cat4, 3 ));
      validateArray( &testArray, &cat1, &cat2, &cat3, &cat4 );

      BOOST_CHECK_NO_THROW( testArray.removeAll() );
      validateArray( &testArray, nullptr, nullptr, nullptr, nullptr );

      BOOST_CHECK_THROW( testArray.add( &cat1, 1 ), out_of_range );
      BOOST_CHECK_NO_THROW( testArray.add( &cat1, 0 ) );
      validateArray( &testArray, &cat1, nullptr, nullptr, nullptr );
   }

   BOOST_AUTO_TEST_CASE( test_swap ) {
      CatPride testArray;

      Cat cat1 { "Abel", Color::CALICO, true, Gender::FEMALE, 1.2 };
      Cat cat2 { "Beno", Color::BLACK, false, Gender::MALE, 2.2 };
      Cat cat3 { "Coco", Color::WHITE, true, Gender::FEMALE, 3.2 };
      Cat cat4 { "Duke", Color::CREAM, false, Gender::UNKNOWN_GENDER, 4.2 };

      BOOST_CHECK_NO_THROW( testArray.add( &cat1, 0 ));
      BOOST_CHECK_NO_THROW( testArray.add( &cat2, 1 ));
      BOOST_CHECK_NO_THROW( testArray.add( &cat3, 2 ));
      BOOST_CHECK_NO_THROW( testArray.add( &cat4, 3 ));

      validateArray( &testArray, &cat1, &cat2, &cat3, &cat4 );

      // testArray.dump();

      testArray.swap( 0, 1 );
      validateArray( &testArray, &cat2, &cat1, &cat3, &cat4 );

      testArray.swap( 1, 2 );
      validateArray( &testArray, &cat2, &cat3, &cat1, &cat4 );

      testArray.swap( 2, 1 );
      validateArray( &testArray, &cat2, &cat1, &cat3, &cat4 );

      testArray.swap( 2, 3 );
      validateArray( &testArray, &cat2, &cat1, &cat4, &cat3 );

      testArray.swap( 3, 3 );
      validateArray( &testArray, &cat2, &cat1, &cat4, &cat3 );

      testArray.swap( 0, 0 );
      validateArray( &testArray, &cat2, &cat1, &cat4, &cat3 );

      testArray.swap( 0, 3 );
      validateArray( &testArray, &cat3, &cat1, &cat4, &cat2 );

      testArray.swap( 1, 3 );
      validateArray( &testArray, &cat3, &cat2, &cat4, &cat1 );

      testArray.swap( 0, 2 );
      validateArray( &testArray, &cat4, &cat2, &cat3, &cat1 );

      testArray.swap( 1, 2 );
      validateArray( &testArray, &cat4, &cat3, &cat2, &cat1 );
   }

   BOOST_AUTO_TEST_CASE( test_remove ) {
      CatPride testArray;

      Cat cat1 { "Abel", Color::CALICO, true, Gender::FEMALE, 1.2 };
      Cat cat2 { "Beno", Color::BLACK, false, Gender::MALE, 2.2 };
      Cat cat3 { "Coco", Color::WHITE, true, Gender::FEMALE, 3.2 };
      Cat cat4 { "Duke", Color::CREAM, false, Gender::UNKNOWN_GENDER, 4.2 };

      BOOST_CHECK_EQUAL( testArray.remove( &cat1 ), nullptr );
      BOOST_CHECK_THROW( testArray.remove( (Container::t_size) 0 ), out_of_range );

      BOOST_CHECK_NO_THROW( testArray.add( &cat1 ));
      validateArray( &testArray, &cat1, nullptr, nullptr, nullptr );
      BOOST_CHECK_NO_THROW( testArray.remove( &testArray[0] ));
      validateArray( &testArray, nullptr, nullptr, nullptr, nullptr );

      BOOST_CHECK_NO_THROW( testArray.add( &cat1 ));
      validateArray( &testArray, &cat1, nullptr, nullptr, nullptr );
      BOOST_CHECK_NO_THROW( testArray.remove( (Container::t_size) 0 ));
      validateArray( &testArray, nullptr, nullptr, nullptr, nullptr );

      BOOST_CHECK_NO_THROW( testArray.add( &cat1 ));

      /// Start on cat2
      BOOST_CHECK_NO_THROW( testArray.add( &cat2 ));
      validateArray( &testArray, &cat1, &cat2, nullptr, nullptr );
      BOOST_CHECK_NO_THROW( testArray.remove( &testArray[1] ));
      validateArray( &testArray, &cat1, nullptr, nullptr, nullptr );

      BOOST_CHECK_NO_THROW( testArray.add( &cat2 ));
      validateArray( &testArray, &cat1, &cat2, nullptr, nullptr );
      BOOST_CHECK_NO_THROW( testArray.remove( 1 ));
      validateArray( &testArray, &cat1, nullptr, nullptr, nullptr );

      BOOST_CHECK_NO_THROW( testArray.add( &cat2 ));
      /// Done

      /// Start on cat3
      BOOST_CHECK_NO_THROW( testArray.add( &cat3 ));
      validateArray( &testArray, &cat1, &cat2, &cat3, nullptr );
      BOOST_CHECK_NO_THROW( testArray.remove( &testArray[2] ));
      validateArray( &testArray, &cat1, &cat2, nullptr, nullptr );

      BOOST_CHECK_NO_THROW( testArray.add( &cat3 ));
      validateArray( &testArray, &cat1, &cat2, &cat3, nullptr );
      BOOST_CHECK_NO_THROW( testArray.remove( 2 ));
      validateArray( &testArray, &cat1, &cat2, nullptr, nullptr );

      BOOST_CHECK_NO_THROW( testArray.add( &cat3 ));
      /// Done

      /// Start on cat4
      BOOST_CHECK_NO_THROW( testArray.add( &cat4 ));
      validateArray( &testArray, &cat1, &cat2, &cat3, &cat4 );
      BOOST_CHECK_NO_THROW( testArray.remove( &testArray[3] ));
      validateArray( &testArray, &cat1, &cat2, &cat3, nullptr );

      BOOST_CHECK_NO_THROW( testArray.add( &cat4 ));
      validateArray( &testArray, &cat1, &cat2, &cat3, &cat4 );
      BOOST_CHECK_NO_THROW( testArray.remove( 3 ));
      validateArray( &testArray, &cat1, &cat2, &cat3, nullptr );

      BOOST_CHECK_NO_THROW( testArray.add( &cat4 ));
      /// Done

      validateArray( &testArray, &cat1, &cat2, &cat3, &cat4 );

      BOOST_CHECK_NO_THROW( testArray.remove( (Container::t_size) 0 ));
      validateArray( &testArray, &cat2, &cat3, &cat4, nullptr );

      BOOST_CHECK_NO_THROW( testArray.remove( (Container::t_size) 0 ));
      validateArray( &testArray, &cat3, &cat4, nullptr, nullptr );

      BOOST_CHECK_NO_THROW( testArray.remove( (Container::t_size) 0 ));
      validateArray( &testArray, &cat4, nullptr, nullptr, nullptr );

      BOOST_CHECK_NO_THROW( testArray.remove( (Container::t_size) 0 ));
      validateArray( &testArray, nullptr, nullptr, nullptr, nullptr );

      BOOST_CHECK_NO_THROW( testArray.add( &cat1 ));
      BOOST_CHECK_NO_THROW( testArray.add( &cat2 ));
      BOOST_CHECK_NO_THROW( testArray.add( &cat3 ));
      BOOST_CHECK_NO_THROW( testArray.add( &cat4 ));
      validateArray( &testArray, &cat1, &cat2, &cat3, &cat4 );

      BOOST_CHECK_NO_THROW( testArray.remove( 1 ));
      validateArray( &testArray, &cat1, &cat3, &cat4, nullptr );

      BOOST_CHECK_NO_THROW( testArray.remove( 1 ));
      validateArray( &testArray, &cat1, &cat4, nullptr, nullptr );

      BOOST_CHECK_NO_THROW( testArray.remove( 1 ));
      validateArray( &testArray, &cat1, nullptr, nullptr, nullptr );

      BOOST_CHECK_NO_THROW( testArray.add( &cat2 ));
      BOOST_CHECK_NO_THROW( testArray.add( &cat3 ));
      BOOST_CHECK_NO_THROW( testArray.add( &cat4 ));
      validateArray( &testArray, &cat1, &cat2, &cat3, &cat4 );

      BOOST_CHECK_NO_THROW( testArray.remove( 2 ));
      validateArray( &testArray, &cat1, &cat2, &cat4, nullptr );

      BOOST_CHECK_NO_THROW( testArray.remove( 2 ));
      validateArray( &testArray, &cat1, &cat2, nullptr, nullptr );

      BOOST_CHECK_NO_THROW( testArray.add( &cat3 ));
      BOOST_CHECK_NO_THROW( testArray.add( &cat4 ));
      validateArray( &testArray, &cat1, &cat2, &cat3, &cat4 );

      BOOST_CHECK_NO_THROW( testArray.removeAll() );
      validateArray( &testArray, nullptr, nullptr, nullptr, nullptr );
   }

   BOOST_AUTO_TEST_SUITE_END()
