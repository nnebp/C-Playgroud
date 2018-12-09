#include <SDL.h>
#include <stdbool.h>

#ifndef SDL2TEST_TIMER_H
#define SDL2TEST_TIMER_H

typedef struct timer {
    //The clock time when the timer started
    Uint32 startTicks;
    //The ticks stored when the timer was paused
    Uint32 pausedTicks;
    //The timer status
    bool paused;
    bool started;
} timer;

void startTimer(timer* time);
void stopTimer(timer* time);
void pauseTimer(timer* time);
void unpauseTimer(timer* time);
Uint32 getTimerTicks(timer* time);


bool isTimerStarted(timer* time);
bool isTimerPaused(timer* time);

#endif //SDL2TEST_TIMER_H
