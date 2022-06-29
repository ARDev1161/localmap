#ifndef CELL_H
#define CELL_H

#include <vector>

typedef unsigned char byte;

struct driveLogVector
{
    float direction; ///< направление движение, в градусах(?)
    float speedAverage; ///< средняя скорость
    float time; ///< Пока float, потом создать объект(структуру) для формата времени?. Временна'я пометка.
};

//Класс описывает данные, которые робот хранит в ячейке карты
class Cell
{
    bool isPassable; ///< Флаг, задающий проходимость ячейки. Если внутри препятствий нет, то = True. Если препятствия есть - false.
    bool isKnown; ///< Флаг, описывающий наличие информации о ячейке.
    byte cellType; ///< переменная, задающая кодировку типу ячейки. Предлагаю: 0-99 типы проходимых, 100-199 - условно проходимых или временных, 200-255 - совсем не проходимых. (0 - пустоб; 100 - препятствие временное; 200 - препятствие постоянное)
    float lastTimeUpdate; ///< Пока float, потом создать объект(структуру) для формата времени?. Временна'я пометка о последнем обновлении информации о клетке
    int countVisited; ///< Счеткик. Сколько раз робот проехал по клетке.
    float lastVisited; ///< Пока float, потом создать объект(структуру) для формата времени?. Временна'я пометка о последнем Нахождении внутри клетки

    std::vector<driveLogVector> driveLog; ///< Список (прямой аналог vector из С++) объектов, содержащих информацию о проезде ячейки роботом.
    // TODO
    // Итератор
    // Добавление

public:
    Cell();

    bool getIsPassable() const;
    void setIsPassable(bool newIsPassable);

    bool getIsKnown() const;
    void setIsKnown(bool newIsKnown);

    byte getCellType() const;
    void setCellType(byte newCellType);

    float getLastTimeUpdate() const;
    void setLastTimeUpdate(float newLastTimeUpdate);

    int getCountVisited() const;
    void setCountVisited(int newCountVisited);

    float getLastVisited() const;
    void setLastVisited(float newLastVisited);
};

#endif // CELL_H+
