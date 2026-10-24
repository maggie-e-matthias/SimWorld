cmake_minimum_required(VERSION 3.16)

project(Survivor_Island_Simulator)

set(SOURCE_FILES
  src/base.cpp src/survivors.cpp src/builds.cpp src/animals.cpp src/event.cpp src/undo.cpp src/ui.cpp simulation.cpp
)

add_executable(sim ${SOURCE_FILES})

target_include_directories(sim PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})