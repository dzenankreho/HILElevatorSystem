cmake_minimum_required(VERSION 3.14)

project(Elevators LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Gui Quick)

add_subdirectory(rpclib)

include_directories(include)

set(INCLUDES include/Button.h
             include/CallButton.h
             include/FloorButton.h
             include/LocalController.h
             include/ClientComModule.h
             include/Elevator.h
             include/ServerController.h
             include/ServerComModule.h)

set(SOURCES src/Button.cpp
            src/CallButton.cpp
            src/FloorButton.cpp
            src/LocalController.cpp
            src/ClientComModule.cpp
            src/Elevator.cpp
            src/ServerController.cpp
            src/ServerComModule.cpp)

add_executable(Elevators
  src/main.cpp
  ${INCLUDES}
  ${SOURCES}
  resources/qml.qrc
)

target_link_libraries(Elevators rpc Qt5::Gui Qt5::Quick)
