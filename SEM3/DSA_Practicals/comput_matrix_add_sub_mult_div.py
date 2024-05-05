"""
Write a Python program to compute following computation on matrix:
a) Addition of two matrices B) Subtraction of two matrices
c) Multiplication of two matrices d) Transpose of a matrix
""" 

print(__doc__)

print("Enter the 1st matrix information: ")
row1 = int(input("Give the number of rows: "))
col1 = int(input("Give the number of columns: "))
matrix1 = [[0 for _ in range(col1)] for _ in range(row1)]

for i in range(row1):
    for j in range(col1):
        matrix1[i][j] = int(input(f"Enter the value of [{i+1},{j+1}]: "))

print("Matrix 1:")
for i in range(row1):
    for j in range(col1):
        print(matrix1[i][j], end=" ")
    print()

print("Enter the 2nd matrix information: ")
row2 = int(input("Give the number of rows: "))
col2 = int(input("Give the number of columns: "))
matrix2 = [[0 for _ in range(col2)] for _ in range(row2)]

for i in range(row2):
    for j in range(col2):
        matrix2[i][j] = int(input(f"Enter the value of [{i+1},{j+1}]: "))

print("Matrix 2:")
for i in range(row2):
    for j in range(col2):
        print(matrix2[i][j], end=" ")
    print()

matrix3 = [[0 for _ in range(col1)] for _ in range(row1)]
print("Matrix 3 (Addition):")
if row1 == row2 and col1 == col2:
    for i in range(row2):
        for j in range(col2):
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j]
    for i in range(row2):
        for j in range(col2):
            print(matrix3[i][j], end=" ")
        print()
else:
    print("Matrix addition is not possible!")

matrix4 = [[0 for _ in range(col1)] for _ in range(row1)]
print("Matrix 4 (Subtraction):")
if row1 == row2 and col1 == col2:
    for i in range(row2):
        for j in range(col2):
            matrix4[i][j] = matrix1[i][j] - matrix2[i][j]
    for i in range(row2):
        for j in range(col2):
            print(matrix4[i][j], end=" ")
        print()
else:
    print("Matrix subtraction is not possible!")

matrix5 = [[0 for _ in range(col2)] for _ in range(row1)]
print("Matrix 5 (Multiplication):")
if col1 == row2:
    for i in range(row1):
        for j in range(col2):
            for k in range(col1):
                matrix5[i][j] += matrix1[i][k] * matrix2[k][j]
    for i in range(row1):
        for j in range(col2):
            print(matrix5[i][j], end=" ")
        print()
else:
    print("Matrix multiplication is not possible!")

matrix6 = [[0 for _ in range(row1)] for _ in range(col1)]
print("Matrix 6 (Transpose of Matrix 1):")
for i in range(row1):
    for j in range(col1):
        matrix6[j][i] = matrix1[i][j]
for i in range(col1):
    for j in range(row1):
        print(matrix6[i][j], end=" ")
    print()

matrix7 = [[0 for _ in range(row2)] for _ in range(col2)]
print("Matrix 7 (Transpose of Matrix 2):")
for i in range(row2):
    for j in range(col2):
        matrix7[j][i] = matrix2[i][j]
for i in range(col2):
    for j in range(row2):
        print(matrix7[i][j], end=" ")
    print()

