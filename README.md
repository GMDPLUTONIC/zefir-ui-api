# Zefir UI API

> [!NOTE]
> This is HEAVILY WIP, some things might not work/don't work. If you find anything that doesn't work, make an issue!

The api used in GDHM v37.0

## How to use (C++):

- Clone the [cpp example](https://github.com/adafcaefc/zefir-ui-api/tree/v37.0-alpha/examples/cpp).
- Delete the C code in "src/dllmain.cpp".
- Modify the code however you want (you can add buttons, checkboxes, etc)/
- Build the project (preferably with CMake).
- Add the dll to "%localappdata%\ToastedMarshmellow\extension".
- Open GD, open GDHM, and have fun!

### This is code for some functions:

Text:
```
zefir::api::cm::text("Hello from C++");
zefir::api::cm::text("This is a test window");
```

Window:
```
zefir::api::window::add({
    // window ID
    .m_id = "CppTest.TestWindowCpp",
    // window title
    .m_title = "CPP Window",
    // when rendered
    .m_onRenderContent = {.m_value = &renderContentCpp, .m_hasValue = true} });
```

Button:
```
zefir::api::cm::button({
    // button ID
    .m_uniqueId = ZEFIR_NEW_UID(),
    // button label
    .m_label = "This is a button",
    // when clicked
    .m_onActivate = {.m_value = &whatever, .m_hasValue = true} });
```

Checkbox:
```
zefir::api::cm::checkbox({
    // checkbox ID
    .m_uniqueId = ZEFIR_NEW_UID(),
    // checkbox label
    .m_label = "This is a checkbox",
    // bool that it uses
    .m_value = someBool });
```

Input Float:
```
zefir::api::cm::inputFloat({
    // input float ID
    .m_uniqueId = ZEFIR_NEW_UID(),
    // input float label
    .m_label = "This is an input float",
    // float that it uses
    .m_value = someFloat });
```

Your window should look something like this: ![sorry, the image didn't load, try refreshing the page or making an issue](/docs/cppWindow.png)

## How to use (C)

- Clone the [cpp/c example](https://github.com/adafcaefc/zefir-ui-api/tree/v37.0-alpha/examples/cpp).
- Delete the C++ code in "src/dllmain.cpp".
- Rename "dllmain.cpp" to "dllmain.c".
- Modify the code however you want (you can add buttons, checkboxes, etc)/
- Build the project (preferably with CMake).
- Add the dll to "%localappdata%\ToastedMarshmellow\extension".
- Open GD, open GDHM, and have fun!

### This is the code for some functions:

Text:
```
Zefir_renderText("Hello from C!");
Zefir_renderText("This is a test of the C API.");
```

Window:
```
Zefir_WindowData windowData = {
    // window ID
    .m_id = "CppTest.TestWindowC",
    // window title
    .m_title = "C Window",
    // when rendered
    .m_onRenderContent = {.m_value = &renderContentC, .m_hasValue = true} };

Zefir_addWindow(&windowData);
```

Button:
```
Zefir_ButtonData btnData{
    // button ID
    .m_uniqueId = ZEFIR_NEW_UID(),
    // text inside the button
    .m_label = "This is a button",
    // when clicked
    .m_onActivate = {.m_value = &showMessageBoxC, .m_hasValue = true} };

Zefir_renderButton(&btnData);
```

Checkbox:
```
Zefir_CheckboxData checkboxData{
    // checkbox ID
    .m_uniqueId = ZEFIR_NEW_UID(),
    // text by the checkbox
    .m_label = "This is a checkbox",
    // bool that it uses
    .m_value = &testBool };
        
Zefir_renderCheckbox(&checkboxData);
```

Input Float:
```
Zefir_InputFloatData iFData{
    // input float ID
    .m_uniqueId = ZEFIR_NEW_UID(),
    // text right next to the input float
    .m_label = "This is an input float",
    // float for the input float
    .m_value = &testFloat };
```

C preview and Zig tutorial soon!