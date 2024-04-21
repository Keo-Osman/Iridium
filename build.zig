const std = @import("std");
const utils = @import("zig-builds/build-utils.zig");
const ECS = @import("zig-builds/ECS-build.zig");
const root_dir = "";
const proj_location = "Engine/src/Iridium/ECS/";
pub fn build(b: *std.Build) void {
    ECS.build(b);
}
