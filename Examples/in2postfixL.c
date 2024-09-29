
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node* nodeptr;

struct node{
    char val;
    nodeptr next;
};

char pop(nodeptr* head){
    char data = (*head)->val;
    nodeptr temp = *head;
    *head = temp->next;
    free(temp);

    return data;
}

void push(nodeptr* head, char data){
    nodeptr node = malloc(sizeof(nodeptr));
    node->val = data;
    node->next = *head;
    *head = node;
}

char peek(nodeptr head){
    return head->val;
}

bool isEmpty(nodeptr head){
    bool empty = false;
    if(head == NULL)
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
    char input[16];
    char output[16];
    printf("enter postfix equation: ");
    fgets(input, 16, stdin);

    bool full, empty;
    char op;
    int i = 0;
    int j = 0;
    float n1, n2, res;
    nodeptr head = NULL;
    while((op = input[i++]) != '\n'){
        if(isdigit(op)){
            output[j++] = op;
            continue;
        }
        empty = isEmpty(head);
        if(empty){
            push(&head, op);
        }
        else if(op == '('){
            push(&head, op);
        }
        else if(op == ')'){
            empty = isEmpty(head);
            while(!empty){
                if(peek(head) != '('){
                    output[j++] = pop(&head);
                }
                else
                    break;
                empty = isEmpty(head);
            }
        }
        else{
            if(prec(op) >= prec(peek(head))){
                push(&head, op);
                continue;
            }
            empty = isEmpty(head);
            while(!empty){
                if(prec(op) < prec(peek(head))){
                    output[j++] = pop(&head);
                    empty = isEmpty(head);
                }

                else{
                    push(&head, op);
                    break;
                } 
            }

        }
    }
    empty = isEmpty(head);
    while(!empty){
        output[j++] = pop(&head);
        empty = isEmpty(head);
    }
    printf("%s", output);
}
