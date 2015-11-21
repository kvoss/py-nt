#include <vector>
#include <cmath>

#include "Python.h"

typedef unsigned long UL;
typedef std::vector<UL> VU;

VU
factor(UL n)
{
    VU factors;

    UL limit = sqrtl(n);
    for (UL x = 2;; ++x) {
        if (x > limit) break;

        while (n % x == 0) {
            n /= x;
            limit = sqrtl(n);
            factors.push_back(x);
        }
    }
    if (n > 1)
        factors.push_back(n);

    return factors;
}

static PyObject *
py_factor(PyObject *self, PyObject *args)
{
    unsigned long n;

    // k -- unsigned long type
    // K -- unsigned long long type
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

// static struct PyModuleDef factorsmodule = {
//     PyModuleDef_HEAD_INIT,
//     "factors", // name of a module
//     "A module for factoring numbers", // a docstring
//     -1, // Size of per interpreter state or -1
//     FactorsMethods // method table
// };

// PyMODINIT_FUNC
// PyInit_factors(void) {
//     return PyModule_Create(&factorsmodule);
// }

PyMODINIT_FUNC
initfactors(void) {
    (void) Py_InitModule("factors", FactorsMethods);
}

