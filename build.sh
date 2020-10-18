BASEDIR=$(dirname "$0") # Get script location.

printf "Switching to build directory"
cd "$BASEDIR\build"

printf "Running cmake"
cmake ..

printf "Building program"
make

printf "Running application"
./bin/ecs.exe

printf "Switching back to working directory"
cd "$BASEDIR"