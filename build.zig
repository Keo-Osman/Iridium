const std = @import("std");
const utils = @import("zig-builds/build-utils.zig");
const ECS = @import("zig-builds/ECS-build.zig");
const Engine = @import("zig-builds/Engine-build.zig");
const ImGui = @import("zig-builds/ImGui-build.zig");
const GLFW = @import("zig-builds/ImGui-build.zig");
//
//pub fn build(b: *std.Build) !void {
//    const mode = b.standardOptimizeOption(.{});
//    const target = b.standardTargetOptions(.{});
//    const ecslib = try ECS.build(b, target, mode);
//    const imgui = try ImGui.build(b, target, mode);
//    const glfw = try GLFW.build(b, target, mode);
//
//    var engineDependencies: [3]*std.Build.Step.Compile = undefined;
//    engineDependencies[0] = ecslib;
//    engineDependencies[1] = imgui;
//    engineDependencies[2] = glfw;
//    std.debug.print("Dependencies Built{s}\n", .{""});
//    try Engine.build(b, &engineDependencies, target, mode);
//}
//

pub fn build(b: *std.Build) !void {
    const mode = b.standardOptimizeOption(.{});
    const target = b.standardTargetOptions(.{});
    _ = try ECS.build(b, target, mode);
}
