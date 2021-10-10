#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{
    public:
    Node *root;
    BST(){
        root = NULL;
    }
    Node *insert(Node *node, int data) {
        if(node == NULL){
            node = new Node(data);
            return node;
        }
        if(data != node->data){
            if(data <= node->data){
                node->left = insert(node->left,data);
            }
            else{
                node->right = insert(node->right,data);
            }
        }
        return node;
    }

    void inOrder(Node *node){
        if(node == NULL)
        return;
        inOrder(node->left);
        cout << node->data <<endl;
        inOrder(node->right);
    }

    Node *findMin(Node *node){
        while(node->left != NULL){
            node = node->left;
        }
        return node;
    }

    Node *findMax(Node *node){
        while(node->right != NULL){
            node = node->right;
        }
        return node;
    }

    Node *deleteNode(Node *node, int data){
        if(node == NULL)
            return NULL;
        if(data < node->data){
            node->left = deleteNode(node->left,data);
        }
        else if(data > node->data){
            node->right = deleteNode(node->right,data);
        }
        else{
            if(node->left == NULL && node->right == NULL)
                return NULL;
            else if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
            node = node->left;
            else{
                Node *tmp = findMax(node->left);
                node->data = tmp->data;
                node->left = deleteNode(node->left,tmp->data);
            }
        }
        return node;
    }

    void printLeaf(Node *node)
    {
    if ( (node->left == NULL) && (node->right== NULL) )
        cout << node->data << endl;
    else
    {
        if (node->left) printLeaf(node->left);
        if (node->right) printLeaf(node->right);
    }
    }
};

int main(){
    BST *bst = new BST();
    int k;
    while(cin >> k and k != 0){
        bst->root = bst->insert(bst->root,k);
    }
    bst->printLeaf(bst->root);

    return 0;
}