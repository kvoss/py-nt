from distutils.core import setup, Extension

setup(name='factors',
      ext_modules=[Extension('factors', ['factors.cpp', 'factorization.cpp'])]
)

