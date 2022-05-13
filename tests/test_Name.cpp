///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
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
#include <boost/test/tools/output_test_stream.hpp>

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


   // Test all of the error messages with respect to name
   struct cout_redirect {
      cout_redirect( std::streambuf * new_buffer )
              : old( std::cout.rdbuf( new_buffer ) )
      { }

      ~cout_redirect( ) {
         std::cout.rdbuf( old );
      }

   private:
      std::streambuf * old;
   };

   BOOST_AUTO_TEST_CASE( test_validate_empty_name ) {
      /// Testing output
      /// @see https://stackoverflow.com/questions/5405016/can-i-check-my-programs-output-with-boost-test
      boost::test_tools::output_test_stream output;
      {
         cout_redirect guard( output.rdbuf() );
         bool result = Name::validateName( "" );
         BOOST_CHECK_EQUAL( result, false );
      }
      BOOST_CHECK_NE( output.str().find( "The name should not be empty" ), string::npos );
   }

   BOOST_AUTO_TEST_CASE( test_validate_untrimmed_name_front ) {
      boost::test_tools::output_test_stream output;
      {  cout_redirect guard( output.rdbuf() );
         bool result = Name::validateName( "\tSam" );
         BOOST_CHECK_EQUAL( result, false );
      }
      BOOST_CHECK_NE( output.str().find( "The name should be trimmed for whitespace" ), string::npos );
   }

   BOOST_AUTO_TEST_CASE( test_validate_untrimmed_name_back ) {
      boost::test_tools::output_test_stream output;
      {  cout_redirect guard( output.rdbuf() );
         bool result = Name::validateName( "Sam\t" );
         BOOST_CHECK_EQUAL( result, false );
      }
      BOOST_CHECK_NE( output.str().find( "The name should be trimmed for whitespace" ), string::npos );
   }

   BOOST_AUTO_TEST_CASE( test_validate_name_with_special_chars ) {
      boost::test_tools::output_test_stream output;
      {  cout_redirect guard( output.rdbuf() );
         bool result = Name::validateName( "Mr. Boo" );
         BOOST_CHECK_EQUAL( result, false );
      }
      BOOST_CHECK_NE( output.str().find( "The name should not have any special characters" ), string::npos );
   }

   BOOST_AUTO_TEST_CASE( test_validate_name_starting_with_number ) {
      boost::test_tools::output_test_stream output;
      {  cout_redirect guard( output.rdbuf() );
         bool result = Name::validateName( "1-Boo" );
         BOOST_CHECK_EQUAL( result, false );
      }
      BOOST_CHECK_NE( output.str().find( "The name should not start with a number or -" ), string::npos );
   }

   BOOST_AUTO_TEST_CASE( test_validate_name_starting_with_dash ) {
      boost::test_tools::output_test_stream output;
      {  cout_redirect guard( output.rdbuf() );
         bool result = Name::validateName( "-Boo" );
         BOOST_CHECK_EQUAL( result, false );
      }
      BOOST_CHECK_NE( output.str().find( "The name should not start with a number or -" ), string::npos );
   }

   BOOST_AUTO_TEST_CASE( test_validate_name_with_interior_whitespace ) {
      boost::test_tools::output_test_stream output;
      {  cout_redirect guard( output.rdbuf() );
         bool result = Name::validateName( "Boo--Boo" );
         BOOST_CHECK_EQUAL( result, false );
      }
      BOOST_CHECK_NE( output.str().find( "The interior whitespace of the name should be trimmed" ), string::npos );
   }

   // General test (without checking error messages) of names
   BOOST_AUTO_TEST_CASE( test_validate_names ) {
      BOOST_CHECK_EQUAL( Name::validateName( "Sam" ), true );
      BOOST_CHECK_EQUAL( Name::validateName( "A" ), true );
      BOOST_CHECK_EQUAL( Name::validateName( "AB" ), true );

      BOOST_CHECK_EQUAL( Name::validateName( "" ), false );
      BOOST_CHECK_EQUAL( Name::validateName( " " ), false );
      BOOST_CHECK_EQUAL( Name::validateName( "  " ), false );
      BOOST_CHECK_EQUAL( Name::validateName( " Sam" ), false );
      BOOST_CHECK_EQUAL( Name::validateName( "-Sam" ), false );
      BOOST_CHECK_EQUAL( Name::validateName( "0Sam" ), false );
      BOOST_CHECK_EQUAL( Name::validateName( "Sam " ), false );
      BOOST_CHECK_EQUAL( Name::validateName( "Sam-" ), true );
      BOOST_CHECK_EQUAL( Name::validateName( "Sam0" ), true );
      BOOST_CHECK_EQUAL( Name::validateName( "Sam Sam" ), true );
      BOOST_CHECK_EQUAL( Name::validateName( "Sam Sam Sam" ), true );
      BOOST_CHECK_EQUAL( Name::validateName( "Sam Sam Sam Sam" ), true );
      BOOST_CHECK_EQUAL( Name::validateName( "Sam-Sam" ), true );
      BOOST_CHECK_EQUAL( Name::validateName( "Sam-Sam-Sam" ), true );
      BOOST_CHECK_EQUAL( Name::validateName( "Sam-Sam-Sam-Sam" ), true );
      BOOST_CHECK_EQUAL( Name::validateName( "Sam- Sam" ), false );
      BOOST_CHECK_EQUAL( Name::validateName( "Sam -Sam" ), false );
      BOOST_CHECK_EQUAL( Name::validateName( "Sam  Sam" ), false );
      BOOST_CHECK_EQUAL( Name::validateName( "Sam--Sam" ), false );
      BOOST_CHECK_EQUAL( Name::validateName( "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvbwxyz0123456789-" ), true );
      BOOST_CHECK_EQUAL( Name::validateName( "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvbwxyz0123456789*" ), false );
      BOOST_CHECK_EQUAL( Name::validateName( "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvbwxyz0123456789@" ), false );
   }

BOOST_AUTO_TEST_SUITE_END()
