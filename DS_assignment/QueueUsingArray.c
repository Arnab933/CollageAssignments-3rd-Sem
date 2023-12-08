#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define Max_Size 10
#define INT_MIN -2147483648


bool isFull(int*arr,int*rear){
    if(Max_Size - 1 == *rear ) 
        return true;
    else 
        return false;
}

bool isEmpty(int*arr,int*front,int*rear){
    if(*rear == *front)
        return true;
    else
        return false;
}

void enque(int*arr,int* front,int*rear,int val){
    if(isFull(arr,rear))
        printf("The queue is already full!!");
    else{
        arr[(*rear)++] = val;
    }
}

int deque(int*arr,int*front,int*rear){
    if(isEmpty(arr,front,rear)){
        return INT_MIN;
    }
    else{
        int a = arr[*front];
        for (int i = 1; i <= *rear; i++)
        {
            arr[i-1] = arr[i];
        }
        --(*rear);
        
        return a;
    }
}

void displayQueue(int*arr,int front,int rear){
    if(rear == front){
        printf("The queue is already empty!!");
        return;
    }
    for (int i = front; i < rear; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

int main()
{
    int arr[Max_Size];
    int front = 0;
    int rear = 0;
    int choice;

    while (1)
    {
        printf("Do you want to perform Enqueue operation?\n1->Yes\n0->No\n");
        scanf("%d",&choice);
        if(choice == 1){
            printf("Enter the data:\n");
            scanf("%d",&choice);
            enque(arr,&front,&rear,choice);
            }
        else
            break;
    }

    while (1)
    {
        printf("Do you want to perform Deque operation?\n1->Yes\n0->No\n");
        scanf("%d",&choice);
        if(choice == 1)
            printf("%d\n",deque(arr,&front,&rear));
        else
            break;
    }
    printf("Do you want to display the queue:\n");
    scanf("%d",&choice);
    if(choice == 1)
        displayQueue(arr,front,rear);
    return 0;
}