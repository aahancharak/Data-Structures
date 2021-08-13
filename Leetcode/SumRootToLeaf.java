package Leetcode;
//worst case time complexity will be
// O(height*height) one height to traverse whole tree other for looping through the elements in list to get sum of current path.
import java.util.ArrayList;
class TreeNode{
TreeNode left;
TreeNode right;
int val;
    TreeNode(int val){
        this.val=val;
        this.left=null;
        this.right=null;
    }
}
class Solution {
 //This array list will store final sum values
/*
arr=[123,122,22];
sum=123+122+22;
*/
    ArrayList<Integer>arr=new ArrayList<Integer>();
    public int sumNumbers(TreeNode root) {
//no root sum =0
        if(root==null) return 0;
//call get sum on the root
        getSum(root,new ArrayList<Integer>());
//intial sum
        int sum=0;
//calculate the total sum by looping through the arr array
        for(int ele:arr){
            sum+=ele;
        }
        return sum;
    }
    
//this is the main magic function
    public void getSum(TreeNode root,ArrayList<Integer>numbers){
        if(root==null) return;
        //add root value to the numbers list
        numbers.add(root.val);
        //if leaf node,calculate sum
        if(root.left==null &&root.right==null){
            int sum=0;
            int place=(int)Math.pow(10,numbers.size()-1);
            for(int ele:numbers){
                sum+=ele*place;
                place/=10;
            }
            //append current path sum to the list
            arr.add(sum);
            return;
        }
        //if right is null
        else if(root.left==null && root.right !=null){
            //append the left subtree to path and keep traversing
           getSum(root.right,new ArrayList<Integer>(numbers));
            return;
        }
        //if left is null
        else if(root.right==null && root.left!=null){
                //append the right subtree to path and keep traversing
            getSum(root.left,new ArrayList<Integer>(numbers));
            return ;
        }
        //if both are not null
        else if(root.left!=null && root.right!=null){
            //first traverse left subtree
       getSum(root.left,new ArrayList<Integer>(numbers));
            //then traverse right subtree
       getSum(root.right,new ArrayList<Integer>(numbers));
            return;

        }
        return;
    }
}
