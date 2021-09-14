#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<string> q1,q2;
    int n;
    string s;
    while(cin >> n){
        cin >> s;
        if( n == 9){
            cout << n << " " << s << endl;
        }
        if(n ==10){
            q1.push(s);
        }
        if(n == 11){
            q2.push(s);
        }
    }
        while(!q1.empty() or !q2.empty()){
            if(!q1.empty()){
                cout << "10" << " " << q1.front() << endl;
                q1.pop();
            }
            else if(!q2.empty()){
                cout << "11" << " " << q2.front() << endl;
                q2.pop();
            }
        }
    return 0;
}