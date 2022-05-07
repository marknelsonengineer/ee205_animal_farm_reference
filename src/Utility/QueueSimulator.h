///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// A simulator for a Queue
///
/// @file QueueSimulator.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   05_May_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../Container/Node.h"
#include "../Container/Queue.h"

/// A simulator for a Queue
///
/// The simulation can run in 2 modes:
/// |                 | Print output | Speed               | Duration       | Use                                |
/// |-----------------|--------------|---------------------|----------------|------------------------------------|
/// | interactive     | Yes          | Every SPEED_IN_MS   | Forever        | Visualize the operation of a queue |
/// | not interactive | No           | As fast as possible | For ITERATIONS | Test the Queue class               |
///
/// Alpha is a class-within-a-class.
///
/// Sample output from an interactive simulation is:
///
///          in    queue       out
///          ==    ========    ===
///     0000: a >> a
///     0001: b >> ba
///     0002: c >> cba
///     0003:      cb       >> a
///     0004: d >> dcb
///     0005: e >> edcb
///     0006:      edc      >> b
///     0007: f >> fedc
///     0008:      fed      >> c
///     0009: g >> gfed
///     0010:      gfe      >> d
///     0011:      gf       >> e
///
class QueueSimulator {
public:  ////////////////////////// Public Constants ///////////////////////////
   const int PAR = 4;             ///< The average size of the queue
   const int STRENGTH = 1;        ///< The k-factor that brings the queue back to PAR
   const int ITERATIONS = 10000;  ///< The number of iterations (for non-interactive mode)
   const int SPEED_IN_MS = 500;   ///< Milliseconds per Queue operation (for interactive mode)

private:  ////////////////////////// Private Classes ///////////////////////////
   /// Alpha extends Node... and holds a single character, 'a' through 'z' in the Queue
   class Alpha : public Node {
   public:
      char memberChar;            ///< This is the value stored in the Queue
      static char staticChar;     ///< Maintains the next value to insert into the Queue

      Alpha() { memberChar = staticChar++ ; if( staticChar > 'z' ) staticChar = 'a'; }
   };

private:  /////////////////////////// Private Members ////////////////////////////
   Queue queue;   ///< The queue under test

public:  /////////////////////////// Public Methods ////////////////////////////
   static void printQueueSimulatorHeader() noexcept;       ///< Print the header for the simulator

   void runQueueSimulator( bool isInteractive ) noexcept;  ///< Run the simulator
};
