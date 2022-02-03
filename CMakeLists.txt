cmake_minimum_required(VERSION 3.10)
project(Air_Attack)

set(CMAKE_CXX_STANDARD 11)

configure_file(images/chopper.png images/chopper.png COPYONLY)
configure_file(images/chopperGreen.png images/chopperGreen.png COPYONLY)
#configure_file(images/sample.png images/sample.png COPYONLY)

# Define sources and executable
set(EXECUTABLE_NAME "Air_Attack")

add_executable(${EXECUTABLE_NAME} main.cpp Classes/Animation.cpp Classes/Animation.h Classes/Entity.cpp Classes/Entity.h)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()