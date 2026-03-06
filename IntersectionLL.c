/*//WHEN AFTER SOME TIMES NUMBERS ARE REPEATED EXAMPLE
A=1,2,4,5,67,8,43,23,12
B=13,34,45,50,67,8,43,23,12
REPEATITION STARTS AFTER 4 TIMES*/



#include <stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node
{
int data;
struct Node*next;
}*first=NULL,*second=NULL;


struct stack{
int size;
    int top;
    int*S;
};
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
    if (p == NULL) return 0; 
    int len=0;
   while(p!=NULL){
      len++;
        p=p->next;
    } 
   return len;
}
void createfirst(int A[],int n ){
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
void createsecond(int B[],int n ){
    int i;
    struct Node*t,*last;
    second=(struct Node*)malloc(sizeof(struct Node));
  second->data=B[0];
    second->next=NULL;
    last =second;
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=B[i];
      
         t->next=NULL;
       
        last->next=t;
        last=t;
}
}
void push(struct stack*stk,int x){
   if(stk->top==stk->size-1){
         return ; //  printf("stack overflow");

    }
    else{
        
        stk->top++;
        stk->S[stk->top]=x;
    }

}
int pop(struct stack *stk){
    int x=-1;
    if(stk->top==-1){
        printf("stack underflow");
        return 0;
    }
    else{
        x= stk->S[stk->top--];
    }
    return x;
//   printf("%d\n ",x) ;
  
}
int isEmpty(struct stack *stk){
    if(stk->top==-1){
        return 1;
    }
    else{
         return 0; 
    }
}
void createStackfirst(struct stack* stk, int size) {
    stk->size = size;
   stk->top = -1;
    stk->S = (int*)malloc(size * sizeof(int));
     struct Node* p = first;
     while (p != NULL) {
        push(stk, p->data);
        p = p->next;
     }
}
void createStacksecond(struct stack* stk, int size) {
    stk->size = size;
   stk->top = -1;
    stk->S = (int*)malloc(size * sizeof(int));
     struct Node* p = second;
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
 int stackTop(struct stack stk){
    if(stk.top==-1){
        return 0; //empty stack
    }else 
    {
       return stk.S[stk.top];
    }
    

 }

void intersect(struct Node *p,struct Node *q){
struct stack stk1,stk2;
createStackfirst(&stk1, length(p));

   /* while (p != NULL) {
        push(&stk1, p->data);
        p = p->next;
     }*/
createStacksecond(&stk2, length(q));
    
  /*   while (q != NULL) {
        push(&stk2, q->data);
        q = q->next;
     }*/
     int k=-1;
    
         while (stackTop(stk1)==stackTop(stk2))
     {
       k=stackTop(stk1);
       pop(&stk1);
        pop(&stk2);
    if(k!=-1){
    printf(" %d ",k) ;
    } 
    else{
        printf("non interserctig");
    } 
}

printf("\n");
//  displaystk(&stk1);
  // displaystk(&stk2);

}

int main() {
int A[]={9,7,8,6,56};
int B[]={9,1,7,8,6,56};
 createfirst(A,5);
 createsecond(B,6);
 //display(second);
 intersect(first,second);

}