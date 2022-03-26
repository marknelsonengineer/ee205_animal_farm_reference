///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   17_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "config.h"


/// The maximum size of a cat's name
#define MAX_CAT_NAME (50)


/// Felis Catus
///
/// There's no `setGender()` and `setBreed()` methods.  Under normal
/// circumstances, they would be passed in the constructor and never changed
/// afterwards.
///
/// In the real world, it's impossible to change the breed of a cat, however,
/// in actual databases, there are times when a breed is mis-entered and
/// needs to be corrected.

class Cat {
protected:  ///////////////////////// Member Variables /////////////////////////
   char        name[MAX_CAT_NAME] ;  ///< The name of the cat
   enum Gender gender ;              ///< The gender of the cat
   enum Breed  breed ;               ///< The breed of the cat
   bool        amIfixed ;            ///< True if the cat is fixed
   Weight      weight ;              ///< The Weight of the cat.  Must
                                     ///  be >0 or -1 if unknown.

   Cat*        nextCat ;             ///< The next pointer for a linked list

public:  //////////////////////////// Constructors /////////////////////////////
   Cat();            ///< Create a cat with all default values.  For now, this
                     ///< is a necessary evil.

   /// Create a cat with the minimum fields necessary to have a valid cat
   Cat( const char *newName, const Gender newGender, const Breed newBreed, const Weight newWeight );

public:  ////////////////////////// Getters & Setters //////////////////////////
   const char *getName() const;  ///< Get the Cat's name
   void setName( const char* newName );  ///< Set the Cat's name.  The name
                                         ///< must not be empty and it must
                                         ///< be <= MAX_CAT_NAME in length.

   Gender getGender() const;  ///< Get the Cat's gender
   Breed getBreed() const;    ///< Get the Cat's breed
   bool isFixed() const;      ///< Return true if the cat is fixed
   Weight getWeight() const;  ///< The weight of the cat or -1 if unknown
   void setWeight(Weight newWeight);  ///< Set the newWeight of the cat
   void fixCat() noexcept ;   ///< Spay or neuter the cat


protected:  ////////////////////// Protected Methods ///////////////////////////
public:
   void setGender(Gender newGender);  ///< Set the cat's gender
   void setBreed(Breed newBreed);  ///< Set the cat's breed

public:  /////////////////////////// Public Methods ////////////////////////////
   void print() const;   ///< Print out a cat
   bool validate() const noexcept;  ///< Check to see if the Cat object is valid

public:  /////////////////////// Static Public Methods /////////////////////////
   static bool validateName( const char* newName ) ;  ///< Check if `newName` is valid
   static bool validateGender( const Gender newGender ) ; ///< Check if `newGender` is valid
   static bool validateBreed( const Breed newBreed ) ; ///< Check if 'newBreed` is valid
   static bool validateWeight( const Weight newWeight ) ; ///< Check if `newWeight` is valid
};
