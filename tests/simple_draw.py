import raylib.rcore as rl
import raylib.rshapes as rs

WIDTH, HEIGHT = 800, 450

rects = [rl.Rectangle(i*50, 0, 50, 50) for i in range(1, 100)]

rl.InitWindow(WIDTH, HEIGHT, "raylib [core] example - basic window - PYTHON EDITION")
while not rl.WindowShouldClose():
    rl.BeginDrawing()


    rl.ClearBackground(rl.RAYWHITE)

    for rect in rects:
        rs.DrawRectangleRec(rect, rl.BLUE)

    rs.DrawRectangle(200, 100, 50, 50, rl.BLUE)
    rs.DrawRectangleRec(rl.Rectangle(50, 50, 100, 100), rl.GREEN)
    rs.DrawRectangleLines( 10, 10, 250, 113, rl.BLUE)
    rs.DrawLine(0, 0, WIDTH, HEIGHT, rl.RED)

    rl.EndDrawing()

rl.CloseWindow()