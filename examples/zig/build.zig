const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = .ReleaseFast;
    const dll = b.addSharedLibrary(.{
        .name = "dllmain",
        .root_source_file = b.path("src/dllmain.zig"),
        .target = target,
        .optimize = optimize,
    });
    dll.addIncludePath(b.path("../../include"));
    dll.linkLibC();
    b.installArtifact(dll);
}
