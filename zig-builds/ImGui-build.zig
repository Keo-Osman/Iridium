const std = @import("std");
const utils = @import("build-utils.zig");
const proj_location = "Engine/vendor/Imgui";

pub fn build(b: *std.Build, target: std.Build.ResolvedTarget, mode: std.builtin.OptimizeMode) !*std.Build.Step.Compile {
    const project_name = "ImGui";
    const bin_dir = utils.getBinDir(b, target, mode);
    const lib = b.addStaticLibrary(.{
        .name = project_name,
        .optimize = mode,
        .target = target,
    });
    const files = [_][]const u8{ "Engine/Vendor/ImGui/imconfig.h", "Engine/Vendor/ImGui/imgui.h", "Engine/Vendor/ImGui/imgui.h", "Engine/Vendor/ImGui/imgui.h", "Engine/Vendor/ImGui/imgui.cpp", "Engine/Vendor/ImGui/imgui_draw.cpp", "Engine/Vendor/ImGui/imgui_internal.h", "Engine/Vendor/ImGui/imgui_widgets.cpp", "Engine/Vendor/ImGui/imstb_rectpack.h", "Engine/Vendor/ImGui/imstb_textedit.h", "Engine/Vendor/ImGui/imstb_truetype.h", "Engine/Vendor/ImGui/imgui_demo.cpp" };

    //defer std.heap.page_allocator.free(files);
    std.debug.print("ImGui: number of files detected: {any}\n", .{files.len});

    for (files) |filepath| {
        const path = std.Build.LazyPath{ .path = filepath };
        const file = std.Build.Module.CSourceFile{ .file = path };
        std.debug.print("File: {s}\n", .{filepath});
        if (utils.endsWith(filepath, ".cpp")) {
            lib.addCSourceFile(file);
            std.debug.print("File: {s}", .{file.file.path});
        }
    }
    lib.linkLibCpp();
    b.lib_dir = bin_dir;
    b.installArtifact(lib);
    return lib;
}
