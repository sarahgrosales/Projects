# Tic Tac Toe Game

# Importing Libraries
import pygame as pg           # Imports pygame library
import sys                    # Imports sys library
import time                   # Imports time library
from pygame.locals import *   # Imports all the constants from pygame.locals

# Declare global variables
XO = 'x'                      # Stores 'x' or 'o' value as character
winner = None                 # Stores the winner's value at any instant of code
draw = None                   # Checks if game is a draw
width = 400                   # Width of the game window
height = 400                  # Height of the game window
white = (255, 255, 255)       # Sets background color of game window to white
line_color = (0, 0, 0)        # Color of straight lines on the game board (divides board into 9 parts)
board = [[None]*3, [None]*3, [None]*3]  # Sets up a 3x3 board in canvas

# Designing the game display
pg.init()                     # Initializing the pygame window
fps = 30                      # Sets frames per second to 30
CLOCK = pg.time.Clock()       # Used to track time
screen = pg.display.set_mode((width, height + 100), 0, 32)  # Builds infrastructure of display
pg.display.set_caption("Tic Tac Toe")  # Sets up a nametag for game window

# Loading the images as python objects
initiating_window = pg.image.load("assets/modified_cover.png")  # Loads initial cover image
x_img = pg.image.load("assets/X_modified.png")                  # Loads x image
y_img = pg.image.load("assets/O_modified.png")                  # Loads o image

# Resizing images
initiating_window = pg.transform.scale(initiating_window, (width, height + 100))  # Resizes initial cover image
x_img = pg.transform.scale(x_img, (80, 80))  # Resizes x image
o_img = pg.transform.scale(y_img, (80, 80))  # Resizes y image

def game_initiating_window():
    
    screen.blit(initiating_window, (0, 0))  # Displays the initial cover image on the game window
    
    pg.display.update()                     # Updates the display to show the changes
    time.sleep(3)                           # Pauses game for 3 sec so players can see initial cover image
    screen.fill(white)                      # Fills game window with white to prep for game board

    pg.draw.line(screen, line_color, (width / 3, 0), (width / 3, height), 7)           # Draws first vertical line
    pg.draw.line(screen, line_color, (width / 3 * 2, 0), (width / 3 * 2, height), 7)   # Draws second vertical line
    
    pg.draw.line(screen, line_color, (0, height / 3), (width, height / 3), 7)          # Draws first horizontal line            
    pg.draw.line(screen, line_color, (0, height / 3 * 2), (width, height / 3 * 2), 7)  # Draws second horizontal line   
    draw_status()                           # Displays the status of the game (who's turn it is, who won, etc.)

def draw_status():
    global draw       # Gets global variable draw to check if game is a draw
    
    if winner is None:                      # If there is no winner yet
        message = XO.upper() + "'s Turn"    # Displays whose turn it is
    else:
        message = winner.upper() + " won!"  # Displays who won the game
    
    if draw:                                # If the game is a draw
        message = "Game Draw!"              # Displays that the game is a draw
    
    font = pg.font.Font(None, 30)                     # Sets font and size for status message
    text = font.render(message, 1, (255, 255, 255))   # Renders the status message in white color
    
    screen.fill((0, 0, 0), (0, 400, 500, 100))             # Fills the area below the game board with black to display status message
    text_rect = text.get_rect(center=(width / 2, 500-50))  # Centers the status message in the area below the game board
    screen.blit(text, text_rect)                           # Displays the status message on the game window
    pg.display.update()                                    # Updates the display to show the changes   

# Main Algorithm
def check_win():
    global board, winner, draw

    # Checks for winning horizontal rows
    for row in range(0, 3):  
        if ((board[row][0] == board[row][1] == board[row][2]) and (board[row][0] is not None)):
            winner = board[row][0]
            pg.draw.line(screen, (250, 0, 0), (0, (row + 1) * height / 3 - height / 6), (width, (row + 1) * height / 3 - height / 6), 4)
            break
    
    # Checks for winning vertical columns 
    for col in range(0, 3):   
        if ((board[0][col] == board[1][col] == board[2][col]) and (board[0][col] is not None)):
            winner = board[0][col]
            pg.draw.line(screen, (250, 0, 0), ((col + 1) * width / 3 - width / 6, 0), ((col + 1) * width / 3 - width / 6, height), 4)
            break

    # Checks for winning diagonal (top-left to bottom-right)
    if (board[0][0] == board[1][1] == board[2][2]) and (board[0][0] is not None):  
        winner = board[0][0]
        pg.draw.line(screen, (250, 70, 70), (50, 50), (350, 350), 4)

    # Checks for winning diagonal (top-right to bottom-left)
    if (board[0][2] == board[1][1] == board[2][0]) and (board[0][2] is not None): 
        winner = board[0][2]
        pg.draw.line(screen, (250, 70, 70), (350, 50), (50, 350), 4)    

    # Checks for draw 
    if (all([all(row) for row in board]) and winner is None):  
        draw = True

    draw_status()  # Updates the status of the game after checking for win/draw conditions  

# Getting user inpute and displaying "X" or "O"

def drawXO(row, col):
    global board, XO

    if row == 1:                   # First row, image pasted at x coordinate
        posx = 30                  # of 30 from left margin

    if row == 2:                   # Second row, image pasted at x coordinate of 30 from game line
        posx = width / 3 + 30      # margin or width / 3 + 30 from left margin of window

    if row == 3:
        posx = width / 3 * 2 + 30

    if col == 1:
        posy = 30

    if col == 2:
        posy = height / 3 + 30

    if col == 3:
        posy = height / 3 * 2 + 30

    # Setting up board value to display
    board[row - 1][col - 1] = XO

    if(XO == 'x'):                          # Pasting x_img over the screen at
                                            # coordinate position of (posy, posx)
        screen.blit(x_img, (posy, posx))    # defined in the above code
        XO = 'o'

    else:
        screen.blit(o_img, (posy, posx))
        XO = 'x'
    
    pg.display.update()

def user_click():
    x, y = pg.mouse.get_pos()  # Gets the x and y coordinates of the mouse click

    # Get column of mouse click (1-3)
    if(x < width / 3):         # If the click is in the first column
        col = 1
    elif(x < width / 3 * 2):   # If the click is in the second column
        col = 2
    else:                      # If the click is in the third column
        col = 3

    # Get row of mouse click (1-3)
    if(y < height / 3):        # If the click is in the first row
        row = 1
    elif(y < height / 3 * 2):  # If the click is in the second row
        row = 2
    elif(y < height):          # If the click is in the third row
        row = 3
    else:
        row = None
    
    # Draws images at desired positions after getting row and col
    if(row and col and board [row-1][col-1] is None):     
        global XO

        drawXO(row, col)        # Draw "X" or "O" in that cell
        check_win()             # Check if there is a winner or if it's a draw

# Running an infinte loop
def reset_game():
    global board, winner, XO, draw
    time.sleep(3)               # Pause for 3 seconds before resetting the game
    XO = 'x'                    # Reset to 'x' starting first
    draw = False                # Reset draw status
    game_initiating_window()    # Reinitialize game window with initial cover and game board
    winner = None               # Reset winner status
    board = [[None]*3, [None]*3, [None]*3]  # Reset the game board

game_initiating_window()  # Reinitialize the game window with the initial cover and game board

while (True):  # Infinite loop to keep the game running
    for event in pg.event.get():  # Get all events (like mouse clicks, key presses, etc.)

        if event.type == QUIT:    # If the event is a quit event (like closing the window)
            pg.quit()             # Quit the pygame window
            sys.exit()            # Exit the program

        elif event.type == MOUSEBUTTONDOWN:  # If the event is a mouse button click
            user_click()          # Handle the user click to place "X" or "O"

            if(winner or draw):   # If there is a winner or if it's a draw after the click
                reset_game()      # Reset the game for a new round

    pg.display.update()        # Update the display to show any changes made during the loop
    CLOCK.tick(fps)            # Control the frame rate of the game loop
