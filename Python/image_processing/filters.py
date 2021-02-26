def input_matrix():
    print("Size of matrix:", end=" ")
    size = int(input())

    matrix = [[None] * size for _ in range(size)]

    print("Enter the matrix row-wise (each element in a row separated by spaces):")
    for i in range(size):
        for j, item in enumerate(list(map(int, input().split()))[:size]):
            matrix[i][j] = item
    return matrix

def print_matrix(matrix, name="Matrix"):
    print(f"\n{name}:")
    print("\n".join([" ".join([str(cell) for cell in row]) for row in matrix]))

def zero_boundary_padding(matrix, pad_element=0):
    size = len(matrix)
    for i in range(size):
        matrix[i] = [pad_element] + matrix[i] + [pad_element]
    
    matrix.append([pad_element] * (size + 2))
    matrix = [[pad_element] * (size + 2)] + matrix
    return matrix

def get_submatrix(matrix, row, col, size):
    submatrix = [[None] * size for _ in range(size)]
    for i in range(size):
        for j in range(size):
            submatrix[i][j] = matrix[i + row][j + col]
    return submatrix

def min_filter(matrix, filter_size=3):
    size = len(matrix) - 2
    filtered_matrix = [[None] * size for _ in range(size)]

    for row in range(size):
        for col in range(size):
            submatrix = get_submatrix(matrix, row, col, filter_size)
            filtered_matrix[row][col] = min(map(min, submatrix))

    return filtered_matrix

def max_filter(matrix, filter_size=3):
    size = len(matrix) - 2
    filtered_matrix = [[None] * size for _ in range(size)]

    for row in range(size):
        for col in range(size):
            submatrix = get_submatrix(matrix, row, col, filter_size)
        
            filtered_matrix[row][col] = max(map(max, submatrix))

    return filtered_matrix

if __name__ == '__main__':
    matrix = input_matrix()

    padded_matrix = zero_boundary_padding(matrix)
    print_matrix(padded_matrix, "Padded Matrix")

    min_filtered_matrix = min_filter(padded_matrix, filter_size=3)
    print_matrix(min_filtered_matrix, name="Matrix after Min Filter")

    max_filtered_matrix = max_filter(padded_matrix, filter_size=3)
    print_matrix(max_filtered_matrix, name="Matrix after Max Filter")
