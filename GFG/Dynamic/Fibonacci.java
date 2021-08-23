package GFG.Dynamic;
import java.util.HashMap;
class Solution {
    HashMap<Integer,Integer>memo=null;
    Solution(){
        this.memo=new HashMap<Integer,Integer>();
        }
    
    public int fib(int n) {
       if(memo.containsKey(n)){
           return memo.get(n);
       }    
        else if(n==2 ||n==1) return 1;
        else if(n==0) return 0;
        else{
            memo.put(n,(fib(n-1)+fib(n-2)));
        }
        return memo.get(n);
    }
}


public class Fibonacci{
    public static void main(String[] args){

    }
}