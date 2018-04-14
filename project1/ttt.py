__author__ = 'Yi Huang'
'''
Tic-Tac-Toe using both the Minimax Algorithm
and the Alpha-Beta Algorithm
'''

# Global values goes there
DEBUG = True
counter = 0

# Chess row and column global variable
BOARD_ROW = 3
BOARD_COL = 3

EMPTY = 0
HUMAN_X = 1
COMPU_O = 2

# Current input value
current_row = -1
current_col = -1
current_player = -1

# Input two integers, split by a space
def human_input():
    human = input('Human player \'X\', enter move (row[1-3] column[1-3]):')
    vals = human.split()

    global current_row, current_col
    global current_player

    current_row = int(vals[0]) - 1
    current_col = int(vals[1]) - 1
    current_player = HUMAN_X

    return [current_row, current_col]

# Check if the input value is safe to put in the board
def is_safe(board, list_in):
    row = list_in[0]
    col = list_in[1]
    if 0 <= row < BOARD_ROW and 0 <= col < BOARD_COL and board[row][col] == EMPTY:
        return True
    else:
        return False

# Input the current state of board
# If the human input is valid update the board
# and return a new board as the current states
def human_move(board):
    while True:
        try:
            list_in = human_input()
            if len(list_in) > 2:
                continue
        except Exception:
            continue
        if is_safe(board, list_in):
            board[list_in[0]][list_in[1]] = HUMAN_X
            return board

'''
Check the game result
'''
def is_tie(board):
    for row in board:
        for col in row:
            if col == EMPTY:
                return False
    return True

def is_won(board, current_row, current_col, current_player):
    # Check the same row
    seed = True
    for i in range(BOARD_COL):
        ans = (board[current_row][i] == current_player)
        seed &= ans
    if seed:
        return True

    # Check the same col
    seed = True
    for i in range(BOARD_ROW):
        ans = (board[i][current_col] == current_player)
        seed &= ans
    if seed:
        return True

    # Check the diagonal
    seed = True
    for i in range(BOARD_ROW):
        ans = (board[i][i] == current_player)
        seed &= ans
    if seed:
        return True

    seed = True
    for i in range(BOARD_ROW):
        ans = (board[2 - i][i] == current_player)
        seed &= ans
    if seed:
        return True

    return False


'''
The following two functions are
for print out the result of each iteration
'''
def print_cell(content):
    if content == EMPTY:
        print('   ', end='')
    elif content == HUMAN_X:
        print(' X ', end='')
    elif content == COMPU_O:
        print(' O ', end='')

def print_board(board):
    for row in range(BOARD_ROW):
        for col in range(BOARD_COL):
            print_cell(board[row][col])
            if col != BOARD_COL - 1:
                print('|', end='')
        print()
        if row != BOARD_ROW - 1:
            print('-----------')
    print()

'''
Minmax-Decsion Utility value
'''
WIN = 1
LOSE = -1
TIE = 0

'''
The intuitive Minimax Algorithm
'''
def minmax_decsion(board, row, col):
    return min_value(board, row, col, HUMAN_X)

# Human
def max_value(board, row, col, player):
    global counter
    counter += 1

    # player = COMPU_O
    if is_won(board, row, col, player):
        return Seed(LOSE, row, col)
    elif is_tie(board):
        return Seed(TIE, row, col)

    v = -float('inf')
    seeds = Seed(v, -1, -1)

    for i in range(BOARD_ROW):
        for j in range(BOARD_COL):
            if board[i][j] == EMPTY:

                # Mark the place as Human
                board[i][j] = HUMAN_X
                next_seeds = min_value(board, i, j, HUMAN_X)
                if seeds.v < next_seeds.v:
                    seeds.v = next_seeds.v
                    seeds.i = i
                    seeds.j = j

                # Un-mark the place
                board[i][j] = EMPTY

    return seeds

# Machine
def min_value(board, row, col, player):
    global counter
    counter += 1

    # player = HUMAN_X
    if is_won(board, row, col, player):
        return Seed(WIN, row, col)
    elif is_tie(board):
        return Seed(TIE, row, col)

    v = float('inf')
    seeds = Seed(v, -1, -1)

    for i in range(BOARD_ROW):
        for j in range(BOARD_COL):
            if board[i][j] == EMPTY:

                # Mark the place
                board[i][j] = COMPU_O
                next_seeds = max_value(board, i, j, COMPU_O)
                if seeds.v > next_seeds.v:
                    seeds.v = next_seeds.v
                    seeds.i = i
                    seeds.j = j

                # Un-mark the place
                board[i][j] = EMPTY

    return seeds

'''
The Alpha-beta Minimax Pruning Algorithm
'''
def minmax_alpha_beta(board, row, col, alpha, beta):
    return min_value_alpha_beta(board, row, col, HUMAN_X, alpha, beta)

# Human
def max_value_alpha_beta(board, row, col, player, alpha, beta):
    global counter
    counter += 1

    # player = COMPU_O
    if is_won(board, row, col, player):
        return Seed(LOSE, row, col)
    elif is_tie(board):
        return Seed(TIE, row, col)

    v = -float('inf')
    seeds = Seed(v, -1, -1)

    for i in range(BOARD_ROW):
        for j in range(BOARD_COL):
            if board[i][j] == EMPTY:

                # Mark the place as Human
                board[i][j] = HUMAN_X
                next_seeds = min_value_alpha_beta(board, i, j, HUMAN_X, alpha, beta)
                if seeds.v < next_seeds.v:
                    seeds.v = next_seeds.v
                    seeds.i = i
                    seeds.j = j

                # Un-mark the place
                board[i][j] = EMPTY

                # Pruning
                if seeds.v >= beta:
                    return seeds
                alpha = max(alpha, seeds.v)

    return seeds

# Machine
def min_value_alpha_beta(board, row, col, player, alpha, beta):
    global counter
    counter += 1

    # player = HUMAN_X
    if is_won(board, row, col, player):
        return Seed(WIN, row, col)
    elif is_tie(board):
        return Seed(TIE, row, col)

    v = float('inf')
    seeds = Seed(v, -1, -1)

    for i in range(BOARD_ROW):
        for j in range(BOARD_COL):
            if board[i][j] == EMPTY:

                # Mark the place
                board[i][j] = COMPU_O
                next_seeds = max_value_alpha_beta(board, i, j, COMPU_O, alpha, beta)
                if seeds.v > next_seeds.v:
                    seeds.v = next_seeds.v
                    seeds.i = i
                    seeds.j = j

                # Un-mark the place
                board[i][j] = EMPTY

                if seeds.v <= alpha:
                    return seeds
                beta = min(beta, seeds.v)

    return seeds

'''
The seed object is for containing the result of
the minimax value and also the position associated
with that value.
'''
class Seed:
    def __init__(self, v, i, j):
        self.v = v
        self.i = i
        self.j = j


if __name__ == '__main__':

    # Initialize the board
    board = [[EMPTY for x in range(BOARD_COL)] for x in range(BOARD_ROW)]
    print('Tic-Tac-Toe Human vs. Computer!!!')
    print_board(board)

    while True:
        # Ask human to input the move
        board = human_move(board)
        print_board(board)

        # Check if win after the move
        if is_won(board, current_row, current_col, current_player):
            print('Human win!')
            break
        elif is_tie(board):
            print('Human and computer tied.')
            break

        '''
        Run the Minimax algorithm
        '''
        computer = minmax_decsion(board, current_row, current_col)

        # Showing the result here
        print('Minimax algorithm result: ', end='')
        print('[', computer.i + 1, ', ', computer.j + 1, ']', sep='', end='')
        # print('\tMinimax value:', computer.v)
        print('\tSearch tree nodes:', counter)
        counter = 0

        # Test if the board changed after the machine move
        # print('The board in the middle')
        # print_board(board)

        '''
        Run the Alpha-beta Pruning Algorithm
        '''
        alpha = -float('inf')  # The value of the best alternative for MAX along the path to state
        beta = float('inf')  # The value of the best alternative for MIX along the path to state
        computer = minmax_alpha_beta(board, current_row, current_col, alpha, beta)

        # Showing the result here
        print('Alpha-beta pruning result: ', end='')
        print('[', computer.i + 1, ', ', computer.j + 1, ']', sep='', end='')
        # print('\tMinimax value:', computer.v)
        print('\tSearch tree nodes:', counter)
        counter = 0

        # Update the board by the machine move
        board[computer.i][computer.j] = COMPU_O
        print_board(board)

        # Check the result
        if is_won(board, computer.i, computer.j, COMPU_O):
            print('Computer win!')
            break
        elif is_tie(board):
            print('Human and computer tied.')
            break

