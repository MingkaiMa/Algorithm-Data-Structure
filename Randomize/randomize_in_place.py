from random import randint


class Randomize():
    def __init__(self, lst):
        self.L = lst
        self.len = len(self.L)

    def randomize_in_place(self):

        for i in range(self.len):
            n = randint(i, self.len - 1)
            self.L[i], self.L[n] = self.L[n], self.L[i]


    def permute_by_sorting(self):

        dic = {}
        for i in self.L:
            dic[i] = randint(1, self.len ** 3)
        new_dic = sorted(dic, key = lambda x: dic[x])
        self.L = list(new_dic)



if __name__ == '__main__':
    L = [1,2,3,4,5,6]
    A = Randomize(L)
    #A.randomize_in_place()
    A.permute_by_sorting()
    print(A.L)