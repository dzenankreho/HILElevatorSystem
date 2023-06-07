cmake_minimum_required(VERSION 3.14)

project(Elevators LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(JSONRPCPP_PATH ${CMAKE_CURRENT_SOURCE_DIR}/jsonrpcpp/include CACHE INTERNAL "")
set(SERIALIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/serialib/lib CACHE INTERNAL "")

find_package(Qt5 REQUIRED COMPONENTS Gui Quick)

include_directories(include
                    ${JSONRPCPP_PATH}
                    ${SERIALIB_PATH})

set(INCLUDES include/Button.h
             include/CallButton.h
             include/FloorButton.h
             include/LocalController.h
             include/ClientComModule.h
             include/Elevator.h
             include/GuiElevator.h)

set(SOURCES src/Button.cpp
            src/CallButton.cpp
            src/FloorButton.cpp
            src/LocalController.cpp
            src/ClientComModule.cpp
            src/Elevator.cpp
            src/GuiElevator.cpp)

add_executable(Elevators
  src/main.cpp
  ${INCLUDES}
  ${SOURCES}
  ${SERIALIB_PATH}/serialib.cpp
  resources/qml.qrc
)

target_link_libraries(Elevators Qt5::Gui Qt5::Quick)
