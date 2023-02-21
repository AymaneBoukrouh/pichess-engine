from distutils.core import setup, Extension
import glob

pichess_engine_module = Extension(
    'pichess_engine',
    sources = glob.glob('src/*.cpp') + glob.glob('wrapper/*.cpp'),
    include_dirs = ['include']
)

setup(
    name = 'pichess_engine',
    version = '1.0',
    description = 'A chess engine written in C++ for use with Python',
    ext_modules = [pichess_engine_module]
)
