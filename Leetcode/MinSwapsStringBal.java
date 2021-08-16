package Leetcode;

class Solution3 {
    public int minSwaps(String s) {
        int start=0;
        int end=s.length()-1;
        String[] arr=s.split("");
        int opening=0;
        int swaps=0;
        while(start<end){
            if(arr[start].equals("[")){
                opening++;
              
            }
            else if(arr[start].equals("]") && opening>0){
                opening--;
              
            }
            else{
                while(!arr[end].equals("[")){
                    end--;
                }
                arr[start]="[";
                arr[end]="]";
                end--;
                swaps++;
                opening++;
                
            }
               start++;
        }
        System.out.println("end");
        return swaps;
    }
}
public class MinSwapsStringBal {
  public static void main(String[] args){}  
}
