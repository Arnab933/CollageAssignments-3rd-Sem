#include<iostream>
using namespace std;

class Stack{
    private:
        class Node{
            public:
                int data;
                Node*next;
                Node(){}
                Node(int data){
                    this->data = data;
                    this->next = NULL;
                }
        };
    public:
        Node*top;
        Stack(){
            this->top = NULL;
        }
        void push(int data){
            Node*node = new Node(data);
            if(top == NULL)
                top = node;
            else{
                node->next = top;
                top = node;
            }
        }
        
        int pop(){
            Node* node = top;
            int val = top->data;
            top = top->next;
            free(node);
            return val;
        }

        void copyStack(Stack*stack){
            Node*currNode = top;
            while (currNode != NULL)
            {
                stack->push(currNode->data);
                currNode = currNode->next;
            }
            
        }
        void display(){
            Node*node = top;
            while(node != NULL){
                cout<<node->data<<" ";
                node = node->next;
            }
            cout<<endl;
        }
};

int main()
{
    Stack stack1,stack2;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    cout<<"Elements of the first stack is:"<<endl;
    stack1.display();
    stack1.copyStack(&stack2);
    cout<<"Elements of the second stack is:"<<endl;
    stack2.display();
 return 0;
}
