def key_stream_algo(key):
    len_key = len(key)

    S = [i for i in range(256)]

    j = 0
    for i in range(256):
        j = (j + S[i] + key[i % len_key]) % 256
        S[i], S[j] = S[j], S[i]

    return S

def pseudo_random_generation_algo(S):
    i = 0
    j = 0
    while True:
        i = (i + 1) % 256
        j = (j + S[i]) % 256

        S[j], S[i] = S[i], S[j]
        K = S[(S[i] + S[j]) % 256]

        yield K

def RC4(key):
    S = key_stream_algo(key)
    return pseudo_random_generation_algo(S)

def encrypt(payload, key):
    keystream = RC4(key)
    return bytes([ord(i) ^ next(keystream) for i in payload])

def decrypt(ciphertext, key):
    keystream = RC4(key)
    return bytes([(i ^ next(keystream)) for i in ciphertext])

print('RC4 Encryption and Decryption:')
choice = input('1. Encrypt\n2. Decrypt\n3. Exit\nEnter your choice: ')

if (choice == '3'):
    exit(0)

key = [ord(i) for i in input('Enter the key: ')]

if (choice == '1'):
    payload = input('Enter the payload: ')
    ciphertext = encrypt(payload, key)
    print()
    print('Encrypted text: ' + ciphertext.hex())

elif (choice == '2'):
    ciphertext = bytes.fromhex(input('Enter the ciphetext: '))
    plaintext = decrypt(ciphertext, key)
    print()
    print('Decrypted text: ' + plaintext.decode())

