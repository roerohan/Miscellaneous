def xor(a,b):
    return bytes([a[i]^b[i] for i in range(len(a))])

if __name__=="__main__":
    print(xor(input("Enter a: ").encode(),input("\nEnter b: ").encode()))
