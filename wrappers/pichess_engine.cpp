#include <Python.h>

static PyMethodDef pichess_engine_methods[] = {
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef pichess_engine_module = {
  PyModuleDef_HEAD_INIT,
  "pichess_engine",
  NULL,
  -1,
  pichess_engine_methods
};

PyMODINIT_FUNC_PyInit_pichess_engine (void) {
  return PyModule_Create(&pichess_engine_module);
}
