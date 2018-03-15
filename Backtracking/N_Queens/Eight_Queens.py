N = 8

def printSolution(board):
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
    if(col >= N):
        return True

    for i in range(N):
        if(isSafe(board, i, col)):
            board[i][col] = 1
            if(solveNQUtil(board, col + 1)):
                return True

            board[i][col] = 0

    return False

def solveNQ():
    board = [[0] * N for _ in range(N)]

    if(solveNQUtil(board, 0) == False):
        print('No solution')
        return False
    printSolution(board)
    return True

solveNQ()
