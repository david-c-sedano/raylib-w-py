# RAYLIB WITH PYTHON
These are [Raylib](https://github.com/raysan5/raylib) bindings for Python, hand-rolled with the C API. Why? I suppose I just want to get more familiar with the internals of CPython interpreter. I've also had problems with Raylib bindings with Python in the past, so I want to design my own and have a nice way to program stuff reliably.

## Steps:
- `git clone` this project
- Obviously, you need `python` and `pip` installed.
- Working C toolchain, GCC or LLVM.
    - I use MSVC when im developing on my Windows machine. I am a masochist I geuss.
- CMake. This project uses [scikit-build-core](https://github.com/scikit-build/scikit-build-core) to not only build the Python module, but also to compile the Raylib source code.
- do `pip install -e .` in the project directory and you are gucci. Run the tests or whatever to make sure everything works

## TODO:
Currently, a basic Window works and is rather ergonomic. Next:
- add the color constants 
    - raywhite....
- Handle all the different Raylib Modules
    - rcore
        - drawing related funcs
        - input functions, keyboard mouse, the enums for that stuff...
        - camera controls
    - rshapes
        - DrawPixel, DrawLine, DrawCircle, DrawEllipse, DrawRing, DrawRectangle, DrawTriangle, DrawPoly
        - DrawSpline, whatever bezier curve nonsense...
        - GetSplinePoint
        - CheckCollision
    - rtextures
        - LoadImage, UnloadImage, 
        - ImageDraw
        - LoadTexture, DrawTexture
    - rtext
        - LoadFont, UnloadFont, DrawFPS
        - MeasureText, SetTextLineSpacing, Glyphs...
    - rmodels
        - Draw 3d shape funcs...
        - DrawModel,
    - raudio
        - InitAudioDevice, CloseAudioDevice
        - MusicStream Func's
        - LoadSound, UnloadSound, PlaySound
    - back to rcore
        - shaders...

After this point, the rest is just annoying and tedious programming grunt work. Hopefully I get so good at it, I can just play the Nintendo 3DS System OST (internet settings and eShop main theme go so hard) and finish them slowly but with great ease. It should be therapeutic. 