import math

T=int(input())

while T>0:
    N=int(input())
    nums1,nums2=[],[]
    if N==1:
        print("NO")
    elif N==2:
        print("NO")
    
    elif int(N/2)%2==0:
        l=1 
        r=N
        sum1=0
        sum2=0
        for i in range(int(N/2)):
            if l<=int(N/4):
                nums1.append(str(l))
                sum1+=l
                l+=1
            else:
                nums1.append(str(r))
                sum1+=r
                r-=1
        while l<=r:
            nums2.append(str(l))
            sum2+=l
            l+=1
          
        if sum1==sum2:
            print("YES")
            print(" ".join(nums1))
            print(" ".join(nums2))
        else:
            print("NO")
    else:
        l=1 
        r=N
        sum1=0
        sum2=0
        for i in range(int(N/2)-1):
            if l<=int(N/4):
                nums1.append(str(l))
                sum1+=l
                l+=1
            else:
                nums1.append(str(r))
                sum1+=r
                r-=1
        while l<=r:
            nums2.append(str(l))
            sum2+=l            
            l+=1

        x=(sum2-sum1)/2 
        if math.floor(x)==math.ceil(x):
            print("YES")
            nums1.insert(int(N/4),str(int(x)))
            nums2.remove(str(int(x)))
            print(" ".join(nums1))
            print(" ".join(nums2))
        else:
            print("NO")
        
    
    
    
    
    
    T-=1