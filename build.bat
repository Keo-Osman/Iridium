@echo off

set CPPcompiler="clang++"
set Ccompiler="clang"
set build_system="make"
set mode=release
set zigmode=ReleaseSafe
REM Check if command line arguments are provided
if "%~1" neq "" set build_system=%~1
if "%~2" neq "" set compiler=%~2
if "%~3" neq "" set mode=%~3

REM Check for compiler argument
if "%compiler%"=="-c" (
    set Ccompiler="clang"
    set CPPcompiler="clang++"
) else if "%compiler%"=="-g" (
    set Ccompiler="gcc"
    set CPPcompiler="g++"
) else if "%compiler%"=="-z" (
    set Ccompiler="zig cc"
    set Ccompiler="zig c++"
)

REM Check for build system argument
if "%build_system%"=="-m" (
    set build_system="make"
) else if "%build_system%"=="-n" (
    set build_system="ninja"
)

REM Check for mode argument
if "%mode%"=="-d" (
    set mode=debug
    set zigmode=Debug
) else if "%mode%"=="-r" (
    set zigmode=ReleaseSafe
    set mode=release
) else if "%mode%"=="-di" (
    set zigmode=ReleaseFast
    set mode=dist
)

echo Build System: %build_system%
echo Compiler: %ccompiler%
echo Mode: %mode%

call scripts/zigbuild.bat %zigmode%

set condition=F
if %Ccompiler%=="clang" set condition=T
if %Ccompiler%=="gcc" set condition=T


if %build_system%=="make" (
    if condition==T (
        premake --cc="%Ccompiler%" --os=windows gmake2
    ) else (
        premake --os=windows gmake2
    )
    make -j64 config=%mode% CC=%Ccompiler% CXX=%CPPcompiler%
)

