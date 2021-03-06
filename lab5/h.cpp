#include <iostream>
#include <vector>
#define ll long long
using namespace std;
vector<int> b;
vector<ll> a;
class MaxHeap {
    public:

    ll parent(ll i) {
        return (i - 1) / 2;
    }

    ll left(ll i) {
        return 2 * i + 1;
    }

    ll right(ll i) {
        return 2 * i + 2;
    }
 
    void insert(ll k) {
        a.push_back(k);
    }

    int heapify(ll i) { 
        int nn = a.size() - 1;
        if(left(i) > nn){
            return i;
        }
        int j = left(i);
        if(right(i) < nn + 1 && a[right(i)] > a[left(i)])
            j = right(i);
        if(a[i] < a[j]) {
            swap(a[i], a[j]);
            return heapify(j);
        }
        return i;
    }

    void siftUp(){
        ll i = a.size() - 1;
        while (i >= 0){
            if (a[parent(i)] < a[i])
                swap(a[parent(i)], a[i]);
            i--;
        }
    }

    void siftDown(int i){
        int j = right(i);
        int sz = a.size();
        if (right(i) < sz && a[right(i)] > a[left(i)]) {
			j = right(i);
		}
        else {
			j = left(i);
		}
        if (j < sz && a[j] > a[i]) {
			swap(a[i], a[j]);
			siftDown(j);
		}
    }

    int extractMax(){
        int root_value = a[0];
        swap(a[0],a[a.size()-1]);
        a.pop_back();
        if(a.size() > 0){
            heapify(0);
        }
        return root_value;
    }

    void print() {
        for (ll i = a.size() / 2; i >= 0 ; i--) { 
            siftDown(i);
        }
        for (ll i = 0; i < a.size(); i++) {
            heapify(i);
            cout << a[i] << " ";
        }
        cout << endl;
    }

    int getMax() {
        return a[0];
    }
};

int main(){
    ll n, m;
    cin >> n;
    vector<int> b;
    MaxHeap *heap = new MaxHeap();

    for(ll i = 0; i < n; i++){
        ll k;
        cin >> k;
        heap->insert(k);
        
    }
    heap->print();
    for(int i = 0; i < n; i++){
        b.push_back(heap->extractMax());

        if(a.size() > 0)
        heap->print();
    }

    for(int i = n - 1; i >= 0; i--){
        cout << b[i] << " ";
    }
    return 0;
}