#include <iostream>
#include <random>
#include "TrafficLight.h"

/* Implementation of class "MessageQueue" */


template <typename T>
T MessageQueue<T>::receive()
{
    // FP.5a : The method receive should use std::unique_lock<std::mutex> and _condition.wait() 
    // to wait for and receive new messages and pull them from the queue using move semantics. 
    // The received object should then be returned by the receive function. 
    std::unique_lock<std::mutex> uniqueLock(_mutex);	
	_conditionVariable.wait(uniqueLock, [this] {return !_queue.empty(); });	
   	
  	T message = std::move(_queue.back());	
  	_queue.pop_back();	
    	
  	return message;
}

template <typename T>
void MessageQueue<T>::send(T &&message)
{
    // FP.4a : The method send should use the mechanisms std::lock_guard<std::mutex> 
    // as well as _condition.notify_one() to add a new message to the queue and afterwards send a notification.
	std::lock_guard<std::mutex> uniqueLock(_mutex);
	_queue.push_back(std::move(message));
	_conditionVariable.notify_one(); 
}

/* Implementation of class "TrafficLight" */

 
TrafficLight::TrafficLight()
{
    _currentPhase = TrafficLightPhase::red;
}

void TrafficLight::waitForGreen()
{
    // FP.5b : add the implementation of the method waitForGreen, in which an infinite while-loop 
    // runs and repeatedly calls the receive function on the message queue. 
    // Once it receives TrafficLightPhase::green, the method returns.
	while(true) {
		TrafficLightPhase phase = _phasesQueue.receive();
		if(phase == TrafficLightPhase::green) {	break; }
	}
	return;
}

TrafficLightPhase TrafficLight::getCurrentPhase()
{
    return _currentPhase;
}

void TrafficLight::simulate()
{
    // FP.2b : Finally, the private method „cycleThroughPhases“ should be started in a thread when the public method „simulate“ is called. To do this, use the thread queue in the base class. 
	std::thread thread(&TrafficLight::cycleThroughPhases, this);
	threads.emplace_back(std::move(thread));
}

// virtual function which is executed in a thread
void TrafficLight::cycleThroughPhases()
{
    // FP.2a : Implement the function with an infinite loop that measures the time between two loop cycles 
    // and toggles the current phase of the traffic light between red and green and sends an update method 
    // to the message queue using move semantics. The cycle duration should be a random value between 4 and 6 seconds. 
    // Also, the while-loop should use std::this_thread::sleep_for to wait 1ms between two cycles. 

	std::random_device randomDevice; //  A uniformly-distributed integer random number generator that produces non-deterministic random numbers.
	std::mt19937 randomGenerator(randomDevice()); // A Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits.
	std::uniform_int_distribution<> cycleDistribution(4000, 6000); // time in milliseconds
	uint64_t cycleDuration = cycleDistribution(randomGenerator);
  
	std::chrono::time_point<std::chrono::system_clock> lastUpdate = std::chrono::system_clock::now();
  
	while(true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		uint64_t timeDiffLastUpdate = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - lastUpdate).count();
		if(timeDiffLastUpdate >= cycleDuration) {
			_currentPhase = (_currentPhase == TrafficLightPhase::red) ? TrafficLightPhase::green : TrafficLightPhase::red;
			cycleDuration = cycleDistribution(randomGenerator);
			lastUpdate = std::chrono::system_clock::now();
			_phasesQueue.send(std::move(_currentPhase));
		}
	}
}
