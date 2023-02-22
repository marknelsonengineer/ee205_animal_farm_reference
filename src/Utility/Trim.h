///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// General string-trimming functions
///
/// @file   Trim.h
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>

extern std::string_view trim_left(  std::string_view inString ) noexcept;  ///< Remove all leading whitespace from `inString`
extern std::string_view trim_right( std::string_view inString ) noexcept;  ///< Remove all trailing whitespace from `inString`
extern std::string_view trim(       std::string_view inString ) noexcept;  ///< Remove all leading and trailing whitespace from `inString`
extern std::string      trim_in(    std::string_view inString ) noexcept;  ///< Trim leading & trailing whitespace and collapse consecutive interior whitespace into `" "`
