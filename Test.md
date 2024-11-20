## True or False
1. Heaps will always have sorted numbers.
2. Hash functions will always have a chance of collsion.
3. Heap should insert the first number at 0.
4. You should use Hashing when your values are in order.
5. The first index of the heap is the least or greatest number.
6. Its better to have a table size that is prime.
7. To get the left child of an index in the heap you do **2i + 1**.


## Essay
1. Difference between Min and Max heap.
2. Explain how a heap removes an item.
3. Explain why Modular Arithmatic uses Table_Size.
4. Explain the difference between open addressing and separate chaining.
5. Explain Truncation.
6. Explain how option1 string to int can make a collsion.

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

## Code
1. Code one of the String to Integer functions

2. Code one hashing function.

3. Code Double Hashing.
