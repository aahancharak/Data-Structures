package GFG.Greedy;
import java.util.Comparator;
import java.util.Arrays;
class Item{
    int value;
    int weight;
    Item(int val,int weight)
    {
        this.value=val;
        this.weight=weight;
    }
}
class ArrayIndexComparator2 implements Comparator<Integer>{
    Double[] arr;
    ArrayIndexComparator2(Double[]array){
        this.arr=array;
    }
    Integer[] generateIndices(){
        Integer[] indices=new Integer[arr.length];
        for(int i=0;i<arr.length;i++){
            indices[i]=i;
        }
        return indices;
        }
     @Override
     public int compare(Integer index1,Integer index2){
         return arr[index1].compareTo(arr[index2]);
     }
}
class Solution3
{
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) 
    {
        // Your code here
        int[] profits=new int[arr.length];
        int[] weight=new int[arr.length];
        Double[] profWeight=new Double[arr.length];
        //initializing arrays
        for(int i=0;i<arr.length;i++){
            profits[i]=arr[i].value;
            weight[i]=arr[i].weight;
            profWeight[i]=new Double((arr[i].value/(double)arr[i].weight));
        }
        //indices array
        ArrayIndexComparator2 comparator=new ArrayIndexComparator2(profWeight);
        Integer[] indices=comparator.generateIndices();
        Arrays.sort(indices,comparator);
       
        
        int totalWeightTaken=0;
        double totalProfit=0;
        for(int i=indices.length-1;i>=0;i--){
            int index=indices[i];
            if(totalWeightTaken==W)break;
            else if(weight[index]<=(W-totalWeightTaken)){
                totalWeightTaken+=weight[index];
                totalProfit+=(profWeight[index]*weight[index]);
            }
            else{
                int weightLeft=W-totalWeightTaken;
                 totalWeightTaken+=weightLeft;
                 totalProfit+=(profWeight[index]*weightLeft);
            }
        }
        return totalProfit;
        
        
    }
}

public class FracKnapSack {
    public static void main(String[] args){}
}
