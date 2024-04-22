const std = @import("std");
const utils = @import("build-utils.zig");
const proj_location = "Engine/src/Iridium/ECS";
pub fn build(b: *std.Build, target: std.Build.ResolvedTarget, mode: std.builtin.OptimizeMode) !*std.Build.Step.Compile {
    const project_name = "ECS";
    const bin_dir = utils.getBinDir(b, target, mode);
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
    return lib;
}
