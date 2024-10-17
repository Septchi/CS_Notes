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
    nodeptr node = *root, parent;
    nodeptr new_node = malloc(sizeof(nodeptr));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    while(node != NULL){
        parent = node;
        if(val < node->val)
            node = node->left;
        else
            node = node->right;
    }
    if(parent == NULL)
        *root = new_node;
    else if(val < parent->val)
        parent->left = new_node;
    else
        parent->right = new_node;
}
```
#### node
the node we use to traverse the tree.
#### parent
the parent node of **node**. We use it so when node is NULL we know where to insert **new_node**
#### new_node
the new node to insert

![BST_Add](Images/BST_Add.gif)
