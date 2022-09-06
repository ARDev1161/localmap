#ifndef MAPSETTINGS_H
#define MAPSETTINGS_H


class MapSettings
{
    int mapSizeX = 1000;
    int mapSizeY = 1000;

    int sectorSize = 10; ///< Dimensional size of sector in points(mm/mil/inch)

public:
    MapSettings();

    int getMapSizeX() const;
    void setMapSizeX(int newMapSizeX);
    int getMapSizeY() const;
    void setMapSizeY(int newMapSizeY);

    int getSectorSize() const;
    void setSectorSize(int newSectorSize);
};

#endif // MAPSETTINGS_H
