

class Assembly_Line_Schedule():
    def __init__(self, a, t, e, x, n):
        self.a = a
        self.t = t
        self.e = e
        self.x = x
        self.n = n
        self.f0 = [None] * self.n
        self.f1 = [None] * self.n
        self.l0 = [None] * self.n
        self.l1 = [None] * self.n
        self.f = 0
        self.l = 0
        self.L = []


    def fastest_way(self):
        self.f0[0] = self.e[0] + self.a[0][0]
        self.f1[0] = self.e[1] + self.a[1][0]

        for j in range(1, self.n):
            if self.f0[j - 1] + self.a[0][j] <= self.f1[j - 1] + self.t[1][j - 1] + self.a[0][j]:
                self.f0[j] = self.f0[j - 1] + self.a[0][j]
                self.l0[j] = 0
            else:
                self.f0[j] = self.f1[j - 1] + self.t[1][j - 1] + self.a[0][j]
                self.l0[j] = 1

            if self.f1[j - 1] + self.a[1][j] <= self.f0[j - 1] + self.t[0][j - 1] + self.a[1][j]:
                self.f1[j] = self.f1[j - 1] + self.a[1][j]
                self.l1[j] = 1
            else:
                self.f1[j] = self.f0[j - 1] + self.t[0][j - 1] + self.a[1][j]
                self.l1[j] = 0

        if self.f0[self.n - 1] + self.x[0] <= self.f1[self.n - 1] + self.x[1]:
            self.f = self.f0[self.n - 1] + self.x[0]
            self.l = 0
        else:
            self.f = self.f1[self.n - 1] + self.x[1]
            self.l = 1

    def get_line_schedual(self):
        self.fastest_way()
        self.L.append(self.l0)
        self.L.append(self.l1)

        i = self.l
        print(f' line {i} station {self.n}')


        for j in range(self.n - 1, 0, -1):

            i = self.L[i][j]
            print(f' line {i} station {j}')

if __name__ == '__main__':
    a = [[7, 9, 3, 4, 8, 4], [8, 5, 6, 4, 5, 7]]
    t = [[2, 3, 1, 3, 4], [2, 1, 2, 2, 1]]
    e = [2, 4]
    x = [3, 2]
    n = 6
    S = Assembly_Line_Schedule(a, t, e, x, n)
    S.fastest_way()
    print(S.f0)
    print(S.f1)
    print(S.l0)
    print(S.l1)
    print(S.l)
    S.get_line_schedual()
    #print(f'{1} line {2} words')








