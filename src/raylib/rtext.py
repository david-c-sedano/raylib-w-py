import raylibwpy as _rl

RTEXT_FUNCS = {
    "DrawText"
}

__all__ = [name for name in dir(_rl) if name in RTEXT_FUNCS]
globals().update({name: getattr(_rl, name) for name in __all__})