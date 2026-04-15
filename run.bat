@echo off

if not exist build mkdir build
pushd build

set day=%1
set part=%2

cl -O2 /std:c++17  /EHsc /nologo ../day%day%/day%day%_part%part%.cpp ../common.cpp /Fe:day%day%_part%part%.exe
if errorlevel 1 goto end
del day%day%_part%part%.obj
day%day%_part%part%.exe

:end
popd