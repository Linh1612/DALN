cmake_minimum_required(VERSION 3.14)

project(Hospital LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

add_executable(Hospital
  main.cpp
  doctor.h
  instance.h
  lib_.h
  room.h
  solution.h
  solver.h
  data/AbilityMatrix_1.csv
  data/AbsentSchedule_1.csv
  data/Doctor_1.csv
  data/JobSchedule_1.csv
  data/JobSchedule.csv
  data/Room_1.csv
)
target_link_libraries(Hospital Qt${QT_VERSION_MAJOR}::Core)
