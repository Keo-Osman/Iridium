@echo off
setlocal enabledelayedexpansion

set "extensions=.sln .vcxproj .vcxproj.filters .vcxproj.user .csproj .ninja .ninja_deps .ninja_log .cmake"

for %%E in (%extensions%) do (
    for /r %%F in (*) do (
        set "dir=%%~dpF"
        if not "!dir:\vendor\=!"=="!dir!" (
            rem Skip this file/directory as it's in the vendor directory
        ) else (
            if /i "%%~xF"=="%%E" (
                echo Deleting "%%F"
                del "%%F" /f /q
            )
        )
    )
)

echo Deleting .vs and .vscode folders...

if exist ".vs" (
    echo Deleting .vs folder...
    rmdir ".vs" /s /q
)

if exist "CMakeFiles" (
    echo Deleting .vscode folder...
    rmdir "CMakeFiles" /s /q
)

echo Deleting Makefiles...

for /r %%F in (Makefile*) do (
    set "dir=%%~dpF"
    if not "!dir:\vendor\=!"=="!dir!" (
        rem Skip this file/directory as it's in the vendor directory
    ) else (
        echo Deleting "%%F"
        del "%%F" /f /q
    )
)

echo All files with specified extensions, specified folders, and Makefiles have been deleted.
pause