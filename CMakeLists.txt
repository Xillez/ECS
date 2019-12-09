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
  set(OS_NAME "LINUX")
  set(LINUX 1)
  set(APPLE 0)
  set(WINDOWS 0)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  message("Mac build")
  set(OS_NAME "DARWIN")
  set(LINUX 0)
  set(APPLE 1)
  set(WINDOWS 0)
elseif(WIN32)
  message("Windows build")
  set(OS_NAME "WIN32")
  set(LINUX 0)
  set(WINDOWS 1)
  set(APPLE 0)
endif()

# Automatic setup of release and debug build setting
if(DEBUG_BUILD STREQUAL "true")
  set(CMAKE_BUILD_TYPE "Debug")
else()
  set(CMAKE_BUILD_TYPE "Release")
  set(LOGGING "false")
endif()

# Set cmake options + custom compiler
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

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

# OS specific before executable addition
if(WINDOWS)
  #
endif(WINDOWS)

if(APPLE)
	#
endif(APPLE)

if(LINUX)
	#
endif(LINUX)

# Give files for building application
add_executable(${PROJECT_NAME} 
  # src
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
  # check if Doxygen is installed
  find_package(Doxygen)
  if (DOXYGEN_FOUND)
      # set input and output files
      set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
      set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

      # request to configure the file
      configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
      message("Doxygen build started")

      # note the option ALL which allows to build the docs together with the application
      add_custom_target( doc_doxygen ALL
          COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
          WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
          COMMENT "Generating API documentation with Doxygen"
          VERBATIM )
  else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
  endif (DOXYGEN_FOUND)
  #add_subdirectory(ASSIMP)
  #link_directories(${PROJECT_BINARY_DIR})
endif(WINDOWS)

if(APPLE)
	#
endif(APPLE)

if(LINUX)
	#
endif(LINUX)

# File copy example
#file(COPY  ${PROJECT_SOURCE_DIR}/libs/dll/glew32.dll DESTINATION ${PROJECT_BINARY_DIR})
