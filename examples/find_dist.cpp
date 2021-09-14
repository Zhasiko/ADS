#include <iostream>
#include <queue>
using namespace std;

int used[101];
int c[101];

int find_dist(int a, int b){
    queue < pair < int, int > > q;
    q.push(make_pair(a,0));
    used[a] = 1;
    c[a] = a;

    while(!q.empty()){
        int p = q.front().first;
        int d = q.front().second;

        if(p == b)
            return d;

        if(used[p+1] == 0){
            q.push(make_pair(p+1, d+1));
            used[p+1] = 1;
            c[p+1] = p;
        }
        if(used[p*2] == 0){
            q.push(make_pair(p*2, d+1));
            used[p*2] = 1;
            c[p*2] = p;
        }
        if(p - 1 >= 0 and used[p-1] == 0){
            q.push(make_pair(p-1, d+1));
            used[p-1] = 1;
            c[p-1] = p;
        }
        if(used[p/2] == 0){
            q.push(make_pair(p/2, d+1));
            used[p/2] = 1;
            c[p/2] = p;
        }
        q.pop();
    }
    return 0;
}


int main(){

    int a,b;
    cin >> a >> b;
    cout << find_dist(a,b) << endl;

    vector<int> res;
    res.push_back(b);
    int t = b;
    while(c[t]!=t){
        t = c[t];
        res.push_back(t);
    }
    for(int i = res.size()-1; i >= 0; i--){
        cout << res[i] << " ";
    }
    return 0;
}