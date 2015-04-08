#include <iostream>

#include "Timer.h"
#include "Definitions.h"

Timer::Timer() {
	// Initialize the variables
	startTicks = 0;
	pausedTicks = 0;
	paused = false;
	started = false;
	mpf = 0.0f;
	deltaTime = 0;
	lastTime = 0;
}

bool Timer::Initialize(GAME_INT fps) {
	if (fps > 0) {
		mpf = (GAME_FLT)1000 / fps;
		return (true);
	} else {
		return (false);
	}
}

void Timer::start() {
	// Start the timer
	started = true;

	// Unpause the timer
	paused = false;

	// Get the current clock time
	startTicks = SDL_GetTicks();
}

void Timer::stop() {
	// Stop the timer
	started = false;

	// Unpause the timer
	paused = false;
}

void Timer::pause() {
	// If the timer is running and isn't already paused
	if ((started == true) && (paused == false)) {
		// Pause the timer
		paused = true;

		// Calculate the paused ticks
		pausedTicks = SDL_GetTicks();
	}
}

void Timer::unpause() {
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

GAME_INT Timer::getTicks() {
	// If the timer is running
	if (started == true) {
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

bool Timer::isStarted() { return started; }

bool Timer::isPaused() { return paused; }

void Timer::fpsRegulate() {
	// Pause for a length of time such that frame rate is maintained
	if (getTicks() < mpf) {
		SDL_Delay((GAME_INT)mpf - getTicks());
	}
}

// TIME DELTAS!!!
void Timer::Update() {
	deltaTime = SDL_GetTicks() - lastTime;
	lastTime = SDL_GetTicks();
}

GAME_FLT Timer::DeltaTime() {
	return (GAME_FLT)deltaTime/1000.0;
}