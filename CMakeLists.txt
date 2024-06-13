cmake_minimum_required(VERSION 3.28)
project(Regnum_United)

set(CMAKE_CXX_STANDARD 20)

add_executable(Regnum_United main.cpp
        entity_components/Character.cpp
        entity_components/Character.h
        entity_components/Lifebar.cpp
        entity_components/Lifebar.h)
