///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   14_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <cstddef>   // For the size_t datatype

#include "config.h"

/// The maximum size of a cat's name
#define MAX_CAT_NAME (50)

/// A gender... for educational use only.  This is not intended to be
/// inclusive of all possible genders
enum Gender { UNKNOWN_GENDER=0, MALE, FEMALE } ;

/// A breed of cat
enum Breed  { UNKNOWN_BREED=0, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX } ;

/// A color.  Can be used in many places.
enum Color  { BLACK=0, WHITE, RED, BLUE, GREEN, PINK } ;


/// Hold all of the information about a cat
struct Cat {
   char               name[MAX_CAT_NAME] ;  ///< The name of the cat
   enum Gender        gender ;              ///< The gender of the cat
   enum Breed         breed ;               ///< The breed of the cat
   bool               isFixed ;             ///< True if the cat is fixed
   float              weight ;              ///< The weight of the cat.  Must
                                            ///  be >0 or -1 if unknown.
   enum Color         collarColor1 ;        ///< The color of the first part of the collar
   enum Color         collarColor2 ;        ///< The color of the second part of the collar
   unsigned long long license ;             ///< The registration number for the cat.
} ;


/// The array that holds all of our cats
extern struct Cat cats[MAX_CATS] ;

extern size_t numCats ;  /// This points to the next available cat we can add
/// to the database.


/// Initializes the cat database
extern void initializeDatabase() ;

/// Return true if the database is full
extern bool isFull() ;

/// Verify that the database is healthy
extern bool validateDatabase() ;

/// Verify the index is a valid value for this database
extern bool isIndexValid( const size_t index ) ;

/// Verify the name is valid
extern bool isNameValid( const char* name ) ;

/// Verify the weight is valid
extern bool isWeightValid( const float weight ) ;

/// Verify the cat collars are valid
extern bool areCatCollarsValid(const enum Color collarColor1, const enum Color collarColor2 ) ;

/// Zeros out a cat's information from the database
extern void wipeCat( const size_t index ) ;

/// Swap the cats in the indexes
extern bool swapCat( const size_t a, const size_t b ) ;
