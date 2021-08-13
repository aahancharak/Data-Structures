package Algorithms.Searching.java;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Binary{
    static boolean search(int[] arr,int ele,int low,int high){
        int mid=(int)Math.floor((low+high)/2);
        System.out.println(mid);
      if(low==high){
     if(arr[mid]==ele)return true;
     return false;
      }
     if(arr[mid]==ele)return true;
     else if(ele<arr[mid]){
        return search(arr, ele, low, mid-1);
     }
     else if(ele>arr[mid]){
         return search(arr,ele,mid+1,high);
     }
return true;
    }
}

public class BinarySearch {
 public static void main(String[] args) throws IOException{
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    System.out.println("Enter the array : ");
    String[] arrStr=br.readLine().split(" ");
    int[] arr=new int[arrStr.length];
    int index=0;
    for(String s:arrStr){
     arr[index]=Integer.parseInt(s);
     index++;
    }
    System.out.println("Enter the number you want to search : ");
    int ele=Integer.parseInt(br.readLine());
    boolean found=Binary.search(arr,ele,0,arr.length-1);
   if(found)System.out.println("Element Found");
   else System.out.println("Element Not Found");
 }
}
