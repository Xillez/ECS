# Set cmake minimum
cmake_minimum_required(VERSION 3.10)

set(PROJECT_VERSION "v0.1")
set(BUILD_TYPE_DEBUG "Debug")
set(BUILD_TYPE_RELEASE "Release")
set(CMAKE_BUILD_TYPE ${BUILD_TYPE_DEBUG})
set(BUILD_TYPE ${BUILD_TYPE_DEBUG})

set(BUILD_LOG "1")

# Set cmake options
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_GENERATOR "Unix Makefiles" CACHE INTERNAL "" FORCE)

# Set project name
set(PROJECT_NAME "ecs")

# Set project name
project(${PROJECT_NAME})

# Set the output to the bin folder
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
#set(OUTPUT_DEBUG_PATH ${EXECUTABLE_OUTPUT_PATH}/debug)
#set(OUTPUT_RELEASE_PATH ${EXECUTABLE_OUTPUT_PATH}/release)
set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/source)
set(CMAKE_SOURCE_DIR ${PROJECT_SOURCE_DIR})

# Configure a header file to pass some of the CMake settings
# to the source code
configure_file(
  "${PROJECT_SOURCE_DIR}/config/Config.hpp.in"
  "${PROJECT_SOURCE_DIR}/config/Config.hpp"
  @ONLY
  )

#include_directories("${PROJECT_BINARY_DIR}")

#add_definitions(-DPROJECT_VERSION=${PROJECT_VERSION})
#add_definitions(-DBUILD_DEBUG=${BUILD_DEBUG})

# Add all cpp files used in the program
add_executable(${PROJECT_NAME} 
	#src
  ${PROJECT_SOURCE_DIR}/src/main.cpp
  
  # Components
  ${PROJECT_SOURCE_DIR}/ecs/component/Component.cpp

  # Entities
  ${PROJECT_SOURCE_DIR}/ecs/entity/Entity.cpp

  # Managers
  #${PROJECT_SOURCE_DIR}/ecs/system/ComponentMgr.cpp
  ${PROJECT_SOURCE_DIR}/ecs/system/EntityMgr.cpp
)

#ADD_CUSTOM_TARGET(debug
#  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
#  COMMAND ${CMAKE_COMMAND} --build ${OUTPUT_DEBUG_PATH} --target all
#  COMMENT "Switch CMAKE_BUILD_TYPE to Debug"
#)
#
#ADD_CUSTOM_TARGET(release
#  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
#  COMMAND ${CMAKE_COMMAND} --build ${OUTPUT_RELEASE_PATH} --target all
#  COMMENT "Switch CMAKE_BUILD_TYPE to Release"
#)
#
#ADD_CUSTOM_TARGET(all
#  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
#  COMMAND ${CMAKE_COMMAND} --build ${OUTPUT_DEBUG_PATH} --target all
#  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
#  COMMAND ${CMAKE_COMMAND} --build ${OUTPUT_RELEASE_PATH} --target all
#  COMMENT "Switch CMAKE_BUILD_TYPE to All"
#)

#target_compile_features(${PROJECT_NAME} PRIVATE cxx_lambda_init_captures)
#target_compile_definitions(${PROJECT_NAME} PRIVATE PROJECT_VERSION=${PROJECT_VERSION} BUILD_DEBUG=${BUILD_DEBUG})