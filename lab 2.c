#include <stdio.h>

typedef struct Node{
    int value;
    Node* next;
}Node;

void push(Node* &stack, int value){
    if (isEmpty(stack)){
        stack = new Node;
        stack->value = value;
        stack->next = Null;
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
        int tmp = stack-> value;
        Node* next = stack->next;
        delete stack;
        stack = next;
        return tmp;
    }
}

int main(){
    Node* stack = null;
    int n, x;
    prtinf("Enter i;");
    scanf("%i", n);

    for(int i = 0; i <= n; i++){
        scanf("%i", x);
        push(x);

    }
    for(int i = 0; i <= n; i++){
            pop();
        int max = tmp;
        if (max < tmp){
            max = tmp;
        }
    }
    printf(max);
    
}
 