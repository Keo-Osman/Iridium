const std = @import("std");
const utils = @import("build-utils.zig");
const proj_location = "Engine/vendor/glfw";

pub fn build(b: *std.Build, target: std.Build.ResolvedTarget, mode: std.builtin.OptimizeMode) !*std.Build.Step.Compile {
    const project_name = "glfw";
    const bin_dir = utils.getBinDir(b, target, mode);
    const lib = b.addStaticLibrary(.{
        .name = project_name,
        .optimize = mode,
        .target = target,
    });
    const srcDir = "Engine/Vendor/glfw/src";
    const files = try utils.getAllFiles(srcDir, b);
    defer std.heap.page_allocator.free(files);
    std.debug.print("GLFW: number of files detected: {any}\n", .{files.len});
    for (files) |filepath| {
        const path = std.Build.LazyPath{ .path = filepath };
        const file = std.Build.Module.CSourceFile{ .file = path };
        std.debug.print("File: {s}", .{filepath});
        if (utils.endsWith(filepath, ".cpp")) {
            lib.addCSourceFile(file);
            std.debug.print("File: {s}", .{file.file.path});
        }
    }
    b.lib_dir = bin_dir;
    b.installArtifact(lib);
    return lib;
}
