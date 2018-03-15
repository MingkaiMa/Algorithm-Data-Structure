N = 8

k = 1
def printSolution(board):
    global k
    
    print(k)
    k += 1
    for i in range(N):
        for j in range(N):
            print(board[i][j], end= ', ')
        print()


def isSafe(board, row, col):
    
    for i in range(col):
        if(board[row][i]):
            return False


    i = row
    j = col
    while(i >= 0 and j >= 0):
        if(board[i][j]):
            return False

        i -= 1
        j -= 1


    i = row
    j = col
    while(i < N and j >= 0):
        if(board[i][j]):
            return False
        i += 1
        j -= 1

    return True

def solveNQUtil(board, col):
    if(col == N):
        printSolution(board)
        return True

    for i in range(N):
        if(isSafe(board, i, col)):
            board[i][col] = 1
            
            solveNQUtil(board, col + 1)
            
            board[i][col] = 0

    return False

def solveNQ():
    board = [[0] * N for _ in range(N)]

    solveNQUtil(board, 0)


solveNQ()
