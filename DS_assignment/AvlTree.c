#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

typedef struct AVL {
    Node* root;
} AVL;

Node* newNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

Node* rightRotate(Node* p) {
    Node* c = p->left;
    Node* t = c->right;

    c->right = p;
    p->left = t;

    p->height = 1 + ((height(p->left) > height(p->right)) ? height(p->left) : height(p->right));
    c->height = 1 + ((height(c->left) > height(c->right)) ? height(c->left) : height(c->right));

    return c;
}

Node* leftRotate(Node* c) {
    Node* p = c->right;
    Node* t = p->left;

    p->left = c;
    c->right = t;

    p->height = 1 + ((height(p->left) > height(p->right)) ? height(p->left) : height(p->right));
    c->height = 1 + ((height(c->left) > height(c->right)) ? height(c->left) : height(c->right));

    return p;
}

Node* rotate(Node* node) {
    if (height(node->left) - height(node->right) > 1) {
        // left heavy
        if (height(node->left->left) - height(node->left->right) > 0) {
            // left left case
            return rightRotate(node);
        }
        if (height(node->left->left) - height(node->left->right) < 0) {
            // left right case
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    if (height(node->left) - height(node->right) < -1) {
        // right heavy
        if (height(node->right->left) - height(node->right->right) < 0) {
            // right right case
            return leftRotate(node);
        }
        if (height(node->right->left) - height(node->right->right) > 0) {
            // left right case
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

Node* insert(int value, Node* node) {
    if (node == NULL) {
        return newNode(value);
    }

    if (value < node->value) {
        node->left = insert(value, node->left);
    } else if (value > node->value) {
        node->right = insert(value, node->right);
    }

    node->height = 1 + ((height(node->left) > height(node->right)) ? height(node->left) : height(node->right));

    return rotate(node);
}

void populate(AVL* avl, int value) {
    avl->root = insert(value, avl->root);
}

void displayInOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    displayInOrder(node->left);
    printf("%d ", node->value);
    displayInOrder(node->right);
}

void displayTree(AVL* avl) {
    if (avl->root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    printf("Inorder Traversal: ");
    displayInOrder(avl->root);
    printf("\n");
}

int isEmpty(AVL* avl) {
    return avl->root == NULL;
}

int main() {
    AVL avl;
    avl.root = NULL;

    int value;
    printf("Enter values for AVL tree (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        populate(&avl, value);
    }

    displayTree(&avl);

    return 0;
}
