#include <iostream>
#include <queue>


using namespace std;

struct Node{
    int value;
    Node *left,*right;
};

void addElement(Node* &root,int newValue){
    if(!root){
        root = new Node;
        root->value = newValue;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    if(root->value > newValue)
        addElement(root->right, newValue);
    else
        addElement(root->left, newValue);
}

void printTree(Node *root) {
    if (root) {
        printTree(root->left);
        printTree(root->right);
        std::cout << "Node value: " << root->value << std::endl;
    }
}

int findMaxNode(Node* root) {

    if (root == NULL) {
        return 0;
    }
    int maxVal = root->value;
    int leftMaxVal = findMaxNode(root->left);
    int rightMaxVal = findMaxNode(root->right);
    if (leftMaxVal > maxVal)
        maxVal = leftMaxVal;
    if (rightMaxVal > maxVal)
        maxVal = rightMaxVal;
    return maxVal;
}

int main()
{
    Node* root = nullptr;
    int n, x = 0;
    cout << "Enter size of tree: ";
    cin >> n;

    for (int i = 0; i < n; i++){
        cout << "Enter element: ";
        cin >> x;
        addElement(root, x);
    }
    printTree(root);
    cout << "Max element: " << findMaxNode(root);
    return 0;
}