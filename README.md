# RAYLIB WITH PYTHON
These are [Raylib](https://github.com/raysan5/raylib) bindings for Python, hand-rolled with the C API. Why? I suppose I just want to get more familiar with the internals of CPython interpreter. I've also had problems with Raylib bindings with Python in the past, so I want to design my own and have a nice way to program stuff reliably.

## Steps:
- `git clone` this project
- Obviously, you need `python` and `pip` installed.
- Working C toolchain, GCC or LLVM.
    - I use MSVC when im developing on my Windows machine. I am a masochist I geuss.
    - NOTE: CURRENTLY I HAVE NOT TESTED THIS ON DIFFERENT COMPILERS OR OSs. YOU WILL PROBABLY HAVE TO USE MSVC ON WINDOWS FOR THE BEST CHANCE AT GETTING IT TO WORK. IM VERY SORRY (MSVC *SUCKS*) THIS IS ON MY TODO LIST
- CMake. This project uses [scikit-build-core](https://github.com/scikit-build/scikit-build-core) to not only build the Python module, but also to compile the Raylib source code.
- do `pip install -e .` in the project directory and you are gucci. Run the tests or whatever to make sure everything works

## TODO:
REWRITE FREAKING EVERYTHING WITH `pybind11` ON LINUX WITH GCC/CLANG. THEN ENSURE IT WORKS ON MSVC ON WINDOWS!!