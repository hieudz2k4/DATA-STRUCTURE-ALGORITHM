cmake_minimum_required(VERSION 3.26)
project(Week_5_Graph)

set(CMAKE_CXX_STANDARD 17)

add_executable(Week_5_Graph main.cpp
        "Ex1 Connected Component.cpp"
        "Ex2 Shortest path.cpp"
        BFS.cpp)
