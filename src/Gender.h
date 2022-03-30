///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// A gender... for educational use only.
/// This is not intended to be inclusive of all possible genders
///
/// @file Gender.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   30_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <string>

#include "config.h"

/// A gender... for educational use only.  This is not intended to be
/// inclusive of all possible genders
enum class Gender {
    UNKNOWN_GENDER=0
   ,MALE
   ,FEMALE
};


/// @param gender The gender `enum` to lookup
inline std::string genderToString( Gender gender ) {
   switch( gender ) {
      case Gender::UNKNOWN_GENDER: return "Unknown gender";
      case Gender::MALE:           return "Male";
      case Gender::FEMALE:         return "Female";
   }

   /// @throw out_of_range If the enum is not mapped to a string.
   throw std::out_of_range( PROGRAM_NAME ": Gender not mapped to a string" );
}
