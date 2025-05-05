 #ifndef ZEFIR_UI_API_H
 #define ZEFIR_UI_API_H
 
 #define WIN32_LEAN_AND_MEAN
 #define NOMINMAX
 #include <Windows.h>
 #include <stdint.h>
 #include <stdbool.h>
 
 #define ZEFIR_STDCALL __stdcall
 #define ZEFIR_CALLBACK ZEFIR_STDCALL
 
 #define ZEFIR_EXPORT __declspec(dllexport)
 #define ZEFIR_IMPORT __declspec(dllimport)
 #define ZEFIR_DLL ZEFIR_IMPORT
 
 #define ZEFIR_API(type) ZEFIR_DLL type ZEFIR_STDCALL
 
 typedef uint64_t Zefir_UId64;
 typedef void* Zefir_PImFont;
 
 /* Define TextBlock alignment enum */
 
 typedef enum {
     Zefir_TextBlock_Alignment_Left,
     Zefir_TextBlock_Alignment_Center,
     Zefir_TextBlock_Alignment_Right,
     Zefir_TextBlock_Alignment_Justify
 } Zefir_TextBlock_Alignment;
 
 /* Define ImVec4 and ImVec2 structures */
 
 typedef struct {
     float x, y, z, w;
 } Zefir_ImVec4;
 
 typedef struct {
     float x, y;
 } Zefir_ImVec2;
 
 /* Define optional structures */
 
 typedef struct {
     int m_value;
     bool m_hasValue;
 } Zefir_Optional_Int;
 
 typedef struct {
     bool m_value;
     bool m_hasValue;
 } Zefir_Optional_Bool;
 
 typedef struct {
     Zefir_TextBlock_Alignment m_value;
     bool m_hasValue;
 } Zefir_Optional_TextBlock_Alignment;
 
 typedef struct {
     float m_value;
     bool m_hasValue;
 } Zefir_Optional_Float;
 
 typedef struct {
     const char* m_value;
     bool m_hasValue;
 } Zefir_Optional_String;
 
 typedef struct {
     uint8_t* m_value;
     bool m_hasValue;
 } Zefir_Optional_PUInt8;
 
 typedef struct {
     bool* m_value;
     bool m_hasValue;
 } Zefir_Optional_PBool;
 
 typedef struct {
     uint8_t m_value;
     bool m_hasValue;
 } Zefir_Optional_UInt8;
 
 typedef struct {
     Zefir_PImFont m_value;
     bool m_hasValue;
 } Zefir_Optional_PImFont;
 
 typedef struct {
     Zefir_ImVec4 m_value;
     bool m_hasValue;
 } Zefir_Optional_ImVec4;
 
 typedef struct {
     void (ZEFIR_CALLBACK* m_value)(void);
     bool m_hasValue;
 } Zefir_Optional_ZefirCallback;
 
 typedef struct {
     void (ZEFIR_CALLBACK* m_value)(int);
     bool m_hasValue;
 } Zefir_Optional_ZefirCallback_Int;
 
 typedef struct {
     void (ZEFIR_CALLBACK* m_value)(const char*);
     bool m_hasValue;
 } Zefir_Optional_ZefirCallback_String;
 
 typedef struct {
     void (ZEFIR_CALLBACK* m_value)(float);
     bool m_hasValue;
 } Zefir_Optional_ZefirCallback_Float;
 
 /* Data structure for Button parameters */
 
 typedef struct {
     Zefir_UId64 m_uniqueId;
     const char* m_label;
     Zefir_Optional_PUInt8 m_key;
     Zefir_Optional_String m_info;
     Zefir_Optional_PImFont m_customInfoFont;
     Zefir_Optional_ZefirCallback m_onActivate;
     Zefir_Optional_ZefirCallback m_onHotkeySet;
     Zefir_Optional_ZefirCallback m_renderExtra;
 } Zefir_ButtonData;
 
 /* Data structure for Checkbox parameters */
 
 typedef struct {
     Zefir_UId64 m_uniqueId;
     const char* m_label;
     bool* m_value;
     Zefir_Optional_PUInt8 m_key;
     Zefir_Optional_String m_info;
     Zefir_Optional_PImFont m_customInfoFont;
     Zefir_Optional_ZefirCallback m_onActivate;
     Zefir_Optional_ZefirCallback m_onHotkeySet;
     Zefir_Optional_ZefirCallback m_renderExtra;
 } Zefir_CheckboxData;
 
 /* Data structure for ColorPicker parameters */
 
 typedef struct {
     Zefir_UId64 m_uniqueId;
     const char* m_label;
     Zefir_ImVec4* m_colorValue;
     Zefir_Optional_PUInt8 m_key;
     Zefir_Optional_String m_info;
     Zefir_Optional_PImFont m_customInfoFont;
     Zefir_Optional_ZefirCallback m_onActivate;
     Zefir_Optional_ZefirCallback m_onHotkeySet;
     Zefir_Optional_ZefirCallback m_renderExtra;
 } Zefir_ColorPickerData;
 
 /* Data structure for HintedColorPicker parameters */
 
 typedef struct {
     Zefir_UId64 m_uniqueId;
     const char* m_label;
     Zefir_ImVec4* m_colorValue;
     const char** m_hintKeys; /* Array of hint keys */
     Zefir_ImVec4* m_hintValues;   /* Array of hint values */
     size_t m_hintCount;         /* Number of hints */
     Zefir_Optional_PUInt8 m_key;
     Zefir_Optional_String m_info;
     Zefir_Optional_PImFont m_customInfoFont;
     Zefir_Optional_ZefirCallback m_onActivate;
     Zefir_Optional_ZefirCallback m_onHotkeySet;
     Zefir_Optional_ZefirCallback m_renderExtra;
     Zefir_Optional_ZefirCallback m_onSelectHint;
 } Zefir_HintedColorPickerData;
 
 /* Data structure for Listbox parameters */
 
 typedef struct {
     Zefir_UId64 m_uniqueId;
     const char** m_list; /* Array of strings */
     size_t m_listCount;    /* Number of items in list */
     uint8_t* m_value;
     Zefir_Optional_ZefirCallback m_onActivate;
     Zefir_Optional_ZefirCallback m_onRelease;
 } Zefir_ListboxData;
 
 /* Data structure for InputInt parameters */
 
 typedef struct {
     Zefir_UId64 m_uniqueId;
     const char* m_label;
     int* m_value;
     Zefir_Optional_Float m_speed;
     Zefir_Optional_Int m_min;
     Zefir_Optional_Int m_max;
     Zefir_Optional_ZefirCallback m_onActive;
     Zefir_Optional_ZefirCallback m_onRelease;
 } Zefir_InputIntData;
 
 /* Data structure for InputFloat parameters */
 
 typedef struct {
     Zefir_UId64 m_uniqueId;
     const char* m_label;
     float* m_value;
     Zefir_Optional_Float m_speed;
     Zefir_Optional_Float m_min;
     Zefir_Optional_Float m_max;
     Zefir_Optional_String m_format;
     Zefir_Optional_ZefirCallback m_onActive;
     Zefir_Optional_ZefirCallback m_onRelease;
 } Zefir_InputFloatData;
 
 
 /* Data structure for InputText parameters */
 
 typedef struct {
     Zefir_UId64 m_uniqueId;
     char* m_text; /* Mutable buffer for text */
     size_t m_bufferSize; /* Length of the text buffer */
     Zefir_Optional_Float m_width;
     Zefir_Optional_ZefirCallback m_onActive;
     Zefir_Optional_ZefirCallback m_onRelease;
 } Zefir_InputTextData;
 
 
 /* Data structure for InputHintedText parameters */
 
 typedef struct {
     Zefir_UId64 m_uniqueId;
     char* m_text;
     size_t m_bufferSize; /* Length of the text buffer */
     const char** m_hints; /* Array of hint strings */
     size_t m_hintCount;     /* Number of hints */
     Zefir_Optional_Float m_width;
     Zefir_Optional_ZefirCallback m_onActive;
     Zefir_Optional_ZefirCallback m_onRelease;
 } Zefir_InputHintedTextData;
 
 /* Data structure for TextBlock parameters */
 
 typedef struct {
     Zefir_UId64 m_uniqueId;
     const char* m_text;
     Zefir_Optional_TextBlock_Alignment m_alignment; /* Using int for TextBlock_Alignment */
     Zefir_Optional_Float m_maxHeight;
     Zefir_Optional_Float m_contentRatio;
     Zefir_Optional_Bool m_wordWrap;
 } Zefir_TextBlockData;
 
 /* Data structure for Hotkey parameters */
 
 typedef struct {
     Zefir_UId64 m_uniqueId;
     const char* m_label;
     uint8_t* m_key;
     Zefir_Optional_UInt8 m_restartKey;
     Zefir_Optional_ImVec4 m_colorText;
     Zefir_Optional_ImVec4 m_colorBorder;
     Zefir_Optional_ImVec4 m_colorTextActiveMultiplier;
     Zefir_Optional_ImVec4 m_colorBorderActiveMultiplier;
     Zefir_Optional_Float m_size;
 } Zefir_HotkeyData;
 
 /* Data structure for HorizontalBox parameters */
 
 typedef struct {
     Zefir_UId64 m_uniqueId;
     float m_size;
     Zefir_Optional_Float m_verticalMultiplier;
     Zefir_Optional_ZefirCallback m_renderFunction;
 } Zefir_HorizontalBoxData;
 
 
 /* Data structure for PopupCustom parameters */
 
 typedef struct {
     const char* m_title;
     void (ZEFIR_CALLBACK* m_content)(void);
     Zefir_Optional_Float m_customWidth;
     Zefir_Optional_ZefirCallback m_onDismiss;
 } Zefir_PopupCustomData;
 
 /* Data structure for MessageBoxText parameters */
 
 typedef struct {
     const char* m_title;
     const char* m_text;
     Zefir_Optional_Float m_customWidth;
     Zefir_Optional_PImFont m_customFont;
     Zefir_Optional_TextBlock_Alignment m_alignment;
     Zefir_Optional_ZefirCallback m_onDismiss;
 } Zefir_MessageBoxTextData;
 
 /* Data structure for MessageBoxYesNo parameters */
 
 typedef struct {
     const char* m_title;
     const char* m_text;
     Zefir_Optional_Float m_customWidth;
     Zefir_Optional_PImFont m_customFont;
     Zefir_Optional_TextBlock_Alignment m_alignment;
     Zefir_Optional_ZefirCallback m_onConfirm;
     Zefir_Optional_ZefirCallback m_onDismiss;
 } Zefir_MessageBoxYesNoData;
 
 /* Data structure for InputBoxInt parameters */
 
 typedef struct {
     const char* m_title;
     const char* m_label;
     const char* m_text;
     Zefir_Optional_Float m_customWidth;
     Zefir_Optional_PImFont m_customFont;
     Zefir_Optional_TextBlock_Alignment m_alignment;
     Zefir_Optional_ZefirCallback_Int m_onConfirm;
     Zefir_Optional_ZefirCallback_Int m_onDismiss;
     Zefir_Optional_Float m_speed;
     Zefir_Optional_Int m_min;
     Zefir_Optional_Int m_max;
     Zefir_Optional_ZefirCallback m_onInputActive;
     Zefir_Optional_ZefirCallback m_onInputRelease;
 } Zefir_InputBoxIntData;
 
 /* Data structure for InputBoxFloat parameters */
 
 typedef struct {
     const char* m_title;
     const char* m_label;
     const char* m_text;
     Zefir_Optional_Float m_customWidth;
     Zefir_Optional_PImFont m_customFont;
     Zefir_Optional_TextBlock_Alignment m_alignment;
     Zefir_Optional_ZefirCallback_Float m_onConfirm;
     Zefir_Optional_ZefirCallback_Float m_onDismiss;
     Zefir_Optional_Float m_speed;
     Zefir_Optional_Float m_min;
     Zefir_Optional_Float m_max;
     Zefir_Optional_ZefirCallback m_onInputActive;
     Zefir_Optional_ZefirCallback m_onInputRelease;
 } Zefir_InputBoxFloatData;
 
 /* Data structure for InputBoxText parameters */
 
 typedef struct {
     const char* m_title;
     const char* m_text;
     Zefir_Optional_Float m_customWidth;
     Zefir_Optional_PImFont m_customFont;
     Zefir_Optional_TextBlock_Alignment m_alignment;
     Zefir_Optional_ZefirCallback_String m_onConfirm;
     Zefir_Optional_ZefirCallback_String m_onDismiss;
     Zefir_Optional_ZefirCallback m_onInputActive;
     Zefir_Optional_ZefirCallback m_onInputRelease;
 } Zefir_InputBoxTextData;
 
 /* Data structure for InputBoxHintedText parameters */
 
 typedef struct {
     const char* m_title;
     const char* m_text;
     const char** m_hints;
     size_t m_hintCount;
     Zefir_Optional_Float m_customWidth;
     Zefir_Optional_PImFont m_customFont;
     Zefir_Optional_TextBlock_Alignment m_alignment;
     Zefir_Optional_ZefirCallback_String m_onConfirm;
     Zefir_Optional_ZefirCallback_String m_onDismiss;
     Zefir_Optional_ZefirCallback m_onInputActive;
     Zefir_Optional_ZefirCallback m_onInputRelease;
 } Zefir_InputBoxHintedTextData;
 
 /* Data structure for Window parameters */
 
 typedef struct {
     const char* m_id;
     const char* m_title;
     Zefir_Optional_PBool m_handle;
     Zefir_Optional_ZefirCallback m_onInit;
     Zefir_Optional_ZefirCallback m_onRenderHeader;
     Zefir_Optional_ZefirCallback m_onRenderContent;
     Zefir_Optional_ZefirCallback m_onRenderFooter;
 } Zefir_WindowData;
 
 /* Data structure for Version */
 
 typedef enum {
     Zefir_Version_Unknown,
     Zefir_Version_Alpha,
     Zefir_Version_Beta,
     Zefir_Version_Release
 } Zefir_VersionType;
 
 typedef struct {
     int m_major;
     int m_minor;
     int m_preRelease;
     Zefir_VersionType m_type;
 } Zefir_VersionData;
 
 /* Data structure for Scheduler */
 
 typedef enum {
     Zefir_Scheduler_PreRenderScheduler,
     Zefir_Scheduler_PostRenderScheduler,
     Zefir_Scheduler_GameThreadScheduler,
 } Zefir_SchedulerType;
 
 typedef struct {
     Zefir_SchedulerType m_schedulerType;
     void (ZEFIR_CALLBACK* m_callback)(void);
     Zefir_Optional_Int m_delayMs;
 } Zefir_ScheduleOnceData;
 
 typedef struct {
     Zefir_UId64 m_uniqueId;
     Zefir_SchedulerType m_schedulerType;
     void (ZEFIR_CALLBACK* m_callback)(void);
     Zefir_Optional_Int m_delayMs;
 } Zefir_ScheduleRepeatData;
 
 /*
  * 
  * Functions declarations
  * Here we declare the functions that will be used in the API.
  * 
  */
 
 #ifdef __cplusplus 
 extern "C" { /* extern "C" */
 #endif
 
 #ifdef ZEFIR_API_USE_LIB 
 
     /* Common functions */
     ZEFIR_API(bool) Zefir_initializeAPI();
     ZEFIR_API(Zefir_VersionData) Zefir_getAppVersion();
     ZEFIR_API(Zefir_VersionData) Zefir_getLatestStableVersion();
     ZEFIR_API(Zefir_VersionData) Zefir_getLatestBetaVersion();
 
     /* Font functions */ 
     ZEFIR_API(Zefir_PImFont) Zefir_getTitleFont();
     ZEFIR_API(Zefir_PImFont) Zefir_getContentFont();
     ZEFIR_API(Zefir_PImFont) Zefir_getCustomFont(const char* const name);
 
     /* Logging functions */
     ZEFIR_API(void) Zefir_logInfo(const char* const message);
     ZEFIR_API(void) Zefir_logError(const char* const message);
 
     /* Scheduling functions */
     ZEFIR_API(bool) Zefir_scheduleOnce(const Zefir_ScheduleOnceData* const data);
     ZEFIR_API(bool) Zefir_scheduleRepeat(const Zefir_ScheduleRepeatData* const data);
     ZEFIR_API(bool) Zefir_removeScheduleRepeat(const Zefir_SchedulerType type, const Zefir_UId64 uniqueId);
 
     /* Id functions */
     ZEFIR_API(Zefir_UId64) Zefir_hashId_String(const char* const string);
     ZEFIR_API(Zefir_UId64) Zefir_hashId_UId64(Zefir_UId64 value);
     ZEFIR_API(Zefir_UId64) Zefir_autoRegisterId(Zefir_UId64 value); /* only for c++ macro use, otherwise use Zefir_hashId_Type */
 
     /* Component functions */
     ZEFIR_API(void) Zefir_renderText(const char* const text);
     ZEFIR_API(bool) Zefir_renderButton(const Zefir_ButtonData* const data);
     ZEFIR_API(bool) Zefir_renderCheckbox(const Zefir_CheckboxData* const data);
     ZEFIR_API(bool) Zefir_renderColorPicker(const Zefir_ColorPickerData* const data);
     ZEFIR_API(bool) Zefir_renderHintedColorPicker(const Zefir_HintedColorPickerData* const data);
     ZEFIR_API(bool) Zefir_renderListbox(const Zefir_ListboxData* const data);
     ZEFIR_API(bool) Zefir_renderTextBlock(const Zefir_TextBlockData* const data);
     ZEFIR_API(bool) Zefir_renderHotkey(const Zefir_HotkeyData* const data);
     ZEFIR_API(bool) Zefir_renderHorizontalBox(const Zefir_HorizontalBoxData* const data);
     ZEFIR_API(bool) Zefir_renderInputInt(const Zefir_InputIntData* const data);
     ZEFIR_API(bool) Zefir_renderInputFloat(const Zefir_InputFloatData* const data);
     ZEFIR_API(bool) Zefir_renderInputText(const Zefir_InputTextData* const data);
     ZEFIR_API(bool) Zefir_renderInputTextHinted(const Zefir_InputHintedTextData* const data);
 
     /* Popup functions */
     ZEFIR_API(bool) Zefir_openPopupCustom(const Zefir_PopupCustomData* const data);
     ZEFIR_API(bool) Zefir_openMessageBoxText(const Zefir_MessageBoxTextData* const data);
     ZEFIR_API(bool) Zefir_openMessageBoxYesNo(const Zefir_MessageBoxYesNoData* const data);
     ZEFIR_API(bool) Zefir_openInputBoxInt(const Zefir_InputBoxIntData* const data);
     ZEFIR_API(bool) Zefir_openInputBoxFloat(const Zefir_InputBoxFloatData* const data);
     ZEFIR_API(bool) Zefir_openInputBoxText(const Zefir_InputBoxTextData* const data);
     ZEFIR_API(bool) Zefir_openInputBoxTextHinted(const Zefir_InputBoxHintedTextData* const data);
 
     /* Window functions */
     ZEFIR_API(bool) Zefir_addWindow(const Zefir_WindowData* const data);
     ZEFIR_API(bool) Zefir_removeWindow(const char* const id);
     ZEFIR_API(void) Zefir_resetWindowPosition();
 
 #else /* ZEFIR_API_USE_LIB */
 
 #define ZEFIR_CREATE_STRINGIFY(x) #x
 #define ZEFIR_CREATE_CONCAT(a, b) ZEFIR_CREATE_CONCAT_INNER(a, b)
 #define ZEFIR_CREATE_CONCAT_INNER(a, b) a##b
 
 #define ZEFIR_CREATE_DECLARATION_HELPER(rtype, name, ...) \
     typedef rtype (ZEFIR_STDCALL* ZEFIR_CREATE_CONCAT(name, _t))(__VA_ARGS__); ZEFIR_CREATE_CONCAT(name, _t) name = 0;
 
 #define ZEFIR_CREATE_RESOLVE_HELPER(mod, rtype, name) \
     name = (ZEFIR_CREATE_CONCAT(name, _t))GetProcAddress(mod, ZEFIR_CREATE_STRINGIFY(name));
 
     /* Common functions */
     /* This is now local because you are not supposed to call this       */
     /* ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_initializeAPI, void); */ 
     ZEFIR_CREATE_DECLARATION_HELPER(Zefir_VersionData, Zefir_getAppVersion, void);
     ZEFIR_CREATE_DECLARATION_HELPER(Zefir_VersionData, Zefir_getLatestStableVersion, void);
     ZEFIR_CREATE_DECLARATION_HELPER(Zefir_VersionData, Zefir_getLatestBetaVersion, void);
     
     /* Font functions */
     ZEFIR_CREATE_DECLARATION_HELPER(Zefir_PImFont, Zefir_getTitleFont, void);
     ZEFIR_CREATE_DECLARATION_HELPER(Zefir_PImFont, Zefir_getContentFont, void);
     ZEFIR_CREATE_DECLARATION_HELPER(Zefir_PImFont, Zefir_getCustomFont, const char* const name);
     
     /* Logging functions */
     ZEFIR_CREATE_DECLARATION_HELPER(void, Zefir_logInfo, const char* const message);
     ZEFIR_CREATE_DECLARATION_HELPER(void, Zefir_logError, const char* const message);
     
     /* Scheduling functions */
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_scheduleOnce, const Zefir_ScheduleOnceData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_scheduleRepeat, const Zefir_ScheduleRepeatData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_removeScheduleRepeat, const Zefir_SchedulerType type, const Zefir_UId64 uniqueId);
     
     /* Id functions */
     ZEFIR_CREATE_DECLARATION_HELPER(Zefir_UId64, Zefir_hashId_String, const char* const string);
     ZEFIR_CREATE_DECLARATION_HELPER(Zefir_UId64, Zefir_hashId_UId64, Zefir_UId64 value);
     ZEFIR_CREATE_DECLARATION_HELPER(Zefir_UId64, Zefir_autoRegisterId, Zefir_UId64 value); /* only for c++ macro use, otherwise use Zefir_hashId_Type */
     
     /* Component functions */
     ZEFIR_CREATE_DECLARATION_HELPER(void, Zefir_renderText, const char* const text);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_renderButton, const Zefir_ButtonData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_renderCheckbox, const Zefir_CheckboxData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_renderColorPicker, const Zefir_ColorPickerData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_renderHintedColorPicker, const Zefir_HintedColorPickerData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_renderListbox, const Zefir_ListboxData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_renderTextBlock, const Zefir_TextBlockData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_renderHotkey, const Zefir_HotkeyData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_renderHorizontalBox, const Zefir_HorizontalBoxData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_renderInputInt, const Zefir_InputIntData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_renderInputFloat, const Zefir_InputFloatData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_renderInputText, const Zefir_InputTextData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_renderInputTextHinted, const Zefir_InputHintedTextData* const data);
 
     /* Popup functions */
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_openPopupCustom, const Zefir_PopupCustomData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_openMessageBoxText, const Zefir_MessageBoxTextData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_openMessageBoxYesNo, const Zefir_MessageBoxYesNoData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_openInputBoxInt, const Zefir_InputBoxIntData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_openInputBoxFloat, const Zefir_InputBoxFloatData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_openInputBoxText, const Zefir_InputBoxTextData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_openInputBoxTextHinted, const Zefir_InputBoxHintedTextData* const data);
 
     /* Window functions */
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_addWindow, const Zefir_WindowData* const data);
     ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_removeWindow, const char* const id);
     ZEFIR_CREATE_DECLARATION_HELPER(void, Zefir_resetWindowPosition, void);
 
     static inline bool Zefir_initializeAPI_Create(const char* const moduleName)
     {
         HMODULE hZefir = GetModuleHandleA(moduleName);
         if (hZefir)
         {
             ZEFIR_CREATE_DECLARATION_HELPER(bool, Zefir_initializeAPI, void);
 
             /* Common functions */
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_initializeAPI);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, Zefir_VersionData, Zefir_getAppVersion);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, Zefir_VersionData, Zefir_getLatestStableVersion);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, Zefir_VersionData, Zefir_getLatestBetaVersion);
 
             /* Font functions */
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, Zefir_PImFont, Zefir_getTitleFont);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, Zefir_PImFont, Zefir_getContentFont);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, Zefir_PImFont, Zefir_getCustomFont);
 
             /* Logging functions */
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, void, Zefir_logInfo);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, void, Zefir_logError);
 
             /* Scheduling functions */
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_scheduleOnce);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_scheduleRepeat);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_removeScheduleRepeat);
 
             /* Id functions */
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, Zefir_UId64, Zefir_hashId_String);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, Zefir_UId64, Zefir_hashId_UId64);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, Zefir_UId64, Zefir_autoRegisterId);
 
             /* Component functions */
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, void, Zefir_renderText);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_renderButton);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_renderCheckbox);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_renderColorPicker);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_renderHintedColorPicker);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_renderListbox);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_renderTextBlock);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_renderHotkey);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_renderHorizontalBox);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_renderInputInt);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_renderInputFloat);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_renderInputText);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_renderInputTextHinted);
 
             /* Popup functions */
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_openPopupCustom);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_openMessageBoxText);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_openMessageBoxYesNo);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_openInputBoxInt);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_openInputBoxFloat);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_openInputBoxText);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_openInputBoxTextHinted);
 
             /* Window functions */
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_addWindow);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, bool, Zefir_removeWindow);
             ZEFIR_CREATE_RESOLVE_HELPER(hZefir, void, Zefir_resetWindowPosition);
 
             return Zefir_initializeAPI();
         }
         return false;
     }
 
 #endif /* ZEFIR_API_USE_LIB */
 
 #ifdef __cplusplus 
 } /* extern "C" */
 #endif
 
 /*
  *
  * C++ wrappers for the C API
  * Recommended version is C++17 or higher
  *
  */
 
 #ifdef __cplusplus
 
 #include <string>
 #include <vector>
 #include <memory>
 #include <unordered_map>
 
 /* This needs to be separated from the internal zefir:: namespace */
 namespace zefir::api
 {
     namespace app /* Common functions */
     {
         /* call Zefir_initializeAPI() or Zefir_initializeAPI_Create() instead */
         /* inline bool initializeAPI() { return Zefir_initializeAPI(); }      */
         inline Zefir_VersionData getVersion() { return Zefir_getAppVersion(); }
         inline Zefir_VersionData getLatestStableVersion() { return Zefir_getLatestStableVersion(); }
         inline Zefir_VersionData getLatestBetaVersion() { return Zefir_getLatestBetaVersion(); }
     }
 
     namespace log /* Logging functions */
     {
         inline void info(const std::string& message) { Zefir_logInfo(message.c_str()); }
         inline void error(const std::string& message) { Zefir_logError(message.c_str()); }
     }
    
     namespace schedule /* Scheduling functions */
     {
         inline bool once(const Zefir_ScheduleOnceData& data) { return Zefir_scheduleOnce(&data); }
         inline bool repeat(const Zefir_ScheduleRepeatData& data) { return Zefir_scheduleRepeat(&data); }
         inline bool remove(const Zefir_SchedulerType type, const Zefir_UId64 uniqueId) { return Zefir_removeScheduleRepeat(type, uniqueId); }
     }
 
     namespace hash /* Id functions */
     {
         inline Zefir_UId64 value(const std::string& string) { return Zefir_hashId_String(string.c_str()); }
         inline Zefir_UId64 value(Zefir_UId64 value) { return Zefir_hashId_UId64(value); }
         inline Zefir_UId64 autoRegister(Zefir_UId64 value) { return Zefir_autoRegisterId(value); } /* only for c++ macro use, otherwise use Zefir_hashId_Type */
     }
 
     namespace cm /* Component functions */
     {
         inline void text(const std::string& text) { Zefir_renderText(text.c_str()); }
         inline bool button(const Zefir_ButtonData& data) { return Zefir_renderButton(&data); }
         inline bool checkbox(const Zefir_CheckboxData& data) { return Zefir_renderCheckbox(&data); }
         inline bool colorPicker(const Zefir_ColorPickerData& data) { return Zefir_renderColorPicker(&data); }
         inline bool colorPickerHinted(const Zefir_HintedColorPickerData& data, const std::unordered_map<std::string, Zefir_ImVec4>& hints = {})
         {
             if (hints.size())
             {
                 auto dataCopy = data;
                 std::vector<const char*> hintKeys;
                 std::vector<Zefir_ImVec4> hintValues;
                 for (const auto& [key, value] : hints)
                 {
                     hintKeys.push_back(key.c_str());
                     hintValues.push_back(value);
                 }
                 dataCopy.m_hintKeys = hintKeys.data();
                 dataCopy.m_hintValues = hintValues.data();
                 dataCopy.m_hintCount = hintKeys.size();
                 return Zefir_renderHintedColorPicker(&dataCopy);
             }
             return Zefir_renderHintedColorPicker(&data);
         }
         inline bool listbox(const Zefir_ListboxData& data, const std::vector<std::string>& list = {})
         {
             if (list.size())
             {
                 auto dataCopy = data;
                 std::vector<const char*> listPtrs;
                 for (const auto& item : list)
                 {
                     listPtrs.push_back(item.c_str());
                 }
                 dataCopy.m_list = listPtrs.data();
                 dataCopy.m_listCount = listPtrs.size();
                 return Zefir_renderListbox(&dataCopy);
             }
             return Zefir_renderListbox(&data);
         }
         inline bool textBlock(const Zefir_TextBlockData& data) { return Zefir_renderTextBlock(&data); }
         inline bool hotkey(const Zefir_HotkeyData& data) { return Zefir_renderHotkey(&data); }
         inline bool horizontalBox(const Zefir_HorizontalBoxData& data) { return Zefir_renderHorizontalBox(&data); }
         inline bool inputInt(const Zefir_InputIntData& data) { return Zefir_renderInputInt(&data); }
         inline bool inputFloat(const Zefir_InputFloatData& data) { return Zefir_renderInputFloat(&data); }
         inline bool inputText(const Zefir_InputTextData& data) { return Zefir_renderInputText(&data); }
         inline bool inputTextHinted(const Zefir_InputHintedTextData& data, const std::vector<std::string>& hints = {})
         {
             if (hints.size())
             {
                 auto dataCopy = data;
                 std::vector<const char*> hintPtrs;
                 for (const auto& hint : hints)
                 {
                     hintPtrs.push_back(hint.c_str());
                 }
                 dataCopy.m_hints = hintPtrs.data();
                 dataCopy.m_hintCount = hintPtrs.size();
                 return Zefir_renderInputTextHinted(&dataCopy);
 
             }
             return Zefir_renderInputTextHinted(&data);
         }
     }
 
     namespace popup /* Popup functions */
     {
         inline bool custom(const Zefir_PopupCustomData& data) { return Zefir_openPopupCustom(&data); }
         inline bool text(const Zefir_MessageBoxTextData& data) { return Zefir_openMessageBoxText(&data); }
         inline bool yesNo(const Zefir_MessageBoxYesNoData& data) { return Zefir_openMessageBoxYesNo(&data); }
         inline bool inputInt(const Zefir_InputBoxIntData& data) { return Zefir_openInputBoxInt(&data); }
         inline bool inputFloat(const Zefir_InputBoxFloatData& data) { return Zefir_openInputBoxFloat(&data); }
         inline bool inputText(const Zefir_InputBoxTextData& data) { return Zefir_openInputBoxText(&data); }
         inline bool inputTextHinted(const Zefir_InputBoxHintedTextData& data) { return Zefir_openInputBoxTextHinted(&data); }
     }
 
     namespace window /* Window functions */
     {
         inline bool add(const Zefir_WindowData& data) { return Zefir_addWindow(&data); }
         inline bool remove(const std::string& id) { return Zefir_removeWindow(id.c_str()); }
         inline void resetPosition() { Zefir_resetWindowPosition(); }
     }
 }
 
 #endif
 
  /*
   *
   * Macros for generating unique IDs
   * This macro generates a unique ID based on the current time and a counter.
   * Use ZEFIR_NEW_UID() to generate a new unique ID, every usage of the macro
   * has a consistent UId.
   *
   */
 
 #ifdef __cplusplus
 #define ZEFIR_NEW_UID                                                                                                    \
     []() -> Zefir_UId64                                                                                                  \
     {                                                                                                                    \
         static const Zefir_UId64 result =                                                                                \
             Zefir_autoRegisterId(Zefir_hashId_UId64(Zefir_hashId_String(__TIME__) ^ Zefir_hashId_UId64(__COUNTER__)));   \
         return result;                                                                                                   \
     }
 #else 
 #define ZEFIR_NEW_UID() (Zefir_hashId_UId64(Zefir_hashId_String(__TIMESTAMP__) ^ Zefir_hashId_String(__TIME__) ^ Zefir_hashId_UId64(__COUNTER__)))
 #endif
 
 #endif /* ZEFIR_UI_API_H */

 /*
 * Zefir UI API Documentation
 *
 * This header provides the interface for the Zefir UI API, which allows creating
 * user interfaces with various components, popups, and windows.
 *
 * The API is available in both C and C++ versions. The C functions are prefixed
 * with "Zefir_", and the C++ wrappers are under the "zefir::api" namespace.
 *
 * Below is a list of all functions with their descriptions, parameters, return types,
 * and related data structures.

 * ----- Common Functions -----
 *
 * These functions handle initialization and version information.
 *
 * Zefir_initializeAPI_Create
 *    C:   bool Zefir_initializeAPI_Create(const char* const moduleName)
 *    C++: bool Zefir_initializeAPI_Create(const char* const moduleName)
 *    Description: Initializes the Zefir API.
 *    Parameters: 
 *      - const char* const moduleName: Name of the zefir dll to initialize
 *    Returns: bool (true if initialization was successful)
 *
 * Zefir_getAppVersion
 *    C:   Zefir_VersionData Zefir_getAppVersion()
 *    C++: Zefir_VersionData zefir::api::app::getVersion()
 *    Description: Retrieves the current version of the application.
 *    Parameters: None
 *    Returns: Zefir_VersionData
 *    Related Structures:
 *      Zefir_VersionData
 *        - int m_major: Major version number
 *        - int m_minor: Minor version number
 *        - int m_preRelease: Pre-release version number
 *        - Zefir_VersionType m_type: Version type (Unknown, Alpha, Beta, Release)
 *
 * Zefir_getLatestStableVersion
 *    C:   Zefir_VersionData Zefir_getLatestStableVersion()
 *    C++: Zefir_VersionData zefir::api::app::getLatestStableVersion()
 *    Description: Gets the latest stable version available.
 *    Parameters: None
 *    Returns: Zefir_VersionData
 *    Related Structures:
 *      Zefir_VersionData (see above)
 *
 * Zefir_getLatestBetaVersion
 *    C:   Zefir_VersionData Zefir_getLatestBetaVersion()
 *    C++: Zefir_VersionData zefir::api::app::getLatestBetaVersion()
 *    Description: Gets the latest beta version available.
 *    Parameters: None
 *    Returns: Zefir_VersionData
 *    Related Structures:
 *      Zefir_VersionData (see above)

 * ----- Font Functions -----
 *
 * These functions provide access to fonts used in the UI.
 *
 * Zefir_getTitleFont
 *    C:   Zefir_PImFont Zefir_getTitleFont()
 *    C++: Not available
 *    Description: Returns the title font.
 *    Parameters: None
 *    Returns: Zefir_PImFont (pointer to font)
 *
 * Zefir_getContentFont
 *    C:   Zefir_PImFont Zefir_getContentFont()
 *    C++: Not available
 *    Description: Returns the content font.
 *    Parameters: None
 *    Returns: Zefir_PImFont (pointer to font)
 *
 * Zefir_getCustomFont
 *    C:   Zefir_PImFont Zefir_getCustomFont(const char* const name)
 *    C++: Not available
 *    Description: Returns a custom font by name.
 *    Parameters:
 *      - const char* const name: Name of the custom font
 *    Returns: Zefir_PImFont (pointer to font)

 * ----- Logging Functions -----
 *
 * These functions allow logging messages.
 *
 * Zefir_logInfo
 *    C:   void Zefir_logInfo(const char* const message)
 *    C++: void zefir::api::log::info(const std::string& message)
 *    Description: Logs an informational message.
 *    Parameters:
 *      - const char* const message (C): Message to log
 *      - const std::string& message (C++): Message to log
 *    Returns: void
 *
 * Zefir_logError
 *    C:   void Zefir_logError(const char* const message)
 *    C++: void zefir::api::log::error(const std::string& message)
 *    Description: Logs an error message.
 *    Parameters:
 *      - const char* const message (C): Message to log
 *      - const std::string& message (C++): Message to log
 *    Returns: void

 * ----- Scheduling Functions -----
 *
 * These functions manage scheduling callbacks on different threads.
 *
 * Zefir_scheduleOnce
 *    C:   bool Zefir_scheduleOnce(const Zefir_ScheduleOnceData* const data)
 *    C++: bool zefir::api::schedule::once(const Zefir_ScheduleOnceData& data)
 *    Description: Schedules a callback to run once.
 *    Parameters:
 *      - const Zefir_ScheduleOnceData* const data (C): Scheduling data
 *      - const Zefir_ScheduleOnceData& data (C++): Scheduling data
 *    Returns: bool (true if scheduled successfully)
 *    Related Structures:
 *      Zefir_ScheduleOnceData
 *        - Zefir_SchedulerType m_schedulerType: Scheduler type (PreRender, PostRender, GameThread)
 *        - void (ZEFIR_CALLBACK* m_callback)(void): Callback function
 *        - Zefir_Optional_Int m_delayMs: Optional delay in milliseconds
 *
 * Zefir_scheduleRepeat
 *    C:   bool Zefir_scheduleRepeat(const Zefir_ScheduleRepeatData* const data)
 *    C++: bool zefir::api::schedule::repeat(const Zefir_ScheduleRepeatData& data)
 *    Description: Schedules a callback to run repeatedly.
 *    Parameters:
 *      - const Zefir_ScheduleRepeatData* const data (C): Scheduling data
 *      - const Zefir_ScheduleRepeatData& data (C++): Scheduling data
 *    Returns: bool (true if scheduled successfully)
 *    Related Structures:
 *      Zefir_ScheduleRepeatData
 *        - Zefir_UId64 m_uniqueId: Unique identifier
 *        - Zefir_SchedulerType m_schedulerType: Scheduler type
 *        - void (ZEFIR_CALLBACK* m_callback)(void): Callback function
 *        - Zefir_Optional_Int m_delayMs: Optional delay in milliseconds
 *
 * Zefir_removeScheduleRepeat
 *    C:   bool Zefir_removeScheduleRepeat(const Zefir_SchedulerType type, const Zefir_UId64 uniqueId)
 *    C++: bool zefir::api::schedule::remove(const Zefir_SchedulerType type, const Zefir_UId64 uniqueId)
 *    Description: Removes a repeating schedule.
 *    Parameters:
 *      - const Zefir_SchedulerType type: Scheduler type
 *      - const Zefir_UId64 uniqueId: Unique ID of the schedule
 *    Returns: bool (true if removed successfully)

 * ----- ID Functions -----
 *
 * These functions generate unique IDs for UI elements.
 *
 * Zefir_hashId_String
 *    C:   Zefir_UId64 Zefir_hashId_String(const char* const string)
 *    C++: Zefir_UId64 zefir::api::hash::value(const std::string& string)
 *    Description: Generates a unique ID from a string.
 *    Parameters:
 *      - const char* const string (C): String to hash
 *      - const std::string& string (C++): String to hash
 *    Returns: Zefir_UId64
 *
 * Zefir_hashId_UId64
 *    C:   Zefir_UId64 Zefir_hashId_UId64(Zefir_UId64 value)
 *    C++: Zefir_UId64 zefir::api::hash::value(Zefir_UId64 value)
 *    Description: Generates a unique ID from a uint64_t value.
 *    Parameters:
 *      - Zefir_UId64 value: Value to hash
 *    Returns: Zefir_UId64
 *
 * Zefir_autoRegisterId
 *    C:   Zefir_UId64 Zefir_autoRegisterId(Zefir_UId64 value)
 *    C++: Zefir_UId64 zefir::api::hash::autoRegister(Zefir_UId64 value)
 *    Description: Auto-registers an ID (for C++ macro use).
 *    Parameters:
 *      - Zefir_UId64 value: Value to register
 *    Returns: Zefir_UId64

 * ----- Component Functions -----
 *
 * These functions render various UI components.
 *
 * Zefir_renderText
 *    C:   void Zefir_renderText(const char* const text)
 *    C++: void zefir::api::cm::text(const std::string& text)
 *    Description: Renders text on the UI.
 *    Parameters:
 *      - const char* const text (C): Text to render
 *      - const std::string& text (C++): Text to render
 *    Returns: void
 *
 * Zefir_renderButton
 *    C:   bool Zefir_renderButton(const Zefir_ButtonData* const data)
 *    C++: bool zefir::api::cm::button(const Zefir_ButtonData& data)
 *    Description: Renders a button.
 *    Parameters:
 *      - const Zefir_ButtonData* const data (C): Button configuration data
 *      - const Zefir_ButtonData& data (C++): Button configuration data
 *    Returns: bool (true if clicked)
 *    Related Structures:
 *      Zefir_ButtonData
 *        - Zefir_UId64 m_uniqueId: Unique identifier
 *        - const char* m_label: Button label
 *        - Zefir_Optional_PUInt8 m_key: Optional hotkey
 *        - Zefir_Optional_String m_info: Optional info text
 *        - Zefir_Optional_PImFont m_customInfoFont: Optional custom font
 *        - Zefir_Optional_ZefirCallback m_onActivate: Optional callback on activation
 *        - Zefir_Optional_ZefirCallback m_onHotkeySet: Optional callback on hotkey set
 *        - Zefir_Optional_ZefirCallback m_renderExtra: Optional extra render callback
 *
 * Zefir_renderCheckbox
 *    C:   bool Zefir_renderCheckbox(const Zefir_CheckboxData* const data)
 *    C++: bool zefir::api::cm::checkbox(const Zefir_CheckboxData& data)
 *    Description: Renders a checkbox.
 *    Parameters:
 *      - const Zefir_CheckboxData* const data (C): Checkbox configuration data
 *      - const Zefir_CheckboxData& data (C++): Checkbox configuration data
 *    Returns: bool (true if state changed)
 *    Related Structures:
 *      Zefir_CheckboxData
 *        - Zefir_UId64 m_uniqueId: Unique identifier
 *        - const char* m_label: Checkbox label
 *        - bool* m_value: Pointer to checkbox value
 *        - Zefir_Optional_PUInt8 m_key: Optional hotkey
 *        - Zefir_Optional_String m_info: Optional info text
 *        - Zefir_Optional_PImFont m_customInfoFont: Optional custom font
 *        - Zefir_Optional_ZefirCallback m_onActivate: Optional callback on activation
 *        - Zefir_Optional_ZefirCallback m_onHotkeySet: Optional callback on hotkey set
 *        - Zefir_Optional_ZefirCallback m_renderExtra: Optional extra render callback
 *
 * Zefir_renderColorPicker
 *    C:   bool Zefir_renderColorPicker(const Zefir_ColorPickerData* const data)
 *    C++: bool zefir::api::cm::colorPicker(const Zefir_ColorPickerData& data)
 *    Description: Renders a color picker.
 *    Parameters:
 *      - const Zefir_ColorPickerData* const data (C): Color picker configuration data
 *      - const Zefir_ColorPickerData& data (C++): Color picker configuration data
 *    Returns: bool (true if color changed)
 *    Related Structures:
 *      Zefir_ColorPickerData
 *        - Zefir_UId64 m_uniqueId: Unique identifier
 *        - const char* m_label: Color picker label
 *        - Zefir_ImVec4* m_colorValue: Pointer to color value
 *        - Zefir_Optional_PUInt8 m_key: Optional hotkey 
 *        - Zefir_Optional_String m_info: Optional info text
 *        - Zefir_Optional_PImFont m_customInfoFont: Optional custom font
 *        - Zefir_Optional_ZefirCallback m_onActivate: Optional callback on activation
 *        - Zefir_Optional_ZefirCallback m_onHotkeySet: Optional callback on hotkey set
 *        - Zefir_Optional_ZefirCallback m_renderExtra: Optional extra render callback
 *
 * Zefir_renderHintedColorPicker
 *    C:   bool Zefir_renderHintedColorPicker(const Zefir_HintedColorPickerData* const data)
 *    C++: bool zefir::api::cm::colorPickerHinted(const Zefir_HintedColorPickerData& data, const std::unordered_map<std::string, Zefir_ImVec4>& hints = {})
 *    Description: Renders a color picker with hints.
 *    Parameters:
 *      - const Zefir_HintedColorPickerData* const data (C): Hinted color picker configuration data
 *      - const Zefir_HintedColorPickerData& data (C++): Hinted color picker configuration data
 *      - const std::unordered_map<std::string, Zefir_ImVec4>& hints (C++): Optional hints map
 *    Returns: bool (true if color changed)
 *    Related Structures:
 *      Zefir_HintedColorPickerData
 *        - Zefir_UId64 m_uniqueId: Unique identifier
 *        - const char* m_label: Color picker label
 *        - Zefir_ImVec4* m_colorValue: Pointer to color value
 *        - const char** m_hintKeys: Array of hint keys
 *        - Zefir_ImVec4* m_hintValues: Array of hint values
 *        - size_t m_hintCount: Number of hints
 *        - Zefir_Optional_PUInt8 m_key: Optional hotkey
 *        - Zefir_Optional_String m_info: Optional info text
 *        - Zefir_Optional_PImFont m_customInfoFont: Optional custom font
 *        - Zefir_Optional_ZefirCallback m_onActivate: Optional callback on activation
 *        - Zefir_Optional_ZefirCallback m_onHotkeySet: Optional callback on hotkey set
 *        - Zefir_Optional_ZefirCallback m_renderExtra: Optional extra render callback
 *        - Zefir_Optional_ZefirCallback m_onSelectHint: Optional callback on hint selection
 *
 * Zefir_renderListbox
 *    C:   bool Zefir_renderListbox(const Zefir_ListboxData* const data)
 *    C++: bool zefir::api::cm::listbox(const Zefir_ListboxData& data, const std::vector<std::string>& list = {})
 *    Description: Renders a listbox.
 *    Parameters:
 *      - const Zefir_ListboxData* const data (C): Listbox configuration data
 *      - const Zefir_ListboxData& data (C++): Listbox configuration data
 *      - const std::vector<std::string>& list (C++): Optional list of items
 *    Returns: bool (true if selection changed)
 *    Related Structures:
 *      Zefir_ListboxData
 *        - Zefir_UId64 m_uniqueId: Unique identifier
 *        - const char** m_list: Array of strings
 *        - size_t m_listCount: Number of items in list
 *        - uint8_t* m_value: Pointer to selected value
 *        - Zefir_Optional_ZefirCallback m_onActivate: Optional callback on activation
 *        - Zefir_Optional_ZefirCallback m_onRelease: Optional callback on release
 *
 * Zefir_renderTextBlock
 *    C:   bool Zefir_renderTextBlock(const Zefir_TextBlockData* const data)
 *    C++: bool zefir::api::cm::textBlock(const Zefir_TextBlockData& data)
 *    Description: Renders a text block.
 *    Parameters:
 *      - const Zefir_TextBlockData* const data (C): Text block configuration data
 *      - const Zefir_TextBlockData& data (C++): Text block configuration data
 *    Returns: bool (true if rendered successfully)
 *    Related Structures:
 *      Zefir_TextBlockData
 *        - Zefir_UId64 m_uniqueId: Unique identifier
 *        - const char* m_text: Text to display
 *        - Zefir_Optional_TextBlock_Alignment m_alignment: Optional text alignment
 *        - Zefir_Optional_Float m_maxHeight: Optional maximum height
 *        - Zefir_Optional_Float m_contentRatio: Optional content ratio
 *        - Zefir_Optional_Bool m_wordWrap: Optional word wrap setting
 *
 * Zefir_renderHotkey
 *    C:   bool Zefir_renderHotkey(const Zefir_HotkeyData* const data)
 *    C++: bool zefir::api::cm::hotkey(const Zefir_HotkeyData& data)
 *    Description: Renders a hotkey input.
 *    Parameters:
 *      - const Zefir_HotkeyData* const data (C): Hotkey configuration data
 *      - const Zefir_HotkeyData& data (C++): Hotkey configuration data
 *    Returns: bool (true if hotkey set)
 *    Related Structures:
 *      Zefir_HotkeyData
 *        - Zefir_UId64 m_uniqueId: Unique identifier
 *        - const char* m_label: Hotkey label
 *        - uint8_t* m_key: Pointer to hotkey value
 *        - Zefir_Optional_UInt8 m_restartKey: Optional restart key
 *        - Zefir_Optional_ImVec4 m_colorText: Optional text color
 *        - Zefir_Optional_ImVec4 m_colorBorder: Optional border color
 *        - Zefir_Optional_ImVec4 m_colorTextActiveMultiplier: Optional active text color multiplier
 *        - Zefir_Optional_ImVec4 m_colorBorderActiveMultiplier: Optional active border color multiplier
 *        - Zefir_Optional_Float m_size: Optional size
 *
 * Zefir_renderHorizontalBox
 *    C:   bool Zefir_renderHorizontalBox(const Zefir_HorizontalBoxData* const data)
 *    C++: bool zefir::api::cm::horizontalBox(const Zefir_HorizontalBoxData& data)
 *    Description: Renders a horizontal box for layout.
 *    Parameters:
 *      - const Zefir_HorizontalBoxData* const data (C): Horizontal box configuration data
 *      - const Zefir_HorizontalBoxData& data (C++): Horizontal box configuration data
 *    Returns: bool (true if rendered successfully)
 *    Related Structures:
 *      Zefir_HorizontalBoxData
 *        - Zefir_UId64 m_uniqueId: Unique identifier
 *        - float m_size: Box size
 *        - Zefir_Optional_Float m_verticalMultiplier: Optional vertical multiplier
 *        - Zefir_Optional_ZefirCallback m_renderFunction: Optional render function
 *
 * Zefir_renderInputInt
 *    C:   bool Zefir_renderInputInt(const Zefir_InputIntData* const data)
 *    C++: bool zefir::api::cm::inputInt(const Zefir_InputIntData& data)
 *    Description: Renders an integer input field.
 *    Parameters:
 *      - const Zefir_InputIntData* const data (C): Input int configuration data
 *      - const Zefir_InputIntData& data (C++): Input int configuration data
 *    Returns: bool (true if value changed)
 *    Related Structures:
 *      Zefir_InputIntData
 *        - Zefir_UId64 m_uniqueId: Unique identifier
 *        - const char* m_label: Input label
 *        - int* m_value: Pointer to integer value
 *        - Zefir_Optional_Float m_speed: Optional input speed
 *        - Zefir_Optional_Int m_min: Optional minimum value
 *        - Zefir_Optional_Int m_max: Optional maximum value
 *        - Zefir_Optional_ZefirCallback m_onActive: Optional callback on active
 *        - Zefir_Optional_ZefirCallback m_onRelease: Optional callback on release
 *
 * Zefir_renderInputFloat
 *    C:   bool Zefir_renderInputFloat(const Zefir_InputFloatData* const data)
 *    C++: bool zefir::api::cm::inputFloat(const Zefir_InputFloatData& data)
 *    Description: Renders a float input field.
 *    Parameters:
 *      - const Zefir_InputFloatData* const data (C): Input float configuration data
 *      - const Zefir_InputFloatData& data (C++): Input float configuration data
 *    Returns: bool (true if value changed)
 *    Related Structures:
 *      Zefir_InputFloatData
 *        - Zefir_UId64 m_uniqueId: Unique identifier
 *        - const char* m_label: Input label
 *        - float* m_value: Pointer to float value
 *        - Zefir_Optional_Float m_speed: Optional input speed
 *        - Zefir_Optional_Float m_min: Optional minimum value
 *        - Zefir_Optional_Float m_max: Optional maximum value
 *        - Zefir_Optional_String m_format: Optional format string
 *        - Zefir_Optional_ZefirCallback m_onActive: Optional callback on active
 *        - Zefir_Optional_ZefirCallback m_onRelease: Optional callback on release
 *
 * Zefir_renderInputText
 *    C:   bool Zefir_renderInputText(const Zefir_InputTextData* const data)
 *    C++: bool zefir::api::cm::inputText(const Zefir_InputTextData& data)
 *    Description: Renders a text input field.
 *    Parameters:
 *      - const Zefir_InputTextData* const data (C): Input text configuration data
 *      - const Zefir_InputTextData& data (C++): Input text configuration data
 *    Returns: bool (true if text changed)
 *    Related Structures:
 *      Zefir_InputTextData
 *        - Zefir_UId64 m_uniqueId: Unique identifier
 *        - char* m_text: Mutable text buffer
 *        - size_t m_bufferSize: Length of the text buffer
 *        - Zefir_Optional_Float m_width: Optional input width
 *        - Zefir_Optional_ZefirCallback m_onActive: Optional callback on active
 *        - Zefir_Optional_ZefirCallback m_onRelease: Optional callback on release
 *
 * Zefir_renderInputTextHinted
 *    C:   bool Zefir_renderInputTextHinted(const Zefir_InputHintedTextData* const data)
 *    C++: bool zefir::api::cm::inputTextHinted(const Zefir_InputHintedTextData& data, const std::vector<std::string>& hints = {})
 *    Description: Renders a text input field with hints.
 *    Parameters:
 *      - const Zefir_InputHintedTextData* const data (C): Hinted input text configuration data
 *      - const Zefir_InputHintedTextData& data (C++): Hinted input text configuration data
 *      - const std::vector<std::string>& hints (C++): Optional hints list
 *    Returns: bool (true if text changed)
 *    Related Structures:
 *      Zefir_InputHintedTextData
 *        - Zefir_UId64 m_uniqueId: Unique identifier
 *        - char* m_text: Mutable text buffer
 *        - size_t m_bufferSize: Length of the text buffer
 *        - const char** m_hints: Array of hint strings
 *        - size_t m_hintCount: Number of hints
 *        - Zefir_Optional_Float m_width: Optional input width
 *        - Zefir_Optional_ZefirCallback m_onActive: Optional callback on active
 *        - Zefir_Optional_ZefirCallback m_onRelease: Optional callback on release

 * ----- Popup Functions -----
 *
 * These functions open various types of popups.
 *
 * Zefir_openPopupCustom
 *    C:   bool Zefir_openPopupCustom(const Zefir_PopupCustomData* const data)
 *    C++: bool zefir::api::popup::custom(const Zefir_PopupCustomData& data)
 *    Description: Opens a custom popup.
 *    Parameters:
 *      - const Zefir_PopupCustomData* const data (C): Custom popup configuration data
 *      - const Zefir_PopupCustomData& data (C++): Custom popup configuration data
 *    Returns: bool (true if opened successfully)
 *    Related Structures:
 *      Zefir_PopupCustomData
 *        - const char* m_title: Popup title
 *        - void (ZEFIR_CALLBACK* m_content)(void): Content rendering callback
 *        - Zefir_Optional_Float m_customWidth: Optional custom width
 *        - Zefir_Optional_ZefirCallback m_onDismiss: Optional callback on dismiss
 *
 * Zefir_openMessageBoxText
 *    C:   bool Zefir_openMessageBoxText(const Zefir_MessageBoxTextData* const data)
 *    C++: bool zefir::api::popup::text(const Zefir_MessageBoxTextData& data)
 *    Description: Opens a message box with text.
 *    Parameters:
 *      - const Zefir_MessageBoxTextData* const data (C): Message box configuration data
 *      - const Zefir_MessageBoxTextData& data (C++): Message box configuration data
 *    Returns: bool (true if opened successfully)
 *    Related Structures:
 *      Zefir_MessageBoxTextData
 *        - const char* m_title: Message box title
 *        - const char* m_text: Message text
 *        - Zefir_Optional_Float m_customWidth: Optional custom width
 *        - Zefir_Optional_PImFont m_customFont: Optional custom font
 *        - Zefir_Optional_TextBlock_Alignment m_alignment: Optional text alignment
 *        - Zefir_Optional_ZefirCallback m_onDismiss: Optional callback on dismiss
 *
 * Zefir_openMessageBoxYesNo
 *    C:   bool Zefir_openMessageBoxYesNo(const Zefir_MessageBoxYesNoData* const data)
 *    C++: bool zefir::api::popup::yesNo(const Zefir_MessageBoxYesNoData& data)
 *    Description: Opens a yes/no message box.
 *    Parameters:
 *      - const Zefir_MessageBoxYesNoData* const data (C): Yes/no message box configuration data
 *      - const Zefir_MessageBoxYesNoData& data (C++): Yes/no message box configuration data
 *    Returns: bool (true if opened successfully)
 *    Related Structures:
 *      Zefir_MessageBoxYesNoData
 *        - const char* m_title: Message box title
 *        - const char* m_text: Message text
 *        - Zefir_Optional_Float m_customWidth: Optional custom width
 *        - Zefir_Optional_PImFont m_customFont: Optional custom font
 *        - Zefir_Optional_TextBlock_Alignment m_alignment: Optional text alignment
 *        - Zefir_Optional_ZefirCallback m_onConfirm: Optional callback on confirm
 *        - Zefir_Optional_ZefirCallback m_onDismiss: Optional callback on dismiss
 *
 * Zefir_openInputBoxInt
 *    C:   bool Zefir_openInputBoxInt(const Zefir_InputBoxIntData* const data)
 *    C++: bool zefir::api::popup::inputInt(const Zefir_InputBoxIntData& data)
 *    Description: Opens an input box for integers.
 *    Parameters:
 *      - const Zefir_InputBoxIntData* const data (C): Input box int configuration data
 *      - const Zefir_InputBoxIntData& data (C++): Input box int configuration data
 *    Returns: bool (true if opened successfully)
 *    Related Structures:
 *      Zefir_InputBoxIntData
 *        - const char* m_title: Input box title
 *        - const char* m_label: Input label
 *        - const char* m_text: Descriptive text
 *        - Zefir_Optional_Float m_customWidth: Optional custom width
 *        - Zefir_Optional_PImFont m_customFont: Optional custom font
 *        - Zefir_Optional_TextBlock_Alignment m_alignment: Optional text alignment
 *        - Zefir_Optional_ZefirCallback_Int m_onConfirm: Optional callback on confirm
 *რ: Optional callback on dismiss
 *        - Zefir_Optional_ZefirCallback_Int m_onDismiss: Optional callback on dismiss
 *        - Zefir_Optional_Float m_speed: Optional input speed
 *        - Zefir_Optional_Int m_min: Optional minimum value
 *        - Zefir_Optional_Int m_max: Optional maximum value
 *        - Zefir_Optional_ZefirCallback m_onInputActive: Optional callback on input active
 *        - Zefir_Optional_ZefirCallback m_onInputRelease: Optional callback on input release
 *
 * Zefir_openInputBoxFloat
 *    C:   bool Zefir_openInputBoxFloat(const Zefir_InputBoxFloatData* const data)
 *    C++: bool zefir::api::popup::inputFloat(const Zefir_InputBoxFloatData& data)
 *    Description: Opens an input box for floats.
 *    Parameters:
 *      - const Zefir_InputBoxFloatData* const data (C): Input box float configuration data
 *      - const Zefir_InputBoxFloatData& data (C++): Input box float configuration data
 *    Returns: bool (true if opened successfully)
 *    Related Structures:
 *      Zefir_InputBoxFloatData
 *        - const char* m_title: Input box title
 *        - const char* m_label: Input label
 *        - const char* m_text: Descriptive text
 *        - Zefir_Optional_Float m_customWidth: Optional custom width
 *        - Zefir_Optional_PImFont m_customFont: Optional custom font
 *        - Zefir_Optional_TextBlock_Alignment m_alignment: Optional text alignment
 *        - Zefir_Optional_ZefirCallback_Float m_onConfirm: Optional callback on confirm
 *        - Zefir_Optional_ZefirCallback_Float m_onDismiss: Optional callback on dismiss
 *        - Zefir_Optional_Float m_speed: Optional input speed
 *        - Zefir_Optional_Float m_min: Optional minimum value
 *        - Zefir_Optional_Float m_max: Optional maximum value
 *        - Zefir_Optional_ZefirCallback m_onInputActive: Optional callback on input active
 *        - Zefir_Optional_ZefirCallback m_onInputRelease: Optional callback on input release
 *
 * Zefir_openInputBoxText
 *    C:   bool Zefir_openInputBoxText(const Zefir_InputBoxTextData* const data)
 *    C++: bool zefir::api::popup::inputText(const Zefir_InputBoxTextData& data)
 *    Description: Opens an input box for text.
 *    Parameters:
 *      - const Zefir_InputBoxTextData* const data (C): Input box text configuration data
 *      - const Zefir_InputBoxTextData& data (C++): Input box text configuration data
 *    Returns: bool (true if opened successfully)
 *    Related Structures:
 *      Zefir_InputBoxTextData
 *        - const char* m_title: Input box title
 *        - const char* m_text: Descriptive text
 *        - Zefir_Optional_Float m_customWidth: Optional custom width
 *        - Zefir_Optional_PImFont m_customFont: Optional custom font
 *        - Zefir_Optional_TextBlock_Alignment m_alignment: Optional text alignment
 *        - Zefir_Optional_ZefirCallback_String m_onConfirm: Optional callback on confirm
 *        - Zefir_Optional_ZefirCallback_String m_onDismiss: Optional callback on dismiss
 *        - Zefir_Optional_ZefirCallback m_onInputActive: Optional callback on input active
 *        - Zefir_Optional_ZefirCallback m_onInputRelease: Optional callback on input release
 *
 * Zefir_openInputBoxTextHinted
 *    C:   bool Zefir_openInputBoxTextHinted(const Zefir_InputBoxHintedTextData* const data)
 *    C++: bool zefir::api::popup::inputTextHinted(const Zefir_InputBoxHintedTextData& data)
 *    Description: Opens an input box for text with hints.
 *    Parameters:
 *      - const Zefir_InputBoxHintedTextData* const data (C): Hinted input box text configuration data
 *      - const Zefir_InputBoxHintedTextData& data (C++): Hinted input box text configuration data
 *    Returns: bool (true if opened successfully)
 *    Related Structures:
 *      Zefir_InputBoxHintedTextData
 *        - const char* m_title: Input box title
 *        - const char* m_text: Descriptive text
 *        - const char** m_hints: Array of hint strings
 *        - size_t m_hintCount: Number of hints
 *        - Zefir_Optional_Float m_customWidth: Optional custom width
 *        - Zefir_Optional_PImFont m_customFont: Optional custom font
 *        - Zefir_Optional_TextBlock_Alignment m_alignment: Optional text alignment
 *        - Zefir_Optional_ZefirCallback_String m_onConfirm: Optional callback on confirm
 *        - Zefir_Optional_ZefirCallback_String m_onDismiss: Optional callback on dismiss
 *        - Zefir_Optional_ZefirCallback m_onInputActive: Optional callback on input active
 *        - Zefir_Optional_ZefirCallback m_onInputRelease: Optional callback on input release

 * ----- Window Functions -----
 *
 * These functions manage windows in the UI.
 *
 * Zefir_addWindow
 *    C:   bool Zefir_addWindow(const Zefir_WindowData* const data)
 *    C++: bool zefir::api::window::add(const Zefir_WindowData& data)
 *    Description: Adds a new window.
 *    Parameters:
 *      - const Zefir_WindowData* const data (C): Window configuration data
 *      - const Zefir_WindowData& data (C++): Window configuration data
 *    Returns: bool (true if added successfully)
 *    Related Structures:
 *      Zefir_WindowData
 *        - const char* m_id: Window identifier
 *        - const char* m_title: Window title
 *        - Zefir_Optional_PBool m_handle: Optional handle pointer
 *        - Zefir_Optional_ZefirCallback m_onInit: Optional initialization callback
 *        - Zefir_Optional_ZefirCallback m_onRenderHeader: Optional header render callback
 *        - Zefir_Optional_ZefirCallback m_onRenderContent: Optional content render callback
 *        - Zefir_Optional_ZefirCallback m_onRenderFooter: Optional footer render callback
 *
 * Zefir_removeWindow
 * Romansh
 *    C:   bool Zefir_removeWindow(const char* const id)
 *    C++: bool zefir::api::window::remove(const std::string& id)
 *    Description: Removes a window by ID.
 *    Parameters:
 *      - const char* const id (C): ID of the window to remove
 *      - const std::string& id (C++): ID of the window to remove
 *    Returns: bool (true if removed successfully)
 *
 * Zefir_resetWindowPosition
 *    C:   void Zefir_resetWindowPosition()
 *    C++: void zefir::api::window::resetPosition()
 *    Description: Resets the position of the window.
 *    Parameters: None
 *    Returns: void

 * ----- Macros -----
 *
 * ZEFIR_NEW_UID
 *    Description: Macro to generate a new unique ID.
 *    In C, it combines timestamps and counter.
 *    In C++, it uses a lambda to register the ID.
 */