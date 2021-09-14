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

class Deque{
    public:
    Node *tail, *front;
    int sz;

    Deque(){
        tail = NULL;
        front = NULL;
        sz = 0;
    }

    void push_front(int data){
        Node *node = new Node(data);

        if(front == NULL){
            tail = node;
            front = node;
        } else {
            front->prev = node;
            node->next = front;
            front = node;
        }
        sz++;
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

    void pop_back(){
        if(tail != NULL){
            tail = tail->prev;
            if(tail != NULL){
                tail->next = NULL;}
        }
        else front = NULL;
        sz--;
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

    bool empty(){
        return (tail == NULL);
    }
    int size(){
        return sz;
    }

};

int main(){
    Deque *qq = new Deque();
    string s;
    while(cin >> s)
    {
        
        if(s == "push_front"){
            int x;
            cin >> x;
            qq->push_front(x);
            cout << "ok" << endl;
        }

        if(s == "push_back"){
            int x;
            cin >> x;
            qq->push_back(x);
            cout << "ok" << endl;
        }

        if(s == "pop_front"){
            if(!qq->empty())
            {
                cout << qq->front->data << endl;
                qq->pop_front();
            }
            else
            {
                cout << "error\n";
            }
        }

        if(s == "pop_back"){
            if(!qq->empty())
            {
                cout << qq->tail->data << endl;
                qq->pop_back();
            }
            else
            {
                cout << "error\n";
            }
        }

        if(s == "back"){
            if(!qq->empty())
            {
                cout << qq->tail->data << endl;
            }
            else
            {
                cout << "error" << endl;
            }
        }

        if(s == "front"){
            if(!qq->empty())
            {
                cout << qq->front->data << endl;
            }
            else
            {
                cout << "error" << endl;
            }
        }

        if(s == "size"){
            cout << qq->size()<<endl;

        }
        if(s == "clear"){
            while(!qq->empty())
                {
                    qq->pop_front();
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