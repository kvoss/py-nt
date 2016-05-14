#include "Python.h"
#include "factorization.hpp"

static PyObject *
py_factor(PyObject *self, PyObject *args)
{
    UL n;

    // k -- unsigned long type
    if (!PyArg_ParseTuple(args, "k", &n))
        return NULL;
    VUL fs = factor(n);

    PyObject *ret = PyList_New(fs.size());
    if (NULL == ret)
        return NULL;

    PyObject *val;
    Py_ssize_t idx = 0;
    for (VUL::iterator it = fs.begin(); it < fs.end(); ++it, ++idx) {
        val = Py_BuildValue("k", *it);
        PyList_SetItem(ret, idx, val);
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

