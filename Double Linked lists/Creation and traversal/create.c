#include <stdio.h>
#include<malloc.h>
struct node{
  int data;
  struct node*prev;
  struct node*next;
}*head;
void create(int n){
  struct node*newNode,*prevNode;
  head=(struct node*)malloc(sizeof(struct node));
  if(head !=NULL){
    printf("Enter the number to insert\n");
    int data;
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;
    head->prev=NULL;
    prevNode=head;
    for(int i=2;i<=n;i++){
      newNode=(struct node*)malloc(sizeof(struct node));
      if(newNode!=NULL){
        printf("Enter the number\n");
        scanf("%d",&data);
        newNode->data=data;
        newNode->prev=prevNode;
        prevNode->next=newNode;
        prevNode=newNode;
        newNode->next=NULL;
      }
      else{
        printf("Error\n");
      }
    
    }
  }
  else{
    printf("There seems to be an error\n");
  }

}
void display(){
  struct node*temp;
  if(head==NULL){
    printf("No linked list could be created\n");
    
  }
  else{
    temp=head;
    while(temp!=NULL){
      printf("%d->\n",temp->data);
      temp=temp->next;
    }
  }
}
int main(void) {
  printf("Hello World\n");
  printf("Enter how many numbers to insert into the list\n");
  int n;
  scanf("%d",&n);
  create(n);
  printf("\n");
  display();
    return 0;
}