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

/* RAYLIB RCORE FUNCTION DEFINITIONS */
DEFINE_PY_FUNC_W_ARGS(InitWindow);
DEFINE_PY_FUNC_W_ARGS(WindowShouldClose);
DEFINE_PY_FUNC_W_ARGS(BeginDrawing);
DEFINE_PY_FUNC_W_ARGS(EndDrawing);
DEFINE_PY_FUNC_W_ARGS(ClearBackground);
DEFINE_PY_FUNC_W_ARGS(CloseWindow);

/* RAYLIB RTEXT FUNCTION DEFINITIONS */
DEFINE_PY_FUNC_W_ARGS(DrawText);

/* MACROS TO HELP ADDING ALL THE FUNCTIONS TO THE GLOBAL MODULES ARRAY */
#define INCLUDE_RCORE\
    INCLUDE_PY_FUNC_W_ARGS(InitWindow, "Initialize window and OpenGL context"),\
    INCLUDE_PY_FUNC_W_ARGS(WindowShouldClose, "Check if application should close (KEY_ESCAPE pressed or windows close icon clicked)"),\
    INCLUDE_PY_FUNC_W_ARGS(BeginDrawing, "Setup canvas (framebuffer) to start drawing"),\
    INCLUDE_PY_FUNC_W_ARGS(EndDrawing, "End canvas drawing and swap buffers (double buffering)"),\
    INCLUDE_PY_FUNC_W_ARGS(ClearBackground, "Set background color (framebuffer clear color)"),\
    INCLUDE_PY_FUNC_W_ARGS(CloseWindow, "Close window and unload OpenGL context")

#define INCLUDE_RTEXT\
    INCLUDE_PY_FUNC_W_ARGS(DrawText, "Draw text (using default font)")

#endif