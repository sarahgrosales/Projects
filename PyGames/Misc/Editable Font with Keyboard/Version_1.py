"""Edit text with the keyboard."""

import pygame
from pygame.locals import *
import time

BLACK = (0, 0, 0)
GREEN = (221, 242, 209)
PINK = (255, 209, 220)

pygame.init()
screen = pygame.display.set_mode((640, 240))

text = 'this text is editable'         # text - editable string
font = pygame.font.SysFont(None, 48)   # default font and size of pixels (48)
img = font.render(text, True, GREEN)   # text -> converts text to image / true -> anti-aliasing (smooth edge)

rect = img.get_rect()                  # creates a rect the size of text image
rect.topleft = (20, 20)                # position on the screen
# blinking cursor is a rect of width 3 and height of text image
cursor = Rect(rect.topright, (3, rect.height))  # rect.topright -> position of cursor is at the end of text / (3, rect.height) -> size of cursor

running = True
background = PINK

while running:
    for event in pygame.event.get():
        if event.type == QUIT:
            running = False

        if event.type == KEYDOWN:           # runs when a key is pressed
            if event.key == K_BACKSPACE:    # removes last character
                if len(text) > 0:           # if there is text to remove ( > 0)
                    text = text[:-1]        # removes last character from text (text[:-1] -> all characters except the last one)
            else:                           # else adds the unicode of the key pressed to the text
                text += event.unicode       # event.unicode -> gives the character corresponding to the key pressed (e.g. if 'a' is pressed, event.unicode will be 'a')
            img = font.render(text, True, GREEN)  # updates the text image with the new text
            rect.size=img.get_size()              # updates rectangle size
            cursor.topleft = rect.topright        # moves cursor to the end of the text

    screen.fill(background)
    screen.blit(img, rect)
    # makes cursor blink by checking the current time in seconds and using modulo operator to create a blinking effect (cursor is visible for 0.5 seconds and invisible for 0.5 seconds)
    if time.time() % 1 > 0.5:    # time.time() -> gives the current time in seconds / % 1 -> gives the fractional part of the time (e.g. if time is 10.3 seconds, time.time() % 1 will be 0.3) / > 0.5 -> cursor is visible for 0.5 seconds and invisible for 0.5 seconds
        pygame.draw.rect(screen, GREEN, cursor)
    pygame.display.update()

pygame.quit()
