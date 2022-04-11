///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// Every Animal has a Weight.
///
/// @file Weight.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   06_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>
#include <ostream>

/// Every Animal has a Weight.
///
/// C++ maintains Weight as a `float`, however, weights in the physical world
/// have certain constraints (i.e. you can't have a negative weight -- or you
/// *may* have a maximum weight.
///
/// By default, the weight is UNKNOWN_WEIGHT.  Once it's known, it can never
/// be un-known.
///
/// If the Weight has a maximum weight, then weight must be <= it.  Also,
/// the weight can never be <= 0.  The maximum weight must be set in the
/// constructor and it can not be changed.
///
/// Weight can can be expressed in multiple units of measure.  The Weight's
/// unit of measure can be set in the constructor and can not be changed.  It
/// defaults to the POUND.
///
/// We are not fully implemented a good numeric class.  A full/complete
/// implementation would have overrides for the following operators:
/// `=  -=  *=  /=  %=  ++  --  +  -  *  /  >=  >  <=  !=` and `<=>`
///
/// @see https://en.wikipedia.org/wiki/Pound_(mass)
/// @see https://en.wikipedia.org/wiki/Kilogram
/// @see https://en.wikipedia.org/wiki/Slug_(unit)
///
class Weight {
public:  //////////////// Enumerations & Type Definitions //////////////////////
   /// A unit of measure for weight
   enum UnitOfWeight { POUND, KILO, SLUG };

   /// The native datatype of this Weight class
   typedef float t_weight;

public:   //////////////////////// Constants ///////////////////////////////////
   static const t_weight UNKNOWN_WEIGHT ;    ///< When a weight is not known, return this.

   static const t_weight KILOS_IN_A_POUND ;  ///< The number of kilos in a pound
   static const t_weight SLUGS_IN_A_POUND ;  ///< The number of slugs in a pound

   static const std::string POUND_LABEL ;       ///< Unit of measure for the pound
   static const std::string KILO_LABEL ;        ///< Unit of measure for the kilogram
   static const std::string SLUG_LABEL ;        ///< Unit of measure for the slug

private:  ////////////////////// Member Variables //////////////////////////////
   bool bIsKnown = false ;  ///< `true` if Weight is known.  Defaults to `false`.
   bool bHasMax = false ;   ///< `true` if Weight has a maximum weight defined.  Defaults to `false`.
   enum UnitOfWeight unitOfWeight = POUND ;  ///< How the Weight is held and displayed.  Defaults to POUND.
   ///< The UnitOfWeight can only be set when the Weight is constructed.

   t_weight weight{} ;      ///< The weight.  It must always be > 0.  If `maxWeight` is set then it must also be <= `maxWeight`.
   t_weight maxWeight{} ;   ///< The maximum weight.  The maximum weight can only be set when the Weight is constructed.

public:   //////////////////////// Constructors ////////////////////////////////
   explicit Weight() noexcept;  ///< A default weight
   explicit Weight( t_weight newWeight );  ///< A weight with a value
   explicit Weight( UnitOfWeight newUnitOfWeight ) noexcept;  ///< A weight with a UnitOfWeight
   explicit Weight( t_weight newWeight, UnitOfWeight newUnitOfWeight );  ///< A weight with a value and UnitOfWeight
   explicit Weight( t_weight newWeight, t_weight newMaxWeight );  ///< A weight with a value and a maximum weight
   explicit Weight( UnitOfWeight newUnitOfWeight, t_weight newMaxWeight );  ///< A weight with a UnitOfWeight and a maximum weight
   explicit Weight( t_weight newWeight, UnitOfWeight newUnitOfWeight, t_weight newMaxWeight );  ///< A weight with a value, UnitOfWeight and a maximum weight

public:   /////////////////////////// Getters  /////////////////////////////////
   bool  isWeightKnown() const noexcept;  ///< `true` if the weight is known
   bool  hasMaxWeight() const noexcept;   ///< `true` if the maximum weight is set
   t_weight getWeight() const noexcept;      ///< Get the weight in the Weight's units
   t_weight getWeight( UnitOfWeight weightUnits ) const noexcept;  ///< Get the weight in a specified unit
   t_weight getMaxWeight() const noexcept;   ///< Get the maximum weight
   UnitOfWeight getWeightUnit() const noexcept;  ///< Get the UnitOfWeight for this Weight

public:   /////////////////////////// Setters  /////////////////////////////////
   void setWeight( t_weight newWeight );  ///< Set the weight
   void setWeight( t_weight newWeight, UnitOfWeight weightUnits );  ///< Set the weight as a specified unit

private:   ///////////////////// Private Methods ///////////////////////////////
   void setMaxWeight( t_weight newMaxWeight );  ///< Set the maximum weight

public:   /////////////////////// Static Methods ///////////////////////////////
   // Static methods are `const` by default
   static float fromKilogramToPound( t_weight kilogram ) noexcept;  ///< Convert kilo to pound
   static float fromPoundToKilogram( t_weight pound ) noexcept;     ///< Convert pound to kilo
   static float fromSlugToPound( t_weight slug ) noexcept;          ///< Convert slug to pound
   static float fromPoundToSlug( t_weight pound ) noexcept;         ///< Convert pound to slug

   /// Convert fromWeight in fromUnit to the weight in toUnit
   static float convertWeight( t_weight fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit ) noexcept;

public:   /////////////////////// Public Methods ///////////////////////////////
   bool isWeightValid( t_weight checkWeight ) const noexcept;  ///< Check the weight
   bool validate() const noexcept;   ///< Check Weight to ensure it's healthy
   void dump() const noexcept;       ///< Print the Weight class

public:   ////////////////////// Public Overrides //////////////////////////////
   bool operator==( const Weight& rhs_Weight ) const;  ///< Weights are equal when their `weight`s are equal
   bool operator<( const Weight& rhs_Weight ) const;   ///< Compare two Weights
   Weight& operator+=( t_weight rhs_addToWeight );     ///< Add to an existing weight
};


/// Output Weight as a formatted string
///
/// @param lhs_stream     The output stream to write to (usually `cout`).  `lhs` stands for Left Hand Side and means the left side of the `<<` operator.
/// @param rhs_Weight The Weight to output.  `rhs` stands for Right Hand Side and means the right side of the `<<` operator.
/// @return `Unknown Pounds` or `3.14 out of 20 Kilos`
std::ostream& operator<<( std::ostream& lhs_stream, const Weight& rhs_Weight ) ;


/// Output the UnitOfMeasure as a formatted string
///
/// @param lhs_stream     The output stream to write to (usually `cout`).  `lhs` stands for Left Hand Side and means the left side of the `<<` operator.
/// @param rhs_UnitOfWeight The weight-unit to output.  `rhs` stands for Right Hand Side and means the right side of the `<<` operator.
/// @return Pound`, `Kilo` or `Slug` as defined by LABEL_POUND, LABEL_KILO or LABEL_SLUG
std::ostream& operator<<( std::ostream& lhs_stream, Weight::UnitOfWeight rhs_UnitOfWeight );
