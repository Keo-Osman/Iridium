const std = @import("std");
pub fn modeToString(mode: std.builtin.Mode) []const u8 {
    switch (mode) {
        .Debug => return "Debug",
        .ReleaseSafe => return "Release",
        .ReleaseFast => return "Dist",
        .ReleaseSmall => return "Dist-Small",
    }
}

pub fn getBinDir(b: *std.Build, target: std.Build.ResolvedTarget, mode: std.builtin.OptimizeMode) []const u8 {
    const os_str = @tagName(target.result.os.tag);
    const cpu = @tagName(target.result.cpu.arch);

    const hyphen = "__";
    var buffer = std.ArrayList(u8).init(b.allocator);
    defer buffer.deinit();

    buffer.appendSlice(cpu) catch unreachable;
    buffer.appendSlice(hyphen) catch unreachable;
    buffer.appendSlice(os_str) catch unreachable;

    const cfg = buffer.items;

    const bin_dir = std.fs.path.join(b.allocator, &[_][]const u8{ "bin", modeToString(mode), cfg }) catch unreachable;

    return bin_dir;
}
pub fn getLibraryPath(prjName: []const u8, b: *std.Build, target: std.Build.ResolvedTarget, mode: std.builtin.OptimizeMode) std.Build.LazyPath {
    const os_str = @tagName(target.result.os.tag);
    const cpu = @tagName(target.result.cpu.arch);

    const hyphen = "__";
    var buffer = std.ArrayList(u8).init(b.allocator);
    defer buffer.deinit();

    buffer.appendSlice(cpu) catch unreachable;
    buffer.appendSlice(hyphen) catch unreachable;
    buffer.appendSlice(os_str) catch unreachable;

    const cfg = buffer.items;

    var libname = std.ArrayList(u8).init(b.allocator);
    defer libname.deinit();
    libname.appendSlice(prjName) catch unreachable;
    libname.appendSlice(".lib") catch unreachable;

    const filename = libname.items;

    const bin_dir = std.fs.path.join(b.allocator, &[_][]const u8{ "bin", modeToString(mode), cfg, filename }) catch unreachable;
    const ret: std.Build.LazyPath = std.Build.LazyPath{ .path = bin_dir };

    return ret;
}

pub fn getAllFiles(path: []const u8, b: *std.Build) ![][]const u8 {
    var dir = try std.fs.cwd().openDir(path, .{ .iterate = true });
    defer dir.close();

    var walker = try dir.walk(b.allocator);

    var files = std.ArrayList([]const u8).init(std.heap.page_allocator);
    defer files.deinit();

    while (try walker.next()) |entry| {
        if (entry.kind == std.fs.Dir.Entry.Kind.file) {
            try files.append(entry.path);
        }
    }
    return files.toOwnedSlice();
}

pub fn endsWith(s: []const u8, suffix: []const u8) bool {
    if (s.len < suffix.len) return false;

    var i: usize = s.len - suffix.len;
    for (suffix) |c| {
        if (s[i] != c) return false;
        i += 1;
    }
    return true;
}
