//References Stud class from assignment 4

#include "Person.h"

Person::Person()
{
    startingTicksNeeded = 1;
    remainingTicksNeeded = startingTicksNeeded;
}

Person::Person(int timeGetInLine, int timeNeeded)
{
    startingTicksNeeded = timeNeeded;
    tickToArrive = timeGetInLine;
    remainingTicksNeeded = startingTicksNeeded;
}

void Person::decreaseRemainingTicksNeeded()
{
    remainingTicksNeeded--;
}


int Person::getTickToArrive()
{
    return tickToArrive;
}

int Person::getRemainingTicksNeeded()
{
    return remainingTicksNeeded;
}

int Person::getStartingTicksNeeded()
{
    return startingTicksNeeded;
}

void Person::assignWindow(int window)
{
    assignedWindow = window;
}

int Person::getAssignedWindow()
{
    return assignedWindow;
}

Person::~Person()
{
    
}