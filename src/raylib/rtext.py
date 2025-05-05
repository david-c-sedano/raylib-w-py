import raylibwpy as _c

RTEXT_FUNCS = {
    "DrawText"
}

__all__ = [name for name in dir(_c) if name in RTEXT_FUNCS]
globals().update({name: getattr(_c, name) for name in __all__})