#ifndef ZEFIR_UI_API_H
#define ZEFIR_UI_API_H

#include <stdint.h>
#include <stdbool.h>

#define ZEFIR_CALLBACK __stdcall
#define ZEFIR_API __declspec(dllimport)

typedef uint64_t Zefir_UId64;
typedef void* Zefir_PImFont;

/* Define TextBlock alignment enum */
typedef enum {
    Zefir_TextBlock_Alignment_Left,
    Zefir_TextBlock_Alignment_Center,
    Zefir_TextBlock_Alignment_Right,
    Zefir_TextBlock_Alignment_Justify
} Zefir_TextBlock_Alignment;

typedef struct {
    float x, y, z, w;
} Zefir_ImVec4;

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
    int m_hintCount;         /* Number of hints */
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
    int m_listCount;    /* Number of items in list */
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
    unsigned int m_bufferSize; /* Length of the text buffer */
    Zefir_Optional_Float m_width;
    Zefir_Optional_ZefirCallback m_onActive;
    Zefir_Optional_ZefirCallback m_onRelease;
} Zefir_InputTextData;


/* Data structure for InputHintedText parameters */
typedef struct {
    Zefir_UId64 m_uniqueId;
    char* m_text;
    unsigned int m_bufferSize; /* Length of the text buffer */
    const char** m_hints; /* Array of hint strings */
    int m_hintCount;     /* Number of hints */
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
} Zefir_InputBoxTextData;

/* Data structure for InputBoxHintedText parameters */
typedef struct {
    const char* m_title;
    const char* m_text;
    const char** m_hints;
    int m_hintCount;
    Zefir_Optional_Float m_customWidth;
    Zefir_Optional_PImFont m_customFont;
    Zefir_Optional_TextBlock_Alignment m_alignment;
    Zefir_Optional_ZefirCallback_String m_onConfirm;
    Zefir_Optional_ZefirCallback_String m_onDismiss;
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

#ifdef __cplusplus 
extern "C" { /* extern "C" */
#endif

    /* Common functions */
    ZEFIR_API void Zefir_waitUntilReady();

    /* Id functions */
    ZEFIR_API Zefir_UId64 Zefir_hashId_String(const char* const string);
    ZEFIR_API Zefir_UId64 Zefir_hashId_UId64(Zefir_UId64 value);
    ZEFIR_API Zefir_UId64 Zefir_autoRegisterId(Zefir_UId64 value); // only for c++ macro use, otherwise use Zefir_hashId

    /* Component functions */
    ZEFIR_API void Zefir_renderText(const char* const text);
    ZEFIR_API bool Zefir_renderButton(const Zefir_ButtonData* const data);
    ZEFIR_API bool Zefir_renderCheckbox(const Zefir_CheckboxData* const data);
    ZEFIR_API bool Zefir_renderColorPicker(const Zefir_ColorPickerData* const data);
    ZEFIR_API bool Zefir_renderHintedColorPicker(const Zefir_HintedColorPickerData* const data);
    ZEFIR_API bool Zefir_renderListbox(const Zefir_ListboxData* const data);
    ZEFIR_API bool Zefir_renderTextBlock(const Zefir_TextBlockData* const data);
    ZEFIR_API bool Zefir_renderHotkey(const Zefir_HotkeyData* const data);
    ZEFIR_API bool Zefir_renderHorizontalBox(const Zefir_HorizontalBoxData* const data);
    ZEFIR_API bool Zefir_renderInputInt(const Zefir_InputIntData* const data);
    ZEFIR_API bool Zefir_renderInputFloat(const Zefir_InputFloatData* const data);
    ZEFIR_API bool Zefir_renderInputText(const Zefir_InputTextData* const data);
    ZEFIR_API bool Zefir_renderInputTextHinted(const Zefir_InputHintedTextData* const data);

    /* Popup functions */
    ZEFIR_API bool Zefir_openPopupCustom(const Zefir_PopupCustomData* const data);
    ZEFIR_API bool Zefir_openMessageBoxText(const Zefir_MessageBoxTextData* const data);
    ZEFIR_API bool Zefir_openMessageBoxYesNo(const Zefir_MessageBoxYesNoData* const data);
    ZEFIR_API bool Zefir_openInputBoxInt(const Zefir_InputBoxIntData* const data);
    ZEFIR_API bool Zefir_openInputBoxFloat(const Zefir_InputBoxFloatData* const data);
    ZEFIR_API bool Zefir_openInputBoxText(const Zefir_InputBoxTextData* const data);
    ZEFIR_API bool Zefir_openInputBoxHintedText(const Zefir_InputBoxHintedTextData* const data);

    /* Window functions */
    ZEFIR_API bool Zefir_addWindow(const Zefir_WindowData* const data);
    ZEFIR_API bool Zefir_removeWindow(const char* const id);
    ZEFIR_API void Zefir_resetWindowPosition();

#ifdef __cplusplus 
} /* extern "C" */
#endif

/*
 *
 * C++ wrappers for the C API
 * Todo: Implement C++ wrappers for the C API functions
 *
 */
#ifdef __cplusplus


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