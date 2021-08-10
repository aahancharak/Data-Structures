package TreeHeap;
import java.util.ArrayDeque;
import java.util.Deque;


//this will be the node
class Node{
    int val;
    Node left=null;
    Node right=null;
  Node(int val){
     this.val=val;
     this.left=null;
     this.right=null;
    }
}
class MaxHeap{
    //the root node
   Node root=null;
   MaxHeap(){
     this.root=null;
   }
   //return the maximum element
   int getMax() throws IllegalArgumentException{
       if(root==null) throw new IllegalArgumentException("Root not initialized");
       return root.val;
   }
   //print in-order
   void inorder(){
   traverseInOrder(this.root);
   System.out.println();
   } 
   void traverseInOrder(Node r){
      if(r==null) return;
       System.out.print(r.val+"->");
       if(r.left!=null){
           traverseInOrder(r.left);
       } 
       if(r.right!=null){
           traverseInOrder(r.right);
       }
    }
   //check is maxHeap
    boolean checkMaxHeap(Node root){
         if(root==null) return true;
         if(root.left!=null){
             if(root.val<root.left.val){
                 return false;
             }
         }
         if(root.right!=null){
             if(root.val<root.right.val){
                 return false;
             }
         }

         return checkMaxHeap(root.left) && checkMaxHeap(root.right);
   }
   //insert value into the heap
   void insert(int value){
       insertNode(value);
    
       boolean correct=checkMaxHeap(this.root);
       if(correct){
           System.out.println("Heap is correct");
       }
       else{
           System.out.println("Heap is not correct");
       }
   }
   //main insertion
   void insertNode(int value){

       if(this.root==null){
           this.root=new Node(value);
           return;
       }
       
       Deque<Node> queue=new ArrayDeque<Node>();
       queue.push(this.root);
       //traverse level order and find a node which has one child not given
       while(!queue.isEmpty()){
           Node info=queue.peek();
           queue.remove();
           if(info.left==null){
             info.left=new Node(value);
             return;
           }
           else queue.add(info.left);
            if(info.right==null){
               info.right=new Node(value);
               return;
           }
           else queue.add(info.right);
          
       }
       
   }

}
//main driver code
public class MaxHeapTreeRun {
    public static void main(String[] args){
        int[] arr={20,10,11,8,7,5,4};
        MaxHeap m=new MaxHeap();
        for(int i=0;i<arr.length;i++){
            
         m.insert(arr[i]);
        }
        m.inorder();
        int data=m.getMax();
        System.out.println("The maximum element is "+data);
    }
}
