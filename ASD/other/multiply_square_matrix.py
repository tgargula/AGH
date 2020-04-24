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
#       Space complexity: O(n^2 * log n)(?)
#       Works only when N = 2^k, k ∈ ℤ
#
# 3) Strassen method:
#       Time complexity: O(n^log7) ≈ O(n^2.81)
#       Space complexity: O(n^2 * log n)(?)
#       Works only when N = 2^k, k ∈ ℤ

import numpy as np

def multiply_square_matrix(A, B):
    N = len(A)
    C = np.array(N*[N*[None]])
    for i in range(N):
        for j in range(N):
            c_ij = 0
            for k in range(N):
                c_ij += A[i,k] * B[k,j]
            C[i,j] = c_ij
    return C

def multiply_square_matrix_recursive(A, B):
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

        C_11 = multiply_square_matrix_recursive(A_11, B_11) + multiply_square_matrix_recursive(A_12, B_21)
        C_12 = multiply_square_matrix_recursive(A_11, B_12) + multiply_square_matrix_recursive(A_12, B_22)
        C_21 = multiply_square_matrix_recursive(A_21, B_11) + multiply_square_matrix_recursive(A_22, B_21)
        C_22 = multiply_square_matrix_recursive(A_21, B_12) + multiply_square_matrix_recursive(A_22, B_22)
        
        for i in range(N):
            for j in range(N):
                if i < N//2 and j < N//2:   C[i][j] = C_11[i][j]
                elif i < N//2:              C[i][j] = C_12[i][j-N//2]
                elif j < N//2:              C[i][j] = C_21[i-N//2][j]
                else:                       C[i][j] = C_22[i-N//2][j-N//2]
    
    return C

def multiply_square_matrix_strassen_method(A, B):
    def add(A,B):
        N = len(A)
        res = np.array(N*[N*[None]])
        for i in range(N):
            for j in range(N): res[i,j] = A[i,j] + B[i,j]
        return res
    
    def substract(A,B):
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

        S_1 = substract(B_12, B_22)
        S_2 = add(A_11, A_12)
        S_3 = add(A_21, A_22)
        S_4 = substract(B_21, B_11)
        S_5 = add(A_11, A_22)
        S_6 = add(B_11, B_22)
        S_7 = substract(A_12, A_22)
        S_8 = add(B_21, B_22)
        S_9 = substract(A_11, A_21)
        S_10 = add(B_11,B_12)

        P_1 = multiply_square_matrix_strassen_method(A_11, S_1)
        P_2 = multiply_square_matrix_strassen_method(S_2, B_22)
        P_3 = multiply_square_matrix_strassen_method(S_3, B_11)
        P_4 = multiply_square_matrix_strassen_method(A_22, S_4)
        P_5 = multiply_square_matrix_strassen_method(S_5, S_6)
        P_6 = multiply_square_matrix_strassen_method(S_7, S_8)
        P_7 = multiply_square_matrix_strassen_method(S_9, S_10)

        C_11 = add(substract(add(P_5, P_4),P_2), P_6)
        C_12 = add(P_1, P_2)
        C_21 = add(P_3, P_4)
        C_22 = substract(substract(add(P_5, P_1), P_3), P_7)

        for i in range(N):
            for j in range(N):
                if i < N//2 and j < N//2:   C[i][j] = C_11[i][j]
                elif i < N//2:              C[i][j] = C_12[i][j-N//2]
                elif j < N//2:              C[i][j] = C_21[i-N//2][j]
                else:                       C[i][j] = C_22[i-N//2][j-N//2]
    return C
    

A = np.array ([[2,   1, 3,  4], 
                [1,  -3, 5, 10],
                [22, -2, 0, -1],
                [3,   3, 3,  4]])

B = np.array ([[2, 6, 1, 1],
                [1, 1, -1, 0],
                [0, -1, 0, 3],
                [2, 3, 3, 4]])

C = np.array ([[1, 0, 0, 0],
                [0, 1, 0, 0],
                [0, 0, 1, 0],
                [0, 0, 0, 1]])

D = np.array ([[1, 2, 3],
                [4, 5, 6],
                [7, 8, 9]])

E = np.array ([[0, 1, 3],
                [5, 2, -1],
                [1, 1, 1]])

print(multiply_square_matrix(A,B))
print(multiply_square_matrix_recursive(A,B))
print(multiply_square_matrix_strassen_method(A,B))
print(multiply_square_matrix(D,E))