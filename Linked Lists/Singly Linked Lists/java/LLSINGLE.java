import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
//class for linkedlist
class LinkedList{
    Node head;
    Node tail;
    int length;
    LinkedList(){
        this.head=null;
        this.tail=null;
    }
    //add a new node to the linked list
    void append(int value){
        this.length+=1;
        if(this.head==null && this.tail==null){
            this.head=new Node(value);
            this.tail=this.head;
            return;
        }
        
        Node temp=new Node(value);
        this.tail.next=temp;
        this.tail=temp;
        return;

    }
    //get the last element from the linked list
   Object getFirst(){
       if(this.head==null){
           return null;
       }
       return this.head.data;
    }

    //get the first element of the linked list
    Object getLast(){
      if(this.tail==null){
          return null;
      }
      return tail.data;
    }
    //print the linked list in a good format
    void printList(){
        if(this.head==null && this.tail==null){
            System.out.println("Linked List is empty :(");
            return;
        }
        Node cur=this.head;
        StringBuffer list=new StringBuffer();
        while(cur!=null){
            if(cur.next!=null){
            list.append(Integer.toString(cur.data)+"->");
            }
            else list.append(Integer.toString(cur.data));
            cur=cur.next;

        }
        System.out.println(list);
        return; 
    }
    //int[] get elements
    int[] getElements(){
        int[] data=new int[this.length];
        int index=0;
        Node cur=this.head;
        while(cur!=null){
          data[index]=cur.data;
          cur=cur.next;
          index++;
        }
        return data;
    }
    //remove first
    int removeFirst(){
        if(head==null){
            return 0;
        }
        else if(this.head.next==null){
            this.head=null;
            this.tail=null;
            this.length-=1;
            return 1;
        }
        Node cur=head;
        head=head.next;
        cur.next=null;
        cur=null;
        this.length-=1;
        return 1;
        
    }

    //remove last
    int removeLast(){
        if(this.tail==null){
            return 0;
        }
        Node cur=this.head;
        if(cur.next==null){
            this.tail=null;
            this.head=null;
            this.length-=1;
            return 1;
          
        }
        while(cur.next.next!=null){
            cur=cur.next;
        }
        this.tail=cur;
        cur=cur.next;
        this.tail.next=null;
        cur=null;
        this.length-=1;
        return 1;
    }

    //remove nth element
     boolean removeNth(int index){
         int i=0;
         Node cur=this.head;
         Node prev=null;
         if(this.length==0){
             return false;
         }
         while(i!=index){
          if(cur==null){
              return false;
          }
          prev=cur;
          cur=cur.next;
          i++;
         }
     
     if(i==0){
       if(this.head.next==null){
           this.head=null;
           this.tail=null;
       }
       else{
           head=head.next;
       }
     }
     else{
      if(cur.next==null){
          this.tail=prev;
          prev.next=null;
      }
      else{
          prev.next=cur.next;
          cur.next=null;
      }
     }
     this.length-=1;
     return true;

}
}

class Node{
    Node next;
    int data;
    Node(int number){
        this.next=null;
        this.data=number;
    }
}

//driver code
class LLSINGLE{
    public static void main(String[] args) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        LinkedList ls=new LinkedList();
        int result;
        Object ele;
      System.out.println("############# Welcome to the linked list programme. State your choice :");
      String choice="";
      while((!choice.equals("e"))||(choice.equals(""))){
          System.out.println("1>Add element to linked list\n2>Delete First element\n3>Print the Linked List\n4>Return linked list as array\n5>Delete Last Element\n6>Get First\n7>Get Last\n8>Remove nth index \n9>Exit");
          choice=br.readLine();
          switch(choice){
             
              //O(n)
              case "1":
              System.out.println("\nEnter the number to be added to ll");
              int data=Integer.parseInt(br.readLine());
              ls.append(data);
              ls.printList();
              System.out.println();
              break;
             //O(1)
              case "2":
              result=ls.removeFirst();
              System.out.println("\n");
              if(result==1) ls.printList();
              else System.out.println("List empty cannot remove first element");
              System.out.println("\n");
              break;
              
              case "3":
              System.out.print("\nThe linked list is :");
              ls.printList();
              System.out.println();
              break;

              case "4":
              int arr[]=ls.getElements();
              System.out.println("Elements of linked list are :");
              for(int el :arr){
                  System.out.print(el+" ");
              }
              System.out.println();
              break;

              case "5":
               result=ls.removeLast();
              System.out.println("\n");
              if(result==1) ls.printList();
              else System.out.println("List empty cannot remove last element");
              System.out.println("\n");
              break;

              case "6":
              ele=ls.getFirst();
              if(ele instanceof Integer) System.out.println("\n"+"First element is "+ele+"\n");
              else System.out.println("List is empty");
              break;

              case "7":
              ele=ls.getLast();
              if(ele instanceof Integer) System.out.println("\n"+"Last element is "+ele+"\n");
              else System.out.println("\nList is empty");
              break;

              case "8":
              System.out.println("\nEnter the index you want to remove");
              int index=Integer.parseInt(br.readLine());
              boolean removed=ls.removeNth(index);
              if(removed){
                  System.out.println("\n");
                  ls.printList();
              }
              else System.out.println("\n Couldnt remove the element please provide valid index\n");
              break;

              case "9":
              choice="e";
              break;
              

              default:
              System.out.println("\nEnter valid choice \n");
          }

      }
    }
}