def input_matrix():
    row = int(input("Enter the number of rows: "))
    col = int(input("Enter the number of columns: "))
    matrix = []
    for i in range(row):
        row = list(map(int, input().split()))
        matrix.append(row)
    return matrix

def print_matrix(matrix):
    print("Here is your matrix:")
    for row in matrix:
        print(" ".join(str(x) for x in row))

print_matrix(input_matrix())
