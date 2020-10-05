from base64 import b64decode
from Crypto.Cipher import AES
from pad import pad,depad

def xor(a,b):
    a,b=list(a),list(b)
    for i in range(len(a)):
        a[i]=a[i]^b[i]
    return bytes(a)

def ecb_enc(pt,key):
    return(AES.new(key,AES.MODE_ECB).encrypt(pt))

def ecb_dec(ct,key):
    return(AES.new(key,AES.MODE_ECB).decrypt(ct))

def cbc_enc(pt,key,iv):
    ct=b''
    padded = pad(pt,16)
    for i in range(len(padded)//16):
        send2=xor(padded[i*16: (i+1)*16],iv)
        iv=ecb_enc(send2,key)
        ct+=iv
    return ct

def cbc_dec(ct,key,iv):
    pt=b''
    for i in range(len(ct)//16):
        send2 = ecb_dec(ct[i*16:(i+1)*16],key)
        temp,iv = xor(send2,iv),ct[i*16:(i+1)*16]
        pt+=temp
    pt=depad(bytes(pt))
    return bytes(pt)

inp=open('10.txt','rb').read()
key = b'YELLOW SUBMARINE'
iv = b'\x00'*AES.block_size

pt=b'12345ff67dfg1230'
ct = cbc_enc(pt,key,iv)
print(ct)

print(cbc_dec(ct,key,iv))
