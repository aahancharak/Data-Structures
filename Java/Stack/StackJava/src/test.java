public class test {
    public static void main(String args[]){
     Stack stck=new Stack();
     for(int i=0;i<10;i++){
         stck.push(i);
     }
     for(int i=0;i<10;i++){
         System.out.println("Stack element"+":"+stck.pop());
     }
    }
}
