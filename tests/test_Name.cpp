///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// Comprehensive test of the Name class
///
/// @file test_Name.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   11_May_2022
///////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <istream>

#include "../src/Utility/Name.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_Name )

   BOOST_AUTO_TEST_CASE( test_Name1 ) {
      Name testName( "./data/testNames1.txt" );

      BOOST_CHECK_EQUAL( testName.remainingNames(), 1 );
      BOOST_CHECK_EQUAL( testName.getNextName(), "alpha" );
      BOOST_CHECK_EQUAL( testName.remainingNames(), 0 );

      for( int i = 0 ; i < 10 ; i++ ) {
         BOOST_CHECK_EQUAL( testName.getNextName(), "alpha" );
         // cout << testName.getNextName() << endl;
      }
   }


   BOOST_AUTO_TEST_CASE( test_Name2 ) {
      Name testName( "./data/testNames2.txt" );

      BOOST_CHECK_EQUAL( testName.remainingNames(), 2 );
      BOOST_CHECK_NO_THROW( testName.getNextName() );
      BOOST_CHECK_EQUAL( testName.remainingNames(), 1 );
      BOOST_CHECK_NO_THROW( testName.getNextName() );
      BOOST_CHECK_EQUAL( testName.remainingNames(), 0 );

      for( int i = 0 ; i < 10 ; i++ ) {
         BOOST_CHECK_NO_THROW( testName.getNextName() );
         // cout << testName.getNextName() << endl;
      }
   }


   BOOST_AUTO_TEST_CASE( test_Name24 ) {
      Name testName( "./data/testNames24.txt" );

      BOOST_CHECK_EQUAL( testName.remainingNames(), 24 );

      for( int i = 0 ; i < 100 ; i++ ) {
         BOOST_CHECK_NO_THROW( testName.getNextName() );
         // cout << testName.getNextName() << endl;
      }

   }

   BOOST_AUTO_TEST_CASE( test_NameFromBadFile ) {
      BOOST_CHECK_THROW( Name testName1( "Not_a_file" ), runtime_error );
   }

   BOOST_AUTO_TEST_CASE( test_Serial_no_text ) {
      Name testSerial( "", "" );

      for( int i = 0 ; i < 10 ; i++ ) {
         Name::serial_t maxSerial = Name::maxSerial;

         BOOST_CHECK_EQUAL( testSerial.getNextName(), "0" );
         BOOST_CHECK_EQUAL( testSerial.remainingNames(), --maxSerial );
         BOOST_CHECK_EQUAL( testSerial.getNextName(), "1" );
         BOOST_CHECK_EQUAL( testSerial.remainingNames(), --maxSerial );
         BOOST_CHECK_EQUAL( testSerial.getNextName(), "2" );
         BOOST_CHECK_EQUAL( testSerial.remainingNames(), --maxSerial );
         BOOST_CHECK_EQUAL( testSerial.getNextName(), "3" );
         BOOST_CHECK_EQUAL( testSerial.remainingNames(), --maxSerial );
         BOOST_CHECK_EQUAL( testSerial.getNextName(), "4" );
         BOOST_CHECK_EQUAL( testSerial.remainingNames(), --maxSerial );

         testSerial.reset();
      }
   }


   BOOST_AUTO_TEST_CASE( test_Serial_prefix ) {
      Name testSerial( "Animal ", "" );

      BOOST_CHECK_EQUAL( testSerial.getNextName(), "Animal 0" );
      BOOST_CHECK_EQUAL( testSerial.getNextName(), "Animal 1" );
      BOOST_CHECK_EQUAL( testSerial.getNextName(), "Animal 2" );
      BOOST_CHECK_EQUAL( testSerial.getNextName(), "Animal 3" );
      BOOST_CHECK_EQUAL( testSerial.getNextName(), "Animal 4" );
   }


   BOOST_AUTO_TEST_CASE( test_Serial_suffix ) {
      Name testSerial( "", " Animal" );

      BOOST_CHECK_EQUAL( testSerial.getNextName(), "0 Animal" );
      BOOST_CHECK_EQUAL( testSerial.getNextName(), "1 Animal" );
      BOOST_CHECK_EQUAL( testSerial.getNextName(), "2 Animal" );
      BOOST_CHECK_EQUAL( testSerial.getNextName(), "3 Animal" );
      BOOST_CHECK_EQUAL( testSerial.getNextName(), "4 Animal" );
   }


   BOOST_AUTO_TEST_CASE( test_Serial_all ) {
      Name testSerial( "Animal #[", "]" );

      BOOST_CHECK_EQUAL( testSerial.getNextName(), "Animal #[0]" );
      BOOST_CHECK_EQUAL( testSerial.getNextName(), "Animal #[1]" );
      BOOST_CHECK_EQUAL( testSerial.getNextName(), "Animal #[2]" );
      BOOST_CHECK_EQUAL( testSerial.getNextName(), "Animal #[3]" );
      BOOST_CHECK_EQUAL( testSerial.getNextName(), "Animal #[4]" );
   }


BOOST_AUTO_TEST_SUITE_END()
