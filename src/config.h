///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file config.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   14_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <climits>

/// A grammatically correct title for the program
#define PROGRAM_TITLE "Animal Farm 1"

/// A short-title for the program (used for error messages)
#define PROGRAM_NAME  "animalfarm1"

/// The maximum number of cats the database can hold
#define MAX_CATS (1024)

/// A marker indicating a bad cat
#define BAD_CAT UINT_MAX

/// A gender... for educational use only.  This is not intended to be
/// inclusive of all possible genders
enum Gender { UNKNOWN_GENDER=0, MALE, FEMALE } ;

/// A breed of cat
enum Breed  { UNKNOWN_BREED=0, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX } ;

/// A color.  Can be used in many places.
enum Color  { UNKNOWN_COLOR=-1, BLACK=0, WHITE, RED, BLUE, GREEN, PINK } ;

/// The Weight of an animal
typedef float Weight ;
const Weight UNKNOWN_WEIGHT = -1 ;  ///< Set when the Weight is unknown

/// The license number for an animal
typedef unsigned long long License ;
const License UNKNOWN_LICENSE = 0 ;  /// Set when the license number is unknown
