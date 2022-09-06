#include "cell.h"

Cell::Cell()
{

}

Cell::Cell(const Cell &cell)
{
    this->isKnown = cell.isKnown;
    this->isPassable = cell.isPassable;
    this->cellType = cell.cellType;

//    this->lastTimeUpdate = cell.lastTimeUpdate;
//    this->lastVisited = cell.lastVisited;
//    this->countVisited = cell.countVisited;

    //    this->driveLog = cell.driveLog;
}

Cell::Cell(const Cell &&cell)
{
    this->isKnown = cell.isKnown;
    this->isPassable = cell.isPassable;
    this->cellType = cell.cellType;

//    this->lastTimeUpdate = cell.lastTimeUpdate;
//    this->lastVisited = cell.lastVisited;
//    this->countVisited = cell.countVisited;

    //    this->driveLog = cell.driveLog;
}

Cell & Cell::operator =(const Cell &cell)
{
    ///< Проверка на самоприсваивание
    if (&cell == this)
        return *this;

    isKnown = cell.isKnown;
    isPassable = cell.isPassable;
    cellType = cell.cellType;

    lastTimeUpdate = cell.lastTimeUpdate;
    lastVisited = cell.lastVisited;
    countVisited = cell.countVisited;

    driveLog = cell.driveLog;
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

void Cell::addRecordToLog(driveLogRecord record)
{
    this->driveLog.push_back(record);
}

const std::vector<driveLogRecord> &Cell::getDriveLog() const
{
    return driveLog;
}
