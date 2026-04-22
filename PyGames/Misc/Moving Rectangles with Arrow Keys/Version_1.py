import pygame
from pygame.locals import *

pygame.init()

# Screen
screen = pygame.display.set_mode((640, 240))
pygame.display.set_caption("Move Rectangle")

# Colors
GREEN = (119, 221, 119)
PINK = (255, 209, 220)
BLUE = (167, 199, 231)

# Rectangles
rect0 = pygame.Rect(50, 60, 200, 80)  # original rectangle / Rect(x, y, width, height)
rect = rect0.copy()                   # moving copy / ccreates moveable version

# Movement dictionary (key → direction)
dir = {
    K_LEFT:  (-5, 0),    # left arrow key moves left at x - 5
    K_RIGHT: (5, 0),     # right arrow key moves right at x + 5
    K_UP:    (0, -5),    # up arrow key moves up at y - 5
    K_DOWN:  (0, 5)      # down arrow key moves down at y + 5
}

running = True
while running:
    for event in pygame.event.get():    # collects user input events

        if event.type == QUIT:
            running = False

        elif event.type == KEYDOWN:     # a key was pressed down
            if event.key in dir:        # checked if key was pressed in dir (dicitionary of allowed keys)
                v = dir[event.key]      # gets movement vector from dir dictionary ex: K_RIGHT → (5, 0)
                rect.move_ip(v)         # move_ip = move in place / modifies rect directly with movement vector v
    # if rect.x = 50 and v = (5, 0) then rect.x becomes 55
    
    # Drawing
    screen.fill(PINK)                         # fills the screen with green color to clear previous frame  
    pygame.draw.rect(screen, GREEN, rect0, 10)  # original
    pygame.draw.rect(screen, BLUE, rect, 10)    # moved

    pygame.display.flip()

pygame.quit()
