# Linked List Hash
this hash function uses linked list to resolve collsions.

## Setup
```c
typedef struct {
    char num[4];
    int id;

} CUSTOMER // Data

typedef struct Node* nd;
typedef struct Node{
    CUSTOMER cust;
    nd next;
} NODE;

typedef struct{
    nd head;
} HASH;
```
#### CUSTOMER
The customer struct is the data of the the node pointer.

#### NODE
The **NODE** pointer cointains the **CUSTOMER** data and a pointer to the next **NODE**.

#### HASH
The HASH struct is what is being used as the array type.
ex. `HASH hash[TableSize]`;

## Hash Operations

### Intialize Hash
intializes all hash pointers to NULL.

```c

void Hash_Initialize(HASH hash[]){
    for(int i = 0; i < TableSize; i++){
        hash[i] = NULL; 
    }
}
```

### Add Hash
adds a new Item in the hash table.

```c
void Hash_Add(HASH hash[], CUSTOMER cust){
    int index;
    index = cust.id % TableSize;
    nd tp = malloc(sizeof(NODE));
    tp->cust = cust;
    tp->next = NULL:

    if(hash[index].head != NULL)
        tp->next = hash[index].head;
    hash[index].head = tp;
}
```

### Delete Hash
deletes the item you want in the hash table.

```c
bool Hash_Delete(HASH hash[], int key){
    int index;
    bool found = true;
    index = key % TableSize;
    nd tp = hash[index].head, tp1;
    while(tp != NULL && !found){
        if(tp->cust.id == key){
            if(tp1 == NULL)
                hash[index].head = NULL;
            else if(tp->next == NULL)
                tp1->next = NULL;
            else
                tp1->next = tp->next;
            else
            found = true;
            free(tp);
        }
        else{
            tp1 = tp;
            tp = tp->next;
        }
    }
    return found;
}
```

### Search Hash
Finds the item you want in the hash table and returns it as a parameter.

```c
bool Hash_Search(HASH hash[], int key, CUSTOMER *data){
    int index;
    bool found = true;
    index = cust.id % TableSize;
    nd tp = hash[index].head, tp1;
    while(tp != NULL && !found){
        if(tp->cust.id == key){
            *data = tp->cust;
        }
        else{
            tp1 = tp;
            tp = tp->next;
        }
    }
    return found;
}
```
