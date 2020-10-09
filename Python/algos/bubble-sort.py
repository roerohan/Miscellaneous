a=list(map(int,input("Enter nos:").split()))

for l in range(len(a)-1,0,-1):
    for i in range(l):
        if a[i]>a[i+1]:
            a[i],a[i+1]=a[i+1],a[i]

for i in range(len(a)):
    print(a[i],end=' ')