BASEDIR = (Get-Location)

Write-Output "Switching to build directory"
cd "$(BASEDIR.Path)\build"

Write-Output "Running cmake"
cmake ..

Write-Output "Building program"
mingw32-make

if (-not(Test-Path -Path "./bin/ecs.exe" -PathType Leaf)) {
    Write-Output "Running application"
    ./bin/ecs.exe
} else {
    Write-Host "No application to run, check for build errors!\n"
}

Write-Output "Switching back to working directory"
cd "$(BASEDIR.Path)"