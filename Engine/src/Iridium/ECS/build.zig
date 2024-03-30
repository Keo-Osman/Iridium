const std = @import("std");

pub fn build(b: *std.Build) void {
    const lib = b.addSharedLibrary(.{
        .name = "ECS",
        .optimize = b.standardOptimizeOption(.{}),
        .target = b.host,
        .root_source_file = .{ .path = "ECS.zig" },
    });
    //lib.add
    lib.addIncludePath(.{ .path = "src" });
    lib.linkLibC();
    lib.linkLibCpp();
    b.installArtifact(lib);
}
