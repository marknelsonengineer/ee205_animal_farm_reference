///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file queueSimulator.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   05_May_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>  // For cout
#include <random>    // For random_device
#include <thread>    // For sleep_for
#include <iomanip>   // For setfill

#include "config.h"
#include "Container/Node.h"
#include "Container/Queue.h"
#include "Utility/QueueSimulator.h"

using namespace std;

/// Alpha extends Node... and will carry a single character, 'a' through 'z' in it
class Alpha : public Node {
public:
   char memberChar;

   static char staticChar;

   Alpha() { memberChar = staticChar++ ; if( staticChar > 'z' ) staticChar = 'a'; }
};

char Alpha::staticChar = 'a';

const int PAR = 4;       // The average size of the queue
const int STRENGTH = 1;  // The k-factor that brings the queue back to PAR

//random_device randomDevice;        // Seed with a real random value, if available
//mt19937_64 RNG( randomDevice() );  // Define a modern Random Number Generator
uniform_int_distribution<>  queueRNG (0, PAR * 2);


int main() {
   QueueSimulator::printQueueSimulatorHeader();

   Queue queue = Queue();
   Alpha* oldAlpha = nullptr;

   for(int i = 1 ; i < 10000 ; i++ ) {
      int offset = ((int) queue.size() - PAR) * STRENGTH;  // Close to 0 is ideal.  Positive means throttle down.  Negative means throttle up.
      bool addToQueue = (queueRNG( ANIMAL_FARM_RNG ) < (PAR - offset)) ? true : false;

      // This is one way to format numbers in C++
      cout << setw(4) << setfill('0') << i << ": " ;

      if( addToQueue ) {
         Alpha* newAlpha = new Alpha();
         cout << newAlpha->memberChar << " >> ";
         queue.push( newAlpha );
      } else {
         cout << "     ";
         oldAlpha = (Alpha*) queue.pop();
      }

      // Print the queue
      Node* current = queue.last();
      while( current != nullptr ) {
         cout << ((Alpha*)current)->memberChar ;
         current = Queue::get_next( current );
      }

      // Pad queue with spaces
      int padSize = PAR*2 - (int) queue.size();
      for( int j = 0 ; j < padSize ; j++ ) {
         cout << ' ';
      }

      if( !addToQueue && oldAlpha != nullptr ) {
         cout << " >> " << oldAlpha->memberChar ;
      }

      cout << endl;

      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
   }
}
