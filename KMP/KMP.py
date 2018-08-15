
def kmp_table(W):
    T = [None] * (len(W) + 1)

    pos = 1
    cnd = 0

    T[0] = -1

    while pos < len(W):
       # print(T)
 #       print(f'pos: {pos}  cnd:{cnd}')
        if W[pos] == W[cnd]:
            #print('equal')
            T[pos] = T[cnd]
            pos += 1
            cnd += 1

        else:
 #           print('not equal')
            T[pos] = cnd
            cnd = T[cnd]

            while cnd >= 0 and W[pos] != W[cnd]:
                cnd = T[cnd]

            pos = pos + 1
            cnd += 1

 #   print(pos)
 #   print(cnd)
    T[pos] = cnd

 #   print(T)

    return T


w1 = "ABCDABD"
w2 = "ABACABABC"
kmp_table(w2)



def kmp_search(S, W):
    T = kmp_table(W)

    j = 0
    k = 0

    nP = 0

    while j < len(S):
        if W[k] == S[j]:
            k += 1
            j += 1

            if(k == len(W)):
                nP += 1
                k = T[k]
        else:
            k = T[k]
            if k < 0:
                j += 1
                k += 1

    return nP
        

    
