
class MatrixMultiply():
    def __init__(self, A, B):
        self.A = A
        self.B = B


    def Matrix_Multiply(self):
        if(len(self.A[0]) != len(self.B)):
            return
        row_nb = len(self.A)
        column_nb = len(self.B[0])

        C = [[0] * column_nb for _ in range(row_nb)] 
        print(C)
        for i in range(len(self.A)):
            for j in range(len(self.B[0])):
                for k in range(len(self.A[0])):
                    print(f'C[0][0] is {C[0][0]}')
                    print(f'i-j {i}-{j}, i-k {i}-{k}, k-j {k}-{j}')
                    print(self.A[i][k], self.B[k][j], C[i][j])
                    print(self.A[i][k] * self.B[k][j])
                    C[i][j] = C[i][j] + self.A[i][k] * self.B[k][j]


        print(C[0][0])
        return C



if __name__ == '__main__':
    MM = MatrixMultiply([[1,2,3], [4,5,6]], [[1,2,3,4], [5,6,7,8], [1,2,3,4]])
    C = MM.Matrix_Multiply()
    print(C)
