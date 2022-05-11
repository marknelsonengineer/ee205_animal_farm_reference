///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// A utility class for managing lists of Animal names
///
/// @file Name.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   10_May_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>
#include <vector>

/// A utility class for managing lists of Animal names
///
/// Names can come from several sources:
///
///    - #FROM_FILE:  A list of names in a file
///    - #FROM_SERIAL:  Monotonically generated names
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
   enum NameType nameType;  ///< Holds how the names are generated;

   std::string fileName;  ///< If FROM_FILE, then the source filename
   std::vector<std::string> names;  ///< If #FROM_FILE, then this is the set of names

   std::string serialPrefix;  ///< If #FROM_SERIAL, then print this before the serial number
   std::string serialSuffix;  ///< If #FROM_SERIAL, then print this after the serial number
   serial_t serial = 0;   ///< If #FROM_SERIAL, then this is the serial number

public:  //////////////////////////// Constructors /////////////////////////////
   Name( std::string newFilename );  ///< Construct a #FROM_FILE Name class
   Name( std::string newSerialPrefix, std::string newSerialSuffix );  ///< Construct a #FROM_SERIAL Name class

public:  /////////////////////////// Public Methods ////////////////////////////
   std::string getNextName() noexcept;  ///< Get the next name

   void reset();  ///< Erase and then re-load the names database
   serial_t remainingNames() noexcept;  ///< Return the number of unique names left

   static bool validateName( const std::string& newName ) ;  ///< Check if `newName` is valid
};
