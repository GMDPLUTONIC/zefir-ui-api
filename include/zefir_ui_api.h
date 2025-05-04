#ifndef ZEFIR_UI_API_H
#define ZEFIR_UI_API_H

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
 * Todo: add loader without lib
 * 
 */

#ifdef __cplusplus 
extern "C" { /* extern "C" */
#endif

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

#ifdef __cplusplus 
} /* extern "C" */
#endif

/*
 *
 * C++ wrappers for the C API
 * Recommended version is C++17 or higher
 * Todo: Implement C++ wrappers for the C API functions
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
        inline bool initializeAPI() { return Zefir_initializeAPI(); }
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
#define ZEFIR_NEW_UID                                                                                                             \
    []() -> Zefir_UId64                                                                                                           \
    {                                                                                                                             \
        static const Zefir_UId64 result =                                                                                         \
            Zefir_autoRegisterId(Zefir_hashId_UId64(Zefir_hashId_String(__TIME__) ^ Zefir_hashId_UId64(__COUNTER__)));            \
        return result;                                                                                                            \
    }
#else 
#define ZEFIR_NEW_UID() (Zefir_hashId_UId64(Zefir_hashId_String(__TIMESTAMP__) ^ Zefir_hashId_String(__TIME__) ^ Zefir_hashId_UId64(__COUNTER__)))
#endif

#endif /* ZEFIR_UI_API_H */