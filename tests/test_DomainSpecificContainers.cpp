///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// Test the domain specific containers like CatWrangler and CatEmpire
///
/// @file test_DomainSpecificContainers.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   24_May_2022
///////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include "../src/Animal/Mammal/Cat/CatEmpire.h"
#include "../src/Animal/Mammal/Cat/CatWrangler.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_DomainSpecificContainers )

   BOOST_AUTO_TEST_CASE( test_CatEmpire ) {
      CatEmpire testContainer;

      int count = 0;

      for( int i = 0 ; i < 9 ; i++ ) {
         Cat::names.reset();
         BOOST_REQUIRE_NO_THROW( testContainer.removeAll() );
         BOOST_REQUIRE_EQUAL( testContainer.isEmpty(), true );
         BOOST_REQUIRE_EQUAL( testContainer.size(), 0 );
         count = 0;

         double idealSizeOfContainer = pow( 2, i );

         BOOST_TEST_MESSAGE( "ideal size of container = [" << idealSizeOfContainer << "]   remaining Cat names = [" << Cat::names.remainingNames() << "]" ) ;

         for( int j = 0 ; j < 1024 ; j++ ) {
            // Print a histogram of the current size of testContainer
            // std::cout << std::setw( testContainer.size() ) << std::setfill( '=' ) << "" << std::endl;

            bernoulli_distribution isFixedRNG( testContainer.size() / ( idealSizeOfContainer * 2) );  // If ideal size is 4, then 4/8 = 0.5
            bool deleteCat = isFixedRNG( ANIMAL_FARM_RNG );

            if( deleteCat ) {
               Cat* catToDelete = testContainer.getRandomNode();
               BOOST_REQUIRE_NO_THROW( testContainer.remove( catToDelete ) );
               count -= 1;
               BOOST_REQUIRE_EQUAL( testContainer.isIn( catToDelete ), false );

            } else { // Insert a Cat
               Cat& aCat = Cat::newRandomCat();
               BOOST_REQUIRE_NO_THROW( testContainer.add( &aCat ) );
               count += 1;
               BOOST_REQUIRE_EQUAL( testContainer.isIn( &aCat ), true );
               BOOST_REQUIRE_EQUAL( testContainer.isEmpty(), false );
            }
            BOOST_REQUIRE_EQUAL( testContainer.size(), count );
            BOOST_REQUIRE_EQUAL( testContainer.validate(), true );
         }
      }
      BOOST_REQUIRE_NO_THROW( testContainer.removeAll() );
      BOOST_REQUIRE_EQUAL( testContainer.isEmpty(), true );
      BOOST_REQUIRE_EQUAL( testContainer.size(), 0 );
      count = 0;
   }

   BOOST_AUTO_TEST_CASE( test_CatWrangler ) {
      CatWrangler testContainer;

      int count = 0;

      for( int i = 0 ; i < 9 ; i++ ) {
         Cat::names.reset();
         BOOST_REQUIRE_NO_THROW( testContainer.removeAll() );
         BOOST_REQUIRE_EQUAL( testContainer.isEmpty(), true );
         BOOST_REQUIRE_EQUAL( testContainer.size(), 0 );
         count = 0;

         double idealSizeOfContainer = pow( 2, i );

         BOOST_TEST_MESSAGE( "ideal size of container = [" << idealSizeOfContainer << "]   remaining Cat names = [" << Cat::names.remainingNames() << "]" ) ;

         for( int j = 0 ; j < 512 ; j++ ) {

            // Print a histogram of the current size of testContainer
            // std::cout << std::setw( testContainer.size() ) << std::setfill( '=' ) << "" << std::endl;

            bernoulli_distribution isFixedRNG( testContainer.size() / ( idealSizeOfContainer * 2) );  // If ideal size is 4, then 4/8 = 0.5
            bool deleteCat = isFixedRNG( ANIMAL_FARM_RNG );

            if( deleteCat ) {
               // -1 = removeFront
               //  0 = remove
               //  1 = removeBack
               uniform_int_distribution<>  methodRNG( -1, 1 );
               int removeMethod = methodRNG( ANIMAL_FARM_RNG );

               Cat* catToDelete;
               switch( removeMethod ) {
                  case -1:
                     BOOST_REQUIRE_NO_THROW( catToDelete = testContainer.getFirst() );
                     BOOST_REQUIRE_NO_THROW( testContainer.removeFront() );
                     break;
                  case 0:
                     BOOST_REQUIRE_NO_THROW( catToDelete = testContainer.getRandomNode() );
                     BOOST_REQUIRE_NO_THROW( testContainer.remove( catToDelete ) );
                     break;
                  case 1:
                     BOOST_REQUIRE_NO_THROW( catToDelete = testContainer.getLast() );
                     BOOST_REQUIRE_NO_THROW( testContainer.removeBack() );
                     break;
               }
               BOOST_REQUIRE_EQUAL( testContainer.isIn( catToDelete ), false );
               count -= 1;

            } else { // Insert a Cat
               // -2 = addFront
               // -1 = addBefore
               //  0 = add
               //  1 = addAfter
               //  2 = addBack
               uniform_int_distribution<>  methodRNG( -2, 2 );
               int addMethod = methodRNG( ANIMAL_FARM_RNG );
               Cat* randomCat = testContainer.getRandomNode();
               if( randomCat == nullptr )  // If the container is empty
                  addMethod = 0;          // ... then do a regular add

               Cat& aCat = Cat::newRandomCat();

               switch( addMethod ) {
                  case -2:
                     BOOST_REQUIRE_NO_THROW( testContainer.addFront( &aCat ) );
                     break;
                  case -1:
                     BOOST_REQUIRE_NO_THROW( testContainer.addBefore( randomCat, &aCat ) );
                     break;
                  case 0:
                     BOOST_REQUIRE_NO_THROW( testContainer.add( &aCat ) );
                     break;
                  case 1:
                     BOOST_REQUIRE_NO_THROW( testContainer.addAfter( randomCat, &aCat ) );
                     break;
                  case 2:
                     BOOST_REQUIRE_NO_THROW( testContainer.addBack( &aCat ) );
                     break;
               }
               count += 1;
               BOOST_REQUIRE_EQUAL( testContainer.isIn( &aCat ), true );
               BOOST_REQUIRE_EQUAL( testContainer.isEmpty(), false );
            }

            if( count == idealSizeOfContainer ) {
               testContainer.insertionSort();
               BOOST_REQUIRE_EQUAL( testContainer.isSorted(), true );
            }

            if( count == idealSizeOfContainer+1 ) {
               int count1 = 0;
               Cat* currentCat = testContainer.getFirst();
               while( currentCat != nullptr ) {
                  currentCat = testContainer.getNext( currentCat );
                  count1++;
               }
               BOOST_REQUIRE_EQUAL( testContainer.size(), count1 );
            }

            if( count == idealSizeOfContainer-1 ) {
               int count1 = 0;
               Cat* currentCat = testContainer.getLast();
               while( currentCat != nullptr ) {
                  currentCat = testContainer.getPrev( currentCat );
                  count1++;
               }
               BOOST_REQUIRE_EQUAL( testContainer.size(), count1 );
            }

            BOOST_REQUIRE_EQUAL( testContainer.size(), count );
            BOOST_REQUIRE_EQUAL( testContainer.validate(), true );
         }
      }
      BOOST_REQUIRE_NO_THROW( testContainer.removeAll() );
      BOOST_REQUIRE_EQUAL( testContainer.isEmpty(), true );
      BOOST_REQUIRE_EQUAL( testContainer.size(), 0 );
      count = 0;
   }

BOOST_AUTO_TEST_SUITE_END()
