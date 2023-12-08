#include<stdio.h>
#include<stdlib.h>
#define INT_MIN -2147483648

typedef struct node{
    int data;
    struct node*next;
}Node;

typedef struct LinkedList{
    Node* front;
    Node*rear;    
}Queue;

void initQue(Queue*queue){
    queue -> front = NULL;
    queue -> rear = NULL;
}

Node*initNode(int data){
    Node*node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    return node;
}

void enque(Queue*queue,int data){
    Node* node = initNode(data);
    if(queue -> rear == NULL){
        queue -> rear = node;
        queue -> front = node;
    }
    else{
        (queue -> rear)->next = node;
        queue -> rear = node;
    }
}

int deque(Queue*queue){
    if(queue -> front == NULL)
        return INT_MIN;
    Node*temp = queue -> front;
    queue -> front = (queue -> front)->next;
    int data = temp->data;
    free(temp);
    return data;
}

void displayQueue(Queue*queue){
    Node*temp = queue -> front;
    while (temp != NULL)
    {
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
}

int main()
{
    Queue queue;
    initQue(&queue);
    int choice;
     while (1)
    {
        printf("Do you want to perform Enqueue operation?\n1->Yes\n0->No\n");
        scanf("%d",&choice);
        if(choice == 1){
            printf("Enter the data:\n");
            scanf("%d",&choice);
            enque(&queue,choice);
            }
        else
            break;
    }

    while (1)
    {
        printf("Do you want to perform Deque operation?\n1->Yes\n0->No\n");
        scanf("%d",&choice);
        if(choice == 1){
            int n = deque(&queue);
            if(n == INT_MIN)
                printf("The queue is already full!!\n");
            else
                printf("%d\n",n);
        }
        else
            break;
    }
    printf("Do you want to display the queue:\n");
    scanf("%d",&choice);
    if(choice == 1)
        displayQueue(&queue);
    
    
 return 0;
}