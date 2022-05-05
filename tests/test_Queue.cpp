///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// Comprehensive test of the Queue class
///
/// @file test_Queue.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   05_May_2022
///////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

#include "../src/Container/Queue.h"
#include "../src/Utility/QueueSimulator.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_Queue )

   BOOST_AUTO_TEST_CASE( simulate_Queue ) {
      QueueSimulator queueSimulator;

      BOOST_TEST_MESSAGE( "Test a Queue for " << queueSimulator.ITERATIONS << " iterations" ) ;

      BOOST_REQUIRE_NO_THROW( queueSimulator.runQueueSimulator( false ) );
   }

BOOST_AUTO_TEST_SUITE_END()
