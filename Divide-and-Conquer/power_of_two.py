

def func(b, n):
    if n == 1:
        return b
    
    if n % 2 == 0:
        return func(b, n // 2) * func(b, n // 2)

    if n % 2:
        return b * func(b, n // 2) * func(b, n // 2)
