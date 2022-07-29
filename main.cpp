#include <iostream>
//#include <gtest/gtest.h>
#include "localmap.h"

using namespace std;

// Demonstrate some basic assertions.
//TEST(HelloTest, BasicAssertions) {
//  // Expect two strings not to be equal.
//  EXPECT_STRNE("hello", "world");
//  // Expect equality.
//  EXPECT_EQ(7 * 6, 42);
//}

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

    cout << "Hello World!" << endl;
    return 0;
}
