cmake_minimum_required(VERSION 3.23)
project(W_H_ManageSystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(W_H_ManageSystem main.cpp Warehouse.h Warehouse.cpp menu.cpp menu.h WH.cpp WH.h)

