#include <iostream>
using namespace std;
int p[1000010];
void findPrimes1(int n){
    for(int i = 2;i*i<=n;i++){
        if (p[i] == 0){
            int k = i;
            while(k+i<=n){
                k += i;
                p[k] = 1;
            }
        }
    }
    for(int i = 2; i <= n;i++)
        if (p[i] == 0)
            cout << i << " ";
        
}

int main(){
    int n;
    cin >> n;
    findPrimes1(n);
    return 0;
}