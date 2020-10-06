a=list(map(int,input("Enter nos: ").split()))
for i in range(len(a)):
    index=i
    for j in range(i+1,len(a)):
        if a[index]>a[j]:
            index=j
    a[i],a[index]=a[index],a[i]

for i in range(len(a)):
    print(a[i],end=' ')