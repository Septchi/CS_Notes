# Queue

A stack is a list with the restriction that inserts and deletes
can only be performed on the top of the list.
A queue is a list with the restriction that you can insert at the front of the list
and you can delete at the end of the list.

## Linear Queue Array
```c
typedef struct{
    int que[size];

    int front;
    int rear;
} Queue;
```
#### que
The actual array of Queue.

#### front
The front of the Queue, this is where you ### [EnQueue] in the Queue.
front starts at index 0.

#### rear
The rear of the Queue, this is where you ### [DeQueue] in the Queue.
rear starts at index -1.

![Queue](Images/queue.png)

## Queue Operataions
### EnQueue
The function increases rear and inserts a value in that index.
```c
void EnQueue(Queue* queue, int val){
    queue->rear += 1;
    queue->que[queue->rear] = val;
}
```
![enqueue_gif](Images/enqueue.gif)
### DeQueue
The function increases rear and inserts a value in that index.
```c
return DeQueue(Queue* queue){
    int val queue->que[queue->front];
    queue->front += 1;
    return val;
}
```
![dequeue_gif](Images/dequeue.gif)

### IsFull
 The function check if the Queue is full by checking if rear is equal to size.
```c
bool isFull(int rear){
    bool full = false;
    if(rear == size-1)
        full = true;
    return true;
}
```

### IsEmpty
 The function check if the Queue is full by checking if rear is equal to size.
```c
bool isEmpty(int rear){
    bool empty = false;
    if(rear == size-1)
        empty = true;
    return true;
}
```
## Reference
