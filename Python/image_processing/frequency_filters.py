from math import *
import numpy as np

M = 4
N = 4


def D(u, v):
    return sqrt((u - M//2) ** 2 + (v - N//2) ** 2)


def ideal_low_pass_filter(d0):
    global M, N
    H = np.zeros(shape=(M, N))
    for u in range(M):
        for v in range(N):
            if D(u, v) <= d0:
                H[u][v] = 1

    print(f"\nIdeal low pass filter matrix for d0={d0} and M=N={M}:")
    print(H)


def butterworth_low_pass_filter(d0, n):
    global M, N
    H = np.zeros(shape=(M, N))
    for u in range(M):
        for v in range(N):
            H[u][v] = 1/(1 + (D(u, v) / d0) ** (2*n))

    print(
        f"\nButterworth low pass filter matrix for d0={d0}, n={n} and M=N={M}:")
    print(H)


def gaussian_low_pass_filter(d0):
    global M, N
    H = np.zeros(shape=(M, N))
    for u in range(M):
        for v in range(N):
            x = - (D(u, v) ** 2) / (2 * (d0 ** 2))
            H[u][v] = e ** x

    print(f"\nGaussian low pass filter matrix for d0={d0} and M=N={M}:")
    print(H)


def ideal_high_pass_filter(d0):
    global M, N
    H = np.zeros(shape=(M, N))
    for u in range(M):
        for v in range(N):
            if D(u, v) > d0:
                H[u][v] = 1

    print(f"\nIdeal high pass filter matrix for d0={d0} and M=N={M}:")
    print(H)


def butterworth_high_pass_filter(d0, n):
    global M, N
    H = np.zeros(shape=(M, N))
    for u in range(M):
        for v in range(N):
            if D(u, v) == 0:
                continue
            H[u][v] = 1/(1 + (d0 / D(u, v)) ** (2*n))

    print(
        f"\nButterworth high pass filter matrix for d0={d0}, n={n} and M=N={M}:")
    print(H)


def gaussian_high_pass_filter(d0):
    global M, N
    H = np.zeros(shape=(M, N))
    for u in range(M):
        for v in range(N):
            x = - (D(u, v) ** 2) / (2 * (d0 ** 2))
            H[u][v] = 1 - (e ** x)

    print(f"\nGaussian high pass filter matrix for d0={d0} and M=N={M}:")
    print(H)


def dft(arr):
    dftarr = np.fft.fft2(arr)
    print("Array after DFT:")
    print(dftarr)
    return dftarr


def idft(arr):
    idftarr = np.fft.ifft2(arr)
    print("Array after IDFT:")
    print(idftarr)
    return idftarr


def mult(arr1, arr2):
    l = len(arr1)
    res = np.zeros(size=(l, l))
    for i in range(l):
        for j in range(l):
            res[i][j] = arr1[i][j] * arr2[i][j]

    return res


if __name__ == '__main__':
    M = N = int(input("Enter the size of the matrix: "))
    d0 = float(input("Enter the value of D0: "))
    ideal_low_pass_filter(d0)
    butterworth_low_pass_filter(d0, n=1)
    gaussian_low_pass_filter(d0)

    ideal_high_pass_filter(d0)
    butterworth_high_pass_filter(d0, n=1)
    gaussian_high_pass_filter(d0)
