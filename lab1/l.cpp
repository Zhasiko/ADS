#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    while (a > 0 && b > 0) {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return a + b;
}

int main() {
    long long n, m;
    cin >> n >> m;
    cout << (n*m)/gcd(n, m);
    return 0;
}