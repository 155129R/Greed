#include <ctime>
#include <iostream>
#include <fstream>
#include "game.h"



void CountDown()
{
    int timeleft = 60000;
    const int MAX_TIME_LIMIT = timeleft; //10 seconds or 10 * 1000 milliseconds
    long start_time = clock();
    long end_time = clock();
    if( end_time - start_time > MAX_TIME_LIMIT)
    {
         g_Console.writeToBuffer(12,10, "Times up!", 0x0B);
    }
     


}

