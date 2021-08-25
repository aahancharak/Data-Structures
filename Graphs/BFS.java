package Graphs;
import java.util.ArrayDeque;
import java.util.ArrayList;
class Graph{
  private int V;
  private ArrayList<ArrayList<Integer>>adj=null; 
   
 Graph(int V){
   this.V=V;
   adj=new ArrayList<>();
   //intialize V empty lists
   for(int i=0;i<V;i++){
       adj.add(new ArrayList<Integer>());
   }
 }

 //add a new element to adjacency lists
 void add(int V,int n){
     adj.get(V).add(n);

   
 }

 //BFD traversal
 void bfs(int start){
     boolean[] visited=new boolean[V];
     ArrayDeque<Integer> nodes=new ArrayDeque<>();
     nodes.push(start);

     while(!nodes.isEmpty()){
      Integer data=nodes.poll();
      visited[data]=true;
      System.out.println(data);
      ArrayList<Integer>lis=adj.get(data);
      for(Integer ele : lis){
          if(visited[ele]==true) continue;
          else{
            nodes.addLast(ele);
             
          }
      }
     }

                
    
    }

 
 }
public class BFS {
    public static void main(String[] args){
     Graph gs=new Graph(4);
     gs.add(2, 0);
     gs.add(2,3);
     gs.add(0,0);
     gs.add(0,2);
     gs.add(3,1);
     gs.add(1,1);
     gs.add(1,0);
     gs.bfs(2);
    }
}
