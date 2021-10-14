#include <iostream>
#include <vector>
#define ll long long
using namespace std;

class MaxHeap {
    public:
    vector<ll> a;

    ll parent(ll i) {
        return (i - 1) / 2;
    }

    ll left(ll i) {
        return 2 * i + 1;
    }

    ll right(ll i) {
        return 2 * i + 2;
    }

    int getMax(){
        return a[0];
    }
 
    void insert(ll k) {
        a.push_back(k);
        ll i = a.size() - 1;
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    int siftDown(ll i) { 
        if(left(i) > a.size() - 1){
            return i;
        }
        int j = left(i);
        if(right(i) < a.size() && a[right(i)] > a[j])
            j = right(i);
        if(a[i] < a[j]) {
            swap(a[i], a[j]);
            return siftDown(j);
        }
            return i;
    }

    int extractMax(){
        int root_value = getMax();
        swap(a[0],a[a.size()-1]);
        a.pop_back();
        if(a.size() > 0){
            cout << siftDown(0) + 1 << " ";
        }
        return root_value;
    }

    void print() {
        for (ll i = 0; i < a.size(); i++) 
            cout << a[i] << " ";
        
        cout << endl;
    }
};

int main(){
    ll n;
    cin >> n;
    MaxHeap *heap = new MaxHeap();

    for(ll i = 0; i < n; i++){
        ll k;
        cin >> k;
        heap->insert(k);
        
    }

    for(int i = 0; i < n - 1; i++){
        cout << heap->extractMax() << endl;
    }
   
    return 0;
}