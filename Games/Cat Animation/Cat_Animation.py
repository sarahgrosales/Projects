# Cat Animation

# Initialization or setup phase
from turtle import up

import pygame, sys
from pygame.locals import *

pygame.init()

# Frame rate control
FPS = 30 # frames per second setting
fpsClock = pygame.time.Clock()

# set up the window
DISPLAYSURF = pygame.display.set_mode((400, 300), 0, 32)
pygame.display.set_caption('Cat_Animation')

# Load and prepare image
WHITE = (255, 255, 255)
catImg = pygame.image.load('Assets/cat.png')
resized_img = pygame.transform.scale(catImg, (200, 200))

# Initial position and movement direction of the cat
catx = 10               # Top of scren is (0,0)
caty = 10
direction = 'right'      

while True: # the main game loop
    DISPLAYSURF.fill(WHITE)      # Wipes screen each frame, prevents
                                 # trails of cat on screen
    if direction == 'right':     # moves right at x + 5, stops at x = 210
        catx += 5                # then swithes to down
        if catx == 210:
            direction = 'down'

    elif direction == 'down':    # moves down at y + 5, stops at y = 110
        caty += 5                # switches to left
        if caty == 110:
            direction = 'left'

    elif direction == 'left':    # moves left at x - 5, stops at x = 10
        catx -= 5                # switches to up
        if catx == 10:
            direction = 'up'
            
    elif direction == 'up':      # moves up at y - 5, stops at y = 10
        caty -= 5                # switches to right
        if caty == 10:
            direction = 'right'

    DISPLAYSURF.blit(resized_img, (catx, caty))   # draws image

    # event handling loop
    for event in pygame.event.get():
        if event.type == QUIT:          # listens for user actions
            pygame.quit()               # such as closing window
            sys.exit()

    pygame.display.update()
    fpsClock.tick(FPS)
