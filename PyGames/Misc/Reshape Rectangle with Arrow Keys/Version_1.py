import pygame
from pygame.locals import *

pygame.init()

# Screen
screen = pygame.display.set_mode((640, 240))
pygame.display.set_caption("Resize Rectangle")

# Colors
PINK = (255, 209, 220)
BLUE = (167, 199, 231)

# Rectangles
rect0 = pygame.Rect(220, 80, 200, 80)  # reference (original)
rect = rect0.copy()                    # resizable copy

# Key → size change (dw, dh)
size_map = {
    K_LEFT:  (-10, 0),   # shrink width
    K_RIGHT: (10, 0),    # grow width
    K_UP:    (0, -10),   # shrink height
    K_DOWN:  (0, 10)     # grow height
}

clock = pygame.time.Clock()
running = True

while running:
    for event in pygame.event.get():
        if event.type == QUIT:
            running = False

        elif event.type == KEYDOWN:    # If key is pressed
            if event.key in size_map:  # checks if key is valid and searches dictionary of allowed keys
                dw, dh = size_map[event.key]  # dw - change in width, dh - change in height
                # if size_map = K_RIGHT: (10, 0) -> dw = 10, dh = 0 → width increases by 10, height stays the same
                rect.inflate_ip(dw, dh)  # inflate - expand/shrink | _ip -> "in place" (modifies original)
                # Optional safety: keep minimum size (prevents rect from disappearing or inverting)
                rect.width = max(rect.width, 10)   # max (a, b) -> returns larger value
                rect.height = max(rect.height, 10) # forces width/height to be at least 10
                # without this, width/height could become zero or negative, causing issues with drawing and collision detection
    # Draw
    screen.fill(PINK)
    pygame.draw.rect(screen, BLUE, rect0, 1)  # original outline
    pygame.draw.rect(screen, BLUE, rect, 4)   # resized rectangle

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
