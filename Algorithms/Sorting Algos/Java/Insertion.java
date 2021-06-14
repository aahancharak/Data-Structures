import java.util.Arrays;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
class InsertionSort{
  static int[]Sort(int[] arr,int flag){
       int[] arr2=Arrays.copyOf(arr, arr.length);
       switch(flag){
           //case 1 for ascending
           case 0:
           for(int i=1;i<arr2.length;i++){
            int curEle=arr2[i];
            int j=i-1;
            while(j>=0 && arr2[j]>curEle){
                arr2[j+1]=arr2[j];
                j--;
   
            }
            arr2[j+1]=curEle;
          }
          break;
          
          // case 1 for descending
          case 1:
          for(int i=0;i<arr2.length;i++){
            int j=i-1;
             int curEle=arr2[i];
            while(j>=0 && arr2[j]<curEle){
                arr2[j+1]=arr2[j];
                j--;
            }
            arr2[j+1]=curEle;
          }
          break;

       }
      

       return Arrays.copyOf(arr2, arr2.length);
  }
}

class Insertion{
    public static void main(String[] args) throws IOException{
       BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
  System.out.println("Enter the elements of the array : ");
  System.out.println();
    String[] strArr=br.readLine().split(" ");
    System.out.println("Enter 0 for ascending 1 for descending ");
    int choice=Integer.parseInt(br.readLine());
    int[] arr=new int[strArr.length];
    int index=0;
    for(String s:strArr){
        arr[index]=Integer.parseInt(s);
        index++;

    }
    arr=InsertionSort.Sort(arr,choice);
    System.out.println("The resultant array is given by : ");
    for(int ele : arr){
        System.out.print(ele+" ");
    }
    System.out.println();
    }
}