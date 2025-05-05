#include <Python.h>
#include "raylib.h"
#include "../raylib_w_py.h"

PyObject* py_DrawText(PyObject* self, PyObject* args) {
    const char* text;
    int x, y, size;
    py_ColorStruct* color;
    if (!PyArg_ParseTuple(args, "siiiO!", &text, &x, &y, &size, &py_Color, &color))
        return NULL;

    DrawText(text, x, y, size, color->col);
    Py_RETURN_NONE;
}