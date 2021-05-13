cmake_minimum_required(VERSION 3.17)
project(task3)

set(CMAKE_CXX_STANDARD 14)

add_executable(task3 main.cpp Board.h BoardSize.cpp BoardSize.h
        CellId.cpp CellId.h  Dice.cpp Dice.h Player.cpp
        Tile.cpp   Player.h Tile.h Board.cpp AvailableTiles.h AvailableTiles.cpp CellId.cpp CellId.h
        TestHelper.cpp TestHelper.h TestAvailableTiles3.cpp TestTile3.cpp
        TestBoard3.cpp)