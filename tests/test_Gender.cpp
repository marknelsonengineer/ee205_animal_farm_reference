///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// Comprehensive test of the Gender class enum
///
/// @file test_Gender.cpp
/// @version 1.0
///
/// @see https://www.jetbrains.com/help/clion/boost-test-support.html
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   06_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

#include <stdexcept>
#include <iostream>

#include "../src/Utility/Gender.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_Gender )

   // For testing the Gender << redirect
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


   BOOST_AUTO_TEST_CASE( test_Gender ) {
      Gender aGender;

      BOOST_CHECK_NO_THROW( aGender = Gender::UNKNOWN_GENDER );
      BOOST_CHECK_EQUAL( aGender, Gender::UNKNOWN_GENDER );

      BOOST_CHECK_NO_THROW( aGender = Gender::MALE );
      BOOST_CHECK_EQUAL( aGender, Gender::MALE );

      BOOST_CHECK_NO_THROW( aGender = Gender::FEMALE );
      BOOST_CHECK_EQUAL( aGender, Gender::FEMALE );
   }


   BOOST_AUTO_TEST_CASE( test_Random_Gender ) {
      Gender aGender;

      BOOST_CHECK_NO_THROW( aGender = newRandomGender());
      BOOST_CHECK_GE( aGender, Gender::UNKNOWN_GENDER );
      BOOST_CHECK_LE( aGender, Gender::FEMALE );
   }


   BOOST_AUTO_TEST_CASE( test_Gender_Output ) {
      Gender unknownGender = Gender::UNKNOWN_GENDER;
      Gender maleGender    = Gender::MALE;
      Gender femaleGender  = Gender::FEMALE;

      /// Test the output of cout << someGender
      /// @see https://stackoverflow.com/questions/5405016/can-i-check-my-programs-output-with-boost-test
      {
         boost::test_tools::output_test_stream output;
         cout_redirect guard( output.rdbuf() );
         cout << unknownGender;
         BOOST_CHECK( output.is_equal("Unknown gender")  ) ;
         output.clear();
         cout << maleGender;
         BOOST_CHECK( output.is_equal("Male")  ) ;
         output.clear();
         cout << femaleGender;
         BOOST_CHECK( output.is_equal("Female")  ) ;
      }
   }

BOOST_AUTO_TEST_SUITE_END()
