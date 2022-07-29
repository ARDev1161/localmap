#ifndef LEVEL_H
#define LEVEL_H

#include <utility>
#include <functional>
#include <string>

#include "mapsettings.h"
#include "cell.h"

/** Определение типа координат сектора */
typedef std::pair<int,int> SectorCoords;

/*! \brief Структура для хеширования по ключу типа std::pair<T1,T2>.
 *
 *  Only for pairs of std::hash-able types for simplicity.
 *  You can of course template this struct to allow other hash functions
 */
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};

/*!
    \brief Класс карты секторов слоя

    Данный класс содержит карту секторов слоя представленную хеш таблицей и методы к ней.
    Ключ таблицы - std::pair<int N, int M>, координаты сектора M по X, а N по Y.
    Значение - указатель на объект сектора.
*/

class Level
{
    int countM, countN, sectorSize;
    std::string name = "";
    MapSettings *settings;

    /** Объявление карты секторов в слое*/
    std::unordered_map< SectorCoords, Cell*, pair_hash> sectorsMap; // Map of all sectors in layer, key - sector coordinates(number of sector), value - pointer to NetsMap

public:
    Level();

    int generateLevel();
    void clearLevel();

    std::pair<int,int> getCoordsByCell(Cell *cell);

    Cell *getCell(int sectorCoordX, int sectorCoordY);
    void setCellData(const Cell* cell, int xCoord, int yCoord);

    int getCountM() const;
    void setCountM(int newCountM);
    int getCountN() const;
    void setCountN(int newCountN);

    int getSectorSize() const;
    void setSectorSize(int newSectorSize);

    const std::string &getName() const;
    void setName(const std::string &newName);

    int getCountOfSectors();
};

#endif // LEVEL_H
