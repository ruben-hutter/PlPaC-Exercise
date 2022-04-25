# python implementation of 4 in a row
import random
import os
import operator
import string
from scipy.signal import convolve2d
import numpy as np

PLAYER_SYMBOLS = ('X', '◯')
player = True
field = []
is_won = False

hor_k = np.array([[ 1, 1, 1, 1]])
vert_k = np.transpose(hor_k)
d1_k = np.eye(4, dtype=np.uint8)
d2_k = np.fliplr(d1_k)
det_k = [hor_k, vert_k, d1_k, d2_k]

    
# return the index of the top of a column
def get_top(column):
    return operator.indexOf(field[column], '.')

# return a random player (False = player 0, True = player 1)
def get_rand_player():
    return bool(random.getrandbits(1))

# switches players
def switch_player():
    global player
    player = not player

# init the playfield with blank symbols
def init_field():
    field.clear()
    for i in range (0,9):
        field.append(['.' for j in range(0,9)])

# gets a playes symbol
def get_player_symbol(player):
    return PLAYER_SYMBOLS[int(player)]

# prints the player anouncement header
def print_header():
    player_symbol = get_player_symbol(player)
    print(f'Turn of player {player_symbol}')

# prints the playfield to the command line
def print_field():
    print("  A B C D E F G H I")
    for i in range(8, -1, -1):
        print(f'{i} ' + ' '.join([field[j][i] for j in range(9)]))
    return

# checks for winning configuration on the board
def check_for_win():
    for kernel in det_k:
        if (convolve2d(np.array(field) == get_player_symbol(player), kernel, mode="valid") == 4).any():
            return True
    return False

# clears the terminal    
def clear_terminal():
    os.system('cls' if os.name == 'nt' else 'clear')

# prints the winner
def print_win():
    global player
    print_field()
    winner = get_player_symbol(player)
    print('--------------------------------------------------')
    print(f' Player {winner} won the game!')
    print('--------------------------------------------------')

# on launch of game
def launch():
    clear_terminal()
    global is_won
    is_won = False
    init_field()
    player = get_rand_player()
    run_game()

def run_game():
    print('> A new game has started!')
    global is_won, player
    while not is_won:
        # switch player
        switch_player()
        # print game state
        print_header()
        print_field()
        # promt action
        column = string.ascii_lowercase.index(input("> Enter a column in wich you'd like to set:"))
        clear_terminal()
        # update field
        field[column][get_top(column)] = get_player_symbol(player)
        # check for win
        is_won = check_for_win()
    print_win()
    input("Press Enter to start new game...")
    launch()
        
if __name__ == "__main__":
    launch()