///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
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

#include "../src/Cat.h"

using namespace std;

BOOST_AUTO_TEST_CASE( test_Cat_min_constructor ) {
   Cat aCat( "Kali" );
   BOOST_CHECK_EQUAL( aCat.getName(), "Kali" );
   BOOST_CHECK_EQUAL( aCat.isFixed(), false );
   BOOST_CHECK_EQUAL( aCat.getColor(), Color::UNKNOWN_COLOR );
   BOOST_CHECK_EQUAL( aCat.getSpecies(), Cat::SPECIES_NAME );
   BOOST_CHECK_EQUAL( aCat.getClassification(), Mammal::MAMMAL_NAME );
   BOOST_CHECK_EQUAL( aCat.getKingdom(), Animal::KINGDOM_NAME );
   BOOST_CHECK_EQUAL( aCat.getGender(), Gender::UNKNOWN_GENDER );
   BOOST_CHECK_EQUAL( aCat.getWeight(), Weight::UNKNOWN_WEIGHT );
   BOOST_CHECK( aCat.validate() );

   #ifdef DEBUG
      aCat.dump();
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
      aCat.dump();
   #endif
}
