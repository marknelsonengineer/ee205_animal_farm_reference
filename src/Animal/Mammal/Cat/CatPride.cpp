///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// A specialized static Array that holds Cats
///
/// @file   CatPride.cpp
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <cassert>    // For assert()
#include <random>
#include <stdexcept>  // For logic_error, length_error and out_of_range

#include "CatPride.h"

/// The Cat that occupies empty elements in the Array
#define NULL_CAT Cat("X")

using namespace std;


CatPride::CatPride() : Array( MAX_CATS )
                     , catArray { NULL_CAT, NULL_CAT, NULL_CAT, NULL_CAT } { }


void CatPride::add( Cat* newCat ) {
   if( isFull() ) {
      /// @throws length_error If the Array is full
      throw length_error( "The array is full.  Unable to add a new Cat." );
   }

   if( newCat == nullptr ) {
      /// @throws invalid_argument If `newCat == nullptr`
      throw invalid_argument( "Can't add a nullptr Cat" );
   }

   assert( newCat->validate() );

   assert( validate() );
   catArray[count++] = *newCat;
   assert( validate() );
}


/// #### Internal
/// If `index` is an existing Cat, then replace it.
void CatPride::add( Cat* newCat, const Container::t_size index ) {
   if( index == count ) { /// If `index` points to the next available index in the
      add( newCat );      /// Array, then add `newCat` to the end of the Array.
      return;
   }

   if( index > count ) {
      /// @throws out_of_range If `index > count`
      throw out_of_range( "Can not add a Cat beyond the end of the Array" );
   }

   assert( index < count );

   if( newCat == nullptr ) {
      /// @throws invalid_argument If `newCat == nullptr`
      throw invalid_argument( "Can't add a nullptr Cat" );
   }

   assert( newCat->validate() );

   assert( validate() );
   catArray[index] = *newCat;
   assert( validate() );
}


bool CatPride::isIn( const Cat* aCat ) const {
   if( isEmpty() ) { return false; }

   if( aCat == nullptr ) { return false; }

   assert( aCat->validate() );

   for( Container::t_size i = 0 ; i < count ; i++ ) {
      /// @todo Think about what constitutes `==` between two Cats.
      /// For now, `==` between two cats means they are the exact same object and
      /// they have the same address in memory
      if( &catArray[i] == aCat ) { return true; }
   }

   return false;  // Searched the array and never got a match
}


/// @return A random Cat... or `nullptr` if the Array is empty
Cat* CatPride::getRandomNode() const noexcept {
   if( isEmpty() ) { return nullptr; }

   uniform_int_distribution<> indexRNG( 0, (int) count-1 );
   Container::t_size index = indexRNG( ANIMAL_FARM_RNG );

   assert( catArray[index].validate() );

   return (Cat*) &catArray[index];
}


/// The Cat that's returned may be either an lvalue or an rvalue.
Cat& CatPride::operator[]( const Container::t_size index ) {
   if( !(index < count) ) {
      /// @throws out_of_range If index is `>= count`
      throw out_of_range( "Indexes into the Array must be less than the size of the array" );
   }

   return catArray[index];
}


/// Print the Array and then each Cat in it
///
/// #### Sample Output
/**@verbatim
Object              class               CatPride
Object              this                0x7ffcda17af40
Container           count               4
Array               maxSize             4
================================================================================
================================================================================
Object              class               Cat
Object              this                0x7ffcda17af58
Node                next                0
Node                prev                0
Node                left                0
Node                right               0
Animal              kingdom             Animalia
Animal              classification      Mammalia
Animal              species             Felis Catus
Animal              gender              Male
Animal              weight              21.8408 out of 40 Pounds
Mammal              color               Green
Cat                 name                Mila
Cat                 isFixed             true
@endverbatim */
void CatPride::dump() const noexcept {
   Array::dump();

   PRINT_HEADING_FOR_DUMP;

   if( isEmpty() ) { return; }

   for( Container::t_size i = 0 ; i < count ; i++ ) {
      catArray[i].dump();
   }
}


bool CatPride::validate() const noexcept {
   assert( Array::validate() );

   for( Container::t_size i = 0 ; i < count ; i++ ) {
      assert( catArray[i].validate() );
   }

   for( Container::t_size i = count ; i < maxSize ; i++ ) {
      assert( catArray[i].validate() );
      // cout << "catArray[" << i << "]     name=[" << catArray[i].getName() << "]" << endl;
      // catArray[i].dump();
      assert( catArray[i].getName() == "X" );
      assert( catArray[i].getKingdom() == Animal::KINGDOM_NAME );
      assert( catArray[i].getClassification() == Mammal::CLASSIFICATION_NAME );
      assert( catArray[i].getSpecies() == Cat::SPECIES_NAME );
      assert( catArray[i].getWeight() == Weight::UNKNOWN_WEIGHT );
      assert( catArray[i].getGender() == Gender::UNKNOWN_GENDER );
      assert( catArray[i].getColor() == Color::UNKNOWN_COLOR );
   }

   return true;
}


/// #### Internal
/// Find the `index` to `catToRemove` then call remove( const Container::t_size index )
Cat* CatPride::remove( Cat* catToRemove ) {
   if( catToRemove == nullptr ) {
      /// @throws invalid_argument If `catToRemove == nullptr`
      throw invalid_argument( "Can't remove a nullptr Cat" );
   }

   for( Container::t_size i = 0 ; i < count ; i++ ) {
      /// @todo Think about what constitutes `==` between two Cats.
      /// For now, `==` between two cats means they are the exact same object and
      /// they have the same address in memory
      if( &catArray[i] == catToRemove ) {
         return remove( i );
      }
   }

   return nullptr;  /// Return `nullptr` if the Cat can't be found
}


/// #### Internal
/// Use swap() to bubble the Node to delete to the end of the Array and then
/// delete it.
///
/// @param index The index to the Cat to delete.
/// @return Always returns `nullptr`.  Because the storage is an Array, the
///         Cat will be destroyed and not reallocated on the heap.
Cat* CatPride::remove( const Container::t_size index ) {
   if( index >= count ) {
      /// @throws out_of_range If index is `>= count`
      throw out_of_range( "Can not remove a Cat beyond the end of the Array" );
   }

   if( isEmpty() ) {
      return nullptr;
   }

   assert( validate() );

   // cout << "remove index=" << index << "   count=" << count << endl;

   for( Container::t_size i = index ; i+1 < count ; i++ ) {
      // cout << "swap( " << i << ", " << i+1 << " )" << endl;
      swap( i, i+1 );
   }

   // At this point, the node to delete is at the end of the Array
   assert( count >= 1 );

   catArray[count-1] = NULL_CAT;
   count -= 1;

   assert( validate() );

   return nullptr;
}


void CatPride::swap( const Container::t_size index1,
                     const Container::t_size index2 ) {
   if( index1 >= count || index2 >= count ) {
      /// @throws out_of_range If either index is `>= count`
      throw out_of_range( "Can not move a Cat beyond the end of the Array" );
   }

   if( index1 == index2 ) {
      return;
   }

   assert( validate() );

   Cat tempCat { catArray[index1] };
   catArray[index1] = catArray[index2];
   catArray[index2] = tempCat;

   assert( validate() );
}
