#include <iostream>
#include <vector>

using namespace std;

int bin_search(vector<int> &a, int k) {
    int l = 0;
    int r = a.size() - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (a[m] == k)
            return m;
        if (a[m] > k)
            r = m - 1;
        else
            l = m + 1;
    }
    if (a[l] == k)
        return l;
    return 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(k);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++)
        cin >> b[i];
    
    for(int i = 0; i < k; i++){
         cout << bin_search(a,b[i])  << endl;
    }
    for(int i = k-1;i >= 0; i--){
        cout << bin_search(a,b[i]) << endl;
    }
    return 0;
}