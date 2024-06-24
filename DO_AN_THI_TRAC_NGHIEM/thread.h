#pragma once
#include <graphics.h>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

std::mutex mtx;
bool tra_ve = 0;
bool out = 0;
void countdownClock(int minutes, int seconds) 
{
    while(minutes >= 0 && seconds >= 0 ) {
    	if(out == 1) return;
        char timeStr[10];
        sprintf(timeStr, "%02d:%02d", minutes, seconds);
        mtx.lock(); 
        outtextxy(100+textwidth("THOI GIAN LAM BAI:     "), 150, timeStr);
        if(seconds == 0) {
            minutes--;
            seconds = 59;
        }
        else {
            seconds--;
        }
        
        mtx.unlock();
        std::this_thread::sleep_for(chrono::milliseconds(1000));
    }
    tra_ve = 1;
}




