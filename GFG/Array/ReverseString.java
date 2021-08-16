package GFG.Array;
// { Driver Code Starts
//Initial Template for Java






//User function Template for Java


class Reverse
{
    // Complete the function
    // str: input string
    public static String reverseWord(String str)
    {
        // Reverse the string str
         String[] arr=str.split("");
         int start=0;
         int end=arr.length-1;
         while(start<end){
             String temp=arr[start];
             arr[start]=arr[end];
             arr[end]=temp;
             start++; end--;
         }
         str="";
         for(String ele : arr){
             str+=ele;
         }
         return str;
    }
}
public class ReverseString {
    public static void main(String[] args){}
}
