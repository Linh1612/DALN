cmake_minimum_required(VERSION 3.14)

project(Hospital_Schedule LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

add_executable(Hospital_Schedule
  main.cpp
  Solution.h
  Solver.h
  Instance.h
  Library.h
  Room.h
  Doctor.h
  JobSchedule.csv
  AbilityMatrix.csv
  Room.csv
  Doctor.csv

)
target_link_libraries(Hospital_Schedule Qt${QT_VERSION_MAJOR}::Core)
