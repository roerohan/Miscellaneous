def pad(inp, size):
    nos = size - len(inp) % size if len(inp)%size!=0 else size
    return bytes(inp) + (chr(nos)*nos).encode()

def depad(inp):
    return inp[:len(inp)-inp[len(inp)-1]] 

if __name__=="__main__":    
    inp = b"1234567890123456"
    print(inp)
    aa=pad(inp, 20)
    print(aa)
    print(depad(aa))
