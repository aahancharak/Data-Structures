class Linear:
    @staticmethod
    def search(arr,ele):
        for num in arr:
            if num==ele:
                return True
        return False 



if __name__=='__main__':
    arr=list(map(int,input("Enter the array : ").split(" ")))
    ele=int(input("Enter the element you want to search: "))
    found=Linear.search(arr,ele)
    if found:
        print("Element found")
    else:
        print("Element not found")