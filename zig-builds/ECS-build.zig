const std = @import("std");
const utils = @import("build-utils.zig");
const proj_location = "Engine/src/Iridium/ECS";

pub fn build(b: *std.Build) void {
    const project_name = "ECS";
    const mode = b.standardOptimizeOption(.{});
    const target = b.standardTargetOptions(.{});
    const bin_dir = utils.getBinDir(project_name, b);
    const src_file = std.fs.path.join(b.allocator, &[_][]const u8{ proj_location, "ECS.zig" }) catch unreachable;
    const lib = b.addStaticLibrary(.{
        .name = project_name,
        .optimize = mode,
        .target = target,
        .root_source_file = .{ .path = src_file },
    });

    lib.addIncludePath(.{ .path = "src" });
    b.lib_dir = bin_dir;
    b.installArtifact(lib);
}
