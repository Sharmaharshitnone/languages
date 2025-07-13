# Matrix multiplication
def matrix_multiply(A, B):
    rows_A, cols_A = len(A), len(A[0])
    rows_B, cols_B = len(B), len(B[0])
    
    if cols_A != rows_B:
        raise ValueError("Incompatible dimensions")
    
    result = [[0 for _ in range(cols_B)] for _ in range(rows_A)]
    for i in range(rows_A):
        for j in range(cols_B):
            for k in range(cols_A):
                result[i][j] += A[i][k] * B[k][j]
    return result

def rotate_90_clockwise(matrix):
    n = len(matrix)
    result = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            result[j][n-1-i] = matrix[i][j]
    return result

# Create identity matrix of size n
def identity_matrix(n):
    return [[1 if i == j else 0 for j in range(n)] for i in range(n)]

# Create a zero matrix of size rows x cols
def zero_matrix(rows, cols):
    return [[0 for _ in range(cols)] for _ in range(rows)]


# Print matrix in a readable format
def print_matrix(matrix):
    for row in matrix:
        print(" ".join(str(x) for x in row))

# Function to take matrix input from user
def input_matrix():
    rows = int(input("Enter number of rows: "))
    cols = int(input("Enter number of columns: "))
    
    matrix = []
    print(f"Enter the matrix elements row by row ({rows}x{cols}):")
    for i in range(rows):
        row = list(map(int, input().split()))
        while len(row) != cols:
            print(f"Please enter exactly {cols} elements for row {i+1}")
            row = list(map(int, input().split()))
        matrix.append(row)
    
    return matrix


print_matrix(input_matrix())
