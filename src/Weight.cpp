///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   06_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>    // For assert()
#include <iostream>   // For cout
#include <stdexcept>  // For out_of_range
#include <iomanip>    // For setw() & setfill()

#include "Weight.h"

using namespace std;

const float Weight::UNKNOWN_WEIGHT = -1 ;

const float Weight::KILOS_IN_A_POUND = 0.453592 ;
const float Weight::SLUGS_IN_A_POUND = 0.031081 ;  ///< @see https://en.wikipedia.org/wiki/Slug_(unit)

const string Weight::POUND_LABEL = "Pound" ; ///< @see https://en.wikipedia.org/wiki/Pound_(mass)
const string Weight::KILO_LABEL  = "Kilo" ;  ///< @see https://en.wikipedia.org/wiki/Kilogram
const string Weight::SLUG_LABEL  = "Slug" ;  ///< @see https://en.wikipedia.org/wiki/Slug_(unit)


Weight::Weight() noexcept {
   assert( validate() );
}



Weight::Weight( const float newWeight ) {
   setWeight( newWeight );
   assert( validate() );
}


/// Once UnitOfWeight is set, it can't be changed
Weight::Weight( const Weight::UnitOfWeight newUnitOfWeight ) noexcept {
   unitOfWeight = newUnitOfWeight ;
   assert( validate() );
}


/// Once UnitOfWeight is set, it can't be changed
Weight::Weight( const float newWeight, const Weight::UnitOfWeight newUnitOfWeight ) : Weight( newUnitOfWeight ) {
   setWeight( newWeight, newUnitOfWeight );
   assert( validate() );
}


/// Once maxWeight is set, it can't be changed
Weight::Weight( const float newWeight, const float newMaxWeight ) {
   setMaxWeight( newMaxWeight );
   setWeight( newWeight );
   assert( validate() );
}


/// Once UnitOfWeight is set, it can't be changed.
/// Once maxWeight is set, it can't be changed.
Weight::Weight( const Weight::UnitOfWeight newUnitOfWeight, const float newMaxWeight ) : Weight( newUnitOfWeight ) {
   setMaxWeight( newMaxWeight );
   assert( validate() );
}


/// Once UnitOfWeight is set, it can't be changed.
/// Once maxWeight is set, it can't be changed.
Weight::Weight( const float newWeight
        ,const Weight::UnitOfWeight newUnitOfWeight
        ,const float newMaxWeight ) : Weight( newUnitOfWeight, newMaxWeight ) {
   setWeight( newWeight );
   assert( validate() );
}


bool Weight::isWeightKnown() const noexcept {
   assert( validate() );

   return bIsKnown;
}


bool Weight::hasMaxWeight() const noexcept {
   assert( validate() );

   return bHasMax;
}


/// If the weight is not known, return UNKNOWN_WEIGHT.
float Weight::getWeight() const noexcept {
   assert( validate() );

   if( bIsKnown )
      return weight ;
   else
      return UNKNOWN_WEIGHT ;
}


float Weight::getWeight( const Weight::UnitOfWeight weightUnits ) const noexcept {
   assert( validate() );

   return convertWeight( weight, unitOfWeight, weightUnits );
}


/// If the maximum weight is not known, return UNKNOWN_WEIGHT.
float Weight::getMaxWeight() const noexcept {
   assert( validate() );

   if( bHasMax )
      return maxWeight ;
   else
      return UNKNOWN_WEIGHT ;
}


Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
   assert( validate() );

   return unitOfWeight ;
}


void Weight::setWeight( const float newWeight ) {
   assert( validate() );

   if( !isWeightValid( newWeight ) ) {
      /// @throws out_of_range When the weight is <=0 or > `maxWeight` (if `maxWeight` is set)
      throw out_of_range( "Weight is out of range" ) ;
   }

   weight = newWeight ;
   bIsKnown = true ;
   assert( validate() );
}


void Weight::setWeight( const float newWeight, const Weight::UnitOfWeight weightUnits ) {
   setWeight( convertWeight( newWeight, weightUnits, unitOfWeight ));
}


void Weight::setMaxWeight( const float newMaxWeight ) {
   /// The maximum weight should not be set when we start this routine
   assert( !bHasMax );

   if( !isWeightValid( newMaxWeight) ) {
      /// @throws out_of_range When the maximum weight is <= 0
      throw out_of_range( "The maximum weight is out of range" );
   }

   maxWeight = newMaxWeight;
   bHasMax = true ;

   // We can't do this yet as the weight hasn't been set yet
   // assert( bIsKnown == true && weight <= maxWeight );
}


bool Weight::isWeightValid( const float checkWeight ) const noexcept {
   /// Verify that `checkWeight` > 0
   if( checkWeight <= 0 ) {
      cout << "Weight [" << checkWeight << "] can not be <= 0" << endl ;
      return false;
   }

   /// If `bHasMax`, then `checkWeight` must be <= `maxWeight`
   if( bHasMax ) {
      if( checkWeight > maxWeight ) {
         cout << "Weight [" << checkWeight << "] is > the maximum weight [" << maxWeight << "]" << endl ;
         return false;
      }
   }

   return true;
}


bool Weight::validate() const noexcept {
   if( bHasMax ) {
      if( !isWeightValid(( maxWeight))) {
         cout << "Max weight is <= 0" << endl;
         return false;
      }

      assert( maxWeight > 0 );
   }

   if( bIsKnown ) {
      if( !isWeightValid( weight ) ) {
         return false;
      }

      assert( weight > 0);

      if( bHasMax ) {
         assert( weight <= maxWeight );
      }
   }

   return true;
}


float Weight::fromKilogramToPound( const float kilogram ) noexcept {
   return kilogram / KILOS_IN_A_POUND ;
}


float Weight::fromPoundToKilogram( const float pound ) noexcept {
   return pound * KILOS_IN_A_POUND ;
}


float Weight::fromSlugToPound( const float slug ) noexcept {
   return slug / SLUGS_IN_A_POUND ;
}


float Weight::fromPoundToSlug( const float pound ) noexcept {
   return pound * SLUGS_IN_A_POUND ;
}


float Weight::convertWeight( const float fromWeight
        ,const UnitOfWeight fromUnit
        ,const UnitOfWeight toUnit ) noexcept {
   float commonWeight = UNKNOWN_WEIGHT;

   switch( fromUnit ) {
      case POUND: commonWeight = fromWeight ;
         break;
      case KILO: commonWeight = fromKilogramToPound( fromWeight ) ;
         break;
      case SLUG: commonWeight = fromSlugToPound( fromWeight ) ;
         break;
      default: assert( false );  // We should never get here
   }

   // cout << "commonWeight = [" << commonWeight << "] " << POUND_LABEL << endl;

   float toWeight = UNKNOWN_WEIGHT;

   switch( toUnit ) {
      case POUND: toWeight = commonWeight ;  // No conversion necessary
         break;
      case KILO: toWeight = fromPoundToKilogram( commonWeight );
         break;
      case SLUG: toWeight = fromPoundToSlug( commonWeight );
         break;
      default: assert( false );  // We should never get here
   }

   // cout << fromWeight << " " << fromUnit << " is " << toWeight << " " << toUnit << endl ;

   return toWeight ;
}


/// Format a line for dumping the members of a class to the console
#define FORMAT_LINE( className, member ) std::cout \
                                      << std::setw(8) << (className) \
                                      << std::setw(20) << (member)   \
                                      << std::setw(52)  /* (data) */

/// #### Sample Output
/// @code
/// Weight noWeight;
///     ==============================================
///     Weight  this                0x7ffd00c73360
///     Weight  isKnown             false
///     Weight  weight              0
///     Weight  unitOfWeight        Pound
///     Weight  hasMax              false
///     Weight  maxWeight           0
///
/// Weight myWeight( 3.14, Weight::KILO, 20 );
///     ==============================================
///     Weight  this                0x7ffcc65aeb00
///     Weight  isKnown             true
///     Weight  weight              3.14
///     Weight  unitOfWeight        Kilo
///     Weight  hasMax              true
///     Weight  maxWeight           20
/// @endcode
///
void Weight::dump() const noexcept {
   // Print ===================================================================
   cout << setw(80) << setfill( '=' ) << "" << endl ;
   cout << setfill( ' ' ) ;   // Space pad
   cout << left ;             // Left justify
   cout << boolalpha ;        // Print `true` and `false` for `bool`s

   FORMAT_LINE( "Weight", "this" )         << this         << endl ;
   FORMAT_LINE( "Weight", "isKnown" )      << bIsKnown     << endl ;
   FORMAT_LINE( "Weight", "weight" )       << weight       << endl ;
   FORMAT_LINE( "Weight", "unitOfWeight" ) << unitOfWeight << endl ;
   FORMAT_LINE( "Weight", "hasMax" )       << bHasMax      << endl ;
   FORMAT_LINE( "Weight", "maxWeight" )    << maxWeight    << endl ;
   // FORMAT_LINE( "Weight", "<<" ) << this << endl ;
}


/// #### Output rules
///
///   - If the weight is unknown, print `Unknown`
///   - If the weight has a maximum weight, print the weight followed by ` out of ` and the maximum weight
///   - Print the unit.  If the last number that's printed is > 1, then make the unit plural by adding an `s`
///
/// #### Sample Output
///
/// Test vectors for Weight << override:
///     | Usage                                   | The Output              |
///     |-----------------------------------------|-------------------------|
///     | `Weight weight`                         | `Unknown`               |
///     | `Weight weight( 0.5 )`                  | `0.5 Pound`             |
///     | `Weight weight( 1 )`                    | `1 Pound`               |
///     | `Weight weight( 1.5 )`                  | `1.5 Pounds`            |
///     | `Weight weight( 1.5, Weight::KILO )`    | `1.5 Kilos`             |
///     | `Weight weight( 0.5, Weight::KILO, 1 )` | `0.5 out of 1 Kilo`     |
///     | `Weight weight( 0.5, Weight::KILO, 2 )` | `0.5 out of 2 Kilos`    |
///     | `Weight weight( Weight::KILO, 1 )`      | `Unknown out of 1 Kilo` |
///
std::ostream& operator<<( std::ostream& lhs_stream, const Weight& rhs_Weight ) {
   if( !rhs_Weight.isWeightKnown() && !rhs_Weight.hasMaxWeight() ) {
      lhs_stream << "Unknown" ;
      return lhs_stream;
   }
   else if( rhs_Weight.isWeightKnown() ) {
      lhs_stream << rhs_Weight.getWeight();
   } else {
      lhs_stream << "Unknown";
   }

   if( rhs_Weight.hasMaxWeight() ) {
      lhs_stream << " out of " << rhs_Weight.getMaxWeight();
   }

   lhs_stream << " " << rhs_Weight.getWeightUnit() ;

   /// If the numeric weight is 1, use the singular form of the unit.
   /// If the numeric weight is not 1, use the plural form of the unit.
   if(    ( !rhs_Weight.hasMaxWeight() && rhs_Weight.getWeight() > 1 )
          || ( rhs_Weight.hasMaxWeight() && rhs_Weight.getMaxWeight() > 1 ) ) {
      lhs_stream << "s";
   }

   return lhs_stream;
}


std::ostream& operator<<( ostream& lhs_stream, const Weight::UnitOfWeight rhs_UnitOfWeight ) {
   switch( rhs_UnitOfWeight ) {
      case Weight::POUND: return lhs_stream << Weight::POUND_LABEL ;
      case Weight::KILO:  return lhs_stream << Weight::KILO_LABEL ;
      case Weight::SLUG:  return lhs_stream << Weight::SLUG_LABEL ;
      default: throw out_of_range( "The unit can not be converted to a string" );
   }
}


bool Weight::operator==( const Weight& rhs_Weight ) const {
   /// Remember to convert the two weight's units into a common unit!
   /// Treat unknown weights as 0 (so we can sort them without dealing with exceptions)
   float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
   float rhs_weight = (rhs_Weight.bIsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;

   return lhs_weight == rhs_weight;
}


bool Weight::operator<( const Weight& rhs_Weight ) const {
   /// Remember to convert the two weight's units into a common unit!
   /// Treat unknown weights as 0 (so we can sort them without dealing with exceptions)
   float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
   float rhs_weight = (rhs_Weight.bIsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;

   return lhs_weight < rhs_weight;
}


/// It's assumed that rhs_addToWeight is in the same units as Weight
Weight& Weight::operator+=( const float rhs_addToWeight ) {
   if( !bIsKnown ) {
      /// @throws out_of_range When a mathematical operation is attempted when the weight is unknown
      throw out_of_range( "Weight is unknown" ) ;
   }

   setWeight( weight + rhs_addToWeight );

   return *this;
}
