@echo off
for /l %%i in (1,1,25) do (
    mkdir day%%i 2>nul
    type nul > day%%i\day%%i_part1.cpp
    type nul > day%%i\day%%i_part2.cpp
    type nul > day%%i\day%%i_input.txt
)