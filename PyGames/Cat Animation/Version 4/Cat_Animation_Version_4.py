# Version 4 allows user to resize image using arrow keys (ex: shrink, expand, etc.)


import pygame
from pygame.locals import *

pygame.init()

# Screen
screen = pygame.display.set_mode((640, 240))
pygame.display.set_caption("Resize Cat")

# Colors
PINK = (255, 209, 220)

# Original image
cat = pygame.image.load('Assets/cat.png')

# Starting size
width, height = 100, 100
cat_rect = pygame.Rect(0, 0, width, height)

# Clock + running
clock = pygame.time.Clock()
running = True

while running:

    # --- Events ---
    for event in pygame.event.get():
        if event.type == QUIT:
            running = False

    # --- Input ---
    keys = pygame.key.get_pressed()

    if keys[K_LEFT]:
        width += 2
    if keys[K_RIGHT]:
        width -= 2
    if keys[K_UP]:
        height += 2
    if keys[K_DOWN]:
        height -= 2

    # --- Prevent invalid sizes ---
    width = max(width, 10)
    height = max(height, 10)

    # --- Resize image ---
    resized_cat = pygame.transform.scale(cat, (width, height))

    # --- Update rect ---
    cat_rect.size = (width, height)

    # --- Draw ---
    screen.fill(PINK)
    screen.blit(resized_cat, cat_rect)

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
