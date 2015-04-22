#pragma once

#include "SDL.h"
#include "Definitions.h"

class Timer {
public:
	// Initializes variables
	Timer();
	bool Initialize(uint32);

	// The various clock actions
	void start();
	void stop();
	void pause();
	void unpause();

	// Gets the timer's time
	uint32 getTicks();

	// Checks the status of the timer
	bool isStarted();
	bool isPaused();

	// Regulate
	void fpsRegulate();

	// Time Delta!
	void Update();
	float32 DeltaTime();

private:
	// The clock time when the timer started
	uint32 startTicks;
	float32 mpf; // millisecond per frame

	// Time Delta!
	uint32 deltaTime;
	uint32 lastTime;

	// The ticks stored when the timer was paused
	uint32 pausedTicks;

	// The timer status
	bool paused;
	bool started;
};
