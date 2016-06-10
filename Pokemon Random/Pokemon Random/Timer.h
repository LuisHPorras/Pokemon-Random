#pragma once

#include <SDL.h>

class Timer
{
public:

	Timer(void);
	~Timer(void);

	void start();
	void pause();
	void reset();
	void stop();
	unsigned int millis();
	bool isRunning();

private:

	bool started;
	bool paused;
	unsigned int startTime;
	unsigned int currentTime;
};



