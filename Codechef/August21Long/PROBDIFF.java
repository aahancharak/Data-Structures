package Codechef.August21Long;

/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class PROBDIFF
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		try{
		    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine());
		while(T>0){
		    String problems=br.readLine();
		    String[] prob=problems.split(" ");
		    int different=0;
		    HashMap<Integer,Integer>map=new HashMap<Integer,Integer>();
		    for(String ele:prob){
		        int data=Integer.parseInt(ele);
		        if(!map.containsKey(data)){
		            different+=1;
		            map.put(data,1);
		        }
		        else{
		            map.put(data,map.get(data)+1);
		        }
		        
		    }
		    if(different==4) System.out.println(2);
		    else if(different==3) System.out.println(2);
		    else if(different==2){
		        int flag=0;
		       for(int ele:map.values()){
		           if(ele==3 || ele==1){
		               System.out.println(1);
		               flag=1;
		               break;
		           }
		       }
		       if(flag==0){
		           System.out.println(2);
		       }
		       
		    }
		    else if(different==1)System.out.println(0);
	
		    T--;
		}
		}catch(Exception e){}
	}
}
