package Algorithms.Searching.java;

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int i=0;
        int j=0;
        int index=0;
        int[] resArr=new int[nums1.length+nums2.length];
        while(i<nums1.length || j<nums2.length){
            if(j>=nums2.length){
               resArr[index]=nums1[i];
               i++;
            }
            else if(i>=nums1.length){
                resArr[index]=nums2[j];
                j++;
            }
            else if(nums1[i]<nums2[j]){
                resArr[index]=nums1[i];
                i++;
            }
            else if(nums1[i]>=nums2[j]){
                resArr[index]=nums2[j];
                j++;
            }


            index++;
        }
        double median=0;

        if(resArr.length>0){
        index=(int)resArr.length/2;
        if(resArr.length%2==0){
          median=((resArr[index-1]+resArr[index])/2.0);
        }
        else{
            median=resArr[index];
        }
    }

        return median;
    }
}
public class TestClass {
    public static void main(String args[] ) throws Exception {
        Solution sc=new Solution();
        int[] arr1={2};
        int[] arr2={};
        double d=sc.findMedianSortedArrays(arr1, arr2);
        System.out.println(d);
    
     
    }
}
