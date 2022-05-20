///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// Lorem ipsum dolor sit amet
///
/// @file test_Bird.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   19_May_2022
///////////////////////////////////////////////////////////////////////////////
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "../src/Animal/Bird/Finch.h"
#include "../src/Animal/Bird/Chicken.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_Bird )

   BOOST_AUTO_TEST_CASE( test_Finch0 ) {
      Finch::names.reset();
      Finch aFinch;
      BOOST_CHECK_EQUAL( aFinch.validate(), true );
      BOOST_CHECK_EQUAL( aFinch.getName(), "Finch 0" );
      BOOST_CHECK_EQUAL( aFinch.getClassification(), Bird::CLASSIFICATION_NAME );
      BOOST_CHECK_EQUAL( aFinch.getGender(), Gender::UNKNOWN_GENDER );
      BOOST_CHECK_EQUAL( aFinch.getKingdom(), Animal::KINGDOM_NAME );
      BOOST_CHECK_EQUAL( aFinch.getSpecies(), Finch::SPECIES_NAME );
      BOOST_CHECK_EQUAL( aFinch.getWeight(), Weight::UNKNOWN_WEIGHT );
      BOOST_CHECK_EQUAL( aFinch.info().find( "Finch" ), 4 );
      BOOST_CHECK_EQUAL( aFinch.speak(), "Tweet" );
   }

   BOOST_AUTO_TEST_CASE( test_Finch1 ) {
      Finch aFinch { "Boo" };
      BOOST_CHECK_EQUAL( aFinch.validate(), true );
      BOOST_CHECK_EQUAL( aFinch.getName(), "Boo" );
      BOOST_CHECK_EQUAL( aFinch.getClassification(), Bird::CLASSIFICATION_NAME );
      BOOST_CHECK_EQUAL( aFinch.getGender(), Gender::UNKNOWN_GENDER );
      BOOST_CHECK_EQUAL( aFinch.getKingdom(), Animal::KINGDOM_NAME );
      BOOST_CHECK_EQUAL( aFinch.getSpecies(), Finch::SPECIES_NAME );
      BOOST_CHECK_EQUAL( aFinch.getWeight(), Weight::UNKNOWN_WEIGHT );
      BOOST_CHECK_EQUAL( aFinch.info().find( "Finch" ), 4 );
      BOOST_CHECK_EQUAL( aFinch.speak(), "Tweet" );
   }

   BOOST_AUTO_TEST_CASE( test_Finch2 ) {
      Finch aFinch { "Boo", Gender::FEMALE };
      BOOST_CHECK_EQUAL( aFinch.validate(), true );
      BOOST_CHECK_EQUAL( aFinch.getName(), "Boo" );
      BOOST_CHECK_EQUAL( aFinch.getClassification(), Bird::CLASSIFICATION_NAME );
      BOOST_CHECK_EQUAL( aFinch.getGender(), Gender::FEMALE );
      BOOST_CHECK_EQUAL( aFinch.getKingdom(), Animal::KINGDOM_NAME );
      BOOST_CHECK_EQUAL( aFinch.getSpecies(), Finch::SPECIES_NAME );
      BOOST_CHECK_EQUAL( aFinch.getWeight(), Weight::UNKNOWN_WEIGHT );
      BOOST_CHECK_EQUAL( aFinch.info().find( "Finch" ), 4 );
      BOOST_CHECK_EQUAL( aFinch.speak(), "Tweet" );
   }

   BOOST_AUTO_TEST_CASE( test_Finch3 ) {
      Finch aFinch { "Boo", Gender::MALE, 0.00222 };
      BOOST_CHECK_EQUAL( aFinch.validate(), true );
      BOOST_CHECK_EQUAL( aFinch.getName(), "Boo" );
      BOOST_CHECK_EQUAL( aFinch.getClassification(), Bird::CLASSIFICATION_NAME );
      BOOST_CHECK_EQUAL( aFinch.getGender(), Gender::MALE );
      BOOST_CHECK_EQUAL( aFinch.getKingdom(), Animal::KINGDOM_NAME );
      BOOST_CHECK_EQUAL( aFinch.getSpecies(), Finch::SPECIES_NAME );
      BOOST_CHECK_CLOSE( aFinch.getWeight(), 0.00222, 0.00001 );
      BOOST_CHECK_EQUAL( aFinch.info().find( "Finch" ), 4 );
      BOOST_CHECK_EQUAL( aFinch.speak(), "Tweet" );
   }

   BOOST_AUTO_TEST_CASE( test_Random_Finch ) {
      for( int i = 0 ; i < 500 ; i++ ) {
         Finch aFinch { Bird::ConstructorType::RANDOM };
         BOOST_CHECK_EQUAL( aFinch.validate(), true );
         BOOST_CHECK_EQUAL( aFinch.getName().empty(), false );
         BOOST_CHECK_EQUAL( aFinch.getClassification(),
                            Bird::CLASSIFICATION_NAME );
         BOOST_CHECK_NO_THROW( aFinch.getGender());
         BOOST_CHECK_EQUAL( aFinch.getKingdom(), Animal::KINGDOM_NAME );
         BOOST_CHECK_EQUAL( aFinch.getSpecies(), Finch::SPECIES_NAME );
         BOOST_CHECK_GT( aFinch.getWeight(), 0 );
         BOOST_CHECK_LE( aFinch.getWeight(), Finch::MAX_WEIGHT );
         BOOST_CHECK_EQUAL( aFinch.info().find( "Finch" ), 4 );
         BOOST_CHECK_EQUAL( aFinch.speak(), "Tweet" );
      }
   }

   BOOST_AUTO_TEST_CASE( test_Chicken0 ) {
      Chicken::names.reset();
      Chicken aChicken;
      BOOST_CHECK_EQUAL( aChicken.validate(), true );
      BOOST_CHECK_EQUAL( aChicken.getName(), "Chicken 0" );
      BOOST_CHECK_EQUAL( aChicken.getClassification(), Bird::CLASSIFICATION_NAME );
      BOOST_CHECK_EQUAL( aChicken.getGender(), Gender::UNKNOWN_GENDER );
      BOOST_CHECK_EQUAL( aChicken.getKingdom(), Animal::KINGDOM_NAME );
      BOOST_CHECK_EQUAL( aChicken.getSpecies(), Chicken::SPECIES_NAME );
      BOOST_CHECK_EQUAL( aChicken.getWeight(), Weight::UNKNOWN_WEIGHT );
      BOOST_CHECK_EQUAL( aChicken.info().find( "Chicken" ), 4 );
      BOOST_CHECK_EQUAL( aChicken.speak(), "Cluck" );
   }

   BOOST_AUTO_TEST_CASE( test_Chicken1 ) {
      Chicken aChicken { "Apple" };
      BOOST_CHECK_EQUAL( aChicken.validate(), true );
      BOOST_CHECK_EQUAL( aChicken.getName(), "Apple" );
      BOOST_CHECK_EQUAL( aChicken.getClassification(), Bird::CLASSIFICATION_NAME );
      BOOST_CHECK_EQUAL( aChicken.getGender(), Gender::UNKNOWN_GENDER );
      BOOST_CHECK_EQUAL( aChicken.getKingdom(), Animal::KINGDOM_NAME );
      BOOST_CHECK_EQUAL( aChicken.getSpecies(), Chicken::SPECIES_NAME );
      BOOST_CHECK_EQUAL( aChicken.getWeight(), Weight::UNKNOWN_WEIGHT );
      BOOST_CHECK_EQUAL( aChicken.info().find( "Chicken" ), 4 );
      BOOST_CHECK_EQUAL( aChicken.speak(), "Cluck" );
   }

   BOOST_AUTO_TEST_CASE( test_Chicken2 ) {
      Chicken aChicken { "Apple", Gender::FEMALE };
      BOOST_CHECK_EQUAL( aChicken.validate(), true );
      BOOST_CHECK_EQUAL( aChicken.getName(), "Apple" );
      BOOST_CHECK_EQUAL( aChicken.getClassification(), Bird::CLASSIFICATION_NAME );
      BOOST_CHECK_EQUAL( aChicken.getGender(), Gender::FEMALE );
      BOOST_CHECK_EQUAL( aChicken.getKingdom(), Animal::KINGDOM_NAME );
      BOOST_CHECK_EQUAL( aChicken.getSpecies(), Chicken::SPECIES_NAME );
      BOOST_CHECK_EQUAL( aChicken.getWeight(), Weight::UNKNOWN_WEIGHT );
      BOOST_CHECK_EQUAL( aChicken.info().find( "Chicken" ), 4 );
      BOOST_CHECK_EQUAL( aChicken.speak(), "Cluck" );
   }

   BOOST_AUTO_TEST_CASE( test_Chicken3 ) {
      Chicken aChicken { "Apple", Gender::MALE, 0.00222 };
      BOOST_CHECK_EQUAL( aChicken.validate(), true );
      BOOST_CHECK_EQUAL( aChicken.getName(), "Apple" );
      BOOST_CHECK_EQUAL( aChicken.getClassification(), Bird::CLASSIFICATION_NAME );
      BOOST_CHECK_EQUAL( aChicken.getGender(), Gender::MALE );
      BOOST_CHECK_EQUAL( aChicken.getKingdom(), Animal::KINGDOM_NAME );
      BOOST_CHECK_EQUAL( aChicken.getSpecies(), Chicken::SPECIES_NAME );
      BOOST_CHECK_CLOSE( aChicken.getWeight(), 0.00222, 0.00001 );
      BOOST_CHECK_EQUAL( aChicken.info().find( "Chicken" ), 4 );
      BOOST_CHECK_EQUAL( aChicken.speak(), "Cluck" );
   }

   BOOST_AUTO_TEST_CASE( test_Random_Chicken ) {
      for( int i = 0 ; i < 500 ; i++ ) {
         Chicken aChicken { Bird::ConstructorType::RANDOM };
         BOOST_CHECK_EQUAL( aChicken.validate(), true );
         BOOST_CHECK_EQUAL( aChicken.getName().empty(), false );
         BOOST_CHECK_EQUAL( aChicken.getClassification(),
                            Bird::CLASSIFICATION_NAME );
         BOOST_CHECK_NO_THROW( aChicken.getGender());
         BOOST_CHECK_EQUAL( aChicken.getKingdom(), Animal::KINGDOM_NAME );
         BOOST_CHECK_EQUAL( aChicken.getSpecies(), Chicken::SPECIES_NAME );
         BOOST_CHECK_GT( aChicken.getWeight(), 0 );
         BOOST_CHECK_LE( aChicken.getWeight(), Chicken::MAX_WEIGHT );
         BOOST_CHECK_EQUAL( aChicken.info().find( "Chicken" ), 4 );
         BOOST_CHECK_EQUAL( aChicken.speak(), "Cluck" );
      }
   }

BOOST_AUTO_TEST_SUITE_END()
