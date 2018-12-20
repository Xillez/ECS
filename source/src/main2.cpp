#include "../config/Config.hpp"

#include <stdio.h>
#include <iostream>

int main(int argc, char const *argv[])
{
#if IS_BUILD_TYPE_DEBUG()
	std::printf("DEBUG BUILD!\n");
#endif
#if defined(PROJECT_VERSION)
	std::printf("Project version: %s\n", PROJECT_VERSION);
#endif

	std::cout << "TEST PRINT!\n";
}