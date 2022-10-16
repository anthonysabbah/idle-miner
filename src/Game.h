#ifndef GAME_H
#define GAME_H

#include "Worker.h"
#include "Tool.h"
#include "HandTool.h"
#include "PowerTool.h"
#include "MegaDrill.h"
#include "ItemShop.h"
#include <vector>
#include <ctime>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

class Game{
   
    public:
    Game(); // default constructor;
    Game(int _tickLimit, int _ticksPerSecond); // constructor for setting custom params and debugging;
    int tick = 0; // one tick is 1 hr in game;
    int tickLimit = 2400; // max game length in ticks;
    int ticksPerSecond = 1; // ticks per second 
    clock_t startingTime;
    int timeElapsed;
    double score; // game score, cumulative gold collected from mining 
    double gold; // gold available to spend
    vector<Worker*> workers;
    vector<Worker*> workerShop;
    ItemShop *toolShop;
    vector<double> goldMined; // gold mined per tick
    vector<double> goldHistory; // gold balance history 
    //vector<double> scores; // score history
    double *scores; //score history
    void update();
    void nextTick(bool _manual); // moves the game forward in time, and calls mine() on all miners. Is called in main() loop;
    double getTotalMiningRate(); // gold per tick
    // bool isPaused; game pause?
    int day(); // returns days passed since game started (24 ticks is one day)
    ~Game(); // destructor
    void powerCurrentTools(); //gives power to all tools currently equipped. Must be rebought if new tools are bought.
    void clearScores(); //deletes array of scores
    void buyWorker(); //buys a new worker
    void buyTool(int positionInShop, Worker *workerEquipping); //buying an tool from the tool shop
    void addTool(Tool *toolAdded); //adding a tool to the tool shop

};

#endif //GAME_H