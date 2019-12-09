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

# OS specific before executable addition
if(WINDOWS)
  set(CMAKE_GENERATOR "MinGW Makefiles" CACHE INTERNAL "" FORCE)
endif(WINDOWS)

if(APPLE)
  #
endif(APPLE)

if(LINUX)
  set(CMAKE_GENERATOR "Unix Makefiles" CACHE INTERNAL "" FORCE)
endif(LINUX)

