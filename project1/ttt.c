typedef enum
{
    False, // 0
    True   // 1
} Boolean;

typedef enum
{
    Empty,   // 0
    Human_X, // 1
    Robot_O  // 2
} Role;

typedef enum
{
    WIN = 1,
    LOSE = -1,
    TIE = 0
} Status;

typedef struct
{
    int row;
    int col;
} BoardDim;

typedef struct
{
    Status    value;
    BoardDim  position;
} Decision;

// Global define goes there
#define DEBUG       False
#define BOARD_ROW   3
#define BOARD_COL   3
#define INF_NEG     -100
#define INF_POS     100
#define INI_POS     -1

// Library include goes there
#include <stdio.h>
#include <string.h>

// Global varialbes goes there
static int         counter;
static BoardDim    current_board;
static Role        current_player;
static Role        board[BOARD_ROW][BOARD_COL];

// Function prototype declarations
static void InitGlobalVariables(void);

void    Human_Input(void);
Boolean Safe_Check(void);
void    Human_Move(void);
Boolean Check_Tie(void);
Boolean Check_Win(int row, int col, Role player);
void    Print_Cell(Role content);
void    Print_Board(void);

// Entry function goes there
int main(int argc, char const *argv[])
{
    InitGlobalVariables();
    Print_Board();

    while(True)
    {
        Human_Move();
        Print_Board();
    }

    // Human_Input();
    // printf("%d %d %d\n", current_board.row, current_board.col, current_player);
    // printf("%d\n", Safe_Check());
    // Human_Move();
    // Print_Board();
    // printf("%d %d %d\n", WIN, LOSE, TIE);

    // Decision final;
    // final.value = INF_NEG;
    // final.position.row = 29;
    // final.position.col = 30;

    // printf("%d %d %d\n", final.value, final.position.row, final.position.col);

    // Decision start;
    // start.value = INF_POS;
    // BoardDim a = {200, 300};
    // start.position = a;

    // final.position = start.position;
    // printf("%d %d %d\n", final.value, final.position.row, final.position.col);

    return 0;
}

// Function implementations goes there
static void InitGlobalVariables(void)
{
    counter = 0;
    current_board.row = INI_POS;
    current_board.col = INI_POS;
    current_player = Empty;

    int i, j;
    for (i = 0; i < BOARD_ROW; ++i)
    {
        for (j = 0; j < BOARD_COL; ++j)
        {
            board[i][j] = Empty;
        }
    }
}

void Human_Input(void)
{
    int x_axle, y_axle;

    printf("Human player 'X', enter move >>>\n");
    printf("row[1-3]: ");
    scanf("%d", &x_axle);

    printf("col[1-3]: ");
    scanf("%d", &y_axle);
    // printf("%d %d\n", x_axle, y_axle);

    current_player = Human_X;
    current_board.row = x_axle - 1;
    current_board.col = y_axle - 1;
}

Boolean Safe_Check(void)
{
    Boolean is_safe;

    if (  current_board.row >= 0
       && current_board.row < BOARD_ROW
       && current_board.col >= 0
       && current_board.col < BOARD_COL
       && board[current_board.row][current_board.col] == Empty
        )
    {
        is_safe = True;
    }
    else
    {
        is_safe = False;
    }

    return is_safe;
}

void Human_Move(void)
{
    while(True)
    {
        Human_Input();
        if (Safe_Check())
        {
            board[current_board.row][current_board.col] = Human_X;
            break;
        }
        printf("Invalid input!!!\n\n");
    }
}

Boolean Check_Tie(void)
{
    int i, j;
    for (i = 0; i < BOARD_ROW; ++i)
    {
        for (j = 0; j < BOARD_COL; ++j)
        {
            if (board[i][j] == Empty)
            {
                return False;
            }
        }
    }
    return True;
}

Boolean Check_Win(int row, int col, Role player)
{
    Boolean res = True;
    int i;
    // Check the same row
    for (i = 0; i < BOARD_COL; ++i)
    {
        if (board[row][i] != player)
        {
            res = False;
            break;
        }
    }

    if (res == True)
    {
        return res;
    }

    res = True;
    // Check the same col
    for (i = 0; i < BOARD_ROW; ++i)
    {
        if (board[i][col] != player)
        {
            res = False;
            break;
        }
    }

    if (res == True)
    {
        return res;
    }

    res = True;
    // Check the diagonal forward
    for (i = 0; i < BOARD_ROW; ++i)
    {
        if (board[i][i] != player)
        {
            res = False;
            break;
        }
    }

    if (res == True)
    {
        return res;
    }

    res = True;
    // Check the diagonal backward
    for (i = 0; i < BOARD_ROW; ++i)
    {
        if (board[2-i][i] != player)
        {
            res = False;
            break;
        }
    }

    return res;
}

void Print_Cell(Role content)
{
    if (content == Empty)
    {
        printf("   ");
    }
    else if (content == Human_X)
    {
        printf(" X ");
    }
    else if (content == Robot_O)
    {
        printf(" O ");
    }
}

void Print_Board(void)
{
    int i, j;
    for (i = 0; i < BOARD_ROW; ++i)
    {
        for (j = 0; j < BOARD_COL; ++j)
        {
            Print_Cell(board[i][j]);
            if (j != BOARD_COL - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i != BOARD_ROW - 1)
        {
            printf("-----------\n");
        }
    }
    printf("\n");
}
/*
void Set_Player(Role player)
{
    current_player = player;
}

// Human
Decision Max_Value(void)
{
    counter += 1;
    Decision final;

    // Player is Robot
    if (Check_Won())
    {
        final.value = LOSE;
        final.position = current_board;
        return final;
    }
    else if (Check_Tie())
    {
        final.value = TIE;
        final.position = current_board;
        return final;
    }

    final.value = INF_NEG;
    final.position.row = INI_POS;
    final.position.col = INI_POS;

    int i, j;
    for (i = 0; i < BOARD_ROW; ++i)
    {
        for (j = 0; j < BOARD_COL; ++j)
        {
            if (board[i][j] == Empty)
            {
                // Mark the place as Human
                board[i][j] = Human_X;
                Decision next_decision = Maxx_Value();

                if (final.value < next_decision.value)
                {
                    final.value = next_decision.value;
                    final.position = next_decision.position;
                }

                // Un-mark the place
                board[i][j] = Empty;
            }
        }
    }

    return final;
}

// Machine
Decision Min_Value(void)
{
    counter += 1;
    Decision final;

    // Player is Human
    if (Check_Won())
    {
        final.value = LOSE;
        final.position = current_board;
        return final;
    }
    else if (Check_Tie())
    {
        final.value = TIE;
        final.position = current_board;
        return final;
    }

    final.value = INF_NEG;
    final.position.row = INI_POS;
    final.position.col = INI_POS;

    int i, j;
    for (i = 0; i < BOARD_ROW; ++i)
    {
        for (j = 0; j < BOARD_COL; ++j)
        {
            if (board[i][j] == Empty)
            {
                // Mark the place as Human
                board[i][j] = Human_X;
                Decision next_decision = Maxx_Value();

                if (final.value < next_decision.value)
                {
                    final.value = next_decision.value;
                    final.position = next_decision.position;
                }

                // Un-mark the place
                board[i][j] = Empty;
            }
        }
    }

    return final;
}
*/