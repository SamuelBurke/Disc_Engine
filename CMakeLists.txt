cmake_minimum_required(VERSION 2.6)
project(DISC_ENGINE)

add_executable(Goldwell
 src/Goldwell/main.cpp
)

add_library(Disc_Engine
 src/Disc_Engine/Core.h
 src/Disc_Engine/Core.cpp
)

target_link_libraries(Goldwell Disc_Engine)