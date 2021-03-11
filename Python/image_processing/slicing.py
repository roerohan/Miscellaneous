from functools import reduce

def input_matrix():
    print("Size of matrix:", end=" ")
    size = int(input())

    matrix = [[None] * size for _ in range(size)]

    print("Enter the matrix row-wise (each element in a row separated by spaces):")
    for i in range(size):
        for j, item in enumerate(list(map(int, input().split()))[:size]):
            matrix[i][j] = item
    return size, matrix


def print_matrix(matrix, name="Matrix"):
    print(f"\n{name}:")
    print("\n".join([" ".join([str(cell) for cell in row]) for row in matrix]))


def gray_level_slicing(matrix, size, lower, upper, L=256, bg_subtraction=False):
    result = [[None] * size for _ in range(size)]
    for i in range(size):
        for j in range(size):
            if (matrix[i][j] >= lower and matrix[i][j] <= upper):
                result[i][j] = L - 1
            else:
                if (bg_subtraction):
                    result[i][j] = 0
                else:
                    result[i][j] = matrix[i][j]
    return result


def bit_plane_slicing(matrix, size, number_of_planes=8):
    binary_matrix = [[None] * size for _ in range(size)]
    for i in range(size):
        for j in range(size):
            binary_matrix[i][j] = bin(matrix[i][j])[2:].zfill(8)
    
    print_matrix(binary_matrix, name="Binary matrix")

    matrices = [[[None] * size for _ in range(size)] for _ in range(number_of_planes)]
    for k in range(number_of_planes):
        for i in range(size):
            for j in range(size):
                matrices[k][i][j] = binary_matrix[i][j][k]

    return matrices

if __name__ == '__main__':
    size, matrix = input_matrix()
    print_matrix(matrix, name="Input Matrix")
    
    lower = int(input("Lower limit for gray level slicing: "))
    upper = int(input("Upper limit for gray level slicing: "))

    gl_slicing_wo_bg_sub = gray_level_slicing(matrix, size, lower, upper, bg_subtraction=False)
    print_matrix(gl_slicing_wo_bg_sub, name="Gray level slicing without background subtraction")

    gl_slicing_bg_sub = gray_level_slicing(matrix, size, lower, upper, bg_subtraction=True)
    print_matrix(gl_slicing_bg_sub, name="Gray level slicing with background subtraction")

    bit_plane_matrices = bit_plane_slicing(matrix, size)
    for m in bit_plane_matrices:
        print_matrix(m)
