
T=int(input())

while T>0:
    N,A,B,C=list(map(int,input().split()))
    maxDishes=B
    total_other_ingredient_choices=A+C
    if N>maxDishes:
        print("NO")
    
    elif total_other_ingredient_choices>=maxDishes:
        print("YES")
    elif total_other_ingredient_choices<maxDishes:
        dishes_made=total_other_ingredient_choices
        if dishes_made>=N:
            print("YES")
        else:
            print("NO") 
        
    T-=1