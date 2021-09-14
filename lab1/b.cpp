#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *prev;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Queue{
    public:
    Node *front;
    Node *tail;
    int sz;

    Queue(){
        tail = NULL;
        front = NULL;
        sz = 0;
    }
    void push(int data){
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
    void pop(){
        if(front != NULL){
            front = front->next;
            if(front != NULL){
                front->prev = NULL;
            }
            else tail = NULL;
        }
        sz--;
    }

    bool empty(){
        return (front == NULL);
    }
    int size(){
        return sz;
    }
};
int main(){
    Queue *q = new Queue();
    string s;
    while(cin >> s)
    {
        
        if(s == "push"){
            int x;
            cin >> x;
            q->push(x);
            cout << "ok" << endl;
        }

        if(s == "pop"){
            if(!q->empty())
            {
                cout << q->front->data << endl;
                q->pop();
            }
            else
            {
                cout << "error" << endl;
            }
        }

        if(s == "front"){
            if(!q->empty())
            {
                cout << q->front->data << endl;
            }
            else
            {
                cout << "error" << endl;
            }
        }

        if(s == "size"){
            cout << q->size()<<endl;

        }
        if(s == "clear"){
            while(!q->empty())
                {
                    q->pop();
                }
                cout << "ok" << endl;
        }

        if(s == "exit")
        {
            cout << "bye" << endl;
            break;
        }
    }
    return 0;
}