public class Stack {
    private int stack[]=new int[10];
    private int top;
    Stack(){
        top=-1;
    }
    void push(int data){
        if(top>=9){
            System.out.println("\nStack overflow\n");
        }
        else{
            this.stack[++top]=data;
        }
    }
    int pop(){
        if(top<0){
            System.out.println("\nStack underflow\n");
            return 0;
        }
        else{
            return this.stack[top--];
        }
    }

}
