#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

#define s 32

typedef struct{
    char stk[s];
    int tos;
} Stack;

Stack newStack(){
    Stack stack;
    stack.tos = -1;

    return stack;
}

char pop(Stack* stack){
    char data = stack->stk[stack->tos];
    stack->tos--;

    return data;
}

void push(Stack* stack, char data){
    stack->tos++;
    stack->stk[stack->tos] = data;
}

char peek(Stack stack){
    return stack.stk[stack.tos];
}

bool isFull(int tos){
    bool full = false;
    if(tos == s -1)
        full = true;

    return full;
}

bool isEmpty(int tos){
    bool empty = false;
    if(tos == -1)
        empty = true;

    return empty;
}

int prec(char op){
    switch(op){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;
    }
    return -1;
}
int main(){
    char input[s/2];
    char output[s/2];
    printf("enter postfix equation: ");
    fgets(input, s/2, stdin);

    bool full, empty;
    char op;
    int i = 0;
    int j = 0;
    float n1, n2, res;
    Stack stack = newStack();
    while((op = input[i++]) != '\n'){
        if(isdigit(op)){
            output[j++] = op;
            continue;
        }
        empty = isEmpty(stack.tos);
        if(empty){
            full = isFull(stack.tos);
            if(!full)
                push(&stack, op);
            else{
                printf("stack full\n");
            }
        }
        else if(op == '('){
            full = isFull(stack.tos);
            if(!full)
                push(&stack, op);
            else{
                printf("stack full\n");
            }
        }
        else if(op == ')'){
            empty = isEmpty(stack.tos);
            while(!empty){
                if(peek(stack) != '('){
                    output[j++] = pop(&stack);
                }
                else
                    break;
                empty = isEmpty(stack.tos);
            }
        }
        else{
            if(prec(op) >= prec(peek(stack))){
                full = isFull(stack.tos);
                if(!full)
                    push(&stack, op);
                else{
                    printf("stack full\n");
                }
                continue;
            }
            empty = isEmpty(stack.tos);
            while(!empty){
                if(prec(op) < prec(peek(stack))){
                    output[j++] = pop(&stack);
                    empty = isEmpty(stack.tos);
                }

                else{
                    full = isFull(stack.tos);
                    if(!full)
                        push(&stack, op);
                    else{
                        printf("stack full\n");
                    }
                    break;
                } 
            }

        }
    }
    empty = isEmpty(stack.tos);
    while(!empty){
        output[j++] = pop(&stack);
        empty = isEmpty(stack.tos);
    }
    printf("%s", output);
}
