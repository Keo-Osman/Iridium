const std = @import("std");
const root_dir = "../../../../";

pub fn modeToString(mode: std.builtin.Mode) []const u8 {
    switch (mode) {
        .Debug => return "Debug",
        .ReleaseSafe => return "Release",
        .ReleaseFast => return "Dist",
        .ReleaseSmall => return "Dist-Small",
    }
}

fn concatAndReturnBuffer(allocator: *std.mem.Allocator, one: []const u8, two: []const u8) !std {
    var b = try std.Buffer.init(allocator, one);
    try b.append(two);
    return b;
}

pub fn build(b: *std.Build) void {
    const project_name = "ECS";

    // Set release options
    const mode = b.standardOptimizeOption(.{});

    const target = b.standardTargetOptions(.{});
    const os_str = @tagName(target.result.os.tag);
    const cpu = @tagName(target.result.cpu.arch);

    const hyphen = "__";
    var buffer = std.ArrayList(u8).init(b.allocator);
    defer buffer.deinit();

    buffer.appendSlice(cpu) catch unreachable;
    buffer.appendSlice(hyphen) catch unreachable;
    buffer.appendSlice(os_str) catch unreachable;

    const cfg = buffer.items;

    const bin_dir = std.fs.path.join(b.allocator, &[_][]const u8{
        root_dir,
        "bin",
        cfg,
        project_name,
    }) catch unreachable;

    //const obj_dir = std.fs.path.join(b.allocator, &[_][]const u8{
    //    root_dir,
    //    "bin-int",
    //    modeToString(mode),
    //    @tagName(target),
    //    project_name,
    //}) catch unreachable;

    const lib = b.addStaticLibrary(.{
        .name = project_name,
        .optimize = mode,
        .target = target,
        .root_source_file = .{ .path = "ECS.zig" },
    });

    //const path = std.Build.LazyPath{ .path = "Path" };
    //const install = std.Build.InstallDir{ .custom = "install" };
    //const options = std.Build.Step.InstallDir.Options{ .install_dir = install, .source_dir = path, .install_subdir = "sub" };
    //var dir = std.Build.step(self: *Build, name: []const u8, description: []const u8)
    //install_dir_options.mode = 0o755; // Set the permissions for the directoryonst dir: =
    lib.addIncludePath(.{ .path = "src" });
    lib.linkLibC();
    lib.linkLibCpp();
    //b.dest_dir = "Test";
    b.lib_dir = bin_dir;
    //_ = b.addInstallDirectory(options);
    b.installArtifact(lib);
}
