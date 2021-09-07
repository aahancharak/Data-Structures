package Graphs.DFS;
import java.util.ArrayList;
class Graph{
    private int V;
    private ArrayList<ArrayList<Integer>>adjacencyList;
    private boolean[] visited;
//constructor function
Graph(int V){
    this.V=V;
    this.adjacencyList=new ArrayList<ArrayList<Integer>>();
    this.visited=new boolean[V];
    for(int i=0;i<V;i++){
        this.adjacencyList.add(new ArrayList<Integer>());
    }
}
//add vertex 
protected void add(int V,int n){
   adjacencyList.get(V).add(n);
}
//depth first search
protected void depthFirst(int vertex){
        if(visited[vertex]==true)return;
        else{
            System.out.println(vertex);
            visited[vertex]=true;
            //get vertex of adjacency list
            ArrayList<Integer>list=adjacencyList.get(vertex);
            for(int ele :list){
              depthFirst(ele);
            }
        }
}
}
public class DFS {
    public static void main(String[] args){
           Graph gs=new Graph(4);
           gs.add(0, 1);
           gs.add(0, 2);
           gs.add(1, 2);
           gs.add(2, 0);
           gs.add(2, 3);
           gs.add(3, 3);
          gs.depthFirst(2);

    }
}
