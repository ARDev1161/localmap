#include "level.h"

/*!
Базовый конструктор
*/
Level::Level()
{
    settings = new MapSettings();
}

/*!
Создаёт объект карты секторов с количеством секторов определяемым настройками сетки в индексе

\param[in] *layer Указатель на объект слоя
\return 0 - успешно
*/
int Level::generateLevel()
{
    this->countM = settings->getMapSizeX()/settings->getSectorSize();
    this->countN = settings->getMapSizeY()/settings->getSectorSize();
    this->sectorSize = settings->getSectorSize();

    Cell * tmp = new Cell();

    for(int y = 0; y < countN; y++){
        for(int x = 0; x < countM; x++){
            sectorsMap.insert( std::make_pair( std::make_pair(x, y), tmp) );
        }
    }

    return 0;
}

/*!
Удаляет карту секторов уровня
*/
void Level::clearLevel()
{
    sectorsMap.clear();
}

/*!
Возвращает координаты сектора по таблице цепей

\param[in] *netsMap Указатель на объект таблицы электрических цепей
\return 0 - успешно
*/
std::pair<int, int> Level::getCoordsByCell(Cell *cell)
{

    auto it = sectorsMap.begin();  // получаем итератор
    while(it != sectorsMap.end())    // пока не дойдем до конца
    {
        if(it->second == cell) // Ищем первое вхождение искомого слоя
            return it->first; // Возвращаем указатель на слой

        ++it;             // перемещаемся вперед на один элемент
    }
    return std::make_pair(-1,-1);
}

/*!
Возвращает указатель на таблицу цепей сектора

\param[in] xCoordIn Координата (номер сектора) по оси X
\param[in] yCoordIn Координата (номер сектора) по оси Y
\return указатель на таблицу цепей
*/
Cell *Level::getCell(int sectorCoordX, int sectorCoordY)
{
    return sectorsMap.find(std::make_pair(sectorCoordX, sectorCoordY))->second;
}

/*!
Устанавливает указатель на таблицу цепей для сектора

\param[in] netsTable Указатель на объект ячейки
\param[in] xCoordIn Координата (номер сектора) по оси X
\param[in] yCoordIn Координата (номер сектора) по оси Y
*/
void Level::setCellData(const Cell *cell, int xCoord, int yCoord)
{
    *sectorsMap[std::make_pair(xCoord, yCoord)] = *cell;
}

int Level::getCountM() const
{
    return countM;
}

void Level::setCountM(int newCountM)
{
    countM = newCountM;
}

int Level::getCountN() const
{
    return countN;
}

void Level::setCountN(int newCountN)
{
    countN = newCountN;
}

int Level::getSectorSize() const
{
    return sectorSize;
}

void Level::setSectorSize(int newSectorSize)
{
    sectorSize = newSectorSize;
}

const std::string &Level::getName() const
{
    return name;
}

void Level::setName(const std::string &newName)
{
    name = newName;
}

int Level::getCountOfSectors()
{
    return sectorsMap.size();
}

