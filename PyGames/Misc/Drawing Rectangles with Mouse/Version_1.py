# Using mouse to draw rectangle on the screen

import pygame
from pygame.locals import *

pygame.init()

# Screen setup
width, height = (640, 320)
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption('Draw Rectangle with Mouse')

# Colors
PINK = (255, 209, 220)
WHITE = (255, 255, 255)

# Drawing variables
start = (0, 0)          # This is where you first start
size = (0, 0)           # This is how big the rectangle is (width, height)
drawing = False         # This is a flag to check if we are currently drawing

# Frame rate
FPS = 30
fpsClock = pygame.time.Clock()

running = True
while running:

    # --- Event handling ---
    for event in pygame.event.get():      # Gets all user inputs (mouse, keyboard, and window close)

        if event.type == QUIT:            # If the event is a quit event (like closing the window)
            running = False               # Set running to False to exit the loop and end the program

        elif event.type == MOUSEBUTTONDOWN:    # event.pos = (x, y) of mouse
            start = event.pos                  # Saves starting position of the rectangle when mouse button is pressed
            size = (0, 0)                      # Resets size to (0, 0) when starting a new rectangle
            drawing = True

        elif event.type == MOUSEMOTION and drawing:        # Triggers when mouse move and holding down
            end = event.pos                                # Gets current position of the mouse while moving                                       
            size = (end[0] - start[0], end[1] - start[1])  # end[0] - start[0] = width of rectangle / end[1] - start[1] = height of rectangle

        elif event.type == MOUSEBUTTONUP:     # Triggers when mouse button is released, which means we are done drawing the rectangle
            drawing = False                   # Set drawing to False to stop updating the rectangle size when mouse moves

    # --- Drawing ---
    screen.fill(WHITE)     # Fills screen with white every frame, prevents trails of rectangles on the screen

    if drawing:                                               # screen -> where to draw / PINK -> color of rectangle
        pygame.draw.rect(screen, PINK, (start, size), 10)     # (start, size) -> position and size of rectangle / 2 -> thickness

    pygame.display.update()
    fpsClock.tick(FPS)

pygame.quit()
