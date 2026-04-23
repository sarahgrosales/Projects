# version 2 allows user to continously input text and backspace to delete/add text.

import pygame
from pygame.locals import *
import time

pygame.init()

# Enable key repeat (continuous typing)
pygame.key.set_repeat(400, 50)

# Screen
screen = pygame.display.set_mode((640, 240))
pygame.display.set_caption("Editable Text")

# Colors
GREEN = (221, 242, 209)
PINK = (255, 209, 220)

# Text setup
text = "this text is editable"
font = pygame.font.SysFont(None, 48)
img = font.render(text, True, GREEN)

# Positioning
rect = img.get_rect()
rect.topleft = (20, 20)

# Cursor
cursor = pygame.Rect(rect.topright, (3, rect.height))

running = True
clock = pygame.time.Clock()

while running:
    for event in pygame.event.get():

        if event.type == QUIT:
            running = False

        # --- TEXT INPUT ---
        if event.type == KEYDOWN:
            if event.key == K_BACKSPACE:
                if len(text) > 0:
                    text = text[:-1]
            else:
                text += event.unicode

            # Re-render text after change
            img = font.render(text, True, GREEN)
            rect.size = img.get_size()

            # Move cursor to end of text
            cursor.topleft = rect.topright

    # --- DRAW ---
    screen.fill(PINK)
    screen.blit(img, rect)

    # --- BLINKING CURSOR ---
    if time.time() % 1 > 0.5:
        pygame.draw.rect(screen, GREEN, cursor)

    pygame.display.update()
    clock.tick(60)

pygame.quit()
