#include <iostream>
using namespace std;

int main(){
int n,k = 0,m = 1;
cin >> n;
while(m < n){
    m = m * 2;
    k += 1;
}
cout << k;
    return 0;
}