#include <iostream>

using namespace std;
int main(){
    int n;
    int num;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int max = a[0];
    for(int i = 0; i < n; i++){
        if(a[i] > max){
            max = a[i];
            num = i;
        }
    }
    if(max == a[0]){
        cout <<'1';
        return 0;
    }
    cout << num+1;
    return 0;
}