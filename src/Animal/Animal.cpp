///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2022
//
/// Where the Wild Things Are
///
/// @file Animal.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   30_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>    // For assert()
#include <iostream>   // For cout
#include <stdexcept>  // For out_of_range
#include <iomanip>    // For setw() & setfill()
#include <boost/core/typeinfo.hpp>  // for typeinfo()

#include "../config.h"
#include "Animal.h"
#include "../Utility/Trim.h"
#include "../Utility/Name.h"

using namespace std;


/// @param newMaxWeight Must be a valid weight per Weight::isWeightValid
/// @param newClassification Must be a valid name per Name::validateName
/// @param newSpecies Must be a valid name per Name::validateName
Animal::Animal( const Weight::t_weight newMaxWeight
              , const std::string_view newClassification
              , const std::string_view newSpecies )
              : Node()                                           // Delegating constructor
              , species { trim_in( newSpecies ) }                // Member initializer list
              , classification { trim_in( newClassification ) }  // Member initializer list
              , weight( Weight::POUND, newMaxWeight ) {          // Delegating constructor

   if( !Name::validateName( newClassification ) ) {
      /// @throws invalid_argument When the classification is invalid per Name::validateName
      throw invalid_argument( "The classification [" + classification + "] is invalid" );
   }

   if( !Name::validateName( newSpecies ) ) {
      /// @throws invalid_argument When the species is invalid per Name::validateName
      throw invalid_argument( "The species [" + species + "] is invalid" );
   }

   Animal::validate();
}


/// @param newGender The Gender of the Animal
/// @param newWeight Must be a valid weight per Weight::isWeightValid
/// @param newMaxWeight Must be a valid weight per Weight::isWeightValid
/// @param newClassification Must be a valid name per Name::validateName
/// @param newSpecies Must be a valid name per Name::validateName
Animal::Animal( const Gender newGender
              , const Weight::t_weight newWeight
              , const Weight::t_weight newMaxWeight
              , const string_view newClassification
              , const string_view newSpecies )
              : Animal( newMaxWeight, newClassification, newSpecies ) {  // Delegating constructor

   setGender( newGender );
   weight.setWeight( newWeight );

   Animal::validate();
}


/// This can be `static` but for symmetry with the other `get` methods, I'm
/// leaving it in the class
///
/// @return #KINGDOM_NAME
std::string_view Animal::getKingdom() const noexcept {
   return KINGDOM_NAME;
}


std::string_view Animal::getClassification() const noexcept {
   return classification;
}


std::string_view Animal::getSpecies() const noexcept {
   return species;
}


Gender Animal::getGender() const noexcept {
   return gender;
}


Weight::t_weight Animal::getWeight() const noexcept {
   return weight.getWeight() ;
}


void Animal::setWeight( const Weight::t_weight newWeight ) {
   validate();
   weight.setWeight( newWeight );
   validate();
}


/// This is not normally called as you can't change an Animal's gender, therefore
/// this method is protected.
///
/// You can only change the gender if it's currently UNKNOWN_GENDER.
///
/// @param newGender The new gender
void Animal::setGender( const Gender newGender ) {
   if( gender != Gender::UNKNOWN_GENDER ) {
      /// @throws logic_error If you try to change the gender of an Animal
      throw logic_error( PROGRAM_NAME ": The gender is already set, you can't change it" ) ;
   }

   // At this point, gender is unknown...
   assert( gender == Gender::UNKNOWN_GENDER );

   validate();
   gender = newGender ;
   validate();
}


/// Ideally, this will print out the sort keys a given Animal on the Farm
///
/// #### Sample Output
/**@verbatim
The Cat (Felis Catus) named Rose at 0x676b20 says Meow
@endverbatim */
std::string Animal::info() const noexcept {
   // Put the address of this object into a string
   std::stringstream stringStream;
   stringStream << this;
   std::string theAddressOfThis = stringStream.str();

   string infoString {};

   // Print the class
   infoString += "The ";
   infoString += boost::core::demangled_name( BOOST_CORE_TYPEID( *this ));
   infoString += " (" + species + ")";
   infoString += " named ";
   infoString += getName();
   infoString += " at ";
   infoString += theAddressOfThis;
   infoString += " says ";
   infoString += speak();
   return infoString;
}


/// Output the contents of this object (and its parents).
///
/// #### Sample Output
/**@verbatim
======================================================
Animal              kingdom             Animalia
Animal              classification      Mammalia
Animal              species             Felis Catus
Animal              gender              Unknown gender
Animal              weight              Unknown out of 40 Pounds
@endverbatim */
void Animal::dump() const noexcept {
   assert( validate() ) ;

   PRINT_HEADING_FOR_DUMP ;

   Node::dump();

   FORMAT_LINE_FOR_DUMP( "Animal", "kingdom" ) << getKingdom() << endl ;
   FORMAT_LINE_FOR_DUMP( "Animal", "classification" ) << getClassification() << endl ;
   FORMAT_LINE_FOR_DUMP( "Animal", "species" ) << getSpecies() << endl ;
   FORMAT_LINE_FOR_DUMP( "Animal", "gender" ) << getGender() << endl ;
   FORMAT_LINE_FOR_DUMP( "Animal", "weight" ) << weight << endl ;
}


bool Animal::validate() const noexcept {
   assert( Node::validate());

   assert( !getKingdom().empty());
   assert( Name::validateName( getSpecies()));
   assert( Name::validateName( getClassification()));
   /// Nothing to validate for Gender
   assert( weight.validate());

   return true;
}


/// @anchor Animal_comparison
/// The `this` member is the left side of the operator.
/// @param rhs_animal `rhs` stands for Right Hand Side and is the right side of the operator.
/// @return `true` if `this` < `rhs_animal`
bool Animal::operator<( const Animal& rhs_animal ) const {
   if( classification < rhs_animal.classification )
      return true;
   if( rhs_animal.classification < classification )
      return false;
   // If the two `classifications` are equal, compare `species`
   return species < rhs_animal.species;
}


/// The actual implementation is in @ref Animal_comparison "operator<( Animal& rhs_animal )"
bool Animal::operator<=( const Animal& rhs_animal ) const {
   return !( rhs_animal < *this );
}


/// The actual implementation is in @ref Animal_comparison "operator<( Animal& rhs_animal )"
bool Animal::operator>( const Animal& rhs_animal ) const {
   return rhs_animal < *this;
}


/// The actual implementation is in @ref Animal_comparison "operator<( Animal& rhs_animal )"
bool Animal::operator>=( const Animal& rhs_animal ) const {
   return !( *this < rhs_animal );
}


/// @anchor Animal_Node_comparison
/// Compare an Animal and a Node.  This is the operator that gets overridden by a generic comparison (for example in an algorithm that knows about Nodes, but not Animals).
///
/// The `this` member is the left side of the operator.
/// @param rhs_node `rhs` stands for Right Hand Side and is the right side of the operator.
/// @return `true` if `this` < `rhs_node`
bool Animal::operator<( const Node& rhs_node ) const {
   try {
      const Animal& rhs_animal = dynamic_cast<const Animal&>(rhs_node);  /// First, try to dynamically cast `rhs_node` to an Animal.
      return *this < rhs_animal;          /// If both the left and right sides are Animals, then, use the Animal comparison like @ref Animal_comparison "operator<( Animal& rhs_animal )"
   } catch ( bad_cast& exception ) {      /// If `rhs_node` is not an Animal, it will throw a `bad_cast` exception...
      return Node::operator<( rhs_node ); /// which will be caught and we will use a Node comparison like Node::operator<
   }
}


/// The actual implementation is in @ref Animal_Node_comparison "operator<( Node& rhs_node )"
bool Animal::operator<=( const Node& rhs_node ) const {
   return Node::operator<=( rhs_node );
}


/// The actual implementation is in @ref Animal_Node_comparison "operator<( Node& rhs_node )"
bool Animal::operator>( const Node& rhs_node ) const {
   return Node::operator>( rhs_node );
}


/// The actual implementation is in @ref Animal_Node_comparison "operator<( Node& rhs_node )"
bool Animal::operator>=( const Node& rhs_node ) const {
   return Node::operator>=( rhs_node );
}
