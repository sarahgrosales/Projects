# Version 2 adds continous movement with arrow keys and only shows one rectangle

import pygame
from pygame.locals import *

pygame.init()

# Screen
screen = pygame.display.set_mode((640, 240))
pygame.display.set_caption("Move Rectangle")

# Colors
PINK = (255, 209, 220)
BLUE = (167, 199, 231)

# Rectangles
rect0 = pygame.Rect(50, 60, 200, 80)  # original rectangle / Rect(x, y, width, height)

# Clock (important for smooth motion)
clock = pygame.time.Clock()

running = True
while running:

    for event in pygame.event.get():    # collects user input events
        if event.type == QUIT:
            running = False

    keys = pygame.key.get_pressed()

    if keys [K_LEFT]:
        rect0.move_ip(-2, 0)     # move left at x - 5
    if keys [K_RIGHT]:
        rect0.move_ip(2, 0)      # move right at x +
    if keys [K_UP]:
        rect0.move_ip(0, -2)     # move up at y -
    if keys [K_DOWN]:
        rect0.move_ip(0, 2)      # move down at y +
    
    # Drawing
    screen.fill(PINK)                           # fills the screen with green color to clear previous frame  
    pygame.draw.rect(screen, BLUE, rect0, 10)    # moved

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
