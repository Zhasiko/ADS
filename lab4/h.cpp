#include <iostream>
#include <vector>
using namespace std;

vector<long long> a;

class Node{
    public:
    long long data;
    Node *left, *right;
    Node(long long data){
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
    Node *insert(Node *node, long long data) {
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
        a.push_back(node->data);
        //cout << node->data <<endl;
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

    Node *deleteNode(Node *node, long long data){
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

    int height(Node *node){
        if(node == NULL)
            return 0;
        return max(height(node->right), height(node->left)) + 1;

    }

    bool isBalanced(Node * node){
        if(node == NULL)
            return true;
        if(abs(height(node->right) - height(node->left)) <= 1 && 
           isBalanced(node->right) && isBalanced(node->left))
           return true;
        return false;
    }
};

int main(){
    BST *bst = new BST();
    long long k;
    while(cin >> k and k != 0){
        bst->root = bst->insert(bst->root,k);
    }

    if(bst->isBalanced(bst->root)) cout << "YES";
    else cout << "NO";
    return 0;
}