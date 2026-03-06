#include <stdio.h>
#include<stdlib.h>

struct Node
{
int data;
struct Node*next;
}*first=NULL;


struct stack{
int size;
    int top;
    int*S;
}stk;
void display(struct Node*p){
     if (first == NULL) {
       printf("List is empty.\n");
         return;
     }
   while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
printf("\n");
}
int length(struct Node*p){
    if (first == NULL) return 0; 
    int len=0;
   while(p!=NULL){
      len++;
        p=p->next;
    } 
   return len;
}
void create(int A[],int n ){


    int i;
    struct Node*t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
  first->data=A[0];
    first->next=NULL;
    last =first;
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
      
         t->next=NULL;
       
        last->next=t;
        last=t;
}
}
void push(struct stack*stk,int x){
   if(stk->top==stk->size-1){
         return; //  printf("stack overflow");

    }
    else{
        
        stk->top++;
        stk->S[stk->top]=x;
    }

}
void createStack(struct stack* stk, int size) {
    stk->size = size;
    stk->top = -1;
    stk->S = (int*)malloc(size * sizeof(int));
     struct Node* p = first;
     while (p != NULL) {
        push(stk, p->data);
        p = p->next;
     }
}


void displaystk(struct stack *stk){
    int i;
   
    for(i=stk->top;i>=0;i--){
        printf("%d ",stk->S[i]);
    }
    printf("\n");
}
 
int middle(struct Node *p){
    struct stack stk;
    int mid,len;
     len= length(p); // compulsory to store in temporary variable
     createStack(&stk,len);
    if(len%2==0){
          mid= len/2-1;
          printf("%d %d", stk.S[mid],stk.S[mid+1]);
    }
    else{
  mid= len/2;
   printf("%d ", stk.S[mid]);
    }
}

int main() {
int A[]={9,7,8,6,56};

 create(A,5);
 
 display(first);

 middle(first);
}