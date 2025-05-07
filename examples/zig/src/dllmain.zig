const std = @import("std");
const windows = std.os.windows;
const winxtra = @import("winxtra.zig");

const c = @cImport({
    @cInclude("zefir_ui_api.h");
});

fn hashSourceLocation(comptime loc: std.builtin.SourceLocation) comptime_int {
    var hasher = std.hash.Fnv1a_64.init();
    hasher.update(loc.module);
    hasher.update(loc.file);
    hasher.update(loc.fn_name);
    hasher.update(std.mem.asBytes(&loc.line));
    hasher.update(std.mem.asBytes(&loc.column));
    return hasher.final();
}

// Callback for button activation
fn buttonOnActivate() callconv(std.builtin.CallingConvention.winapi) void {
    // Set up message box data
    var messageBoxData = std.mem.zeroInit(c.Zefir_MessageBoxTextData, .{ .m_title = "Button Released".ptr, .m_text = "Button was released".ptr, .m_alignment = .{
        .m_value = c.Zefir_TextBlock_Alignment_Left,
        .m_hasValue = true,
    } });
    // Open message box
    _ = c.Zefir_openMessageBoxText.?(&messageBoxData);
}

// Callback for rendering window content
fn renderContent() callconv(std.builtin.CallingConvention.winapi) void {
    // Render a button
    var buttonData = std.mem.zeroInit(c.Zefir_ButtonData, .{
        .m_uniqueId = comptime hashSourceLocation(@src()),
        .m_label = "Test Button".ptr,
        .m_info = .{
            .m_value = "This is a test button".ptr,
            .m_hasValue = true,
        },
        .m_onActivate = .{
            .m_value = buttonOnActivate,
            .m_hasValue = true,
        },
    });

    // Render the button
    _ = c.Zefir_renderButton.?(&buttonData);
}

fn mainEntry(_: windows.LPVOID) callconv(std.builtin.CallingConvention.winapi) windows.DWORD {
    // Initialize the Zefir API
    // Replace "ToastedMarshmellow.dll" with the name of the zefir UI DLL you want to use
    const success = c.Zefir_initializeAPI_Create("ToastedMarshmellow.dll");
    if (success) {
        var windowData = std.mem.zeroInit(c.Zefir_WindowData, .{
            .m_id = "ZigTest.TestWindow".ptr,
            .m_title = "Zig Window".ptr,
            .m_onRenderContent = .{
                .m_value = renderContent,
                .m_hasValue = true,
            },
        });

        // Add the window
        _ = c.Zefir_addWindow.?(&windowData);
    }
    return std.os.windows.S_OK;
}

pub fn DllMain(
    _: windows.HINSTANCE,
    fdwReason: windows.DWORD,
    _: windows.LPVOID,
) callconv(std.builtin.CallingConvention.winapi) windows.BOOL {
    switch (fdwReason) {
        winxtra.DLL_PROCESS_ATTACH => {
            _ = winxtra.CreateThread(null, 0, mainEntry, null, 0, null);
        },
        winxtra.DLL_PROCESS_DETACH => {},
        winxtra.DLL_THREAD_ATTACH => {},
        winxtra.DLL_THREAD_DETACH => {},
        else => {},
    }

    return windows.TRUE;
}
