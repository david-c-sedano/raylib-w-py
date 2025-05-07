import raylib.rcore as rl

vector = rl.Vector2(1.5, 1.5)

print(vector.x)
print(vector.y) 
print(vector)

color = rl.Color(100, 231, 194, 8)
print(color)
hex_color = rl.Color(hex=0x87CEEBFF)
print(hex_color)


rectangle = rl.Rectangle(1, 2, 3, 4)
print(rectangle)
rectangle.x = rectangle.x + 10
print(rectangle)

camera = rl.Camera2D(
    target = rl.Vector2(20.0, 20.0),
    offset = rl.Vector2(10, 11),
    rotation = 0.0,
    zoom = 1.0
)

print(f"camera is {camera}")

camera.offset = rl.Vector2(12, 12)

print(f"camera is {camera} once")

camera.rotation = camera.rotation + 10
camera.zoom = camera.zoom + 10

camera.target = rl.Vector2(21, 20)
print(camera.target.x)

print(f"camera is {camera} twice")