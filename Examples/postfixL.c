
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node* nodeptr;

struct node{
    int val;
    nodeptr next;
};

int pop(nodeptr* head){
    int data = (*head)->val;
    nodeptr temp = *head;
    *head = temp->next;
    free(temp);

    return data;
}

void push(nodeptr* head, int data){
    nodeptr node = malloc(sizeof(nodeptr));
    node->val = data;
    node->next = *head;
    *head = node;
}

bool isEmpty(nodeptr head){
    bool empty = false;
    if(head == NULL)
        empty = true;

    return empty;
}

int main(){
    char input[16];
    printf("enter postfix equation: ");
    fgets(input, 16, stdin);

    bool empty;
    char op;
    int i = 0;
    float n1, n2, res;
    nodeptr head = NULL;
    while((op = input[i++]) != '\n'){
        printf("op: %c\n", op);
        if(isdigit(op)){
            res = op - '0';
            push(&head, res);
        }
        else{
            empty = isEmpty(head);
            if(!empty)
                n1 = pop(&head);
            else{
                printf("stack empty\n");
                return 0;
            }
            empty = isEmpty(head);
            if(!empty)
                n2 = pop(&head);
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
            push(&head, res);
        }
    }
    empty = isEmpty(head);
    if(!empty)
        res = pop(&head);
    else{
        printf("stack empty\n");
        return 0;
    }
    empty = isEmpty(head);
    if(empty)
        printf("Result is %.2f\n", res);

    else
        printf("Error");
}
