package Codechef.August21Long;

/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
 
        long nextLong() { return Long.parseLong(next()); }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
 
  
class SPCTRIPS
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		FastReader s=new FastReader();
		int T=s.nextInt();
		while(T>0){
		    int N=s.nextInt();
		    int total=0;
		    for(int i=1;i<=N;i++){
		        for(int j=1;j<=N;j++){
		            if(i%j==0) continue;
		            int c=i%j;
		            if(j%c==0) total++;
		            
		        }
		    }
		    System.out.println(total);
		    
		    
		    T--;
		}
	}
}
