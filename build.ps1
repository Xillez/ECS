

Write-Output "Switching to build directory"
cd "$((Get-Location).Path)\build"
Write-Output "Running cmake"
cmake ..
Write-Output "Building program"
mingw32-make
Write-Output "Running application"
./bin/ecs.exe
Write-Output "Switching back to working directory"
cd "$((Get-Location).Path)"