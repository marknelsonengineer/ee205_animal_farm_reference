///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// A breed of cat
///
/// @file Breed.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   30_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <string>

#include "config.h"

/// A breed of cat
enum class Breed {
   UNKNOWN_BREED=0
  ,MAINE_COON
  ,MANX
  ,SHORTHAIR
  ,PERSIAN
  ,SPHYNX
} ;


/// Output Breed as a formatted string
///
/// @param lhs_stream The output stream to write to (usually `cout`).  `lhs` stands for Left Hand Side and means the left side of the `<<` operator.
/// @param rhs_Breed  The Breed to output.  `rhs` stands for Right Hand Side and means the right side of the `<<` operator.
/// @return `Unknown breed`, `Mane coon`, `Manx`, etc..
inline std::ostream& operator<<( std::ostream& lhs_stream, const Breed& rhs_Breed ) {
   switch( rhs_Breed ) {
      case Breed::UNKNOWN_BREED: return lhs_stream << "Unknown"    ;
      case Breed::MAINE_COON   : return lhs_stream << "Maine Coon" ;
      case Breed::MANX         : return lhs_stream << "Manx"       ;
      case Breed::SHORTHAIR    : return lhs_stream << "Shorthair"  ;
      case Breed::PERSIAN      : return lhs_stream << "Persian"    ;
      case Breed::SPHYNX       : return lhs_stream << "Sphynx"     ;
      default:
         /// @throw out_of_range If the enum is not mapped to a string.
         throw std::out_of_range( PROGRAM_NAME ": Breed is not mapped to a string" );
   }

   return lhs_stream;
}
