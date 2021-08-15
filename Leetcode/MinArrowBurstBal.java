package Leetcode;
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
class Solution2 {
    public int findMinArrowShots(int[][] points) {
        Integer[] start=new Integer[points.length];
        Integer[] end=new Integer[points.length];
        //add elements to the two arrays
        //O(n)
        for(int i=0;i<points.length;i++){
            start[i]=points[i][0];
            end[i]=points[i][1];
        }
        //initialize comparator object O(n)
        ArrayIndexComparator arr=new ArrayIndexComparator(end);
        //indices
        Integer[] indices=arr.createIndexArray();
        //sort the index array based on end array
        Arrays.sort(indices,arr); //O(nlog(n))
        int totalArrows=0;
        int endMax=-100;
        //apply activity selection O(n)
        for(int i=0;i<indices.length;i++){
            int star=start[indices[i]];
            int curEnd=end[indices[i]];
            if(i==0){
                totalArrows+=1;
                endMax=curEnd;
            }            
            else{
                if(star>endMax){
                    totalArrows++;
                if(curEnd>endMax) endMax=curEnd;

                }
            }
        }
        //total time complexity ~~ O(n*log(n))
        return totalArrows;
        
    }
}
public class MinArrowBurstBal {
    public static void main(String[] args){}
}
