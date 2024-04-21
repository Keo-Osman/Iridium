const std = @import("std");
const utils = @import("build-utils.zig");
const proj_location = "Engine";

pub fn build(b: *std.Build) void {
    const project_name = "Engine";
    const mode = b.standardOptimizeOption(.{});
    const target = b.standardTargetOptions(.{});
    const bin_dir = utils.getBinDir(project_name, b);
    const lib = b.addStaticLibrary(.{
        .name = project_name,
        .optimize = mode,
        .target = target,
    });

    const sources = utils.collectSources(b.allocator);
    lib.addCSourceFiles(sources.items, &[_][]const u8{});
    lib.addIncludePath(.{ .path = "src" });
    lib.addIncludePath(.{ .path = "Engine/vendor/glfw/include" });
    lib.addIncludePath(.{ .path = "Engine/vendor/spdlog/include" });
    lib.addIncludePath(.{ .path = "Engine/vendor/Imgui" });
    lib.setPCH("Engine/src/irpch.h", "Engine/src/irpch.cpp");
    lib.linkLibrary("glfw", utils.getBinDir("glfw", b));
    lib.linkLibrary("ImGui", utils.getBinDir("ImGui", b));

    b.lib_dir = bin_dir;
    b.installArtifact(lib);
}
