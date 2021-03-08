def pprint(matrix):
    s = [[str(e) for e in row] for row in matrix]
    lens = [max(map(len, col)) for col in zip(*s)]
    fmt = "\t".join("{{:{}}}".format(x) for x in lens)
    table = [fmt.format(*row) for row in s]
    print("\n".join(table))

def multiply_matrices(X, Y):
    return [[sum(a * b for a, b in zip(X_row, Y_col)) % 26 for Y_col in zip(*Y)] for X_row in X]

def encode_plaintext(text):
    text = [i for i in text.upper() if i.isalpha()]
    return [[ord(i) - ord('A')] for i in text]

def decode_ciphertext(ct_vectors):
    ciphertext = ""
    for vector in ct_vectors:
        for i in vector:
            ciphertext += chr(i[0] + ord('A'))
    return ciphertext

def hill_cipher(encoded_text, key, n):
    l = len(encoded_text)
    if l % 2 != 0:
        encoded_text.append([25])
        l += 1

    print("\nKey: ")
    pprint(key)

    pt_vectors = [encoded_text[i:i+n] for i in range(0, l, n)]
    print("\nPlaintext as column vectors: ")

    for k, vector in enumerate(pt_vectors):
        print(f"\nBlock {k}:")
        pprint(vector)

    ct_vectors = []

    print("\nColumns after multiplication: ")

    for k, vector in enumerate(pt_vectors):
        result = multiply_matrices(key, vector)
        print(f"\nBlock {k}:")
        pprint(result)
        ct_vectors.append(result)

    return ct_vectors

if __name__ == '__main__':
    n = 2
    key = [[0] * n for i in range(n)]
    plaintext = input("Enter the plaintext: ")

    print("Enter the key matrix:")
    for i in range(n):
        for j in range(n):
            key[i][j] = int(input(f"Element at position {i}, {j}: "))

    pt = encode_plaintext(plaintext)
    print("Encoded plaintext: ", pt)

    ct_vectors = hill_cipher(pt, key, n)
    print("Ciphertext: ", decode_ciphertext(ct_vectors))
