#include "FileManager.h"

Stud::Stud()
{
    string 
}

Stud::Stud(int timeGetInLine, int timeNeeded)
{
    startingTicksNeeded = timeNeeded;
    tickToArrive = timeGetInLine;
    remainingTicksNeeded = startingTicksNeeded;
}

void Stud::decreaseRemainingTicksNeeded()
{
    remainingTicksNeeded--;
}


int Stud::getTickToArrive()
{
    return tickToArrive;
}

int Stud::getRemainingTicksNeeded()
{
    return remainingTicksNeeded;
}

int Stud::getStartingTicksNeeded()
{
    return startingTicksNeeded;
}

void Stud::assignWindow(int window)
{
    assignedWindow = window;
}

int Stud::getAssignedWindow()
{
    return assignedWindow;
}

Stud::~Stud()
{
    
}