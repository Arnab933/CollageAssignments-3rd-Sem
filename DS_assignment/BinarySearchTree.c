#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    int data;
    struct Node*left;
    struct Node*right;
}Node;

typedef struct Bst{
    Node*root;
}Bst;


void displayInorder(Node*node){
    if(node == NULL)
        return;
    displayInorder(node -> left);
    printf("%d->",node -> data);
    displayInorder(node -> right);
}

Node* min_node(Node*root){
    Node* node = root;
    while(node -> left != NULL){
        node = node ->left;
    }
    return node;
}

Node* deleteBst(Node*root,int data){
    if(root == NULL)
        return root;
    if(root -> data == data){
        if(root -> left == NULL && root -> right == NULL){
            free(root);
            return NULL;
        }
        if(root -> left == NULL && root -> right != NULL){
            Node* node = root ->right;
            free(root);
            return node;
        }
        if(root -> left != NULL && root -> right == NULL){
            Node* node = root ->left;
            free(root);
            return node;
        }
        if(root -> left != NULL && root -> right != NULL){
            Node* minNode = min_node(root -> right);
            root -> data = minNode -> data;
            root -> right = deleteBst(root -> right,minNode -> data);
            return root;
        }
    }
    else if(root -> data < data)
        root -> right = deleteBst(root -> right,data);
    else
        root -> left = deleteBst(root -> left,data);
    return root;
}

void delete(Bst* bst){
    int data;
    printf("Enter the data for deletion:\n");
    scanf("%d",&data);
    bst -> root = deleteBst(bst -> root,data);
}


void displayTree(Bst*bst){
    if(bst -> root == NULL)
        return;
    displayInorder(bst -> root);
    printf("NULL");
}

Node* initNode(int val){
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = val;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

Node* insertNode(Node*root,int data){
    if(root == NULL){
        root = initNode(data);
        return root;
    }
    if(data < root -> data )
        root -> left = insertNode(root -> left,data);
    else
        root -> right = insertNode(root -> right,data);
    return root;
}

void inputData(Bst*bst){
    int data;
    printf("Enter data for insert:");
    scanf("%d",&data);
    while (data != -1)
    {
        bst->root = insertNode(bst->root , data);
        scanf("%d",&data);
    }
}

void initBst(Bst* bst){
    bst -> root = NULL;
}

int main()
{
    Bst bst;
    initBst(&bst);
    inputData(&bst);
    displayTree(&bst);
    printf("\n");
    delete(&bst);
    displayTree(&bst);
 return 0;
}