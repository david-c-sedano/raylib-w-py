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