package Leetcode;
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
class Solution4 {
    public int eraseOverlapIntervals(int[][] intervals) {
        //start array
        Integer[] starts=new Integer[intervals.length];
        //end array
        Integer[] ends=new Integer[intervals.length];
        //O(n)
        for(int i=0;i<intervals.length;i++){
            starts[i]=intervals[i][0];
            ends[i]=intervals[i][1];
        }
        ArrayComparator comp=new ArrayComparator(ends);
        //indices
        Integer[] indices=comp.createIndexArray();
        //sort indices
        Arrays.sort(indices,comp);//O(nlog(n))
        int totalRemoval=0;
        int curEnd=0;
        //iterate through sorted indices and include those in the solution
        //O(n)
        for(int i=0;i<indices.length;i++){
            int index=indices[i];
            if(i==0){
                curEnd=ends[index];
            }
            else{
                if(starts[index]<curEnd){
                    totalRemoval++;
                }
                else if(starts[index]>=curEnd){
                    curEnd=ends[index];
                }
            }
        }
        return totalRemoval; //O(n*log(n)+n) ~~O(nlogn)
        
    }
}
public class NonOverlapIntervals {
    public static void main(String[] args){}
}
