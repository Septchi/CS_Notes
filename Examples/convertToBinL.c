#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node* nodeptr;

//This function creates a new stack and starts the tos at -1
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


bool isEmpty(nodeptr node){
    bool empty = false;
    if(node == NULL)
        empty = true;

    return empty;
}

int intValue(){
    int val;
    printf("Enter integer: ");
    scanf("%d", &val);

    return val;
}

void convertBin(int num){
    int tNum, rem;
    int binNum = 0;
    bool empty, full;
    nodeptr head = NULL;

    tNum = num; // Temporary number that copied the value of number input.
    /*
     The while loop works because binary is always divisible by to.
     ex. 1101 = 13
     because
     1101 = (8*1) + (4*1) + (2*0) + (1*1) = 13
     With this reasoning what we can do to get binary is reverse the process.
     instead of multiplying we divide.
     Let say we get need to get the right most bit.
     first we divide 13 by 1
     res = 13/1 
     res = 13
     then we modulo it by 2 because binary is always 2
     bit = 13%2 
     bit = 1
     Now we have our first Bit. We push this into the stack and loop.
     
     Now the next equation is (2*0) So instead of dividing by 1 we divide by 2.
     res = 13/2
     res = 6
     then we modulo it by 2 again
     bit = 6%2
     bit = 0
     And now we have our second Bit 0. We push that into the stack and loop.

     But now our next equation is (4*1) and now the left number is 4 not 2.
     Since we already divided 2 by res we also need to divide 2 to 4.
     So we divide res by 2 still
     res = 6/2
     res = 3
     then we modulo it by 2 again
     bit = 3%2
     bit = 1
     And we get the 3rd bit which is 1. We push that into the stack and loop

     Our final equation is (8*1). You might think we divide 8 by 2 and get 4.
     But now we didnt just divide 2 once but twice so we have to divide 8 by 2 twice or divide by 4 once.
     8/4 is 2 so we divide res by 2.
     res = 3/2
     res = 1
     then modulo it by 2 again
     bit = 1%2
     bit = 1
     And we get our final Bit 1. We push that to the stack and loop.

     Even though in our equation we are done the while loop is not done.
     But since 1/2 is 0 and 0%2 is 0 the next bit would by 0 and 01101 = 1101
    */
    while (tNum !=0) {
        rem  = tNum % 2; 
            push(&head, rem);
        tNum /= 2;
    }
    /*
        Now our stack is full of the bits we want to display.
        But you might have realized that the numbers in the stack are reversed.
        inside the stack its gonna look like [1,0,1,1] instead of [1,1,0,1].
        So we can use a normal for loop normally.

        There alot of ways to display the binary even if the array is reverse.
        One is just reverse the for loop. But since we cant use the array and only pop.
        What we can do is either print each time we pop the stack and not make a new line.
        So the output is reversed.

        What I did is pop the bit into binNum. and then multiplying it by 10.
        So step by step it looks like.
        //before while loop
        binNum = 0

        //1st loop
        binNm = binNum * 10
        binNum = {0} * 10
        binNum = 0
        binNum = binNum + pop(&stack)
        binNum = {0} + {1}
        binNum = 1

        //2nd loop
        binNm = binNum * 10
        binNum = {1} * 10
        binNum = 10
        binNum = binNum + pop(&stack)
        binNum = {10} + {1}
        binNum = 11

        //3nd loop
        binNm = binNum * 10
        binNum = {11} * 10
        binNum = 110
        binNum = binNum + pop(&stack)
        binNum = {110} + {0}
        binNum = 110

        //3nd loop
        binNm = binNum * 10
        binNum = {110} * 10
        binNum = 1100
        binNum = binNum + pop(&stack)
        binNum = {1100} + {1}
        binNum = 1101
        //Loop end
        
        and now we have the binary converted from integer.
    */
    empty = isEmpty(head);
    while(!empty){
        binNum *= 10;
        binNum += pop(&head);
        empty = isEmpty(head);
    }
    printf("binary: %d\n", binNum);
}
int main(){
    int num;
    num  = intValue();
    convertBin(num);
    return 0;
}
