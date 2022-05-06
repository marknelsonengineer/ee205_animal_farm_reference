///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// A color class
///
/// @file Color.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   11_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <string>

#include "../config.h"

/// Color class enumeration
enum class Color {
   UNKNOWN_COLOR=0
  ,BLACK
  ,BROWN
  ,WHITE
  ,RED
  ,BLUE
  ,GREEN
  ,GINGER
  ,CREAM
  ,CINNAMON
  ,CALICO
} ;


/// Output Color as a formatted string
///
/// @param lhs_stream The output stream to write to (usually `cout`).  `lhs` stands for Left Hand Side and means the left side of the `<<` operator.
/// @param rhs_Color The Color to output.  `rhs` stands for Right Hand Side and means the right side of the `<<` operator.
/// @return `Unknown color`, `Black` or `Blue`.
inline std::ostream& operator<<( std::ostream& lhs_stream, const Color& rhs_Color ) {
   switch( rhs_Color ) {
      case Color::UNKNOWN_COLOR:
         lhs_stream << "Unknown color";
         break;
      case Color::BLACK:
         lhs_stream << "Black";
         break;
      case Color::BROWN:
         lhs_stream << "Brown";
         break;
      case Color::WHITE:
         lhs_stream << "White";
         break;
      case Color::RED:
         lhs_stream << "Red";
         break;
      case Color::BLUE:
         lhs_stream << "Blue";
         break;
      case Color::GREEN:
         lhs_stream << "Green";
         break;
      case Color::GINGER:
         lhs_stream << "Ginger";
         break;
      case Color::CREAM:
         lhs_stream << "Cream";
         break;
      case Color::CINNAMON:
         lhs_stream << "Cinnamon";
         break;
      case Color::CALICO:
         lhs_stream << "Calico";
         break;
      default:
         /// @throw out_of_range If the enum is not mapped to a string.
         throw std::out_of_range( PROGRAM_NAME ": Color not mapped to a string" );
   }

   return lhs_stream;
}
