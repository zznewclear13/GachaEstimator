cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

set(GE_EXTERNAL_DIR ${GE_PROJECT_DIR}/external)
set(GE_BUILD_DIR ${GE_PROJECT_DIR}/build)

message("[${GE_NAME}] Submodule downloading begins...")

include(ExternalProject)
ExternalProject_ADD(
    fmtlib
    SOURCE_DIR ${GE_EXTERNAL_DIR}/fmt
    CMAKE_ARGS -DBUILD_SHARED_LIBS=TRUE
    INSTALL_COMMAND ""
)
list(APPEND GE_EXTERNAL_INCLUDE_DIR ${GE_EXTERNAL_DIR}/fmt/include)
list(APPEND GE_EXTERNAL_LINK_DIR ${GE_BUILD_DIR}/external/fmtlib-prefix/src/fmtlib-build/$<CONFIG>)

ExternalProject_ADD(
    nanothreadlib
    SOURCE_DIR ${GE_EXTERNAL_DIR}/nanothread
    INSTALL_COMMAND ""
)
list(APPEND GE_EXTERNAL_INCLUDE_DIR ${GE_EXTERNAL_DIR}/nanothread/include)
list(APPEND GE_EXTERNAL_LINK_DIR ${GE_BUILD_DIR}/external/nanothreadlib-prefix/src/nanothreadlib-build/$<CONFIG>)

message("[${GE_NAME}] Submodule downloading ends...\n")

add_dependencies(${GE_NAME} fmtlib nanothreadlib)
target_include_directories(${GE_NAME} PRIVATE ${GE_EXTERNAL_INCLUDE_DIR})
target_link_directories(${GE_NAME} PUBLIC ${GE_EXTERNAL_LINK_DIR})
target_link_libraries(${GE_NAME} fmt$<$<CONFIG:Debug>:d> nanothread)