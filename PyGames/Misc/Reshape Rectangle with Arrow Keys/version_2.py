# Version 2 allows rectangle to be reshaped continously with arrow keys being pressed down + removes original rect

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

# Clock
clock = pygame.time.Clock()

running = True
while running:

    for event in pygame.event.get():    # collects user input events
        if event.type == QUIT:
            running = False

    keys = pygame.key.get_pressed()

    if keys [K_LEFT]:
        rect0.inflate_ip(-10, 0)      # move left at x - 5
    if keys [K_RIGHT]:
        rect0.inflate_ip(10, 0)      # move right at x +
    if keys [K_UP]:
        rect0.inflate_ip(0, -10)     # move up at y -
    if keys [K_DOWN]:
        rect0.inflate_ip(0, 10)      # move down at y + 
    
    rect0.width = max(rect0.width, 10)   
    rect0.height = max(rect0.height, 10) 

    # Draw
    screen.fill(PINK)
    pygame.draw.rect(screen, BLUE, rect0, 10) 

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
