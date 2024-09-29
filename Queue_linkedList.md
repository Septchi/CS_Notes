# Queue Linked List

The linked list version of a Queue uses node structures and node references instead of
an array. This makes the stack have a dynamic size.
You need 2 nodes **front** and **rear** to use properly.
## Stack Linked List;
```c
typedef struct node* nodeptr;
struct node{
    int val;
    nodeptr next;
} Node;
```
#### val
The value stored in the node.
#### next
The pointer connecting the next node.

#### Linked List Structure
![alt text](Images/stack_linkedlist.png)

## Stack Operations
### Enqueue
The function creates a new node and inserts the current top/head node next to the new  node.
```c
void enqueue(nodeptr* front, nodeptr* rear, int val){
    nodeptr node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    if(*rear != NULL){
        (*rear)->next = node;
        *rear = node;
    }
    else{
        *rear = node;
        *front = *rear;
    }
}
```
![alt text](Images/push_stackLL.gif)
### Dequeue
The function outputs the value in tos and moves tos lower by 1.
```c
int dequeue(nodeptr* front, nodeptr* rear){
    nodeptr* node = *front;
    *front = node->next;
    if(*front = NULL){
        *rear = NULL;
    }
	free(temp);
    return data;
}
```
![alt text](Images/pop_stackLL.gif)
``` 
The free function deallocates the memory of the node pointer so the program reuse the memory from the free'd node.
```
### IsFull
Because a linked list is dynamic it can never be full.

### IsEmpty
Functions checks if the stack is empty by checking if rear is NULL.

```c
bool isEmpty(nodeptr rear){
    bool empty = false;
    if(rear == NULL){
	    empty = true;
    }
    return empty;
}
```

### Peek
Function will output the value in the top of the stack/(the head node).
```c
int peek(nodeptr front){
    int data = front->val;
    return data;
}
```
## References
### Array version
[Linear Queue](Queue.md)<br>
[Circular Queue](CQueue.md)
### Examples


[Back To Main](readme.md)
