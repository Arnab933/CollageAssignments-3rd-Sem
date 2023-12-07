#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node*next;
}Node;

typedef struct LinkedList{
    Node* head;
    Node* tail;
}List;

void initList(List* list){
    list -> head = NULL;
    list -> tail = NULL;
}
Node* initNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;
    return node;
}

void insertNode(List*list,int data){
    Node* node = initNode(data);
    if(list -> head == NULL){
        list -> head = node;
        list -> tail = node;
    }else{
        (list -> tail)->next = node;
        list -> tail = node;
    }
}

void displayList(List*list){
    Node* node = list -> head;
    while (node!=NULL)
    {
        printf("%d->",node -> data);
        node = node -> next;
    }
    printf("NULL");
}

void disp(Node*node){
   if(node == NULL)
    return;
   disp(node -> next);
   printf("%d->",node -> data);
}

void displayRev(List*list){
    disp(list->head);
    printf("NULL");
}

void deleteNode(List* list,int data){
    Node* currNode = list -> head;
    if(currNode -> data == data){
        Node*node = currNode;
        list -> head = currNode -> next;
        if(list -> head == NULL)
            list -> tail = NULL;
        free (node);
    }
    else{
        Node* node = currNode;
        currNode = currNode -> next;
        while (currNode != NULL)
        {
            if(currNode -> data == data){
                Node*temp = currNode;
                node->next = currNode->next;
                if(temp -> next == NULL)
                    list->tail = node;
                free(temp);
                return;
            }
            else{
            node = node -> next;
            currNode = currNode -> next;
            }
        }
        
    }
    
}
void searchNode(List*list,int data){
    Node* node = list -> head;
    while (node != NULL)
    {
        if(node -> data == data){
            printf("The searching is successfull");
            return;
        }
    }
    printf("The searching is unsuccessfull");
}

int main()
{
    List list;
    initList(&list);
    int arr[5]= {5,4,3,2,1};
    for (int i = 0; i < 5; i++)
    {
        insertNode(&list,arr[i]);
    }
    printf("The linkedlist is:\n");
    displayList(&list);
    printf("\n");
    deleteNode(&list,3);
    printf("After deletion the linkedlist is:\n");
    displayList(&list);
    printf("The linkedlist in reverse order:\n");
    displayRev(&list);
 return 0;
}