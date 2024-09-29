#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

#define s 32

typedef struct{
    int stk[s];
    int tos;
} Stack;

Stack newStack(){
    Stack stack;
    stack.tos = -1;

    return stack;
}

int pop(Stack* stack){
    int data = stack->stk[stack->tos];
    stack->tos--;

    return data;
}

void push(Stack* stack, int data){
    stack->tos++;
    stack->stk[stack->tos] = data;
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

int main(){
    char input[s/2];
    printf("enter postfix equation: ");
    fgets(input, s/2, stdin);

    bool full, empty;
    char op;
    int i = 0;
    float n1, n2, res;
    Stack stack = newStack();
    while((op = input[i++]) != '\n'){
        printf("op: %c\n", op);
        if(isdigit(op)){
            res = op - '0';
            full = isFull(stack.tos);
            if(!full)
                push(&stack, res);
            else{
                printf("stack full\n");
                return 0;
            }
        }
        else{
            empty = isEmpty(stack.tos);
            if(!empty)
                n1 = pop(&stack);
            else{
                printf("stack empty\n");
                return 0;
            }
            empty = isEmpty(stack.tos);
            if(!empty)
                n2 = pop(&stack);
            else{
                printf("stack empty\n");
                return 0;
            }
            switch(op){
                case '+':
                    res = n1 + n2;
                    break;
                case '-':
                    res = n2 - n1;
                    break;
                case '*':
                    res = n1 * n2;
                    break;
                case '/':
                    res = n2 / n1;
                    break;
            }
            full = isFull(stack.tos);
            if(!full)
                push(&stack, res);
            else{
                printf("stack full\n");
            }
        }
    }
    empty = isEmpty(stack.tos);
    if(!empty)
        res = pop(&stack);
    else{
        printf("stack empty\n");
        return 0;
    }
    empty = isEmpty(stack.tos);
    if(empty)
        printf("Result is %.2f\n", res);

    else
        printf("Error");
}
