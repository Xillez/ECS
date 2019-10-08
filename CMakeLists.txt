# Set cmake minimum
cmake_minimum_required(VERSION 3.10)

# Set project name
set(PROJECT_NAME "ecs")
set(VERSION "v0.1")

# "true" to build for release or "false" to build for debug.
set(DEBUG_BUILD "true")

# "true" to enable logging or "false" to disable.
set(LOGGING "true")

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  message("Linux build")
  SET(LINUX 1)
  SET(APPLE 0)
  SET(WINDOWS 0)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  message("Mac build")
  SET(LINUX 0)
  SET(APPLE 1)
  SET(WINDOWS 0)
elseif(WIN32)
  message("Windows build")
  SET(WINDOWS 1)
  SET(LINUX 0)
  SET(APPLE 0)
endif()

# Automatic setup of release and debug build setting
if(DEBUG_BUILD STREQUAL "true")
  set(CMAKE_BUILD_TYPE "Debug")
else()
  set(CMAKE_BUILD_TYPE "Release")
  set(LOGGING "false")
endif()

# Set cmake options
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# Set custom compiler
if(LINUX)
  set(CMAKE_GENERATOR "Unix Makefiles" CACHE INTERNAL "" FORCE)
elseif (WINDOWS)
  set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")
  set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")
endif(WINDOWS)

# Set project name
project(${PROJECT_NAME})

# Set the output to the bin folder
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
#set(OUTPUT_DEBUG_PATH ${EXECUTABLE_OUTPUT_PATH}/debug)
#set(OUTPUT_RELEASE_PATH ${EXECUTABLE_OUTPUT_PATH}/release)
set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/source)
set(CMAKE_SOURCE_DIR ${PROJECT_SOURCE_DIR})

# Pass CMake settings to source header
configure_file(
  "${PROJECT_SOURCE_DIR}/config/Config.hpp.in"
  "${PROJECT_SOURCE_DIR}/config/Config.hpp"
  @ONLY
  )

#include_directories("${PROJECT_BINARY_DIR}")

# OS specific before executable addition
if(WINDOWS)
#add_subdirectory(ASSIMP)
#link_directories(${PROJECT_BINARY_DIR})
endif(WINDOWS)

if(APPLE)
	#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${GLEW_INCLUDE_DIRS}")
endif(APPLE)

if(LINUX)
	#
endif(LINUX)

# Give files for building application
add_executable(${PROJECT_NAME} 
  #src
  ${PROJECT_SOURCE_DIR}/src/main.cpp
  
  # Utillities
  ${PROJECT_SOURCE_DIR}/util/Logging.cpp
  
  # Components
  ${PROJECT_SOURCE_DIR}/ecs/component/Component.cpp

  # Entities
  ${PROJECT_SOURCE_DIR}/ecs/entity/Entity.cpp

  # Managers
  ${PROJECT_SOURCE_DIR}/ecs/system/EntityMgr.cpp
)

# OS specific before executable addition
if(WINDOWS)
#add_subdirectory(ASSIMP)
#link_directories(${PROJECT_BINARY_DIR})
endif(WINDOWS)

if(APPLE)
	#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${GLEW_INCLUDE_DIRS}")
endif(APPLE)

if(LINUX)
	#
endif(LINUX)

# File copy example
#file(COPY  ${PROJECT_SOURCE_DIR}/libs/dll/glew32.dll DESTINATION ${PROJECT_BINARY_DIR})
