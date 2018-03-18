MAX = float('inf')

def Matrix_Chain_Order(p):

    n = len(p) - 1
    m = [[MAX] * n for _ in range(n)]
    s = [[-1] * n for _ in range(n)]

    for i in range(n):
        m[i][i] = 0

    for l in range(2, n + 1):
        print(f'chain length is {l}')
        for i in range(n - l + 1):
            j = i + l - 1
            print(f'i--j : {i}--{j}')
            m[i][j] = MAX
            for k in range(i, j):
                print(f'k is: {k}')
                q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j+1]
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k



    return m, s




def print_optimal_parens(s, i, j):
    if i == j:
        print(f'Matrix {i}', end='')
    else:
        print('(',end='')
        print_optimal_parens(s, i, s[i][j])
        print_optimal_parens(s, s[i][j] + 1, j)
        print(')',end='')


if __name__ == '__main__':
    p = [30, 35, 15, 5, 10, 20, 25]
    m, s = Matrix_Chain_Order(p)
    print_optimal_parens(s, 0, 5)
    
    



