package Codechef.August21Long;

/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class OLYRANK
{
	public static void main (String[] args) throws java.lang.Exception
	{ 
		// your code goes here
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine());
		while(T>0){
		    String input=br.readLine();
		    String[] arr=input.split(" ");
		    int total1=0;
		    int total2=0;
		    int idx=0;
		    for(String ele:arr){
		        int num=Integer.parseInt(ele);
		        if(idx<=2)total1+=num;
		        else total2+=num;
		        idx+=1;
		    }
		    if(total1>total2) System.out.println("1");
		    else System.out.println("2");
		    T--;
		}
	}
}
