#ifndef RLTOPY
#define RLTOPY

#define DEFINE_PY_FUNC_W_ARGS(name) PyObject* py_##name (PyObject* self, PyObject* args)
#define INCLUDE_PY_FUNC_W_ARGS(name, docstring) {#name, py_##name, METH_VARARGS, docstring}

/* RAYLIB STRUCT DEFINITIONS */
typedef struct {
    PyObject_HEAD
    Vector2 vec;
} py_Vector2Struct;
extern PyTypeObject py_Vector2;

typedef struct {
    PyObject_HEAD
    Color col;
} py_ColorStruct;
extern PyTypeObject py_Color;

typedef struct {
    PyObject_HEAD
    Rectangle rect;
} py_RectangleStruct;
extern PyTypeObject py_Rectangle;

typedef struct {
    PyObject_HEAD
    py_Vector2Struct* offset;
    py_Vector2Struct* target;
    float rotation;
    float zoom;
} py_Camera2DStruct;
#define PY_CAM2D_TO_CSTRUCT(py_camera, result)\
    Camera2D result = {\
        .offset = py_camera->offset->vec,\
        .target = py_camera->target->vec,\
        .rotation = py_camera->rotation,\
        .zoom = py_camera->zoom\
    }
extern PyTypeObject py_Camera2D;

/* RAYLIB RCORE FUNCTION DEFINITIONS */
DEFINE_PY_FUNC_W_ARGS(InitWindow);
DEFINE_PY_FUNC_W_ARGS(WindowShouldClose);
DEFINE_PY_FUNC_W_ARGS(BeginDrawing);
DEFINE_PY_FUNC_W_ARGS(EndDrawing);
DEFINE_PY_FUNC_W_ARGS(ClearBackground);
DEFINE_PY_FUNC_W_ARGS(CloseWindow);
DEFINE_PY_FUNC_W_ARGS(SetTargetFPS);
DEFINE_PY_FUNC_W_ARGS(BeginMode2D);
DEFINE_PY_FUNC_W_ARGS(EndMode2D);
DEFINE_PY_FUNC_W_ARGS(IsKeyDown);
DEFINE_PY_FUNC_W_ARGS(IsKeyPressed);
DEFINE_PY_FUNC_W_ARGS(GetMouseWheelMove);
DEFINE_PY_FUNC_W_ARGS(GetRandomValue);

/* RAYLIB RSHAPES FUNCTION DEFINITIONS */
DEFINE_PY_FUNC_W_ARGS(DrawLine);
DEFINE_PY_FUNC_W_ARGS(DrawRectangle);
DEFINE_PY_FUNC_W_ARGS(DrawRectangleRec);
DEFINE_PY_FUNC_W_ARGS(DrawRectangleLines);

/* RAYLIB RTEXTURE FUNCTION DEFINITIONS */
DEFINE_PY_FUNC_W_ARGS(Fade);

/* RAYLIB RTEXT FUNCTION DEFINITIONS */
DEFINE_PY_FUNC_W_ARGS(DrawText);

/* MACROS TO HELP ADDING ALL THE FUNCTIONS TO THE GLOBAL MODULES ARRAY */
#define INCLUDE_RCORE\
    INCLUDE_PY_FUNC_W_ARGS(InitWindow, "Initialize window and OpenGL context"),\
    INCLUDE_PY_FUNC_W_ARGS(WindowShouldClose, "Check if application should close (KEY_ESCAPE pressed or windows close icon clicked)"),\
    INCLUDE_PY_FUNC_W_ARGS(BeginDrawing, "Setup canvas (framebuffer) to start drawing"),\
    INCLUDE_PY_FUNC_W_ARGS(EndDrawing, "End canvas drawing and swap buffers (double buffering)"),\
    INCLUDE_PY_FUNC_W_ARGS(ClearBackground, "Set background color (framebuffer clear color)"),\
    INCLUDE_PY_FUNC_W_ARGS(CloseWindow, "Close window and unload OpenGL context"),\
    INCLUDE_PY_FUNC_W_ARGS(SetTargetFPS, "Set target FPS (maximum)"),\
    INCLUDE_PY_FUNC_W_ARGS(BeginMode2D, "Begin 2D mode with custom camera (2D)"),\
    INCLUDE_PY_FUNC_W_ARGS(EndMode2D, "Ends 2D mode with custom camera"),\
    INCLUDE_PY_FUNC_W_ARGS(IsKeyDown, "Check if a key is being pressed"),\
    INCLUDE_PY_FUNC_W_ARGS(IsKeyPressed, "Check if a key has been released once"),\
    INCLUDE_PY_FUNC_W_ARGS(GetMouseWheelMove, "Get mouse wheel movement for X or Y, whichever is larger"),\
    INCLUDE_PY_FUNC_W_ARGS(GetRandomValue, "Get a random value between min and max (both included)")

#define INCLUDE_RSHAPES\
    INCLUDE_PY_FUNC_W_ARGS(DrawLine, "Draw a line"),\
    INCLUDE_PY_FUNC_W_ARGS(DrawRectangle, "Draw a color-filled rectangle"),\
    INCLUDE_PY_FUNC_W_ARGS(DrawRectangleRec, "Draw a color-filled rectangle (with Rectangle struct)"),\
    INCLUDE_PY_FUNC_W_ARGS(DrawRectangleLines, "Draw rectangle outline")

#define INCLUDE_RTEXTURES\
    INCLUDE_PY_FUNC_W_ARGS(Fade, "Get color with alpha applied, alpha goes from 0.0 to 1.0")

#define INCLUDE_RTEXT\
    INCLUDE_PY_FUNC_W_ARGS(DrawText, "Draw text (using default font)")

#endif