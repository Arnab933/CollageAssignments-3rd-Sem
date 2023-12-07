#include<stdio.h>
#include<stdlib.h>

#define INT_MIN -2147483648


typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct LinkedList{
    Node* top;
}Stack;

// void initStack(Stack*stack){
//     stack -> top = NULL;
// } 
Node* initNode(int data){
    Node* node =(Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;

    return node;
}
void push(Stack*stack,int data){
    Node* node = initNode(data);

    if( stack -> top == NULL)
        stack -> top = node;
    else{
        node -> next = stack -> top;
        stack -> top = node;
    }
}

int pop(Stack*stack){
    if(stack -> top == NULL)
        return INT_MIN;//here INT_MIN value symbolizes unsuccessful operation

    else {
        int data = (stack -> top)->data;
        Node* temp = stack -> top;
        stack -> top = (stack -> top)-> next;
        free (temp);

        return data;
    }
}

int peek(Stack*stack) { 
    
    if( stack -> top == NULL)
        return INT_MIN;

    return (stack -> top) -> data; 
    }

void displayStack(Stack*stack){
    Node*currNode = stack -> top;
    while(currNode != NULL){
        printf("%d ",currNode -> data);
        currNode = currNode -> next;
    }
}    

int main()
{
    Stack stack;
    int choice;
    int data;
    while (1)
    {
        printf("Do you want to push data in the stack?\n1->Yes\n0->No\n");
        scanf("%d",&choice);

        if(choice == 1 ){
            printf("Enter the data:");
            scanf("%d",&data);
            push(&stack,data);
        }
        else
            break;
    }
    printf("\n");
    while(1){
        printf("Do you want to pop data from the stack?\n1->Yes\n0->No\n");
        scanf("%d",&choice);

        if(choice == 1){
            data = pop(&stack);
            if( data == INT_MIN )
                printf("Unsuccessfull operation due to stack underflow!!!\n");
            else
                printf("Popped data is:%d\n",data);
        }
        else
            break;
    }
    printf("\n");
    while (1)
    {
        printf("do you want to peek element from the stack?\n1->Yes\n0->No\n");
        scanf("%d",&choice);

        if(choice == 1 ){
            data = peek(&stack);
                if( data == INT_MIN )
                    printf("Unsuccessfull operation due to stack underflow!!\n");
                else
                    printf("Peeked data is:%d\n",data);
        } else
            break;
    }
    printf("\n");
    printf("Do you want to display stack?\n1->Yes\n0->No\n");
     scanf("%d",&choice);

        if(choice == 1 ){
            printf("Current data of the stack is:\n");
           displayStack(&stack);
        }
 return 0;
}