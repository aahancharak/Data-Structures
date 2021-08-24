/*
We will think of this solution as starting from nth stair and going down to the ground below stair.
Let's say n=6
6->5->4->3->2->1->0 , as the number of ways we can go from 0-6 is the same as going from 6-0
0 is the position we start from
from 6, we can either go to 5 or to 4. which divides the solution into two sub-problems i.e number of
ways to go down from 5th floor and number of ways to go down from 4th floor
       6
    ---- ------
    |         |
    5         4
so if we add number of ways to go down from 5th floor and number of ways to go down from 4th floor, we can essentially calculate the number of ways we go down from 6th floor.

We will use the standard dynamic programming memoization approach to achieve this.
*/
package GFG.Dynamic;
import java.util.HashMap;
class Solution2 {
    //intialize the memo map
    HashMap<Integer,Integer> memo=null;
    Solution2(){
        memo=new HashMap<Integer,Integer>();
    }
    public int climbStairs(int n) {
        //check if memo has the solution
        if(memo.containsKey(n)){
            return memo.get(n);
        }
        //number stair number ==1 => 1 way to go to ground 1->0
        if(n==1) return 1;
        //no stairs mean that we can't go down or up, so no way
        else if(n==0) return 0; 
        
        //another base case is if n==2, two ways 2->1->0 or 2->0
        else if(n==2) return 2;
        
        //so, now base cases are complete, lets recurse throgh next solutions
        else{ 
            memo.put(n,(climbStairs(n-1)+climbStairs(n-2)));
            
        }
        return memo.get(n);
        
        
    }
}

public class ClimbingStairs {
    public static void main(String[] args){}
}
