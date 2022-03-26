///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file config.h
/// @version 2.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   14_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

/// A grammatically correct title for the program
#define PROGRAM_TITLE "Animal Farm 2"

/// A short-title for the program (used for console messages)
#define PROGRAM_NAME  "animalfarm2"

/// A gender... for educational use only.  This is not intended to be
/// inclusive of all possible genders
enum Gender { UNKNOWN_GENDER=0, MALE, FEMALE } ;

/// A breed of cat
enum Breed  { UNKNOWN_BREED=0, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX } ;

// A color.  Can be used in many places.
// enum Color  { UNKNOWN_COLOR=-1, BLACK=0, WHITE, RED, BLUE, GREEN, PINK } ;

/// The Weight of an animal
typedef float Weight ;
const Weight UNKNOWN_WEIGHT = -1 ;  ///< Set when the Weight is unknown
