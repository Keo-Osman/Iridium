@echo off
setlocal enabledelayedexpansion

set "extensions=.sln .vcxproj .vcxproj.filters .vcxproj.user .csproj .ninja .ninja_deps .ninja_log .cmake"

for %%E in (%extensions%) do (
    for /r %%F in (*) do (
        if /i not "%%~dpF"=="%CD%\vendor\" (
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

if exist ".vscode" (
    echo Deleting .vscode folder...
    rmdir ".vscode" /s /q
)

echo Deleting Makefiles...

for /r %%F in (Makefile*) do (
    if /i not "%%~dpF"=="%CD%\vendor\" (
        echo Deleting "%%F"
        del "%%F" /f /q
    )
)

echo All files with specified extensions, specified folders, and Makefiles have been deleted.
pause