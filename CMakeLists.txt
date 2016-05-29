cmake_minimum_required(VERSION 3.5)
project(object_oriented_programming_in_c__)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    OLED/ball.cpp
    OLED/ball.hpp
    OLED/circle.cpp
    OLED/circle.hpp
    OLED/drawable.cpp
    OLED/drawable.hpp
    OLED/line.cpp
    OLED/line.hpp
    OLED/main.cpp
    OLED/rectangle.cpp
    OLED/rectangle.hpp
    OLED/vector.cpp
    OLED/vector.hpp
    OLED/victim.cpp
        OLED/victim.hpp
    OLED/wall.cpp
    OLED/wall.hpp)

add_executable(object_oriented_programming_in_c__ ${SOURCE_FILES})