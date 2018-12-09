#include <SDL.h>
#include <stdbool.h>
#include "Timer.h"


//TODO create timer? freetimer?
void startTimer(timer* time) {
    //Start the timer
    time->started = true;

    //Unpause the timer
    time->paused = false;

    //Get the current clock time
    time->startTicks = SDL_GetTicks();
    time->pausedTicks = 0;
}

void stopTimer(timer* time) {
    //Start the timer
    time->started = false;

    //Unpause the timer
    time->paused = false;

    //Get the current clock time
    time->startTicks = 0;
    time->pausedTicks = 0;
}


void pauseTimer(timer* time)
{
    //If the timer is running and isn't already paused
    if( time->started && !time->paused )
    {
        //Pause the timer
        time->paused = true;

        //Calculate the paused ticks
        time->pausedTicks = SDL_GetTicks() - time->startTicks;
        time->startTicks = 0;
    }
}

void unpauseTimer(timer* time)
{
    //If the timer is running and paused
    if( time->started && time->paused )
    {
        //Unpause the timer
        time->paused = false;

        //Reset the starting ticks
        time->startTicks = SDL_GetTicks() - time->pausedTicks;

        //Reset the paused ticks
        time->pausedTicks = 0;
    }
}

Uint32 getTimerTicks(timer* time)
{
    //The actual timer time
    Uint32 result = 0;

    //If the timer is running
    if( time->started )
    {
        //If the timer is paused
        if( time->paused )
        {
            //Return the number of ticks when the timer was paused
            result = time->pausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            result = SDL_GetTicks() - time->startTicks;
        }
    }

    return result;
}
 //TODO boolean functions

bool isTimerStarted(timer* time)
{
    //Timer is running and paused or unpaused
    return time->started;
}

bool isTimerPaused(timer* time)
{
    //Timer is running and paused
    return time->paused && time->started;
}
