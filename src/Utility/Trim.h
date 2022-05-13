///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// General string-trimming functions
///
/// @file Trim.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   10_May_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>

extern std::string trim_left( const std::string inString ) noexcept;   ///< Remove all leading whitespace from `inString`
extern std::string trim_right( const std::string inString ) noexcept;  ///< Remove all trailing whitespace from `inString`
extern std::string trim( const std::string inString ) noexcept;  ///< Remove all leading and trailing whitespace from `inString`
extern std::string trim_in( const std::string inString ) noexcept;  ///< Trim leading & trailing whitespace and collapse consecutive interior whitespace into `" "`
