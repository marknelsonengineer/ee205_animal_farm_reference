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

BOOST_AUTO_TEST_SUITE_END()
