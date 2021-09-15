package Heaps.Java;
class Mheap{
    int[] heap;
    int maxSize;
    int length=0;
    //initialize the heap data structure
    Mheap(int size){
        heap=new int[size];
        maxSize=size;
    }
    //get parent function
    int getParent(int index){
        return (index-1)/2;
    }
    //get left child
     int getLeftChild(int index){
        return (2*index+1);
    }
    //get right child
    int getRightChild(int index){
        return (2*index+2);
    }
    //insert
    void insert(int number){
        if(heap.length>=maxSize){
            System.out.println("Maximum heap size reached\n");
            return;
        }
    }
    //getMin O(1)
    int getMin() throws Exception{
        if(heap.length>0){
            return heap[0];
        }
        throw new Error("Heap Empty");
    }
    

}
class MinHeap{
    public static void main(String[] args){

    }
}