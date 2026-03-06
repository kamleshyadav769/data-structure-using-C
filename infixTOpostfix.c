#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char *S;
};

void push(struct stack *stk, char x) {
    if (stk->top == stk->size - 1) {
        // Stack overflow
        return;
    }
    stk->top++;
    stk->S[stk->top] = x;
}

char pop(struct stack *stk) {
    if (stk->top == -1) {
        // Stack underflow
        return '\0';
    }
    return stk->S[stk->top--];
}

char stackTop(struct stack stk) {
    if (stk.top == -1) {
        return '\0';
    }
    return stk.S[stk.top];
}

// int isEmpty(struct stack *stk) {
//     return stk->top == -1;
// }
int isEmpty(struct stack *stk){
    if(stk->top==-1){
        return 1;
    }
    else{
         return 0; 
    }
}
// int isoperand(char x) {
//     return !(x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')');
// }
int isoperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x=='('||x==')'){
        return 0;
    }
    else{
        return 1;
    }
}
int outstackpre(char x) {
    if (x == '+' || x == '-') return 1;
    else if (x == '*' || x == '/') return 3;
    else if (x == '^') return 6;
    else if (x == '(') return 7;
    else if (x == ')') return 0;
    return 0;
}

int instackpre(char x) {
    if (x == '+' || x == '-') return 2;
    else if (x == '*' || x == '/') return 4;
    else if (x == '^') return 5;
    else if (x == '(') return 0;
    return 0;
}

char *Convert(char *infix) {
    struct stack stk;
    stk.size = strlen(infix);
    stk.top = -1;
    stk.S = (char *)malloc(stk.size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isoperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
         

            //              if (infix[i] != ')') { is block KO UPPER LIKHNA GLT HAI BECAUSE THIS WILL copy just copy the expression without bracket
            //      push(&stk, infix[i]);
            //  }

            //  i++;
             while (!isEmpty(&stk) &&
                   outstackpre(infix[i]) <= instackpre(stackTop(stk))) {

                if (outstackpre(infix[i]) == instackpre(stackTop(stk))) {
                    pop(&stk); // Matching parenthesis
                    break;
                } else {
                    postfix[j++] = pop(&stk);
                }
            }

            // Push only if not closing parenthesis
             if (infix[i] != ')') {
                  push(&stk, infix[i]);
              }

              i++;
        }
    }

    while (!isEmpty(&stk)) {
        postfix[j++] = pop(&stk);
    }

    postfix[j] = '\0';
    free(stk.S);
    return postfix;
}

int main() {
    char *infix = "((a+b)*c)-d^e^f";
   // char *postfix = Convert(infix);
    //printf("Postfix: %s\n", postfix);
      printf("Postfix: %s\n", Convert(infix));
    //free(postfix);
    return 0;
}
