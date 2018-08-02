#CMAKE FOR GLFW GLEW 
cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME "Framework")
set(PROJECT_VERSION "v0.1")

project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES CXX)

#Set the output to the bin folder where cmake was executed
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# Add all cpp files used in the program
add_executable(${PROJECT_NAME} 
	#src
	${PROJECT_SOURCE_DIR}/source/src/main.cpp

	# Datastruct 
	#${PROJECT_SOURCE_DIR}/source/datastruct/Datastruct.cpp 
	
	#ecs
	${PROJECT_SOURCE_DIR}/source/ecs/system/EntityMgr.cpp
	${PROJECT_SOURCE_DIR}/source/ecs/system/ComponentMgr.cpp

	${PROJECT_SOURCE_DIR}/source/ecs/entity/Entity.cpp
	${PROJECT_SOURCE_DIR}/source/ecs/component/Component.cpp
)