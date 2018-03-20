

class Horner_rule():
    def __init__(self, lst, n, x):
        self.L = lst
        self.x = x
        self.n = n


    def horner_rule(self):
        result = 0
        for i in range(self.n - 1, -1, -1):
            result = result * self.x + self.L[i]

        return result



if __name__ == '__main__':

    ##calculate 1 + 2 * (x) + 3 * (x ** 2) + 4 * (x ** 3) + 5 * (x ** 4) + 6 * (x ** 5)
    ##x = 2, n = 6
    ## time complexity: O(n)
    ## naive time complexity: O(n2)
    A = Horner_rule([1, 2, 3, 4, 5, 6], 6, 2)
    print(A.horner_rule())