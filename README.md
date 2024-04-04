# Iridium

## Overview
Iridium is a performance oriented game engine written in C++ and Zig. It's goals are to provide a fast interface for building real-time applications Iridium also plans to have heavy use of extended instruction sets such as AVX-512 and SSE and Multi-Threading to achive performance.

## Features
As of now the Engine is `pre 0.1-alpha` and offers no functionality right now but the features that are planned to be implemented an when are detailed in the roadmap below:

## Roadmap
**This is all subject to possibly change**
### v0.1
#### Graphics Rendering:
- Rendering engine capable of displaying 3D graphics.
- Support for rendering basic shapes (e.g., cubes, spheres, planes).
- Basic lighting support (e.g., ambient, directional).
- Perspective projection for 3D rendering.
#### Basic Event and Input Handling
- Games can listen for mouse movement, keyboard input, and window events
#### Basic E.C.S - Entity Component System
- Will support creation of custom entities
- Will not have Physics, Audio or Scripting functionality will have to be handled by the game manually
#### Scene & Assets
- Will support custom scenes
- Will be able to load common 3d model, texture files etc.. *(files able to load are undecided at the moment)*
- Will **Not** support any asset packing of sort games would have to ship with the raw asset file
#### Missing Features:
*subject to change release data*
- Physics - v0.2
- Audio - v0.2
- Scripting -v0.3
- Networking - v1.0+

## Different Branches
There are 3 main branches:
- Master
- Dev-Stable
- Dev-Unstable

### Master:
- It is a branch that will only contain fully tested code and will be updated every minor update.
- *Currently does not exist*
### Dev-Stable 
- It is a branch with new feautures however they will not be fully tested or finished but it **SHOULD** always be guaranteed to compile and with the be working *mostly correctly* with the feauture set it has.
### Dev-Unstable
- It is branch that has **NO GUARANTEE** to even compile. It acts more as a non-local backup for me and shouldn't be cloned as when a feauture compiles and has working functionality it will be immediatley merged to `Dev-Stable` so this branch is not that far ahead in terms of features. 

## How to build:
- First clone the repo with git clone --recursive https://github.com/Keo-Osman/Iridium.git
### For Windows:
#### Using Microsft Visual Studio
Ensure that you have the following installed & available via the **PATH** environment variable:
- [premake5](https://premake.github.io/)
- [Zig](https://ziglang.org/)

Then run `ZigBuild.bat` and run the command `premake vs2022` *(or other version of visual studio)* then just build in visual studio

#### Using other gcc or clang:
Ensure that you have the following installed & available via the **PATH** environment variable:
- [premake5](https://premake.github.io/)
- [Zig](https://ziglang.org/)
- Clang or GCC
- Make or Ninja

Then run build.bat and enter relevant info - for config enter full name either **debug**, **release** or **dist** *(if using make all lowercase and if using ninja first letter is uppercase- should be fixed soon)*

#### Other compiler:
run `ZigBuild.bat` the relevant premake command then build from there *functionality not guaranted*

### For Linux
The steps should be the same as windows but functionality is not guaranteed as of now

### Other Platforms
Other platforms are not supported and currently there is no plan to support other platforms

