@echo off
setlocal enabledelayedexpansion

cd Engine/src/Iridium/ECS
zig build install
cd ../../../../

set /p "COMPILER=What compiler would you like to use? (Clang (c) or GCC (g)): "

set "COMPILER=!COMPILER:~0,1!"
set "COMPILER=!COMPILER:l=L!"

if "!COMPILER!"=="c" ( 
    echo clang chosen
) else if "!COMPILER!"=="g" ( 
    echo gcc chosen
) else (
    echo Invalid input. Please enter 'c' for Clang or 'g' for GCC.
    goto :EOF
)

set /p "BUILD_SYSTEM=What build system do you want to use? (Ninja (n) or Make (m)): "

set "BUILD_SYSTEM=!BUILD_SYSTEM:~0,1!"
set "BUILD_SYSTEM=!BUILD_SYSTEM:l=L!"

if "!BUILD_SYSTEM!"=="n" ( 
    echo ninja chosen
) else if "!BUILD_SYSTEM!"=="m" ( 
    echo make chosen
) else (
    echo Invalid input. Please enter 'n' for Ninja or 'm' for Make.
    goto :EOF
)

set /p "CONFIG=What Configuration do you want to build: "

if "!COMPILER!"=="c" (
    if "!BUILD_SYSTEM!"=="m" ( 
        premake --cc=clang --os=windows gmake2
        make -j32 config=!CONFIG!
    ) else (
        premake --cc=clang --os=windows cmake
        cmake -GNinja -DCMAKE_BUILD_TYPE=!CONFIG! -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
        ninja
    )
) else (
    if "!BUILD_SYSTEM!"=="m" ( 
        premake --cc=gcc --os=windows gmake2
        make -j32 config=!CONFIG!
    ) else (
        premake --cc=gcc --os=windows cmake
        cmake -GNinja -DCMAKE_BUILD_TYPE=!CONFIG! -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++
        ninja
    )
)

endlocal
