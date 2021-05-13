cmake_minimum_required(VERSION 3.17)
project(saolei)

set(CMAKE_CXX_STANDARD 14)

add_executable(saolei GameEngine.cpp GameEngine.h GameEnginePro.cpp GameEnginePro.h
        GameMenu.cpp GameMenu.h Graphic.cpp Graphic.h Controller.cpp Controller.h
        Main.cpp )