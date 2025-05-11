// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "../../../include/zefir_ui_api.h"

#ifdef __cplusplus

static void ZEFIR_CALLBACK showMessageBoxCpp()
{
    zefir::api::popup::text({
        .m_title = "Cpp Popup",
        .m_text = "Hello from C++",
        .m_alignment = {.m_value = Zefir_TextBlock_Alignment_Center, .m_hasValue = true} });
}

static void ZEFIR_CALLBACK renderContentCpp()
{
    zefir::api::cm::text("Hello from C++");
    zefir::api::cm::text("This is a test window");

    zefir::api::cm::button({
        .m_uniqueId = ZEFIR_NEW_UID(),
        .m_label = "Click me",
        .m_onActivate = {.m_value = &showMessageBoxCpp, .m_hasValue = true} });
}

static void ZEFIR_CALLBACK addWindowCpp()
{
    zefir::api::window::add({
        .m_id = "CppTest.TestWindowCpp",
        .m_title = "CPP Window",
        .m_onRenderContent = {.m_value = &renderContentCpp, .m_hasValue = true} });
}

#endif 

static void ZEFIR_CALLBACK showMessageBoxC()
{
    Zefir_PopupTextData data{
        .m_title = "C Popup",
        .m_text = "Hello from C! Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.",
        .m_customWidth = {.m_value = 450, .m_hasValue = true},
        .m_alignment = {.m_value = Zefir_TextBlock_Alignment_Left, .m_hasValue = true} };
        
    Zefir_openPopupText(&data);
}

static void ZEFIR_CALLBACK renderContentC()
{
    Zefir_renderText("Hello from C!");
    Zefir_renderText("This is a test of the C API.");

    Zefir_ButtonData data{
        .m_uniqueId = ZEFIR_NEW_UID(),
        .m_label = "Click me",
        .m_onActivate = {.m_value = &showMessageBoxC, .m_hasValue = true} };

    Zefir_renderButton(&data);
}

static void ZEFIR_CALLBACK addWindowC()
{
    Zefir_WindowData windowData = {
        .m_id = "CppTest.TestWindowC",
        .m_title = "C Window",
        .m_onRenderContent = {.m_value = &renderContentC, .m_hasValue = true} };

    Zefir_addWindow(&windowData);
}

DWORD WINAPI mainThread(LPVOID lpParam)
{
    if (Zefir_initializeAPI_Create("ToastedMarshmellow.dll"))
    {
#       ifdef __cplusplus
        addWindowCpp();
#       endif
        addWindowC();
    }
    return S_OK;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, 0, mainThread, NULL, 0, NULL);
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

