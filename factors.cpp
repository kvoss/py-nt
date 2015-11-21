#include "Python.h"
#include "factorization.hpp"

static PyObject *
py_factor(PyObject *self, PyObject *args)
{
    UL n;

    // k -- unsigned long type
    if (!PyArg_ParseTuple(args, "k", &n))
        return NULL;

    PyObject *ret = PyList_New(0);
    Py_INCREF(ret);
    VU fs = factor(n);
    for (VU::iterator it = fs.begin(); it < fs.end(); it++) {
        PyList_Append(ret, Py_BuildValue("k", *it));
    }
    return ret;
}

static PyMethodDef FactorsMethods[] = {
    {"factor", py_factor, METH_VARARGS, "Factorization by trial division"},
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC
initfactors(void)
{
    (void) Py_InitModule("factors", FactorsMethods);
}

