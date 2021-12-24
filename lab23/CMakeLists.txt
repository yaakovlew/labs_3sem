cmake_minimum_required(VERSION 3.20)
project(lab23)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab23 main.cpp UnDirectedGraph.h Matrix.h DirectionGraph.h Test_Matrix.h Test_NotDirection.h Test_Direction.h MenuGraph.h ComutatedNets.h MenuNet.h Test_Comutated_Net.h)
