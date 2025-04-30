@echo off

setlocal enabledelayedexpansion

::
set SOURCE_FILES=
for /r src %%f in (*.cpp) do (
    set SOURCE_FILES=!SOURCE_FILES! "%%f"
)

set INCLUDE_DIR=include
set OUTPUT=battleship

g++ -I"%INCLUDE_DIR%" %SOURCE_FILES% -o %OUTPUT%
