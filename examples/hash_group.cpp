#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <string> s;
string x;
int n;

int main(){
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> x;
        s.push_back(x);
    }
    int p = 31;
    vector<long long> p_pow(10000);
    p_pow[0] = 1;
    for(int i = 1; i < 10000;i++){
        p_pow[i] = p_pow[i-1] * p;
    }

    vector<pair<long long,int > > hashes(n);

    for(int i = 0; i < n;i++){
        long long hash = 0;
        for(int j = 0; j < s[i].size();j++){
            hash += (s[i][j] - 'a' + 1) * p_pow[j];
        }
        hashes[i] = make_pair(hash, i);
    }

    sort(hashes.begin(), hashes.end());
    for(int i = 0; i < n;i++)
        cout << hashes[i].first << " " << hashes[i].second << endl;
    return 0;
}