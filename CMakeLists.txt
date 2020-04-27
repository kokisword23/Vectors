cmake_minimum_required(VERSION 3.15)
project(Vectors)

set(CMAKE_CXX_STANDARD 14)

add_executable(Vectors main.cpp entities/Element.cpp entities/Element.h entities/Point.cpp entities/Point.h entities/Vector.cpp entities/Vector.h entities/Line.cpp entities/Line.h entities/Segment.cpp entities/Segment.h entities/Triangle.cpp entities/Triangle.h)