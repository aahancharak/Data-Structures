import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
class Stack{
    int[] stack;
    int last;
    int length;
    //initialize stack array
Stack(int n){
 this.stack=new int[n];
 this.last=-1;
 this.length=n;
}
//O(1)
//pop out of the stack
Object Pop(){
   if(this.last<0){
       return false;
   }
   int ele=this.stack[this.last];
   this.last-=1;
   return ele;

}
//O(n)
//push into the stack
boolean Push(int ele){
 if(this.last==this.length-1){
  return false;
 }
  this.last+=1;
  this.stack[this.last]=ele;
  return true;
}
//O(n)
//print stack
void print(){
    StringBuffer st=new StringBuffer();
    for(int ele:this.stack){
        st.append(ele+" ");
    }
    if(this.stack.length>0){
        System.out.println(st);
    }
    else System.out.println("\nStack is empty\n");
}
}

//runner programme
class StackArray{
 public static void main(String[] args) throws IOException{
     BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
     System.out.println("\nEnter the stack size\n");
     int size=Integer.parseInt(br.readLine());
     Stack st=new Stack(size);
     String choice="";
     while(!choice.equals("4")){
        System.out.println("\nEnter choice\n\n1>Push into stack\n2>Pop\n3>Print stack\n4>Exit\n");

     choice=br.readLine();

     switch(choice){
         case "1":
         System.out.println("\nEnter the number to be added to the stack");
         size=Integer.parseInt(br.readLine());
         boolean data=st.Push(size);
         if(data){
            System.out.println("\nPushed. Stack is :\n");
            st.print();
            System.out.println("\n");
         }
         else{
             System.out.println("\nStack overflow\n");
         }
         break;
         case "2":
         Object ele=st.Pop();
         if(ele instanceof Integer){
             System.out.println("\n"+ele+" Popped outta the stack\n");
         }
         else{
             System.out.println("\nStack underflow\n");
         }
         break;
         case "3":
         System.out.println("\n");
         st.print();
         System.out.println("\n");
         break;
         case "4":
         break;
         
         default:
         System.out.println("\nEnter a valid choice\n");
     }
    }
 }
}