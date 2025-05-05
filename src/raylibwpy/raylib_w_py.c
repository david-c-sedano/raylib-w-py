#include <Python.h>
#include "raylib.h"
#include "raylib_w_py.h"

// test function
static PyObject* 
py_AddTwo(PyObject* self, PyObject* args)
{
    int x, y;
    if (!PyArg_ParseTuple(args, "ii", &x, &y)) {
        return NULL;
    }
    
    return PyLong_FromLong(x + y);
}

// Register Raylib Structs
static int
py_register_type(PyObject* module, PyTypeObject* type, const char* name)
{
    if (PyType_Ready(type) < 0)
        return -1;

    Py_INCREF(type);
    if (PyModule_AddObject(module, name, (PyObject*)type) < 0) {
        Py_DECREF(type);
        return -1;
    }

    return 0;
}

static PyMethodDef 
Methods[] = {
    {"ctest_AddTwo", py_AddTwo, METH_VARARGS, "Just a test function to ensure stuff works"},
    INCLUDE_RCORE,
    INCLUDE_RTEXT,
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef 
ModuleDef = {
    PyModuleDef_HEAD_INIT,
    "raylibwpy",
    NULL,
    -1,
    Methods
};

PyMODINIT_FUNC PyInit_raylibwpy(void) {
    PyObject* m = PyModule_Create(&ModuleDef);
    if (!m)
        return NULL;

    if (py_register_type(m, &py_Vector2, "Vector2") < 0) goto fail;
    if (py_register_type(m, &py_Color, "Color") < 0) goto fail;
        
    return m;

    fail:
        Py_DECREF(m);
        return NULL;
}