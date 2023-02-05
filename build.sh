BASEDIR=$(dirname "$0") # Get script location.

printf "Switching to build directory: \"$BASEDIR/build\"\n"
cd "$BASEDIR/build"

printf "Running cmake...\n"
cmake ..

printf "Building program...\n"
make

if [[ -f "./bin/ecs" ]]; then
    printf "Running application:\n"
    ./bin/ecs
else
    printf "No application to run, check for build errors!\n"
fi

printf "Switching back to working directory\n"
cd "$BASEDIR"