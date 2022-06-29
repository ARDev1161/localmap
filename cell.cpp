#include "cell.h"

Cell::Cell()
{

}

int Cell::getCountVisited() const
{
    return countVisited;
}

void Cell::setCountVisited(int newCountVisited)
{
    countVisited = newCountVisited;
}

float Cell::getLastVisited() const
{
    return lastVisited;
}

void Cell::setLastVisited(float newLastVisited)
{
    lastVisited = newLastVisited;
}

float Cell::getLastTimeUpdate() const
{
    return lastTimeUpdate;
}

void Cell::setLastTimeUpdate(float newLastTimeUpdate)
{
    lastTimeUpdate = newLastTimeUpdate;
}

byte Cell::getCellType() const
{
    return cellType;
}

void Cell::setCellType(byte newCellType)
{
    cellType = newCellType;
}


bool Cell::getIsKnown() const
{
    return isKnown;
}

void Cell::setIsKnown(bool newIsKnown)
{
    isKnown = newIsKnown;
}


bool Cell::getIsPassable() const
{
    return isPassable;
}

void Cell::setIsPassable(bool newIsPassable)
{
    isPassable = newIsPassable;
}

