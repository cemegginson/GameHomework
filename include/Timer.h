#pragma once

#include "SDL.h"
#include "Definitions.h"

class Timer {
private:
	// The clock time when the timer started
	uint32 startTicks;

	// Time Delta!
	uint32 deltaTime;
	uint32 lastTime;

	// The ticks stored when the timer was paused
	uint32 pausedTicks;

	// The timer status
	bool paused;
	bool active;

public:
	// Initializes variables
	Timer();

	// The various clock actions
	void start();
	void stop();
	void pause();
	void resume();

	// Gets the timer's time
	uint32 getTicks();

	// Checks the status of the timer
	bool isRunning();
	bool isPaused();

	// Regulate
	void fpsRegulate();

	// Time Delta!
	void Update();
	float32 DeltaTime();
};
