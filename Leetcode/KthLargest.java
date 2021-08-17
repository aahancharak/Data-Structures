package Leetcode;
class Solution5 {
    public int findKthLargest(int[] nums, int k) {
             
        return Sol.kthSmallest(nums,0,nums.length-1,k);
    }
    
}

class Sol{
  
    public static int kthSmallest(int[] arr, int l, int r, int k) 
    {    
        if(k>0 && k<=arr.length){
           
            int p=partition(arr,l,r);
           
            if(p+1==k) return arr[p];
            else if(p+1>k){
                return kthSmallest(arr,l,p-1,k);
            }
            else if(p+1<k){
                return kthSmallest(arr,p+1,r,k);
            }
        }
        return -1;
        
        
    } 
    public static int partition(int [] arr,int l,int h){
        if(l>=h) return l;
        int x=arr[h];
        int i=l;
        int j=h;
        while(i<j){
            while(arr[i]>x && i<h){
                i++;
            }
            while(arr[j]<=x &&j>l){
                j--;
            }
            if(i<j){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        if(arr[i]<arr[h]){
        int temp=arr[i];
        arr[i]=arr[h];
        arr[h]=temp;
        return i;
        }
        return h;
        
        
    }
    
}
class KthLargest{
    public static void main(String[] args){}
}