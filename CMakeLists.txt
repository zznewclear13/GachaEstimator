cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

set(GE_NAME "GachaEstimator")
message("[${GE_NAME}] CMake configuration begins...")

# Set configuration types
set(CMAKE_CONFIGURATION_TYPES Debug Release)
project(
    "Gacha Estimator"
    DESCRIPTION "A probility estimator for gacha games."
    LANGUAGES CXX
)

if(NOT MSVC)
    message(FATAL_ERROR "This app currently only supports MSVC for building." )
endif()

# Set My App as visual studio startup project
set(GE_PROJECT_DIR ${CMAKE_SOURCE_DIR})
set_property(DIRECTORY ${GE_PROJECT_DIR} PROPERTY VS_STARTUP_PROJECT ${GE_NAME})

add_subdirectory(./source)
add_subdirectory(./external)
