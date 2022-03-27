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
#include "Node.h"


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
///
/// @todo Refactor name to string type and implement space-trimming.
/// @todo Refactor Weight to its own class
/// @todo Refactor Gender and Breed to enum classes
class Cat : public Node {
protected:  ///////////////////////// Member Variables /////////////////////////
   char        name[MAX_CAT_NAME] ;  ///< The name of the cat
   enum Gender gender ;              ///< The gender of the cat
   enum Breed  breed ;               ///< The breed of the cat
   bool        isCatFixed ;            ///< True if the cat is fixed
   Weight      weight ;              ///< The Weight of the cat.  Must
                                     ///  be >0 or -1 if unknown.

public:  /////////////////////// Public Member Variables ///////////////////////
   Cat*        next ;                ///< The next pointer for a linked list
                                     ///< This is very bad form, but we'll use
                                     ///< it for now.  @todo FIX public next pointer!

private:  /////////////////////////// Private Methods //////////////////////////
   void zeroOutMemberData();         ///< Initialize / zero out all member data

public:  //////////////////////////// Constructors /////////////////////////////
   Cat();            ///< Create a cat with all default values.  For now, this
                     ///< is a necessary evil.

   /// Create a cat with the minimum fields necessary to have a valid cat
   Cat( const char *newName, const Gender newGender, const Breed newBreed, const Weight newWeight );

   /// Zero out all of the member data (it's super secret!)
   virtual ~Cat();

public:  ////////////////////////// Getters & Setters //////////////////////////
   const char *getName() const noexcept ; ///< Get the Cat's name
   void setName( const char* newName );   ///< Set the Cat's name.  The name
                                          ///< must not be empty and it must
                                          ///< be <= MAX_CAT_NAME in length.

   Gender getGender() const noexcept ;  ///< Get the Cat's gender
   Breed getBreed() const noexcept ;    ///< Get the Cat's breed
   bool isFixed() const noexcept ;      ///< Return true if the cat is fixed
   void fixCat() noexcept ;             ///< Spay or neuter the cat
   Weight getWeight() const noexcept ;  ///< The weight of the cat or -1 if unknown
   void setWeight(Weight newWeight) ;   ///< Set the newWeight of the cat


protected:  ////////////////////// Protected Methods ///////////////////////////
public:
   void setGender(Gender newGender);  ///< Set the cat's gender
   void setBreed(Breed newBreed);  ///< Set the cat's breed

public:  /////////////////////////// Public Methods ////////////////////////////
   bool print() const noexcept ;    ///< Print a cat
   bool validate() const noexcept;  ///< Check to see if the Cat object is valid

public:  /////////////////////// Static Public Methods /////////////////////////
   // Static methods must be `const`
   static bool validateName( const char* newName ) ;  ///< Check if `newName` is valid
   static bool validateGender( const Gender newGender ) ; ///< Check if `newGender` is valid
   static bool validateBreed( const Breed newBreed ) ; ///< Check if 'newBreed` is valid
   static bool validateWeight( const Weight newWeight ) ; ///< Check if `newWeight` is valid
};
