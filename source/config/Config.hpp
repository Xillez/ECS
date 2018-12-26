#pragma once
/* #undef PROJECT_VERSION */
#define BUILD_TYPE Debug
#define BUILD_TYPE_DEBUG Debug
#define BUILD_TYPE_RELEASE Release
#define BUILD_LOG 1

#define IS_BUILD_TYPE_DEBUG() (BUILD_TYPE == BUILD_TYPE_DEBUG)
#define IS_LOGGING_ENABLED() (BUILD_LOG == 1)
