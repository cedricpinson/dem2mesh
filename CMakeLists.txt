project(dem2mesh)

cmake_minimum_required(VERSION 3.1)

# Fix behavior of CMAKE_CXX_STANDARD when targeting macOS.
if (POLICY CMP0025)
  cmake_policy(SET CMP0025 NEW)
endif ()

# avoid warning about variable with _ROOT
cmake_policy(SET CMP0074 NEW)

set(MAJOR_VERSION 0)
set(MINOR_VERSION 0)
set(PATCH_VERSION 1)

set(VERSION ${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules")


# Apple needs this to work :_(
if(APPLE)
  include_directories(SYSTEM /usr/local/include)
endif(APPLE)

add_subdirectory(src)
