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


/// @param breed The breed `enum` to lookup
inline std::string breedToString( Breed breed ) {
   switch( breed ) {
      case Breed::UNKNOWN_BREED: return "Unknown"    ;
      case Breed::MAINE_COON   : return "Maine Coon" ;
      case Breed::MANX         : return "Manx"       ;
      case Breed::SHORTHAIR    : return "Shorthair"  ;
      case Breed::PERSIAN      : return "Persian"    ;
      case Breed::SPHYNX       : return "Sphynx"     ;
   }
   /// @throw out_of_range If the enum is not mapped to a string.
   throw std::out_of_range( PROGRAM_NAME ": Breed not mapped to a string" );
}
