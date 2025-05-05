#include <Python.h>
#include <stdint.h>
#include <stdio.h>
#include "raylib.h"
#include "../raylib_w_py.h"

// RAYLIB Vector2
static PyMemberDef py_Vector2Members[] = {
    {"x", Py_T_FLOAT, offsetof(py_Vector2Struct, vec.x), 0, "x coordinate"},
    {"y", Py_T_FLOAT, offsetof(py_Vector2Struct, vec.y), 0, "y coordinate"},
    {NULL}
};

static int
py_Vector2Init(py_Vector2Struct* self, PyObject* args, PyObject* kwargs)
{
    static char *kwlist[] = {"x", "y", NULL};

    float x = 0.0, y = 0.0;
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ff", kwlist, &x, &y))
        return -1;

    self->vec.x = x;
    self->vec.y = y;

    return 0;
}

static PyObject*
py_Vector2Repr(PyObject* self) {
    py_Vector2Struct* vector = (py_Vector2Struct*)self;

    char* x_repr = PyOS_double_to_string(vector->vec.x, 'f', 6, 0, NULL);
    if (x_repr == NULL)
        return NULL;

    char* y_repr = PyOS_double_to_string(vector->vec.x, 'f', 6, 0, NULL);
    if (y_repr == NULL)
        return NULL;

    PyObject* repr = PyUnicode_FromFormat("Vector2(x=%s, y=%s)", x_repr, y_repr);
    PyMem_Free(x_repr);
    PyMem_Free(y_repr);
    return repr;
}

PyTypeObject py_Vector2 = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "raylib.Vector2",
    .tp_basicsize = sizeof(py_Vector2),
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_members = py_Vector2Members,
    .tp_init = (initproc)py_Vector2Init,
    .tp_new = PyType_GenericNew,
    .tp_repr = py_Vector2Repr
};

// RAYLIB Color
static PyMemberDef py_ColorMembers[] = {
    {"r", Py_T_BYTE, offsetof(py_ColorStruct, col.r), 0, "red component"},
    {"g", Py_T_BYTE, offsetof(py_ColorStruct, col.g), 0, "green component"},
    {"b", Py_T_BYTE, offsetof(py_ColorStruct, col.b), 0, "blue component"},
    {"a", Py_T_BYTE, offsetof(py_ColorStruct, col.a), 0, "alpha value"},
    {NULL}
};

static int
py_ColorInit(py_ColorStruct* self, PyObject* args, PyObject* kwargs)
{
    static char *kwlist[] = {"r", "g", "b", "a", "hex", NULL};

    unsigned char r=0, g=0, b=0, a=255;
    PyObject* hex = NULL;
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|iiiiO!", kwlist, &r, &g, &b, &a, &PyLong_Type, &hex))
        return -1;

    if (hex != NULL && hex != Py_None) {
        uint32_t rgba = (uint32_t)PyLong_AsUnsignedLong(hex);
        self->col.r = (rgba >> 24) & 0xFF;
        self->col.g = (rgba >> 16) & 0xFF;
        self->col.b = (rgba >> 8) & 0xFF;
        self->col.a = rgba & 0xFF;
    } else {
        self->col.r = r;
        self->col.g = g;
        self->col.b = b;
        self->col.a = a;
    }

    return 0;
}

static PyObject*
py_ColorRepr(py_ColorStruct* self) {
    return PyUnicode_FromFormat(
        "Color(r=%i, g=%i, b=%i, a=%i)", 
        self->col.r, 
        self->col.g, 
        self->col.b,
        self->col.a
    );
}

PyTypeObject py_Color = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "raylib.Color",
    .tp_basicsize = sizeof(py_Color),
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_members = py_ColorMembers,
    .tp_init = (initproc)py_ColorInit,
    .tp_new = PyType_GenericNew,
    .tp_repr = py_ColorRepr
};