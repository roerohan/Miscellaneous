a = list(map(int, input("Enter nos: ").split()))
n=int(input("Enter number to be searched: "))

first=0
last=len(a)-1
while first<=last:
    mid=(first+last)//2
    if a[mid]==n:
        print("Found at position:",mid+1)
        exit()
    else:
        if n<a[mid]:
            last=mid-1
        else:
            first=mid+1
print("Not found")