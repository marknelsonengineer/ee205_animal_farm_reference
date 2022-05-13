///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// A simulator for a Queue
///
/// @file QueueSimulator.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   05_May_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>  // For cout
#include <random>    // For random_device
#include <thread>    // For sleep_for
#include <iomanip>   // For setfill
#include <cassert>   // For assert

#include "../config.h"
#include "../Container/Node.h"
#include "../Container/Queue.h"

#include "QueueSimulator.h"

using namespace std;

/// Initialize an embedded static char to `a`
char QueueSimulator::Alpha::staticChar = 'a';

void QueueSimulator::printQueueSimulatorHeader() noexcept {
   cout << "Queue simulator" << endl;
   cout << "     in    queue       out" << endl;
   cout << "     ==    ========    ===" << endl;
}


/// @param isInteractive `true` if the simulation interactive and should print
///                      output every SPEED_IN_MS.
///                      <br/>
///                      `false` if the simulation is not interactive (it's run
///                      by an automated test).  It should silently run for
///                      ITERATIONS as fast as possible.
void QueueSimulator::runQueueSimulator( bool isInteractive ) noexcept {
   Alpha* oldAlpha = nullptr;
   uniform_int_distribution<>  queueRNG (0, PAR * 2);

   int iterations = 0;

   do {
      assert( queue.validate() );

      int offset = ((int) queue.size() - PAR ) * STRENGTH;  // Close to 0 is ideal.  Positive means throttle down.  Negative means throttle up.
      bool addToQueue = ( queueRNG( ANIMAL_FARM_RNG ) < ( PAR - offset )) ? true : false;

      if( isInteractive ) {
         // Zero-pad the step...
         cout << setw( 4 ) << setfill( '0' ) << iterations << ": ";
      }

      if( addToQueue ) {
         Alpha* newAlpha = new Alpha();
         if( isInteractive ) {
            cout << newAlpha->memberChar << " >> ";
         }
         queue.push( newAlpha );
      } else {
         if( isInteractive ) {
            cout << "     ";
         }
         oldAlpha = (Alpha*) queue.pop();
      }

      // Print the queue
      Node* current = queue.last();
      while( current != nullptr ) {
         if( isInteractive ) {
            cout << ((Alpha*) current )->memberChar;
         }
         current = Queue::get_next( current );
      }

      if( isInteractive ) {
         // Pad queue with spaces
         int padSize = PAR * 2 - (int) queue.size();
         for( int j = 0 ; j < padSize ; j++ ) {
            cout << ' ';
         }

         if( !addToQueue && oldAlpha != nullptr ) {
            cout << " >> " << oldAlpha->memberChar;
         }

         cout << endl;

         std::this_thread::sleep_for( std::chrono::milliseconds( SPEED_IN_MS ));
      }
      iterations++;
   } while( iterations <= ITERATIONS || isInteractive );
}
