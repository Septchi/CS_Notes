# Binary Search Tree
A binary search is a data structure that uses nodes that are connected to other nodes.
Since its binary each node is connect to two other nodes.
![BST](Images/BST.png)

## Structure
```c
typedef struct node* nodeptr;
struct node{
    int val;
    nodeptr left;
    nodeptr right;
}
```

#### val
val is the data of the node it can be any datatype or struct
#### left
The left node of the current node. the left node's **val** is always less than the current node's **val**
#### right
The right node of the current node. the right node's **val** is always greater than the current node's **val**

## BST Operations
### Add
The function adds a new node to the current tree.
```c
void add_Node(nodeptr *root, int val){
    nodeptr new_node = 
}
```
