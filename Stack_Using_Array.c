#include<stdio.h>
#include<stdlib.h>
#define max_size 10

void push(int*stack,int val,int*top){
    if(*(top) >= max_size){
        printf("The stack is overflow");
        return;
    }
    else
        stack[(*top)++] = val;
}

int pop(int*stack,int*top){
    if(*(top) <= 0){
        printf("The stack is already empty");
        return -1;
    }
    else
        return stack[--(*top)];
}

int peek(int*stack,int top){
  if(top <= 0){
        printf("The stack is already empty");
        return -1;
    }
    else
        return stack[--top];
}
void displayStack(int*stack,int top){
    if(top <= 0){
        printf("The stack is empty");
        return;
    }

    for (int i = --top; i >= 0; i--)
    {
        printf("%d ",stack[i]);
    }
    
}
int main()
{
    int stack[max_size],top = 0;
    int choice;
    while (1)
    {
        printf("\n\nEnter the choice:\n");
        printf("1->PUSH\n2->POP\n3->Pick\n4->Display Stack\n5->exit\n");
        scanf("%d",&choice);
        if(choice == 5)
            break;
        switch (choice)
        {
        case 1:
            int val;
            printf("Enter the element for push operation:\n");
            scanf("%d",&val);
            push(stack,val,&top);
            break;
        case 2:
            int pop_val = pop(stack,&top);
            if(pop_val == -1){
                break;
            }
            printf("The popped element is:%d",pop_val);
            break;
        case 3:
            int peek_val = peek(stack,top);
            if(peek_val == -1 )
                break;
            printf("The peeked value is:%d",peek_val);
            break;
        case 4:
            displayStack(stack,top);
            break;
        default:
            printf("Pls enter a valid choice");
            break;
        }
    }
 return 0;
}