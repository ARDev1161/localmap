#include "localmap.h"

LocalMap::LocalMap()
{

}

/*!
Добавляет в индекс указатель на объект уровня

\param[in] *layer Указатель на объект уровня
\return 0 - успешно, -1 - ошибка
*/
int LocalMap::addLayer(Level *level)
{
    if(getLevelNumber(level) < 0) // Проверяем наличие слоя на присутствие в массиве
        levels.push_back(level); // Добавляем слой в индекс если отсутствует
    else
        return -1;  // Если присутствует, возвращаем ошибку добавления

    return 0;
}

/*!
Удаляет указатель на объект слоя из индекса

\param[in] *layer Указатель на объект слоя
\return 0 - успешно
*/
int LocalMap::removeLayer(Level *level)
{
    int layerID = getLevelNumber(level); // Получаем номер элемента в векторе или ошибку поиска
    if(layerID >= 0) // Если элемент найден
        levels.erase(levels.begin() + layerID); // Удаляем элемент
    else
        return layerID; // Возвращаем полученную ошибку поиска

    return 0;
}

/*!
Получаем номер слоя в индексе

\param[in] *layer Указатель на объект слоя
\return Номер слоя, либо -1 - ошибка
*/
int LocalMap::getLevelNumber(Level *level)
{
    auto it = levels.begin();  // получаем итератор
    while(it!=levels.end())    // пока не дойдем до конца
    {
        if(*it == level) // Ищем первое вхождение искомого слоя
            return std::distance( levels.begin(), it ); // Возвращаем номер элемента в векторе

        ++it;             // перемещаемся вперед на один элемент
    }
    return -1; // Элемент не найден
}

/*!
Получаем указатель на объект слоя по его номеру в индексе

\param[in] number Номер слоя в индексе
\return Указатель на слой
*/
Level *LocalMap::getLevel(unsigned int number)
{
    auto it = levels.begin() + number;
    if( it <= levels.end() ) {
        return levels.at(number);
    }

    return nullptr;
}

/*!
Получаем указатель на объект слоя по его наименованию

\param[in] name Наименование слоя
\return Указатель на слой
*/
Level *LocalMap::getLevel(std::string name)
{
    auto it = levels.begin();  // получаем итератор
    while(it != levels.end())    // пока не дойдем до конца
    {
        if((*it)->getName() == name) // Ищем первое вхождение искомого слоя
            return *it; // Возвращаем указатель на слой

        ++it;             // перемещаемся вперед на один элемент
    }
    return nullptr; // Элемент не найден
}
