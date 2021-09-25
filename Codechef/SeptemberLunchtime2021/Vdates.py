# cook your dish here
T=int(input())
while T>0:
    D,L,R=list(map(int,input().split()))
    if D>=L and D<=R:
        print("Take second dose now")
    elif D<L:
        print("Too Early")
    elif D>R:
        print("Too Late")
    T-=1