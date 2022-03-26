///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 2.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   14_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <cstddef>   // For the size_t datatype

#include "config.h"
#include "Cat.h"


/// The head pointer to a linked list of cats
extern Cat* catDatabaseHeadPointer ;

/// This is temporary and only for debugging
/// @todo Remove when we have a proper container class
extern int numberOfCats ;

/// Initializes the cat database
extern void initializeDatabase() ;

/// Return true if aCat is in the database
extern bool isCatInDatabase( Cat* aCat ) ;

/// Verify that the database is healthy
extern bool validateDatabase() ;
