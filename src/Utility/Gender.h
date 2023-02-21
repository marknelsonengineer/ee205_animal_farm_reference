///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// A gender class... for educational use only.
/// This is not intended to be inclusive of all possible genders
///
/// @file   Gender.h
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../config.h"  // For PROGRAM_NAME

#include <iostream>  // For ostream


/// A gender... for educational use only.  This is not intended to be
/// inclusive of all possible genders
enum class Gender {
    UNKNOWN_GENDER=0   ///< Used when the gender is unknown
   ,MALE               ///< Mammals with an XY chromosome
   ,FEMALE             ///< Mammals with 2 X chromosomes
};


/// Get a random Gender
extern Gender newRandomGender();


/// Output Gender as a formatted string
///
/// @param lhs_stream The output stream to write to (usually `cout`).
///                   `lhs` stands for Left Hand Side and means the left side
///                   of the `<<` operator.
/// @param rhs_Gender The Gender to output.
///                   `rhs` stands for Right Hand Side and means the right
///                   side of the `<<` operator.
/// @return `Unknown gender`, `Female` or `Male`.
inline std::ostream& operator<<( std::ostream& lhs_stream, const Gender& rhs_Gender ) {
   switch( rhs_Gender ) {
      case Gender::UNKNOWN_GENDER:
         lhs_stream << "Unknown gender";
         break;
      case Gender::MALE:
         lhs_stream << "Male";
         break;
      case Gender::FEMALE:
         lhs_stream << "Female";
         break;
      default:
         /// @throw out_of_range If the enum is not mapped to a string.
         throw std::out_of_range( PROGRAM_NAME ": Gender not mapped to a string" );
   }

   return lhs_stream;
}
