#include <stdio.h>
#include <iostream>
using namespace std;

struct Node{
    int value;
    struct Node* next;
};

bool isEmpty(Node *stack){
    return stack == NULL;
}

void push(Node* &stack, int value){
    if (isEmpty(stack)){
        stack = new Node;
        stack->value = value;
        stack->next = NULL;
    }else{
        Node* current = stack;
        stack = new Node;
        stack -> value = value;
        stack->next = current;
    }
}

int pop (Node* &stack){
    if(isEmpty(stack)){
        return 0;
    }else{
        int tmp = stack->value;
        Node* next = stack->next;
        delete stack;
        stack = next;
        return tmp;
    }
}

int main(){
    Node* stack = NULL;
    int n, x;
    cout << "Enter n" << endl;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cout << "Enter elem ";
        cin >> x;
        push(stack, x);
}
    
    for(int i = 1; i <= n; i++){
        int max = 0;
        max = pop(stack);
        cout << "msx elem is = " << max << endl;
        if (max < pop(stack)){
            max = pop(stack);
        }
    }

}
 
