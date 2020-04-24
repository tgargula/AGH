# Wprowadzenie do algorytmów r. 4.2 s. 75-83, 93-96
#
#  Three implementations of multiplying square matrix
# 1) Iterative version:
#       Time complexity: O(n^3)
#       Space complexity: O(n^2)
#       Always works :)
#
# 2) Recursive version:
#       Time complexity: O(n^3)
#       Space complexity: O(n^2 * log n) (?)
#       Works only when N = 2^k, k ∈ ℤ
#
# 3) Strassen method:
#       Time complexity: O(n^log7) ≈ O(n^2.81)
#       Space complexity: O(n^2 * log n) (?)
#       Works only when N = 2^k, k ∈ ℤ

import numpy as np

def multiplySquareMatrix (A, B):
    N = len(A)
    C = np.array(N*[N*[None]])
    for i in range(N):
        for j in range(N):
            c_ij = 0
            for k in range(N):
                c_ij += A[i,k] * B[k,j]
            C[i,j] = c_ij
    return C

def multiplySquareMatrixRecursive(A, B):
    N = len(A)
    C = np.array(N*[N*[None]])

    if N == 1: C = np.array([[A[0,0] * B[0,0]]])
    else:
        A_11 = A[:N//2, :N//2]
        A_12 = A[:N//2, N//2:]
        A_21 = A[N//2:, :N//2]
        A_22 = A[N//2:, N//2:]

        B_11 = B[:N//2, :N//2]
        B_12 = B[:N//2, N//2:]
        B_21 = B[N//2:, :N//2]
        B_22 = B[N//2:, N//2:]

        C_11 = multiplySquareMatrixRecursive(A_11, B_11) + multiplySquareMatrixRecursive(A_12, B_21)
        C_12 = multiplySquareMatrixRecursive(A_11, B_12) + multiplySquareMatrixRecursive(A_12, B_22)
        C_21 = multiplySquareMatrixRecursive(A_21, B_11) + multiplySquareMatrixRecursive(A_22, B_21)
        C_22 = multiplySquareMatrixRecursive(A_21, B_12) + multiplySquareMatrixRecursive(A_22, B_22)
        
        for i in range(N):
            for j in range(N):
                if i < N//2 and j < N//2:   C[i][j] = C_11[i][j]
                elif i < N//2:              C[i][j] = C_12[i][j-N//2]
                elif j < N//2:              C[i][j] = C_21[i-N//2][j]
                else:                       C[i][j] = C_22[i-N//2][j-N//2]
    
    return C

def multiplySquareMatrixStrassenMethod(A, B):
    def addMatrix (A,B):
        N = len(A)
        res = np.array(N*[N*[None]])
        for i in range(N):
            for j in range(N): res[i,j] = A[i,j] + B[i,j]
        return res
    
    def substractMatrix (A,B):
        N = len(A)
        res = np.array(N*[N*[None]])
        for i in range(N):
            for j in range(N): res[i,j] = A[i,j] - B[i,j]
        return res

    N = len(A)
    C = np.array(N*[N*[None]])

    if N == 1: C = np.array([[A[0,0] * B[0,0]]])
    else:
        A_11 = A[:N//2, :N//2]
        A_12 = A[:N//2, N//2:]
        A_21 = A[N//2:, :N//2]
        A_22 = A[N//2:, N//2:]

        B_11 = B[:N//2, :N//2]
        B_12 = B[:N//2, N//2:]
        B_21 = B[N//2:, :N//2]
        B_22 = B[N//2:, N//2:]

        S_1 = substractMatrix(B_12, B_22)
        S_2 = addMatrix(A_11, A_12)
        S_3 = addMatrix(A_21, A_22)
        S_4 = substractMatrix(B_21, B_11)
        S_5 = addMatrix(A_11, A_22)
        S_6 = addMatrix(B_11, B_22)
        S_7 = substractMatrix(A_12, A_22)
        S_8 = addMatrix(B_21, B_22)
        S_9 = substractMatrix(A_11, A_21)
        S_10 = addMatrix(B_11,B_12)

        P_1 = multiplySquareMatrixStrassenMethod(A_11, S_1)
        P_2 = multiplySquareMatrixStrassenMethod(S_2, B_22)
        P_3 = multiplySquareMatrixStrassenMethod(S_3, B_11)
        P_4 = multiplySquareMatrixStrassenMethod(A_22, S_4)
        P_5 = multiplySquareMatrixStrassenMethod(S_5, S_6)
        P_6 = multiplySquareMatrixStrassenMethod(S_7, S_8)
        P_7 = multiplySquareMatrixStrassenMethod(S_9, S_10)

        C_11 = addMatrix(substractMatrix(addMatrix(P_5, P_4),P_2), P_6)
        C_12 = addMatrix(P_1, P_2)
        C_21 = addMatrix(P_3, P_4)
        C_22 = substractMatrix(substractMatrix(addMatrix(P_5, P_1), P_3), P_7)

        for i in range(N):
            for j in range(N):
                if i < N//2 and j < N//2:   C[i][j] = C_11[i][j]
                elif i < N//2:              C[i][j] = C_12[i][j-N//2]
                elif j < N//2:              C[i][j] = C_21[i-N//2][j]
                else:                       C[i][j] = C_22[i-N//2][j-N//2]
    
    return C
    

A = np.array  ([[2,   1, 3,  4], 
                [1,  -3, 5, 10],
                [22, -2, 0, -1],
                [3,   3, 3,  4]])

B = np.array  ([[2, 6, 1, 1],
                [1, 1, -1, 0],
                [0, -1, 0, 3],
                [2, 3, 3, 4]])

C = np.array  ([[1, 0, 0, 0],
                [0, 1, 0, 0],
                [0, 0, 1, 0],
                [0, 0, 0, 1]])

D = np.array  ([[1, 2, 3],
                [4, 5, 6],
                [7, 8, 9]])

E = np.array  ([[0, 1, 3],
                [5, 2, -1],
                [1, 1, 1]])

print(multiplySquareMatrix(A,B))
print(multiplySquareMatrixRecursive(A,B))
print(multiplySquareMatrixStrassenMethod(A,B))

print(multiplySquareMatrix(D,E))