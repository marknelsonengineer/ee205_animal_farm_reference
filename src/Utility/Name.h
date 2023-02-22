///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// A utility class for managing Animal names
///
/// @file   Name.h
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>  // For string & string_view
#include <vector>  // For vector<>

/// A utility class for managing Animal names
///
/// Names can come from several sources:
///
///    - #FROM_FILE:  A list of names in a file
///    - #FROM_SERIAL:  Monotonically generated names with an optional prefix and/or suffix
///
/// This class does not have setters as once it's instantiated, nothing needs
/// to change.
class Name {
public:  ////////////////////////// Type Definitions ///////////////////////////

   /// What type of name will this class serve?
   enum NameType { FROM_FILE    ///< The names are randomly selected from a list of names in a file
                  ,FROM_SERIAL  ///< The names are monotonically generated from a serial number
                 } ;
   typedef unsigned long serial_t;  ///< The datatype of the serial number

public:   //////////////////////// Constants ///////////////////////////////////

   static serial_t maxSerial;   ///< The largest possible serial number

protected:  ///////////////////////// Member Variables /////////////////////////
   enum NameType nameType;  ///< Enum that determines how names are generated;

   std::string fileName;  ///< If #FROM_FILE, the source filename
   std::vector<std::string> names;  ///< If #FROM_FILE, the collection of names read from the file

   std::string serialPrefix;  ///< If #FROM_SERIAL, print this before the serial number
   std::string serialSuffix;  ///< If #FROM_SERIAL, print this after the serial number
   serial_t serial = 0;   ///< If #FROM_SERIAL, then this is the serial number

public:  //////////////////////////// Constructors /////////////////////////////
   Name( std::string_view newFilename );  ///< Construct a #FROM_FILE Name class
   Name( std::string_view newSerialPrefix, std::string_view newSerialSuffix );  ///< Construct a #FROM_SERIAL Name class

public:  /////////////////////////// Public Methods ////////////////////////////
   std::string getNextName();  ///< Get the next name

   void reset();  ///< Erase and then re-load the names database or set the serial number to 0
   serial_t remainingNames() noexcept;  ///< Return the number of unique names left

public:  //////////////////////// Static Public Methods ////////////////////////
   static bool validateName( std::string_view newName ) ;  ///< Check if `newName` is valid
   static bool validateNotEmpty( std::string_view newName ) ;  ///< Return `true` if `newName` is not empty
   static bool validateTrimmed( std::string_view newName ) ;  ///< Return `true` if `newName` is left and right trimmed for whitespace
   static bool validateStartsWithAlpha( std::string_view newName ) ;  ///< Return `true` if `newName` starts with an alphabetic character (`A` - `Z` or `a` - `z`)
   static bool validateNoSpecialChars( std::string_view newName ) ;  ///< Return `true` if `newName` only contains `A` - `Z`, `a` - `z`, `0`-`9`, space and `-`
   static bool validateInteriorWhitespaceTrimmed( std::string_view newName ) ;  ///< Return `true` if `newName`'s interior whitespace is trimmed
};
