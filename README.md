# Entity Component System (WIP)

### Author(s): ###

- Xillez - kent.wincent46@gmail.com

### Introduction

Entity Component System.

### Tools used:

- CMake - https://cmake.org/download/
- Make - http://gnuwin32.sourceforge.net/packages/make.htm
- Doxygen - http://www.doxygen.nl/download.html

### Installation / Usage
2. From repository root, run:

   ```Shell
   mkdir build && cd build
   ```


3. Build the program (__LINUX__): 
   
   ```Shell
   cmake .. && make
   ```
   
   Build the program (__WINDOWS__ - __PowerShell__): 
   
   __NOTE:__ MinGW has to be first in PATH environment variables
   
   ```Shell
   cmake ..; mingw32-make.exe
   ```
   
  4. Run the executable:

     ``` 
     ./bin/ecs
     ```

### Features: 

- Entity component lifecycle (start, update, draw, destroy)

### TODO:

- Scene graph integration with parenting
- Extendable entity and component lifecycle
