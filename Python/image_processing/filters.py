from functools import reduce
import copy

def input_matrix():
    print("Size of matrix:", end=" ")
    size = int(input())

    matrix = [[None] * size for _ in range(size)]

    print("Enter the matrix row-wise (each element in a row separated by spaces):")
    for i in range(size):
        for j, item in enumerate(list(map(float, input().split()))[:size]):
            matrix[i][j] = item
    return matrix


def print_matrix(matrix, name="Matrix"):
    print(f"\n{name}:")
    s = [[str(e) for e in row] for row in matrix]
    lens = [max(map(len, col)) for col in zip(*s)]
    fmt = "\t".join("{{:{}}}".format(x) for x in lens)
    table = [fmt.format(*row) for row in s]
    print("\n".join(table))

def boundary_padding(matrix, pad_element=0, type="zero_padding", boundary_size=1):
    new_matrix = copy.deepcopy(matrix)
    size = len(new_matrix)
    
    if (type == "zero_padding"):
        for k in range(boundary_size):
            for i in range(size + 2 * k):
                new_matrix[i] = [pad_element] + new_matrix[i] + [pad_element]
        
            new_matrix.append([pad_element] * len(new_matrix[0]))
            new_matrix = [[pad_element] * len(new_matrix[0])] + new_matrix

    elif (type == "pixel_replication"):
        for k in range(boundary_size):
            for i in range(size + 2 * k):
                new_matrix[i] = [new_matrix[i][0]] + new_matrix[i] + [new_matrix[i][size + k - 1]]

            new_matrix.append(new_matrix[size + k - 1])
            new_matrix = [new_matrix[0]] + new_matrix

    elif (type == "pixel_wrap"):
        new_new_matrix = [[None] * (size + 2) for _ in range(size + 2)]
        for i in range(new_new_matrix):
            pass

    return new_matrix


def get_submatrix(matrix, row, col, size):
    submatrix = [[None] * size for _ in range(size)]
    for i in range(size):
        for j in range(size):
            submatrix[i][j] = matrix[i + row][j + col]
    return submatrix


def mean(l):
    return sum(l) / len(l)


def median(l):
    l.sort()
    mid = len(l) // 2
    return (l[mid] + l[~mid]) / 2


def harmonic_mean(l):
    sum = 0
    for i in l:
        if i == 0:
            continue
        sum += 1/i
    return len(l)/sum


def geometric_mean(l):
    return (reduce(lambda x, y: x * y, l)) ** (1 / len(l))


def min_filter(matrix, filter_size=3):
    size = len(matrix) - (filter_size // 2) * 2
    filtered_matrix = [[None] * size for _ in range(size)]

    for row in range(size):
        for col in range(size):
            submatrix = get_submatrix(matrix, row, col, filter_size)
            filtered_matrix[row][col] = min(map(min, submatrix))

    return filtered_matrix


def max_filter(matrix, filter_size=3):
    size = len(matrix) - (filter_size // 2) * 2
    filtered_matrix = [[None] * size for _ in range(size)]

    for row in range(size):
        for col in range(size):
            submatrix = get_submatrix(matrix, row, col, filter_size)
            filtered_matrix[row][col] = max(map(max, submatrix))

    return filtered_matrix


def simple_smoothing_filter(matrix, filter_size=3):
    size = len(matrix) - (filter_size // 2) * 2
    filtered_matrix = [[None] * size for _ in range(size)]

    for row in range(size):
        for col in range(size):
            submatrix = get_submatrix(matrix, row, col, filter_size)
            filtered_matrix[row][col] = mean(list(map(mean, submatrix)))

    return filtered_matrix


def median_filter(matrix, filter_size=3):
    size = len(matrix) - (filter_size // 2) * 2
    filtered_matrix = [[None] * size for _ in range(size)]

    for row in range(size):
        for col in range(size):
            submatrix = get_submatrix(matrix, row, col, filter_size)
            filtered_matrix[row][col] = median(reduce(lambda x, y: x + y, submatrix))

    return filtered_matrix


def harmonic_mean_filter(matrix, filter_size=3):
    size = len(matrix) - (filter_size // 2) * 2
    filtered_matrix = [[None] * size for _ in range(size)]

    for row in range(size):
        for col in range(size):
            submatrix = get_submatrix(matrix, row, col, filter_size)
            filtered_matrix[row][col] = harmonic_mean(reduce(lambda x, y: x + y, submatrix))

    return filtered_matrix


def geometric_mean_filter(matrix, filter_size=3):
    size = len(matrix) - (filter_size // 2) * 2
    filtered_matrix = [[None] * size for _ in range(size)]

    for row in range(size):
        for col in range(size):
            submatrix = get_submatrix(matrix, row, col, filter_size)
            filtered_matrix[row][col] = geometric_mean(reduce(lambda x, y: x + y, submatrix))

    return filtered_matrix


def apply_custom_filter(matrix, custom_filter):
    filter_size = len(custom_filter)
    size = len(matrix) - (filter_size // 2) * 2

    filtered_matrix = [[None] * size for _ in range(size)]

    for row in range(size):
        for col in range(size):
            submatrix = get_submatrix(matrix, row, col, filter_size)
            s = 0
            for i in range(filter_size):
                for j in range(filter_size):
                    s += custom_filter[i][j] * submatrix[i][j]
            filtered_matrix[row][col] = s

    return filtered_matrix


if __name__ == '__main__':
    matrix = input_matrix()

    padded_matrix = boundary_padding(matrix, type="zero_padding", boundary_size=1)
    print_matrix(padded_matrix, "Padded Matrix")

    print_matrix(matrix)

    pixel_replicated_matrix = boundary_padding(matrix, type="pixel_replication", boundary_size=1)
    print_matrix(pixel_replicated_matrix, "Pixel Replication Padded Matrix")

    min_filtered_matrix = min_filter(padded_matrix, filter_size=3)
    print_matrix(min_filtered_matrix, name="Matrix after Min Filter")

    max_filtered_matrix = max_filter(padded_matrix, filter_size=3)
    print_matrix(max_filtered_matrix, name="Matrix after Max Filter")

    simple_smoothing_filtered_matrix = simple_smoothing_filter(padded_matrix, filter_size=3)
    print_matrix(simple_smoothing_filtered_matrix, name="Matrix after Simple Smoothing Filter")

    median_filtered_matrix = median_filter(padded_matrix, filter_size=3)
    print_matrix(median_filtered_matrix, name="Matrix after Median Filter")

    harmonic_mean_filtered_matrix = harmonic_mean_filter(pixel_replicated_matrix, filter_size=3)
    print_matrix(harmonic_mean_filtered_matrix, name="Matrix after Harmonic Mean Filter")

    geometric_mean_filtered_matrix = geometric_mean_filter(pixel_replicated_matrix, filter_size=3)
    print_matrix(geometric_mean_filtered_matrix, name="Matrix after Geometric Mean Filter")

    print("\nEnter the custom filter:")
    custom_filter = input_matrix()
    custom_filtered_matrix = apply_custom_filter(padded_matrix, custom_filter)
    print_matrix(custom_filtered_matrix, name="Matrix after Custom Filter")
