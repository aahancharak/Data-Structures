package GFG.Stacks;
import java.util.*;
class Solution
{
    //Function to find the next greater element for each element of the array.
    public static long[] nextLargerElement(long[] arr, int n)
    { 
        // Your code here
        Stack<Long>st=new Stack<Long>();
        Stack<Integer>indices=new Stack<Integer>();
        long[] data=new long[arr.length];
        
        
        for(int i=0;i<arr.length;i++){
            if(i==0){
                st.push(arr[i]);
                indices.push(i);
            }
           
            else{
                while(!st.isEmpty()){
                    if(arr[i]>st.peek()){
                        data[indices.pop()]=arr[i];
                        st.pop();
                       
                    }
                    else if(arr[i]<=st.peek()){break;}
                }
                st.push(arr[i]);
                indices.push(i);
            }
        }
        while(!st.isEmpty()){
            data[indices.pop()]=-1;
            st.pop();
        }
        data[arr.length-1]=new Long(-1);
        return data;
       
    } 
}
public class NextLargest {
    public static void main(String[] args){}
}
