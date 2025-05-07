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

char* 
Vector2_AsString(Vector2 vec) {
    char* x_repr = PyOS_double_to_string(vec.x, 'f', 6, 0, NULL);
    if (x_repr == NULL)
        return NULL;

    char* y_repr = PyOS_double_to_string(vec.y, 'f', 6, 0, NULL);
    if (y_repr == NULL) {
        PyMem_Free(x_repr);
        return NULL;
    }

    int len = PyOS_snprintf(NULL, 0, "Vector2(x=%s, y=%s)", x_repr, y_repr);
    if (len < 0) {
        PyMem_Free(x_repr);
        PyMem_Free(y_repr);
        return NULL;
    }

    char* buf = PyMem_Malloc(len + 1);
    if (buf == NULL) {
        PyMem_Free(x_repr);
        PyMem_Free(y_repr);
        return NULL;
    }

    PyOS_snprintf(buf, len + 1, "Vector2(x=%s, y=%s)", x_repr, y_repr);

    PyMem_Free(x_repr);
    PyMem_Free(y_repr);

    return buf;
}

static PyObject*
py_Vector2Repr(py_Vector2Struct* self) {
    char* repr_str = Vector2_AsString(self->vec);
    PyObject* repr = PyUnicode_FromFormat(repr_str);
    PyMem_Free(repr_str);
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

/* RAYLIB RECTANGLE */
static PyMemberDef py_RectangleMembers[] = {
    {"x", Py_T_FLOAT, offsetof(py_RectangleStruct, rect.x), 0, "x coordinate, left corner"},
    {"y", Py_T_FLOAT, offsetof(py_RectangleStruct, rect.y), 0, "y coordinate, top corner"},
    {"width", Py_T_FLOAT, offsetof(py_RectangleStruct, rect.width), 0, "rectangle width"},
    {"height", Py_T_FLOAT, offsetof(py_RectangleStruct, rect.height), 0, "rectangle height"},
    {NULL}
};

static int
py_RectangleInit(py_RectangleStruct* self, PyObject* args, PyObject* kwargs)
{
    static char *kwlist[] = {"x", "y", "width", "height", NULL};

    float x = 0.0, y = 0.0, width = 0.0, height = 0.0;
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ffff", kwlist, &x, &y, &width, &height))
        return -1;

    self->rect.x = x;
    self->rect.y = y;
    self->rect.width = width;
    self->rect.height = height;

    return 0;
}

static PyObject*
py_RectangleRepr(py_RectangleStruct* self) {
    char* x_repr = PyOS_double_to_string(self->rect.x, 'f', 6, 0, NULL);
    if (x_repr == NULL)
        return NULL;

    char* y_repr = PyOS_double_to_string(self->rect.y, 'f', 6, 0, NULL);
    if (y_repr == NULL)
        return NULL;

    char* width_repr = PyOS_double_to_string(self->rect.width, 'f', 6, 0, NULL);
    if (width_repr == NULL)
        return NULL;

    char* height_repr = PyOS_double_to_string(self->rect.height, 'f', 6, 0, NULL);
    if (height_repr == NULL)
        return NULL;

    PyObject* repr = PyUnicode_FromFormat(
        "Rectangle(x=%s, y=%s, width=%s, height=%s)", 
        x_repr, y_repr, 
        width_repr, height_repr
    );

    PyMem_Free(x_repr);
    PyMem_Free(y_repr);
    PyMem_Free(width_repr);
    PyMem_Free(height_repr);

    return repr;
}

PyTypeObject py_Rectangle = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "raylib.Rectangle",
    .tp_basicsize = sizeof(py_Rectangle),
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_members = py_RectangleMembers,
    .tp_init = (initproc)py_RectangleInit,
    .tp_new = PyType_GenericNew,
    .tp_repr = py_RectangleRepr
};

/* RAYLIB CAMERA2D */
static PyMemberDef py_Camera2DMembers[] = {
    {"offset", Py_T_OBJECT_EX, offsetof(py_Camera2DStruct, offset), 0, "Camera offset (displacement from target)"},
    {"target", Py_T_OBJECT_EX, offsetof(py_Camera2DStruct, target), 0, "Camera target (rotation and zoom origin)"},
    {"rotation", Py_T_FLOAT, offsetof(py_Camera2DStruct, rotation), 0, "Camera rotation in degrees"},
    {"zoom", Py_T_FLOAT, offsetof(py_Camera2DStruct, zoom), 0, "Camera zoom (scaling), should be 1.0f by default"},
    {NULL}
};

static int
py_Camera2DInit(py_Camera2DStruct* self, PyObject* args, PyObject* kwargs)
{
    static char *kwlist[] = {"offset", "target", "rotation", "zoom", NULL};

    py_Vector2Struct* offset;
    py_Vector2Struct* target;
    float rotation = 0.0, zoom = 0.0;
    if (!PyArg_ParseTupleAndKeywords(
            args, kwargs, 
            "O!O!ff", 
            kwlist,
            &py_Vector2, 
            &offset, 
            &py_Vector2, 
            &target,
            &rotation, 
            &zoom))
        return -1;

    self->offset = offset;
    self->target = target;
    self->rotation = rotation;
    self->zoom = zoom;

    return 0;
}

static PyObject*
py_Camera2DRepr(py_Camera2DStruct* self) {
    char* offset_repr = Vector2_AsString(self->offset->vec);
    char* target_repr = Vector2_AsString(self->target->vec);

    char* rotation_repr = PyOS_double_to_string(self->rotation, 'f', 6, 0, NULL);
    if (rotation_repr == NULL)
        return NULL;

    char* zoom_repr = PyOS_double_to_string(self->zoom, 'f', 6, 0, NULL);
    if (zoom_repr == NULL)
        return NULL;

    PyObject* repr = PyUnicode_FromFormat(
        "Camera2D(offset=%s, target=%s, rotation=%s, zoom=%s)", 
        offset_repr, target_repr, 
        rotation_repr, zoom_repr
    );
   
    PyMem_Free(offset_repr);
    PyMem_Free(target_repr);
    PyMem_Free(rotation_repr);
    PyMem_Free(zoom_repr);

    return repr;
}

PyTypeObject py_Camera2D = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "raylib.Camera2D",
    .tp_basicsize = sizeof(py_Camera2D),
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_members = py_Camera2DMembers,
    .tp_init = (initproc)py_Camera2DInit,
    .tp_new = PyType_GenericNew,
    .tp_repr = py_Camera2DRepr,
};