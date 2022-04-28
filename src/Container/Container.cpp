///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab14a_animal_farm_4 - EE 205 - Spr 2022
///
/// A generic list-based collection class.
///
/// @file Container.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>

#include "../config.h"
#include "Container.h"

using namespace std;


/// @return `true` if the Container is empty.  `false` if the Container has Nodes in it.
bool Container::empty() const noexcept {
   return (count == 0);
}


/// @return The number of Nodes in the Container
unsigned int Container::size() const noexcept {
   return count ;
}


void Container::dump() const noexcept {
   FORMAT_LINE_FOR_DUMP( "Container", "this" )  << this  << std::endl ;
   FORMAT_LINE_FOR_DUMP( "Container", "count" ) << count << std::endl ;
}


/// If something is not right, print a message and stop the validation.
/// It will not throw an exception, but it may violate an `assert()`.
///
/// @return `true` if the Container is healthy.  `false` if otherwise.
bool Container::validate() const noexcept {
   if( count == 0 ) {
      assert( empty() );
   } else {
      assert( !empty() );
   }

   return true ;  // All is well
}
