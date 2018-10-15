cmake_minimum_required(VERSION 2.6)
project(DISC_ENGINE)

include_directories(
 src
)

add_executable(Goldwell
 src/Goldwell/main.cpp
)

add_library(Disc_Engine
 src/Disc_Engine/Disc_Engine.h
 src/Disc_Engine/Core.h
 src/Disc_Engine/Entity.h
 src/Disc_Engine/Component.h

 src/Disc_Engine/Core.cpp
 src/Disc_Engine/Entity.cpp
 src/Disc_Engine/Component.cpp

)

target_link_libraries(Goldwell Disc_Engine)