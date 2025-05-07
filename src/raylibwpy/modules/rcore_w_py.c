#include <Python.h>
#include "raylib.h"
#include "../raylib_w_py.h"

PyObject* py_InitWindow(PyObject* self, PyObject* args) {
    int width, height;
    const char* title;
    if (!PyArg_ParseTuple(args, "iis", &width, &height, &title))
        return NULL;
    InitWindow(width, height, title);
    Py_RETURN_NONE;
}

PyObject* py_WindowShouldClose(PyObject* self, PyObject* args) {
    return PyBool_FromLong(WindowShouldClose());
}

PyObject* py_BeginDrawing(PyObject* self, PyObject* args) {
    BeginDrawing();
    Py_RETURN_NONE;
}

PyObject* py_EndDrawing(PyObject* self, PyObject* args) {
    EndDrawing();
    Py_RETURN_NONE;
}

PyObject* py_ClearBackground(PyObject* self, PyObject* args) {
    py_ColorStruct* color;

    if (!PyArg_ParseTuple(args, "O!", &py_Color, &color))
        return NULL;

    ClearBackground(color->col);
    Py_RETURN_NONE;
}

PyObject* py_CloseWindow(PyObject* self, PyObject* args) {
    CloseWindow();
    Py_RETURN_NONE;
}

PyObject* py_SetTargetFPS(PyObject* self, PyObject* args) {
    int fps;

    if (!PyArg_ParseTuple(args, "i", &fps))
        return NULL;

    SetTargetFPS(fps);
    Py_RETURN_NONE;
}

/* CAMERA/RENDERING RELATED FUNCTIONS */
PyObject* py_BeginMode2D(PyObject* self, PyObject* args) {
    py_Camera2DStruct* camera;    

    if (!PyArg_ParseTuple(args, "O!", &py_Camera2D, &camera))
        return NULL;

    PY_CAM2D_TO_CSTRUCT(camera, c_camera);
    BeginMode2D(c_camera);
    Py_RETURN_NONE;
}

PyObject* py_EndMode2D(PyObject* self, PyObject* args) {
    EndMode2D();
    Py_RETURN_NONE;
}

/* INPUT RELATED FUNCTIONS: Keyboard */
PyObject* py_IsKeyDown(PyObject* self, PyObject* args) {
    int key;

    if (!PyArg_ParseTuple(args, "i", &key))
        return NULL;

    return PyBool_FromLong(IsKeyDown(key));
}

PyObject* py_IsKeyPressed(PyObject* self, PyObject* args) {
    int key;

    if (!PyArg_ParseTuple(args, "i", &key))
        return NULL;

    return PyBool_FromLong(IsKeyPressed(key));
}

/* INPUT RELATED FUNCTIONS: Mouse */
PyObject* py_GetMouseWheelMove(PyObject* self, PyObject* args) {
    return PyFloat_FromDouble((double)GetMouseWheelMove());
}

/* RANDOM VALUE GENERATION FUNCTIONS */
PyObject* py_GetRandomValue(PyObject* self, PyObject* args) {
    int min, max;

    if (!PyArg_ParseTuple(args, "ii", &min, &max))
        return NULL;

    return PyLong_FromLong(GetRandomValue(min, max));
}
