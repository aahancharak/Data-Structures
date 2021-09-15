package Graphs.Topological_Sort;
import java.util.ArrayList;
import java.util.Stack;
//main class for Graph
class Graph{
    private int V;
    private ArrayList<ArrayList<Integer>>adj=null;
    private boolean[] found=null;
     private Stack<Integer>data=null;
    //constructor function
    Graph(int vertices){
      V=vertices;
      adj=new ArrayList<>();
      found=new boolean[V];
      data=new Stack<Integer>();
      //initialize V empty lists
      for(int i=0;i<V;i++){
          adj.add(new ArrayList<Integer>());
      }
    
    }
    //add a new directed edge to graph
    void add(int v,int n){
        adj.get(v).add(n);
    }
    //helper function for topological sort
    private void topHelper(int v){
        if(found[v]==true) return;
        //get the list for the vertex
        found[v]=true;
        ArrayList<Integer> adjVertices=adj.get(v);
        for(int ele :adjVertices){
             if(!found[ele]){
              topHelper(ele);
             }
        }
        //add the current vertex if not visited to the stack
        data.push(v);

    }
    //topological sort method
    ArrayList<Integer> topologicalSort(){
        ArrayList<Integer>topOrder=new ArrayList<Integer>();
         for(int i=0;i<V;i++){
             if(found[i]) continue;
             else topHelper(i);
         }
         //get the elements from the stack
         while(!data.isEmpty()){
             topOrder.add(data.pop());
         }
        return topOrder;
    }
}
public class Tsort {
    public static void main(String[] args){
       Graph g=new Graph(6);
       g.add(5, 2);
       g.add(5, 0);
       g.add(4, 0);
       g.add(4, 1);
       g.add(2, 3);
       g.add(3, 1);

       ArrayList<Integer>sortVals=g.topologicalSort();
       System.out.println("The topological sort for the given graph is :\n");
       for(int ele:sortVals){
           System.out.print(ele+"->");
       }
       System.out.println();
    }
}
