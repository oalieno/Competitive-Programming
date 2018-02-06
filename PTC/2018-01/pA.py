import math
import ctypes

T = int(input().strip())

for _ in range(T):
    ai = list(map(int, input().strip().split()))
    up = ai[-1]
    down = 1
    for a in ai[-2::-1]:
        up, down = down, up
        up += a * down
        G = math.gcd(up, down)
        up //= G
        down //= G
    print(ctypes.c_long(up).value, ctypes.c_long(down).value)
