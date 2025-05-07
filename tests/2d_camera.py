import raylib.rcore as rl
import raylib.rshapes as rs
import raylib.rtextures as rtex
import raylib.rtext as rtxt
import math

MAX_BUILDINGS = 100
WIDTH, HEIGHT = 800, 450

rl.InitWindow(WIDTH, HEIGHT, "raylib [core] example - 2d camera - PYTHON EDITION")
player = rl.Rectangle(400, 280, 40, 40)
buildings = [rl.Rectangle(0, 0, 0, 0)] * MAX_BUILDINGS
buildColors = [rl.Color(0, 0, 0, 0)] * MAX_BUILDINGS

spacing = 0

for i in range(MAX_BUILDINGS):
    x = -6000.0 + spacing
    width = rl.GetRandomValue(50, 200)
    height = rl.GetRandomValue(100, 800)
    y = HEIGHT - 130.0 - height

    buildings[i] = rl.Rectangle(x, y, width, height)
    spacing += int(buildings[i].width)

    buildColors[i] = rl.Color(
        rl.GetRandomValue(200, 240),
        rl.GetRandomValue(200, 240),
        rl.GetRandomValue(200, 240),
        255
    )

camera = rl.Camera2D(
    target = rl.Vector2(player.x + 20.0, player.y + 20.0),
    offset = rl.Vector2( WIDTH/2.0, HEIGHT/2.0),
    rotation = 0.0,
    zoom = 1.0
)

rl.SetTargetFPS(60)

while not rl.WindowShouldClose():
    if rl.IsKeyDown(rl.KEY_RIGHT): 
        player.x += 2
    elif rl.IsKeyDown(263):
        player.x -= 2

    camera.target = rl.Vector2(player.x + 20, player.y + 20)

    if rl.IsKeyDown(rl.KEY_A):
        camera.rotation -= 1
    elif rl.IsKeyDown(rl.KEY_S): 
        camera.rotation += 1

    if camera.rotation > 40: 
        camera.rotation = 40
    elif camera.rotation < -40: 
        camera.rotation = -40

    camera.zoom = math.exp(math.log(camera.zoom) + rl.GetMouseWheelMove() * 0.1)

    if camera.zoom > 3.0: 
        camera.zoom = 3.0
    elif camera.zoom < 0.1:
        camera.zoom = 0.1

    if rl.IsKeyPressed(rl.KEY_R):
        camera.zoom = 1.0
        camera.rotation = 0.0

    rl.BeginDrawing()
    rl.ClearBackground(rl.RAYWHITE)

    rl.BeginMode2D(camera)

    rs.DrawRectangle(-6000, 320, 13000, 8000, rl.DARKGRAY)
    for building, buildColor in zip(buildings, buildColors):
        rs.DrawRectangleRec(building, buildColor)

    rs.DrawRectangleRec(player, rl.RED)

    # I kid you not, if you don't cast the floats - camera.target.x or camera.target.y - IT WILL SEGFAULT!!!
    rs.DrawLine(int(camera.target.x), -HEIGHT * 10, int(camera.target.x), HEIGHT * 10, rl.GREEN)
    rs.DrawLine(-WIDTH * 10, int(camera.target.y), WIDTH * 10, int(camera.target.y), rl.GREEN)

    rl.EndMode2D()

    rtxt.DrawText("SCREEN AREA", 640, 10, 20, rl.RED)

    rs.DrawRectangle(0, 0, WIDTH, 5, rl.RED)
    rs.DrawRectangle(0, 5, 5, HEIGHT - 10, rl.RED)
    rs.DrawRectangle(WIDTH - 5, 5, 5, HEIGHT - 10, rl.RED)
    rs.DrawRectangle(0, HEIGHT - 5, WIDTH, 5, rl.RED)

    rs.DrawRectangle(10, 10, 250, 113, rtex.Fade(rl.SKYBLUE, 0.5))
    rs.DrawRectangleLines( 10, 10, 250, 113, rl.BLUE)

    rtxt.DrawText("Free 2d camera controls:", 20, 20, 10, rl.BLACK)
    rtxt.DrawText("- Right/Left to move Offset", 40, 40, 10, rl.DARKGRAY)
    rtxt.DrawText("- Mouse Wheel to Zoom in-out", 40, 60, 10, rl.DARKGRAY)
    rtxt.DrawText("- A / S to Rotate", 40, 80, 10, rl.DARKGRAY)
    rtxt.DrawText("- R to reset Zoom and Rotation", 40, 100, 10, rl.DARKGRAY)

    rl.EndDrawing()

rl.CloseWindow()