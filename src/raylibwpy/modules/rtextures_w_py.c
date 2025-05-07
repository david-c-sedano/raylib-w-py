#include <Python.h>
#include "raylib.h"
#include "../raylib_w_py.h"

PyObject* py_Fade(PyObject* self, PyObject* args) {
    py_ColorStruct* color;
    float alpha = 0.0;
    if (!PyArg_ParseTuple(args, "O!f", &py_Color, &color, &alpha))
        return NULL;

    Color faded_color = Fade(color->col, alpha);

    py_ColorStruct* result = PyObject_New(py_ColorStruct, &py_Color);
    if (!result)
        return PyErr_NoMemory();

    result->col = faded_color;
    return (PyObject*)result;
}