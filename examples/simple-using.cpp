#include <iostream>
#include "../src/localmap.h"

using namespace std;

int main()
{
    LocalMap map;
    map.addLayer("base");

    Level *level = map.getLevel("base");
    level->generateLevel();

    if(level->getCountOfSectors() <= 0){
        std::cerr << "Error! Level is empty!" << std::endl;
    }

    Cell * cell = level->getCell(0, 0);
    std::cout << cell->getCountVisited() << std::endl;

    cell->setCountVisited(7);
    level->setCellData(cell, 0, 0);
    std::cout << cell->getCountVisited() << std::endl;

    return 0;
}
