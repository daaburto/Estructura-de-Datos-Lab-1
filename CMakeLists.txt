cmake_minimum_required(VERSION 3.10)
project(Estructura-de-Datos-Lab-1)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Estructura-de-Datos-Lab-1
        src/main.cpp
        include/esbirro.h
        include/heroe.h
)