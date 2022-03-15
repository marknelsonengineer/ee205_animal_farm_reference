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

#define MAX_CAT_NAME (50)   /// This defines the size of the cat's name string

enum Gender { UNKNOWN_GENDER=0, MALE, FEMALE } ;
enum Breed  { UNKNOWN_BREED=0, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX } ;
enum Color  { BLACK=0, WHITE, RED, BLUE, GREEN, PINK } ;

struct Cat {
   char               name[MAX_CAT_NAME] ;
   enum Gender        gender ;
   enum Breed         breed ;
   bool               isFixed ;
   float              weight ;
   enum Color         collarColor1 ;
   enum Color         collarColor2 ;
   unsigned long long license ;
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
