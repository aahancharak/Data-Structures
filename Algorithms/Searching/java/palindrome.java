package Algorithms.Searching.java;
class Sol {
    public int removeDuplicates(int[] nums) {
        if(nums.length<0) return 0;
        int curEle=nums[0];
        int index=1;
        int k=1;
        for(int i=1;i<nums.length;i++){
            if(nums[i]!=curEle) {
                nums[index]=nums[i];
                curEle=nums[i];
                index++;
                k++;
            }
        }
        return k;
    }
}


class Run{
    public static void main(String[] args){
        Sol s=new Sol();
        int[] arr={1,2,3,4,5,6,7,8,8,9,9,9,9,10,10,10};
        System.out.println(s.removeDuplicates(arr));
       for(int ele:arr){
           System.out.println(ele);
       }
    }
}