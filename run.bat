@echo off

if not exist build mkdir build
pushd build

set day=%1
set part=%2

cl /EHsc /nologo ../day%day%/day%day%_part%part%.cpp /Fe:day%day%_part%part%.exe
del day%day%_part%part%.obj
day%day%_part%part%.exe

popd