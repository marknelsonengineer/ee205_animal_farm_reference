///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// A generic collection class.
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


/// @return `true` if the Container is empty.  `false` if the Container has one or more Nodes in it.
bool Container::empty() const noexcept {
   return (count == 0);
}


/// @return The number of Nodes in the Container
unsigned int Container::size() const noexcept {
   return count ;
}


/// @param aNode Check this Node to see if it's in the List
///
/// @return `true` if `aNode` is in the List.  `false` if it's not.
bool Container::isIn( Node* aNode ) const {
   /// @throws invalid_argument If `aNode` is `nullptr`
   if( aNode == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": aNode must have a value." );
   }

   assert( aNode->validate() );

   return false;  /// For the most generic container (with no way to put things in it), it's always `false`.
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
