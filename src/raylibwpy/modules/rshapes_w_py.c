#include <Python.h>
#include "raylib.h"
#include "../raylib_w_py.h"

PyObject* py_DrawLine(PyObject* self, PyObject* args) {
    int startPosX, startPosY, endPosX, endPosY;
    py_ColorStruct* color;

    if (!PyArg_ParseTuple(
            args, 
            "iiiiO!",
            &startPosX, 
            &startPosY, 
            &endPosX, 
            &endPosY, 
            &py_Color, &color))
        return NULL;
    
    DrawLine(startPosX, startPosY, endPosX, endPosY, color->col);
    Py_RETURN_NONE;
}

PyObject* py_DrawRectangle(PyObject* self, PyObject* args) {
    int posX, posY, width, height;
    py_ColorStruct* color;

    if (!PyArg_ParseTuple(
            args, 
            "iiiiO!",
            &posX, 
            &posY, 
            &width, 
            &height, 
            &py_Color, &color))
        return NULL;
    
    DrawRectangle(posX, posY, width, height, color->col);
    Py_RETURN_NONE;
}

PyObject* py_DrawRectangleRec(PyObject* self, PyObject* args) {
    py_RectangleStruct* rectangle;
    py_ColorStruct* color;

    if (!PyArg_ParseTuple(args, "O!O!", &py_Rectangle, &rectangle, &py_Color, &color))
        return NULL;

    DrawRectangleRec(rectangle->rect, color->col);
    Py_RETURN_NONE;
}

PyObject* py_DrawRectangleLines(PyObject* self, PyObject* args) {
    int posX, posY, width, height;
    py_ColorStruct* color;

    if (!PyArg_ParseTuple(
            args, 
            "iiiiO!",
            &posX, 
            &posY, 
            &width, 
            &height, 
            &py_Color, &color))
        return NULL;
    
    DrawRectangleLines(posX, posY, width, height, color->col);
    Py_RETURN_NONE;
}