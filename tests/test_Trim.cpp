///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// Comprehensive test of the Trim functions
///
/// @file test_Trim.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   10_May_2022
///////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <stdexcept>

#include "../src/Utility/Trim.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_Trim )

   BOOST_AUTO_TEST_CASE( test_Trim_Left ) {
      BOOST_CHECK_EQUAL( trim_left( "" ), "" );
      BOOST_CHECK_EQUAL( trim_left( "A" ), "A" );
      BOOST_CHECK_EQUAL( trim_left( "AB" ), "AB" );
      BOOST_CHECK_EQUAL( trim_left( "ABC" ), "ABC" );

      BOOST_CHECK_EQUAL( trim_left( " " ), "" );
      BOOST_CHECK_EQUAL( trim_left( " A" ), "A" );
      BOOST_CHECK_EQUAL( trim_left( " AB" ), "AB" );
      BOOST_CHECK_EQUAL( trim_left( " ABC" ), "ABC" );

      BOOST_CHECK_EQUAL( trim_left( "\t " ), "" );
      BOOST_CHECK_EQUAL( trim_left( "\t A" ), "A" );
      BOOST_CHECK_EQUAL( trim_left( "\t AB" ), "AB" );
      BOOST_CHECK_EQUAL( trim_left( "\t ABC" ), "ABC" );

      BOOST_CHECK_EQUAL( trim_left( " \t\f\n\r\v " ), "" );
      BOOST_CHECK_EQUAL( trim_left( " \t\f\n\r\v A  " ), "A  " );
      BOOST_CHECK_EQUAL( trim_left( " \t\f\n\r\v AB  " ), "AB  " );
      BOOST_CHECK_EQUAL( trim_left( " \t\f\n\r\v ABC  " ), "ABC  " );
   }

   BOOST_AUTO_TEST_CASE( test_Trim_Right ) {
      BOOST_CHECK_EQUAL( trim_right( "" ), "" );
      BOOST_CHECK_EQUAL( trim_right( "A" ), "A" );
      BOOST_CHECK_EQUAL( trim_right( "AB" ), "AB" );
      BOOST_CHECK_EQUAL( trim_right( "ABC" ), "ABC" );

      BOOST_CHECK_EQUAL( trim_right( " " ), "" );
      BOOST_CHECK_EQUAL( trim_right( "A " ), "A" );
      BOOST_CHECK_EQUAL( trim_right( "AB " ), "AB" );
      BOOST_CHECK_EQUAL( trim_right( "ABC " ), "ABC" );

      BOOST_CHECK_EQUAL( trim_right( " \t" ), "" );
      BOOST_CHECK_EQUAL( trim_right( "A \t" ), "A" );
      BOOST_CHECK_EQUAL( trim_right( "AB \t" ), "AB" );
      BOOST_CHECK_EQUAL( trim_right( "ABC \t" ), "ABC" );

      BOOST_CHECK_EQUAL( trim_right( " \t\f\n\r\v " ), "" );
      BOOST_CHECK_EQUAL( trim_right( " A \t\f\n\r\v " ), " A" );
      BOOST_CHECK_EQUAL( trim_right( " AB \t\f\n\r\v " ), " AB" );
      BOOST_CHECK_EQUAL( trim_right( " ABC \t\f\n\r\v " ), " ABC" );
   }


   BOOST_AUTO_TEST_CASE( test_Trim ) {
      BOOST_CHECK_EQUAL( trim( "" ), "" );
      BOOST_CHECK_EQUAL( trim( "A" ), "A" );
      BOOST_CHECK_EQUAL( trim( "AB" ), "AB" );
      BOOST_CHECK_EQUAL( trim( "ABC" ), "ABC" );

      BOOST_CHECK_EQUAL( trim( " " ), "" );
      BOOST_CHECK_EQUAL( trim( " A" ), "A" );
      BOOST_CHECK_EQUAL( trim( " AB" ), "AB" );
      BOOST_CHECK_EQUAL( trim( " ABC" ), "ABC" );

      BOOST_CHECK_EQUAL( trim( "\t " ), "" );
      BOOST_CHECK_EQUAL( trim( "\t A" ), "A" );
      BOOST_CHECK_EQUAL( trim( "\t AB" ), "AB" );
      BOOST_CHECK_EQUAL( trim( "\t ABC" ), "ABC" );

      BOOST_CHECK_EQUAL( trim( " \t\f\n\r\v " ), "" );
      BOOST_CHECK_EQUAL( trim( " \t\f\n\r\v A" ), "A" );
      BOOST_CHECK_EQUAL( trim( " \t\f\n\r\v AB" ), "AB" );
      BOOST_CHECK_EQUAL( trim( " \t\f\n\r\v ABC" ), "ABC" );

      BOOST_CHECK_EQUAL( trim( "A " ), "A" );
      BOOST_CHECK_EQUAL( trim( "AB " ), "AB" );
      BOOST_CHECK_EQUAL( trim( "ABC " ), "ABC" );

      BOOST_CHECK_EQUAL( trim( "A \t" ), "A" );
      BOOST_CHECK_EQUAL( trim( "AB \t" ), "AB" );
      BOOST_CHECK_EQUAL( trim( "ABC \t" ), "ABC" );

      BOOST_CHECK_EQUAL( trim( "A \t\f\n\r\v " ), "A" );
      BOOST_CHECK_EQUAL( trim( "AB \t\f\n\r\v " ), "AB" );
      BOOST_CHECK_EQUAL( trim( "ABC \t\f\n\r\v " ), "ABC" );

      BOOST_CHECK_EQUAL( trim( " A " ), "A" );
      BOOST_CHECK_EQUAL( trim( " AB " ), "AB" );
      BOOST_CHECK_EQUAL( trim( " ABC " ), "ABC" );

      BOOST_CHECK_EQUAL( trim( "\t A \t" ), "A" );
      BOOST_CHECK_EQUAL( trim( "\t AB \t" ), "AB" );
      BOOST_CHECK_EQUAL( trim( "\t ABC \t" ), "ABC" );

      BOOST_CHECK_EQUAL( trim( " \t\f\n\r\v A \t\f\n\r\v " ), "A" );
      BOOST_CHECK_EQUAL( trim( " \t\f\n\r\v AB \t\f\n\r\v " ), "AB" );
      BOOST_CHECK_EQUAL( trim( " \t\f\n\r\v ABC \t\f\n\r\v " ), "ABC" );
   }

   BOOST_AUTO_TEST_CASE( test_Trim_In ) {
      BOOST_CHECK_EQUAL( trim_in( "" ), "" );
      BOOST_CHECK_EQUAL( trim_in( "A" ), "A" );
      BOOST_CHECK_EQUAL( trim_in( " A" ), "A" );
      BOOST_CHECK_EQUAL( trim_in( "A " ), "A" );
      BOOST_CHECK_EQUAL( trim_in( " A " ), "A" );

      BOOST_CHECK_EQUAL( trim_in( " " ), "" );
      BOOST_CHECK_EQUAL( trim_in( " A " ), "A" );
      BOOST_CHECK_EQUAL( trim_in( "  A" ), "A" );
      BOOST_CHECK_EQUAL( trim_in( "A  " ), "A" );
      BOOST_CHECK_EQUAL( trim_in( "  A  " ), "A" );

      BOOST_CHECK_EQUAL( trim_in( "A B" ), "A B" );
      BOOST_CHECK_EQUAL( trim_in( "A  B" ), "A B" );
      BOOST_CHECK_EQUAL( trim_in( "A   B" ), "A B" );

      BOOST_CHECK_EQUAL( trim_in( "AA BB" ), "AA BB" );
      BOOST_CHECK_EQUAL( trim_in( "AA  BB" ), "AA BB" );
      BOOST_CHECK_EQUAL( trim_in( "AA   BB" ), "AA BB" );

      BOOST_CHECK_EQUAL( trim_in( " A B " ), "A B" );
      BOOST_CHECK_EQUAL( trim_in( "  A  B  " ), "A B" );
      BOOST_CHECK_EQUAL( trim_in( "   A   B   " ), "A B" );

      BOOST_CHECK_EQUAL( trim_in( "A B C" ), "A B C" );
      BOOST_CHECK_EQUAL( trim_in( "A  B  C" ), "A B C" );
      BOOST_CHECK_EQUAL( trim_in( "A   B   C" ), "A B C" );

      BOOST_CHECK_EQUAL( trim_in( " A B C " ), "A B C" );
      BOOST_CHECK_EQUAL( trim_in( "  A  B  C  " ), "A B C" );
      BOOST_CHECK_EQUAL( trim_in( "   A   B   C   " ), "A B C" );

      BOOST_CHECK_EQUAL( trim_in( "\t\f\n\r\vA\t\f\n\r\vB\t\f\n\r\vC\t\f\n\r\v" ), "A B C" );
      BOOST_CHECK_EQUAL( trim_in( "\t\f\n\r\vAA\t\f\n\r\vBB\t\f\n\r\vCC\t\f\n\r\v" ), "AA BB CC" );
      BOOST_CHECK_EQUAL( trim_in( "\t\f\n\r\vAAA\t\f\n\r\vBBB\t\f\n\r\vCCC\t\f\n\r\v" ), "AAA BBB CCC" );
   }

   BOOST_AUTO_TEST_SUITE_END()
