
## True or False
1. False
2. True
3. False
4. False
5. True
6. True
7. False


## Essay
1. Difference between Min and Max heap.
The difference between a Min and Max heap is that a min heap
will have its values ordered from least to greatest, while
the max heap will have its values ordered from greatest to least.
2. Explain how a heap removes an item.
The heap will always remove the first value of the heap. Then
replace the first value with the last. Then it heapify to keep the
property of the heap. And Finally return the value that was deleted in the beginning.
3. Explain why Modular Arithmatic uses Table_Size.
Because by using modulo on the key we can make sure that the result will be an index
of the table.
4. Explain the difference between open addressing and separate chaining.
The difference between open addressing and separate chaining
is when you use open addressing for collisions it will use a function to
find an index that isnt used, while for seperate chaining all the indexes are
linked list and you will just insert the collided item to the linked list.
5. Explain Truncation.
Truncation is a has function that shortens the key to n digits, where n is less than
the original keys digits.
6. Explain how option1 string to int can make a collsion.
option1 function uses the integer value of letters and adds them together. 
an example of a collsion would be "abc" and "cba".

bonus. Whats the difference between (node.val) and (node->val).
## Code Analysis

1. Does this  IsFull Function work. Yes/ No. Explain!
```c
bool isFull(int hsize){
    bool full = false;
    if(hsize == SIZE-1)
        full = true;
    return full;
}
```
Yes. Because the heap will be full if the hsize is equal to the
size of the array minus one.

1. Does this Insert Heap Function work. Yes/ No. Explain!
```c
void insert(Heap heap, int val){
    heap->hsize++;
    while(heap->arr[j/2] > val){
        heap->arr[j] = heap->arr[j/2];
        j /=2;
    }
    heap->arr[j] = val;
}
```
No because the parameter uses heap as value not reference. So the hsize will not
update.

2. Does this Add Hash Function work. Yes/ No. Explain!

```c
void Hash_Add(HASH hash[], CUSTOMER cust){
    int index;
    index = cust.id % Table_Size;
    nd temp = malloc(sizeof(NODE));
    temp->cust = cust;
    temp->next = NULL;

    temp->next = hash[index].head;
    hash[index].head = temp;
}
```
Yes. Because the function finds the index of the hash on where to put customer. Then
saves customer into a temporary node. Then inserts the current index next to the temp node.
Finally we save the temp node as the head of the index.

## Code
1. Code one of the String to Integer functions

2. Code one hashing function.

3. Code Double Hashing.
Look at here [Hashing](Hashing.md)
