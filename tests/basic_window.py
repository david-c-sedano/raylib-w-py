import raylib.rcore as rl
import raylib.rtext as rtxt

WIDTH, HEIGHT = 800, 450

rl.InitWindow(WIDTH, HEIGHT, "raylib [core] example - basic window - PYTHON EDITION")
while not rl.WindowShouldClose():
    rl.BeginDrawing()

    rl.ClearBackground(rl.Color(hex=0xFFFFFFFF))
    rtxt.DrawText("Congrats! You created your first window with Python!", 130, 200, 20, rl.Color(hex=0x000000FF))

    rl.EndDrawing()

rl.CloseWindow()