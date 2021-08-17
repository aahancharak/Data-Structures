package GFG.Array;

public class MoveNegativeToLeft {
    static void  printArray(int[]arr){
        for(int ele:arr){
            System.out.print(ele+" ");
        }
        System.out.println();
    }
     static void rearrange(int[] arr){
          int minPositive=Integer.MAX_VALUE;
          int minPosIndex=-1;
          for(int i=0;i<arr.length;i++){
              if(arr[i]<=minPositive && arr[i]>=0){
                minPositive=arr[i];
                minPosIndex=i;
              }
          }
          //make this element the pivot
          int pivot=minPosIndex;
          int l=0;
          int r=arr.length-1;
          while(l<r){
              while((arr[l]<arr[pivot] || l==pivot) && l<arr.length){
                  l++;
              }
              while(arr[r]>arr[pivot] && r>0){
                r--;
              }
              if(l<r){
                int temp=arr[l];
                arr[l]=arr[r];
                arr[r]=temp;
              }
          }
          int temp=arr[pivot];
          arr[pivot]=arr[r];
          arr[r]=temp;
          
     }
    public static void main(String[] args){
        int arr[] = { 9,8,7,6,5,4,0,-1,-2,-3};
        rearrange(arr);
        printArray(arr);

        
    }
}
