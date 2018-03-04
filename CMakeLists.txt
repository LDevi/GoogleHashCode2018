cmake_minimum_required(VERSION 3.9)
project(GoogleHashCode2018)

set(CMAKE_CXX_STANDARD 11)

add_executable(GoogleHashCode2018
        src/City.cpp
        src/City.h
        src/main.cpp
        src/Order.cpp
        src/Order.h
        src/Point.cpp
        src/Point.h
        src/Vehicule.cpp
        src/Vehicule.h)
