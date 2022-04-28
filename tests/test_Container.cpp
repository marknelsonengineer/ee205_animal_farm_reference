///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab14a_animal_farm_4 - EE 205 - Spr 2022
///
/// Comprehensive test of the Container class
///
/// @file test_Container.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <stdexcept>

#include "../src/Container/Container.h"

using namespace std;

BOOST_AUTO_TEST_CASE( test_Container ) {
   Container testContainer;

   BOOST_CHECK_EQUAL( testContainer.empty(), true );
   BOOST_CHECK_EQUAL( testContainer.size(), 0 );
   BOOST_CHECK_EQUAL( testContainer.validate(), true );
   BOOST_CHECK_NO_THROW( testContainer.dump() );
}
