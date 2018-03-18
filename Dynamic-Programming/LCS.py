

def LCS_Length(X, Y):
    m = len(X)
    n = len(Y)

    print(m, n)
    c = [[None] * (n + 1) for _ in range(m + 1)]
    b = [[None] * (n + 1) for _ in range(m + 1)]
    for i in range(m + 1):
        c[i][0] = 0

    for j in range(n + 1):
        c[0][j] = 0

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if X[i - 1] == Y[j - 1]:
                c[i][j] = c[i - 1][j - 1] + 1
                b[i][j] = 'Diag'

            elif c[i - 1][j] >= c[i][j - 1]:
                c[i][j] = c[i - 1][j]
                b[i][j] = 'Up'

            else:
                c[i][j] = c[i][j - 1]
                b[i][j] = 'Left'

    return c, b



def PRINT_LCS(b, X, i, j):
    if i == 0 or j == 0:
        return

    if b[i][j] == 'Diag':
        PRINT_LCS(b, X, i - 1, j - 1)
        print(X[i - 1])

    elif b[i][j] == 'Up':
        PRINT_LCS(b, X, i - 1, j)
    else:
        PRINT_LCS(b, X, i, j - 1)


