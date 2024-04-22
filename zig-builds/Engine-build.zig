const std = @import("std");
const utils = @import("build-utils.zig");
const proj_location = "Engine";

pub fn build(b: *std.Build, links: []*std.Build.Step.Compile, target: std.Build.ResolvedTarget, mode: std.builtin.OptimizeMode) !void {
    const project_name = "Engine";
    const bin_dir = utils.getBinDir(b, target, mode);
    const lib = b.addStaticLibrary(.{
        .name = project_name,
        .optimize = mode,
        .target = target,
    });

    const srcDir = "Engine/src";
    const files = try utils.getAllFiles(srcDir, b);
    defer std.heap.page_allocator.free(files);
    for (files) |filepath| {
        const path = std.Build.LazyPath{ .path = filepath };
        const file = std.Build.Module.CSourceFile{ .file = path };
        if (utils.endsWith(filepath, ".cpp")) {
            lib.addCSourceFile(file);
            std.debug.print("File: {s}", .{file.file.path});
        }
    }

    lib.addIncludePath(.{ .path = "src" });
    lib.addIncludePath(.{ .path = "Engine/vendor/glfw/include" });
    lib.addIncludePath(.{ .path = "Engine/vendor/spdlog/include" });
    lib.addIncludePath(.{ .path = "Engine/vendor/Imgui" });
    //lib.setPCH("Engine/src/irpch.h", "Engine/src/irpch.cpp");
    for (links) |link| {
        lib.linkLibrary(link);
    }
    lib.addObjectFile(utils.getLibraryPath("glfw", b, target, mode));
    lib.addObjectFile(utils.getLibraryPath("ImGui", b, target, mode));

    b.lib_dir = bin_dir;
    b.installArtifact(lib);
}
