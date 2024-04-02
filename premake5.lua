require "ninja"
require "cmake"

include "Dependencies.lua"

workspace "Iridium"
    configurations { "Debug", "Release", "Dist" }
    architecture "x86_64"
    --startproject "Editor"


group "Dependencies"
    include "Engine/vendor"
group ""

group "Core"
	include "Engine"
group ""

group "Tools"
	include "Editor"
group ""



