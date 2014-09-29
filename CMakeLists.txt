project(AquaAntelope)
cmake_minimum_required(VERSION 2.6)

include_directories($ENV{GMOCK_HOME}/include $ENV{GMOCK_HOME}/gtest/include)
link_directories($ENV{GMOCK_HOME}/mybuild $ENV{GMOCK_HOME}/gtest/mybuild)
add_definitions(-std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(sources
    cursesWindow.cpp
    GameMap.cpp
    GameEngine.cpp
    Player.cpp)
add_library(AquaAntelope_lib ${sources})
add_executable(AquaAntelope main.cpp)

target_link_libraries(AquaAntelope AquaAntelope_lib) 
target_link_libraries(AquaAntelope ncurses)

enable_testing()
set (testSources
     testMain.cpp
     PlayerTester.cpp)
add_executable(runUnitTests ${testSources})
target_link_libraries(runUnitTests AquaAntelope_lib) 
target_link_libraries(runUnitTests pthread)
target_link_libraries(runUnitTests gmock)
target_link_libraries(runUnitTests gtest)

add_test(runTests runUnitTests)
