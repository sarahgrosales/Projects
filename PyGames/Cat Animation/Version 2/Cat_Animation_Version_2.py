# In version 2 the cat bounces off the walls infinitly 
# Cat Image bouncing around the screen using Pygame

# Initialization
import pygame
from pygame.locals import *

pygame.init()

# Screen setup                             # size - window dimensions
size = width, height = (640, 320)          # set_mode() - creates the window
screen = pygame.display.set_mode(size)     # screen - drawing surface
pygame.display.set_caption('Test')         # set_caption() - sets the title of the window

# Colors
PINK   =  (255, 209, 220)      # light pink background
WHITE  =  (255, 255, 255)      # rectangle outline

# Frame rate
FPS = 30                           # frames per second setting
fpsClock = pygame.time.Clock()     # used to control the frame rate of the game loop

# Load and prepare image                            # load() - loads image file
ball = pygame.image.load('Assets/cat.png')          # scale() - resizes to 200x200 pixels
ball = pygame.transform.scale(ball, (200, 200))     # get_rect() - creates a rectangle boundary around image
rect = ball.get_rect()                              # rect - stores position and used for movement/collision
                                                    
# Movement Setup
speed = [2, 2]        # moves 2 pixels right and 2 pixels down each frame (initial speed)

# Game loop (most important part)
running = True
while running:                             # Loop runs every frame until user exits
    for event in pygame.event.get():       # Event handling loop - listens for user actions
        if event.type == QUIT:             # if the user clicks the close button on the window
            running = False                # stops the loop
    
    # Move the image
    rect = rect.move(speed)       # move() - moves the rectangle by the specified speed (x and y)

    # Bounce off edges (Bounce logic - collision with walls))
    if rect.left < 0 or rect.right > width:     # If hits left/right wall then reverse horizontal direction
        speed[0] = -speed[0]                    # speed[0] - horizontal movement (x direction)
    if rect.top < 0 or rect.bottom > height:    # If hits top/bottom wall then reverse vertical direction
        speed[1] = -speed[1]                    # speed[1] - vertical movement (y direction)

    # Draw everything
    screen.fill(PINK)                           # Clears the screen each frame [1 means line thickness]
    pygame.draw.rect(screen, WHITE, rect, 1)    # Draws a white rectangle around the image (for visibility of hitbox)
    screen.blit(ball, rect)                     # Draws image onto screen / uses rect as position

    pygame.display.update()                     # Updates the display to show the changes                 
    fpsClock.tick(FPS)                          # Controls the frame rate of the game loop (FPS frames per second)      

pygame.quit()  # Quits the game and closes the window
