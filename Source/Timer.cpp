#include <iostream>

#include "Timer.h"
#include "Definitions.h"

Timer::Timer() {
	// Initialize the variables
	startTicks = 0;
	pausedTicks = 0;
	paused = false;
	active = false;
	deltaTime = 0;
	lastTime = 0;
}

void Timer::start() {
	// Start the timer
	active = true;
	paused = false;

	// Get the current clock time
	startTicks = SDL_GetTicks();
}

void Timer::stop() {
	// Stop the timer
	active = false;

	// Unpause the timer
	paused = false;
}

void Timer::pause() {
	// If the timer is running and isn't already paused
	if ((active == true) && (paused == false)) {
		// Pause the timer
		paused = true;

		// Calculate the paused ticks
		pausedTicks = SDL_GetTicks();
	}
}

void Timer::resume() {
	// If the timer is paused
	if (paused == true) {
		// Unpause the timer
		paused = false;

		// Reset the starting ticks
		startTicks = SDL_GetTicks() - pausedTicks;

		// Reset the paused ticks
		pausedTicks = 0;
	}
}

uint32 Timer::getTicks() {
	// If the timer is running
	if (active == true) {
		// If the timer is paused
		if (paused == true) {
			// Return the number of ticks when the timer was paused
			return pausedTicks;
		} else {
			// Return the current time minus the start time
			return SDL_GetTicks();
		}
	}

	// If the timer isn't running
	return 0;
}

bool Timer::isRunning() { return active; }

bool Timer::isPaused() { return paused; }

void Timer::Update() {
	deltaTime = SDL_GetTicks() - lastTime;
	lastTime = SDL_GetTicks();
}

float32 Timer::DeltaTime() {
	return (float32)deltaTime/1000.0;
}
