from distutils.core import setup, Extension

setup(name='factors',
      ext_modules=[
          Extension('factors',
                    sources = ['factors.cpp'],
                    include_dirs = ['/usr/include/python2.7'],
                    )
          ]
)

