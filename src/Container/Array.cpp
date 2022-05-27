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

/// This is a partial implementation.  It checks newMaxSize is >= 1 and
/// sets maxSize.  It does not actually allocate the Array.
Array::Array( size_t newMaxSize ) {
   if( !(newMaxSize >= 1) ) {
      /// @throws out_of_range The maximum size of the Array must be >= 1
      throw out_of_range( "The maximum size of the Array must be >= 1" );
   }

   maxSize = newMaxSize;
}


/// Remove all of the elements (from the highest index to 0)
void Array::removeAll() noexcept {
   for( Container::t_size i = size() ; i > 0 ; i-- ) {
      remove( i );
   }
}


/// Print the Array and then each Node in it
///
/// #### Sample Output
/**@verbatim
/// @todo Replace this when we have a concrete Array
...
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

   assert( maxSize > 0 );      /// `maxSize` must be `>= 1`
   // assert( count >= 0 );    /// `count` must be `>= 0`
   assert( count < maxSize );  /// `count` must be `< maxSize`.  For example, if maxSize is 10, then count must be 9 or less.
}


/// This method only validates the parameters.  It *may* be able to do the actual swap
/// @todo Check on the swap
void Array::swap( size_t index1, size_t index2 ) {
   // if( index1 < 0 || index2 < 0) {
   //    /// @throws out_of_range Indexes into the Array must be >= 0
   //    throw out_of_range( "Indexes into the Array must be >= 0" );
   // }

   if( index1 > count || index2 > count ) {
      /// @throws out_of_range Indexes into the Array must be <= count
      throw out_of_range( "Indexes into the Array must be <= count" );
   }

   this->operator[](1);

   std::swap( (*this)[index1], (*this)[index2] );
   // std::swap( this->operator[](1), this->operator[](1) );
}
