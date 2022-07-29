#ifndef LOCALMAP_H
#define LOCALMAP_H

#include "level.h"

/*!
    \brief Класс локальной карты здания
*/
class LocalMap
{
    std::vector< Level* > levels; ///< Array of all layers, ILayer - pointer to Layer interface, SectorsMap - pointer to sectorsMapInLayer

public:
    LocalMap();

    int addLayer(Level *level);
    int addLayer(std::string name);
    int addLayer();

    int removeLayer(Level *level);

    int getLevelNumber(Level *level);


    // Методы взятия указателя на слой
    Level *getLevel(unsigned int number); // по номеру в векторе
    Level *getLevel(std::string name); // по имени слоя
    //_______________________________________
};

#endif // LOCALMAP_H
