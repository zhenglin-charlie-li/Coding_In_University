# cmake_minimum_required(VERSION <specify CMake version here>)
project(4_15C__500r)

set(CMAKE_CXX_STANDARD 14)

add_executable(4_15C__500r
        AvailableTiles.h
        BoardSize.h BoardSize.cpp
        Board.h Board.cpp
        CellChooser.h CellChooser.cpp
        CellId.h CellId.cpp
        Dice.h Dice.cpp
        Game.h Game.cpp
        Player.h Player.cpp
        TestHelper.h TestHelper.cpp
        Tile.h Tile.cpp
        TileMoney.h TileMoney.cpp
        TileDice.h TileDice.cpp
        TilePoints.cpp TilePoints.h
        main.cpp
        )