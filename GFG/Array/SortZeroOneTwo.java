package GFG.Array;
class SortZeroOneTwoArray
{
    public static void sort012(int a[], int n)
    {
        // code here 
        int numZero=0;
        int numOne=0;
        for(int i=0;i<a.length;i++){
            if(a[i]==0) numZero++;
            else if(a[i]==1)numOne++;
        }

        for(int i=0;i<a.length;i++){
            if(numZero>0){a[i]=0;numZero--;}
            else if(numOne>0){a[i]=1;numOne--;}
            else a[i]=2;
        }
    }
}
public class SortZeroOneTwo {
    public static void main(String[] args){

    }
}
