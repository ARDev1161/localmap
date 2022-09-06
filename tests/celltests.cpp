#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/localmap.h"

using namespace std;

// Demonstrate some basic assertions.
//TEST(HelloTest, BasicAssertions) {
//  // Expect two strings not to be equal.
//  EXPECT_STRNE("hello", "world");
//  // Expect equality.
//  EXPECT_EQ(7 * 6, 42);
//}

int celltests()
{
    Cell cell;
    cell.setCountVisited(7);
    std::cout << cell.getCountVisited() << std::endl;

    return 0;
}

int leveltest()
{
    return 0;
}

int localmaptests()
{
    return 0;
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);


//    LocalMap map;
//    map.addLayer("base");

//    Level *level = map.getLevel("base");
//    level->generateLevel();

//    if(level->getCountOfSectors() <= 0){
//        std::cerr << "Error! Level is empty!" << std::endl;
//    }

//    Cell * cell = level->getCell(0, 0);
//    std::cout << cell->getCountVisited() << std::endl;

//    cell->setCountVisited(7);
//    level->setCellData(cell, 0, 0);
//    std::cout << cell->getCountVisited() << std::endl;

    return RUN_ALL_TESTS();
}
