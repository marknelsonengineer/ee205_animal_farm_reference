///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// General string-trimming functions
///
/// There are *so many ways* to implement string trimming...
///
///   - Maximize clarity and understandability
///   - Maximize efficiency
///   - Use an advanced C++ feature
///
/// This implementation is designed to try to balance all three.
///
/// @file Trim.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   10_May_2022
///////////////////////////////////////////////////////////////////////////////

#include <string>

#include "Trim.h"

using namespace std;


/// Get the first non-whitespace character starting from the left.
///
/// This function is static in order to be private to Trim.cpp
static size_t get_left_start_char( const string_view inString ) noexcept {
   size_t i = 0;
   while( i < inString.size() && isspace( inString[i] ) ) {
      i++;
   }

   return i;
}


/// Get the last non-whitespace character in the string
///
/// This function is static in order to be private to Trim.cpp
static size_t get_right_start_char( const string_view inString ) noexcept {
   size_t i = inString.size();
   while( i > 0 ) {
      if( isspace( inString[i-1] )) {
         i--;
      } else {
         break;
      }
   }

   return i;
}

/// @see https://en.cppreference.com/w/cpp/string/byte/isspace
/// @see https://en.cppreference.com/w/cpp/string/basic_string/substr
string_view trim_left( const string_view inString ) noexcept {
   return inString.substr( get_left_start_char( inString ), inString.size() );
}


/// @see https://en.cppreference.com/w/cpp/string/byte/isspace
/// @see https://en.cppreference.com/w/cpp/string/basic_string/substr
std::string_view trim_right( const std::string_view inString ) noexcept {

   return( inString.substr( 0, get_right_start_char( inString ) ) );
}

/// This trim function does not modify the interior of the string
///
/// @see https://en.cppreference.com/w/cpp/string/byte/isspace
/// @see https://en.cppreference.com/w/cpp/string/basic_string/substr
std::string_view trim( const std::string_view inString ) noexcept {
   const size_t left_start_char = get_left_start_char( inString );
   const size_t right_start_char = get_right_start_char( inString );

   return( inString.substr( left_start_char, right_start_char - left_start_char ) );
}


/// This function does the following:
///
///    - Trim the leading whitespace
///    - Trim trailing whitespace
///    - Replace consecutive whitespace characters inside the string with
///      a single `" "`
std::string trim_in( const std::string_view inString ) noexcept {
   if( inString.empty() ) {
      return ""s;
   }

   char* buffer = (char*) malloc( inString.size()+1 );

   size_t inStringIndex = 0;
   size_t bufferIndex   = 0;

   // Find the first non-whitespace character in inString...
   while( isspace( inString[inStringIndex] ) && inStringIndex < inString.size() ) {
      inStringIndex++;
   }

   // cout << "1) inStringIndex=" << inStringIndex << "    bufferIndex=" << bufferIndex << endl;

   while( inStringIndex < inString.size() ) {
      // Copy non-whitespace characters from inString to buffer
      while( !isspace( inString[inStringIndex] ) &&
             inStringIndex < inString.size()) {
         buffer[bufferIndex++] = inString[inStringIndex++];
      }

      // cout << "2) inStringIndex=" << inStringIndex << "    bufferIndex=" << bufferIndex << endl;

      // We are either at the end or at a whitespace character.  If we are at a
      // whitespace character, move a space into the buffer...
      if( inStringIndex < inString.size()) {
         buffer[bufferIndex++] = ' ';
      }

      // cout << "3) inStringIndex=" << inStringIndex << "    bufferIndex=" << bufferIndex << endl;

      // Skip first non-whitespace characters in inString...
      while( isspace( inString[inStringIndex] ) &&
             inStringIndex < inString.size()) {
         inStringIndex++;
      }
   }

   // Trim the space off the end of the buffer
   if( buffer[bufferIndex-1] == ' ' ) {
      buffer[bufferIndex - 1] = '\0';
   }

   // Don't forget to null-terminate
   buffer[bufferIndex++] = '\0';

   return std::string{ buffer };
}
