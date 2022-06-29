cmake_minimum_required(VERSION 3.10)
project(TestProject LANGUAGES CXX)

set(MAIN "main.cpp")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(LIBRARIES_DIR "${CMAKE_CURRENT_LIST_DIR}/../lib")
set(EXECUTABLE_NAME "${PROJECT_NAME}")

add_executable(${EXECUTABLE_NAME}
    ${MAIN}
)

add_library(General_Library STATIC
    ${LIBRARIES_DIR}/Menus/MenuPrincipal.hpp
    ${LIBRARIES_DIR}/Menus/MenuPrincipal.cpp
    ${LIBRARIES_DIR}/Menus/MenuStack.hpp
    ${LIBRARIES_DIR}/Menus/MenuStack.cpp
    ${LIBRARIES_DIR}/Menus/MenuQueue.hpp
    ${LIBRARIES_DIR}/Menus/MenuQueue.cpp
    ${LIBRARIES_DIR}/Menus/MenuLinkedList.hpp
    ${LIBRARIES_DIR}/Menus/MenuLinkedList.cpp
    ${LIBRARIES_DIR}/Menus/MenuArrayList.hpp
    ${LIBRARIES_DIR}/Menus/MenuArrayList.cpp
    ${LIBRARIES_DIR}/Tools/Input.hpp
    ${LIBRARIES_DIR}/Tools/Input.cpp
)

target_include_directories(General_Library PUBLIC 
    ${LIBRARIES_DIR}/Menus
    ${LIBRARIES_DIR}/Tools
)

target_link_libraries(${EXECUTABLE_NAME} 
    General_Library
)