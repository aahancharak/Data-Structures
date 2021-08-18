package GFG.Greedy;
import java.util.*;
class ArrayComparator implements Comparator<Integer>{
    Integer[] array;
 
    ArrayComparator(Integer[] arr){
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
 class Job{
     int index;
     int deadline;
     int profit;
     Job(int  index,int deadline,int profit){
         this.index=index;
         this.deadline=deadline;
         this.profit=profit;
     }
 }
class Solution2
{
    //Function to find the maximum profit and the number of jobs done.
    int[] JobScheduling(Job arr[], int n)
    {
         Integer[] deadlines=new Integer[arr.length];
         Integer[] profit=new Integer[arr.length];
         for(int i=0;i<n;i++){
             deadlines[i]=arr[i].deadline;
             profit[i]=arr[i].profit;
         }
         ArrayComparator comparator=new ArrayComparator(profit);
         Integer[] indices=comparator.createIndexArray();
         Arrays.sort(indices,comparator);
         
         //now job scheduling algo
         HashMap<Integer,Boolean>slots=new HashMap<Integer,Boolean>();
         int pro=0;
         int selected=0;
         for(int i=indices.length-1;i>=0;i--){
             int index=indices[i];
             int deadline=deadlines[index];
             for(int j=deadline-1;j>=0;j--){
                 if(!slots.containsKey(j)){
                     slots.put(j,true);
                     pro+=profit[index];
                     selected++;
                     break;
                 }
             }
         }
         int[] data=new int[2];
         data[0]=selected;
         data[1]=pro;
         return data;
    }
}
public class JobSequencing {
    public static void main(String[] args){}
}
