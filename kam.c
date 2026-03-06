#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
int size;
    int top;
    char*S;
}stk;
void push(struct stack*stk,int x){
   if(stk->top==stk->size-1){
         return ; //  printf("stack overflow");

    }
    else{
        
        stk->top++;
        stk->S[stk->top]=x;
    }

}
char pop(struct stack *stk){
    int x=-1;
    if(stk->top==-1){
        printf("stack underflow ");
        return 0;
    }
    else{
        x= stk->S[stk->top--];
    }
    return x;
//   printf("%d\n ",x) ;
  
}
 char stackTop(struct stack stk){
    if(stk.top==-1){
        return 0; //empty stack
    }else 
    {
       return stk.S[stk.top];
    }
    
 }
 int isEmpty(struct stack *stk){
    if(stk->top==-1){
        return 1;
    }
    else{
         return 0; 
    }
}
int isoperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x=='('||x==')'){
        return 0;
    }
    else{
        return 1;
    }
}
int outstackpre(char x){
     if(x=='+'||x=='-'){
        return 1;
    }
    else if(x=='*'||x=='/'){
        return 3;
    } 
      else if(x=='^'){
        return 6;
    } 
      else if(x=='('){
        return 7;
    } 
      else if(x==')'){
        return 0;
    } 
    return 0;
}
int instackpre(char x){
     if(x=='+'||x=='-'){
        return 2;
    }
    else if(x=='*'||x=='/'){
        return 4;
    } 
      else if(x=='^'){
        return 5;
    } 
      else if(x=='('){
        return 0;
    } 
    //   else if(x==')'){
    //     return 0;
    // } 
    return 0;
}
char *Convert(char *infix){

 stk.size = strlen(infix);
    stk.top = -1;
    stk.S = (char*)malloc(strlen(infix)* sizeof(char));

    char *postfix= (char*)malloc( (strlen(infix)+1)* sizeof(char));
    int i=0;int j=0;
    while(infix[i]!='\0'){
        if( isoperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(outstackpre(infix[i])>instackpre(stackTop(stk))){
                push(&stk,infix[i++]);
            }
            else if(instackpre(infix[i])>outstackpre(stackTop(stk))){
                postfix[j++]=pop(&stk);
            }
             else if(instackpre(infix[i])==outstackpre(stackTop(stk))){
                pop(&stk);
             }
        }
    }
        while(!isEmpty(&stk)){
          postfix[j++]=pop(&stk);   
        }
         postfix[j]='\0';
         return postfix ;
    
}

int main (){
    char *infix="((a+b)*c)-d^e^f";
    
    char *postfix =Convert(infix);
    printf("%s",postfix);
    return 0;
}