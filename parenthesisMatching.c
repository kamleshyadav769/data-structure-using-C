#include<stdio.h>
#include<stdlib.h>
struct Node{
    char data;
    struct Node *next;
}*top=NULL;
void push(char x){
    struct Node*t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("stackis full");
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
    
   // printf("%c",top->data);
}
char pop(){
    struct Node*t;
    char x=-1;
    if(top==NULL){
        printf("stak is empty");
    }
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}
int isBalanced(char*exp){
    int i;
     char x;
    for(i=0;exp[i]!='\0';i++){
      //  if(exp[i]=='('){
      // push(exp[i]);
           // printf("push\n");
        //}
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
        push(exp[i]);
        }
       else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            if (top == NULL) {
                return 0;
            }
            
                  x=  pop();
                if (exp[i] - x != 1 && exp[i] - x != 2) {
                return 0;
            }
                   // printf("pop\n");
        }
    }
if(top==NULL){
    return 1;
   // printf("pip");
             
}
else{
    return 0;
    
            
}
}
void display(){
    struct Node*p;
    p=top;
    while(p!=NULL){
        printf("%c",p->data);
        p=p->next;
    }
printf("\n");
}
int main(){
    char *exp="[(a+b)*{(c+d)]";
    printf("%d\n",isBalanced(exp));

// display();  
}