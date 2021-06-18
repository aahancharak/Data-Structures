import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class LinearSearch{
    static boolean  search(int arr[],int ele){
    for(int num:arr){
    if(num==ele) return true;
    }
    return false;
    }
}

class Linear{
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
   boolean found=LinearSearch.search(arr, ele);
  if(found)System.out.println("Element Found");
  else System.out.println("Element Not Found");

}
}