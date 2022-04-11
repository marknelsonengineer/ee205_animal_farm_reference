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

BOOST_AUTO_TEST_CASE( test_Cat ) {
   Cat aCat( "Chili" );

   aCat.dump();
}
