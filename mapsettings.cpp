#include "mapsettings.h"

int MapSettings::getMapSizeX() const
{
    return mapSizeX;
}

void MapSettings::setMapSizeX(int newMapSizeX)
{
    mapSizeX = newMapSizeX;
}

int MapSettings::getMapSizeY() const
{
    return mapSizeY;
}

void MapSettings::setMapSizeY(int newMapSizeY)
{
    mapSizeY = newMapSizeY;
}

int MapSettings::getSectorSize() const
{
    return sectorSize;
}

void MapSettings::setSectorSize(int newSectorSize)
{
    sectorSize = newSectorSize;
}

MapSettings::MapSettings()
{

}
