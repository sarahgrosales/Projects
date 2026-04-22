# Version 3 allows user to move cat png eith arrow keys + allows user to continously move png when an arrow key is held down

import pygame
from pygame.locals import *

pygame.init()

# Screen
screen = pygame.display.set_mode((640, 240))
pygame.display.set_caption("Move Rectangle")

# Colors
PINK = (255, 209, 220)
BLUE = (167, 199, 231)

# Cat
cat = pygame.image.load('Assets/cat.png')
resized_cat = pygame.transform.scale(cat, (100, 100))
cat_rect = resized_cat.get_rect(topleft = (0, 0))  

# Clock (important for smooth motion)
clock = pygame.time.Clock()

running = True
while running:

    for event in pygame.event.get():    # collects user input events
        if event.type == QUIT:
            running = False

    keys = pygame.key.get_pressed()

    if keys [K_LEFT]:
        cat_rect.move_ip(-2, 0)     # move left at x - 5
    if keys [K_RIGHT]:
        cat_rect.move_ip(2, 0)      # move right at x +
    if keys [K_UP]:
        cat_rect.move_ip(0, -2)     # move up at y -
    if keys [K_DOWN]:
        cat_rect.move_ip(0, 2)      # move down at y +
    
    # Drawing
    screen.fill(PINK)                           # fills the screen with green color to clear previous frame  
    screen.blit(resized_cat, cat_rect)      # draws the cat at its new position

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
