#include <iostream>
#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList{
    public:
    Node *tail, *front;
    int sz;

    LinkedList(){
        tail = NULL;
        front = NULL;
        sz = 0;
    }

    void push_back(int data){
        Node *node = new Node(data);

        if(tail == NULL){
            tail = node;
            front = node;
        }
        else{
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        sz++;
    }

    void pop_front(){
        if(front != NULL){
            front = front->next;
            if(front != NULL){
                front->prev = NULL;
            }
            else tail = NULL;
        }
        sz--;
    }

    void print(){
        Node *node = front;
        while(node != NULL){
            cout << node ->data << " ";
            node = node->next;
        }
        cout << endl;
    }

    void insrt(Node *node1, int data){
        Node *node = new Node(data);
        if(node1 == tail){
            push_back(data);
        }
        else{
            Node *node2 = node1->next;
            node1 ->next = node;
            node->prev = node1;
            node->next = node2;
            node2->prev = node;
        }
    }

    int size(){
        return sz;
    }
    Node* find_node(int data) {
        Node *node = front;
        while (node != NULL) {
            if (node->data == data)
                return node;
            node = node->next; 
        }
        return NULL;
    }
};

int main(){
    LinkedList *ll = new LinkedList();
    int n; 
    cin >> n; 
    for(int i = 0; i < n; i++){ 
        string s; 
        cin >> s; 
        if(s == "+"){ 
            int x; 
            cin >> x; 
            ll->push_back(x); 
        } 
        if(s == "*"){ 
            int x; 
            cin >> x;
            node = ll->find_node();
            ll->insrt(node, x);


        } 
        if(s == "-"){ 
            cout << qq.front()<<endl; 
            qq.pop_front(); 
        } 
    } 
    return 0;
}