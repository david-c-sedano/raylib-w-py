import raylibwpy as _c

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

__all__ = [name for name in dir(_c) if name in RCORE_FUNCS or name in RAYLIB_STRUCTS]
globals().update({name: getattr(_c, name) for name in __all__})