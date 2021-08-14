package Codechef.August21Long;
/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class CHFINVNT
	

{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine());
		while(T>0){
		    String input=br.readLine();
		    String[] inputs=input.split(" ");
		    int N=Integer.parseInt(inputs[0]);
		    int p=Integer.parseInt(inputs[1]);
		    int K=Integer.parseInt(inputs[2]);
		    int totalDays=0;
            int moduloPrev=p%K-1;
            int numberEleMaxStep=((int)Math.floor((N-1)/K))*K;
            numberEleMaxStep=N-1-K;
            if(moduloPrev+1>numberEleMaxStep+1){
                totalDays+=((numberEleMaxStep+1)*((int)Math.floor((N-1)/K)+1)+(moduloPrev-numberEleMaxStep)*((int)Math.floor((N-1)/K)));
            }
            else{
                totalDays+=(moduloPrev+1)*((int)Math.floor((N-1)/K)+1);
            }
            for(int i=moduloPrev+1;i<N;i++){
                totalDays+=1;
                if(i==p){
                    break;
                }
            }
            System.out.println(totalDays);
		    
		    
		    T--;
		}
	}
}
