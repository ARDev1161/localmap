#ifndef CELL_H
#define CELL_H

#include <vector>
#include <string>

typedef unsigned char byte;

struct driveLogRecord
{
    float direction; ///< направление движение, в градусах, от точки входа до точки выхода
    float speedAverage; ///< средняя скорость
    float time; ///< Временная метка входа в ячейку.
    std::string robotId = ""; ///< Имя проезжавшего робота
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

    std::vector<driveLogRecord> driveLog; ///< Список объектов, содержащих информацию о проезде ячейки роботом.

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

    void addRecordToLog(driveLogRecord record);
    const std::vector<driveLogRecord> &getDriveLog() const;
};

#endif // CELL_H+
