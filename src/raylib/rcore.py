import raylibwpy as _rl

RCORE_FUNCS = {
    "InitWindow",
    "WindowShouldClose",
    "BeginDrawing",
    "EndDrawing",
    "ClearBackground",
    "CloseWindow"
}

RAYLIB_STRUCTS = {
    "Vector2",
    "Color"
}

LIGHTGRAY   = _rl.Color(200, 200, 200, 255)
GRAY        = _rl.Color(130, 130, 130, 255)
DARKGRAY    = _rl.Color(80, 80, 80, 255)
YELLOW      = _rl.Color(253, 249, 0, 255)
GOLD        = _rl.Color(255, 203, 0, 255)
ORANGE      = _rl.Color(255, 161, 0, 255)
PINK        = _rl.Color(255, 109, 194, 255)
RED         = _rl.Color(230, 41, 55, 255)
MAROON      = _rl.Color(190, 33, 55, 255)
GREEN       = _rl.Color(0, 228, 48, 255)
LIME        = _rl.Color(0, 158, 47, 255)
DARKGREEN   = _rl.Color(0, 117, 44, 255)
SKYBLUE     = _rl.Color(102, 191, 255, 255)
BLUE        = _rl.Color(0, 121, 241, 255)
DARKBLUE    = _rl.Color(0, 82, 172, 255)
PURPLE      = _rl.Color(200, 122, 255, 255)
VIOLET      = _rl.Color(135, 60, 190, 255)
DARKPURPLE  = _rl.Color(112, 31, 126, 255)
BEIGE       = _rl.Color(211, 176, 131, 255)
BROWN       = _rl.Color(127, 106, 79, 255)
DARKBROWN   = _rl.Color(76, 63, 47, 255)
WHITE       = _rl.Color(255, 255, 255, 255)
BLACK       = _rl.Color(0, 0, 0, 255)
BLANK       = _rl.Color(0, 0, 0, 0)
MAGENTA     = _rl.Color(255, 0, 255, 255)
RAYWHITE    = _rl.Color(245, 245, 245, 255)

__all__ = [name for name in dir(_rl) if name in RCORE_FUNCS or name in RAYLIB_STRUCTS]
globals().update({name: getattr(_rl, name) for name in __all__})
__all__ += [
    "LIGHTGRAY", "GRAY", "DARKGRAY", "YELLOW", "GOLD", "ORANGE", "PINK", "RED", "MAROON",
    "GREEN", "LIME", "DARKGREEN", "SKYBLUE", "BLUE", "DARKBLUE", "PURPLE", "VIOLET",
    "DARKPURPLE", "BEIGE", "BROWN", "DARKBROWN", "WHITE", "BLACK", "BLANK", "MAGENTA", "RAYWHITE"
]