package GFG.Greedy;
import java.util.*;

class ArrayIndexComparator implements Comparator<Integer>{
    Integer[] array;
 
    ArrayIndexComparator(Integer[] arr){
        this.array=arr;
    }
    Integer[] createIndexArray(){
        Integer[] indices=new Integer[array.length];
        for(int i=0;i<array.length;i++){
            indices[i]=i;
        }
        return indices;
     }
     @Override
     public int compare(Integer index1,Integer index2){
       return array[index1].compareTo(array[index2]);
     }
 
 }
 class Solution
{
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    public static int activitySelection(int start[], int end[], int n)
    {    int total=0;
        // add your code here
        Integer[] arr=new Integer[start.length];
        int index=0;
        for(int ele:end){
            arr[index]=ele;
            index++;
        }
       ArrayIndexComparator arrs=new ArrayIndexComparator(arr);
       Integer[] indices=arrs.createIndexArray();
       Arrays.sort(indices,arrs);
       int completeTime=0;
        for(int i=0;i<indices.length;i++){
            if(i==0){
                total+=1;
                completeTime=end[indices[i]];
            }
            else{
                int ind=indices[i];
                if(completeTime>=start[ind]) continue;
                else{total+=1;
                    completeTime=end[ind];
                    
                }
            }
        }
    
        return total;
        
    }
}
public class ActivitySelection {
    public static void main(String[] args){

    }
}
