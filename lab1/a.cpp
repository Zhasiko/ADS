#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
    public:
    Node *top;
    int sz;

    Stack(){
        top = NULL;
        sz = 0;
    }
    void push(int data){
        Node *new_node = new Node(data);
        new_node ->next = top;
        top = new_node;
        sz++;
    }
    void pop(){
        if(top != NULL){
            top = top ->next;
            sz--;
        }
    }
    bool empty(){
        return (top == NULL);
    }
    int size(){
        return sz;
    }
};
int main(){
    Stack *st = new Stack();
    string s;
    while(cin >> s)
    {
        
        if(s == "push"){
            int x;
            cin >> x;
            st->push(x);
            cout << "ok" << endl;
        }

        if(s == "pop"){
            if(!st->empty())
            {
                cout << st->top->data << endl;
                st->pop();
            }
            else
            {
                cout << "error\n";
            }
        }

        if(s == "back"){
            if(!st->empty())
            {
                cout << st->top->data << endl;
            }
            else
            {
                cout << "error" << endl;
            }
        }

        if(s == "size"){
            cout << st->size()<<endl;

        }
        if(s == "clear"){
            while(!st->empty())
                {
                    st->pop();
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