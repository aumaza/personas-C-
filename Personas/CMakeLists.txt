cmake_minimum_required(VERSION 2.6)

project(personas)

add_executable(personas main.cpp ArrayList.h ArrayList.cpp Personas.h Personas.cpp)

install(TARGETS personas RUNTIME DESTINATION bin)
