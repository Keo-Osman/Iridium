const std = @import("std");
pub fn modeToString(mode: std.builtin.Mode) []const u8 {
    switch (mode) {
        .Debug => return "Debug",
        .ReleaseSafe => return "Release",
        .ReleaseFast => return "Dist",
        .ReleaseSmall => return "Dist-Small",
    }
}

pub fn getBinDir(prjName: []const u8, b: *std.Build) []const u8 {
    const t = b.standardTargetOptions(.{});
    const os_str = @tagName(t.result.os.tag);
    const cpu = @tagName(t.result.cpu.arch);

    const hyphen = "__";
    var buffer = std.ArrayList(u8).init(b.allocator);
    defer buffer.deinit();

    buffer.appendSlice(cpu) catch unreachable;
    buffer.appendSlice(hyphen) catch unreachable;
    buffer.appendSlice(os_str) catch unreachable;

    const cfg = buffer.items;

    const bin_dir = std.fs.path.join(b.allocator, &[_][]const u8{
        "bin",
        modeToString(b.standardOptimizeOption(.{})),
        cfg,
        prjName,
    }) catch unreachable;

    return bin_dir;
}

pub fn collectSources(allocator: *std.mem.Allocator) !std.ArrayList([]const u8) {
    var sources = std.ArrayList([]const u8).init(allocator);
    {
        var dir = try std.fs.cwd().openDir("src", .{ .iterate = true });

        var walker = try dir.walk(allocator);
        defer walker.deinit();

        const allowed_exts = [_][]const u8{ ".c", ".cpp", ".cxx", ".c++", ".cc" };
        while (try walker.next()) |entry| {
            const ext = std.fs.path.extension(entry.basename);
            const include_file = for (allowed_exts) |e| {
                if (std.mem.eql(u8, ext, e))
                    break true;
            } else false;
            if (include_file) {
                // we have to clone the path as walker.next() or walker.deinit() will override/kill it
                try sources.append(allocator, entry.path);
            }
        }
    }
    return sources;
}
