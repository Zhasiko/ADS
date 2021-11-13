#include <iostream>
#include <vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    int i1, i2, len;
    cin >> i1 >> i2 >> len;
    int p = 31;
    int n = s.size();
    vector<long long> p_pow(n);

    p_pow[0] = 1;
    for(int i = 0; i < n; i++){
        p_pow[i] = p_pow[i - 1] * p;
    }

    vector<long long> h(n);
    for(int i = 0; i < n;i++){
        h[i] = (s[i] - 'a' + 1) * p_pow[i];
        if(i){
            h[i] += h[i - 1];
        }
    }

    int j1 = i1 + len - 1;
    int j2 = i2 + len - 1;

    long long h1 = h[j1];
    if(i1) h1 -= h[i1 - 1];
    long long h2 = h[j2];
    if(i2) h2 -= h[i2 - 1];

    bool equal = false;
    if(i1 < i2){
        if(h1 * p_pow[i2 - i1] == h2)
            equal = true;
    } else {
        if(h2 * p_pow[i1 - i2] == h1)
            equal = true;
    }

    if(equal){
        cout << "equal";
    }
    else{
        cout << "different";
    }

    return 0;
}