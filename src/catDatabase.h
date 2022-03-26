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
#include "Cat.h"


/// The head pointer to a linked list of cats
extern Cat* catDBheadPtr ;

/// Initializes the cat database
extern void initializeDatabase() ;
extern bool isCatInDatabase( Cat* aCat ) ;


/*
/// Verify that the database is healthy
extern bool validateDatabase() ;

/// Swap the cats in the indexes
extern bool swapCat( const size_t a, const size_t b ) ;
*/
