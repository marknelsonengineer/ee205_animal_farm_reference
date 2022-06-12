///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// A general-purpose Array based collection class.
///
/// @file Array.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   26_May_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdexcept>  // For out_of_range
#include <cassert>    // For assert

#include "Array.h"

using namespace std;

/// This is a partial implementation.  It checks `newMaxSize >= 1` and
/// sets `maxSize`.  It does not actually allocate the Array.
Array::Array( const Container::t_size newMaxSize ) {
   if( !(newMaxSize >= 1) ) {
      /// @throws out_of_range The maximum size of the Array must be `>= 1`
      throw out_of_range( "The maximum size of the Array must be >= 1" );
   }

   maxSize = newMaxSize;
}


Container::t_size Array::getMaxSize() const noexcept {
   return maxSize;
}


bool Array::isFull() const noexcept {
   assert( !(count > maxSize) );  // Count is never > max size

   if( count == maxSize )
      return true;

   assert( count < maxSize );  // Kinda paranoid, but the post-condition is clear

   return false;
}


/// Remove all of the elements (from the highest index to 0)
void Array::removeAll() noexcept {
   assert( validate() );

   if( isEmpty() ) return;

   for( Container::t_size i = size() ; i > 0 ; ) {
      remove( --i );
   }

   assert( validate() );
}


/// Print the Array and then each Node in it
///
/// #### Sample Output
/**@verbatim
Object              class               CatPride
Object              this                0x7ffcda17af40
Container           count               4
Array               maxSize             4
================================================================================
@endverbatim */
void Array::dump() const noexcept {
   Container::dump();

   FORMAT_LINE_FOR_DUMP( "Array", "maxSize" )  << maxSize  << std::endl ;
}


/// If something is not right, print a message and stop the validation.
/// It will not throw an exception.
///
/// @note This method can not call `validate()` on each Node... that is left to
/// concrete Arrays.
///
/// @return `true` if the Array is healthy.  `false` if otherwise.
bool Array::validate() const noexcept {
   return Container::validate();

   assert( maxSize > 0 );      /// `maxSize` must be `> 0`
   // assert( count >= 0 );    /// `count` must be `>= 0`
   assert( count <= maxSize );  /// `count` must be `<= maxSize`.  For example, if `maxSize == 10`, then `count <= 10`.
}
