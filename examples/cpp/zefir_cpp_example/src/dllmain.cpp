// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "bools.h"
#include <zefir_ui_api.h>

#ifdef __cplusplus

static void ZEFIR_CALLBACK showMessageBoxCpp()
{
    zefir::api::popup::text({
        // popup title
        .m_title = "Cpp Popup",
        // text in the popup
        .m_text = "Hello from C++",
        // position of the text
        .m_alignment = {.m_value = Zefir_TextBlock_Alignment_Center, .m_hasValue = true} });
}

static void ZEFIR_CALLBACK renderContentCpp()
{
    zefir::api::cm::text("Hello from C++");
    zefir::api::cm::text("This is a test window");

    zefir::api::cm::button({
        .m_uniqueId = ZEFIR_NEW_UID(),
        .m_label = "This is a button",
        .m_onActivate = {.m_value = &showMessageBoxCpp, .m_hasValue = true} });

    zefir::api::cm::checkbox({
        .m_uniqueId = ZEFIR_NEW_UID(),
        .m_label = "This is a checkbox",
        .m_value = &testBool });

    zefir::api::cm::inputFloat({
        .m_uniqueId = ZEFIR_NEW_UID(),
        .m_label = "This is an input float",
        .m_value = &testFloat });
}

static void ZEFIR_CALLBACK addWindowCpp()
{
    zefir::api::window::add({
        .m_id = "CppTest.TestWindowCpp",
        .m_title = "CPP Window",
        .m_onRenderContent = {.m_value = &renderContentCpp, .m_hasValue = true} });
}

#endif 

// c stuff
static void ZEFIR_CALLBACK showMessageBoxC()
{
    Zefir_MessageBoxTextData data{
        // popup title
        .m_title = "C Popup",
        // text in the popup
        .m_text = "Hello from C! Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.",
        // width of the popup
        .m_customWidth = {.m_value = 450, .m_hasValue = true},
        // position of the text
        .m_alignment = {.m_value = Zefir_TextBlock_Alignment_Left, .m_hasValue = true} };
        
    Zefir_openMessageBoxText(&data);
}

static void ZEFIR_CALLBACK renderContentC()
{
    Zefir_renderText("Hello from C!");
    Zefir_renderText("This is a test of the C API.");

    Zefir_ButtonData btnData{
        // button ID
        .m_uniqueId = ZEFIR_NEW_UID(),
        // text inside the button
        .m_label = "This is a button",
        // when clicked
        .m_onActivate = {.m_value = &showMessageBoxC, .m_hasValue = true} };
    
    Zefir_CheckboxData checkboxData{
        // checkbox ID
        .m_uniqueId = ZEFIR_NEW_UID(),
        // text by the checkbox
        .m_label = "This is a checkbox",
        // bool that it uses
        .m_value = &testBool };
    
    Zefir_InputFloatData iFData{
        // input float ID
        .m_uniqueId = ZEFIR_NEW_UID(),
        // text right next to the input float
        .m_label = "This is an input float",
        // float for the input float
        .m_value = &testFloat };
        
    Zefir_renderButton(&btnData);
    Zefir_renderCheckbox(&checkboxData);
    Zefir_renderInputFloat(&iFData);
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
#ifdef __cplusplus
        addWindowCpp();
#endif
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