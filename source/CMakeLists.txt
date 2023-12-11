#[[
# CMakeLists.txt template for visual studio, Windows

## Features
1. Configure project with just a double click.
2. Minimized configuration: Debug and Release.
3. Customized binary output directory.
4. Automatically set startup project.
5. Automatically find all source files.
6. Automatically generate visual studio filters.
7. Hide console in Release build.

## Folder Structure
```
Base Folder
    |
    +---- binary
    |       |
    |       +---- *binary files*
    |
    +---- build
    |       |
    |       +---- MyApp.sln
    |       +---- *cmake files*
    |
    +---- include
    |
    +---- library
    |
    +---- source
    |       |
    |       +---- *source files*
    |       +---- CMakeLists.txt
    |
    +---- cmake.bat
```

## cmake.bat
```
@echo off
cd %~dp0
if not exist "%~dp0build" (mkdir "%~dp0build")
cd %~dp0build
cmake ../source
cd %~dp0
pause
```

## Usage
Double click `cmake.bat`.

## Limitations
Currently only supports configuring visual studio projects on Windows.


## The MIT License (MIT)
Copyright © 2023 zznewclear@gmail.com

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

]]

# Set c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message("[${GE_NAME}] Making paths...")
# Set path variables
set(GE_SOURCE_DIR ${GE_PROJECT_DIR}/source)
set(GE_INCLUDE_DIR ${GE_SOURCE_DIR} ${GE_PROJECT_DIR}/include)
set(GE_BINARY_DIR ${GE_PROJECT_DIR}/binary)
set(GE_BUILD_DIR ${GE_PROJECT_DIR}/build)
set(GE_TEST_DIR ${GE_PROJECT_DIR}/test)
message("[${GE_NAME}] PROJECT_DIR: ${GE_PROJECT_DIR}")

message("[${GE_NAME}] Gathering all source files...")
# Find all source files, auto re-configure if any file changes
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS *.cpp* *.h* *.hpp*)

message("\n[${GE_NAME}] Building visual studio filters...")
# Set visual studio filters
foreach(_source IN ITEMS ${SOURCE_FILES})
    get_filename_component(_source_path "${_source}" PATH)
    string(REPLACE "${CMAKE_SOURCE_DIR}" "" _group_path "${_source_path}")
    string(REPLACE "/" "\\" _group_path "${_group_path}")
    message(${_source})
    source_group("${_group_path}" FILES "${_source}")
endforeach()

message("\n[${GE_NAME}] Setting build directories...")
# Set custom build directories
foreach(config IN ITEMS ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${config} CONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONFIG} ${GE_BINARY_DIR}/${config})
endforeach()

message("[${GE_NAME}] Adding executables...")
# Add executable
add_executable(${GE_NAME} ${SOURCE_FILES})

# Set include directories
target_include_directories(${GE_NAME} PUBLIC ${GE_INCLUDE_DIR})

add_custom_command(TARGET ${GE_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    ${GE_BUILD_DIR}/external/fmtlib-prefix/src/fmtlib-build/bin/$<CONFIG>/fmt$<$<CONFIG:Debug>:d>.dll
                    ${GE_BUILD_DIR}/external/nanothreadlib-prefix/src/nanothreadlib-build/$<CONFIG>/nanothread.dll
                    ${GE_BINARY_DIR}/$<CONFIG>)

add_custom_command(TARGET ${GE_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${GE_TEST_DIR}
                    ${GE_BINARY_DIR}/$<CONFIG>)
                   

message("[${GE_NAME}] CMake configuration ends.\n")