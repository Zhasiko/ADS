#include <iostream>

using namespace std;

long long get_hash(string s) {
	int p = 31;
	long long hash = 0, p_pow = 1;
	for (int i = 0; i < s.size(); i++) { // s[0] = 'd'
		hash += (s[i] - 'a' + 1) * p_pow; // s[0] * p^0 + s[1] * p^1 + s[2]*p^2
		p_pow *= p; // p_pow = 31^2
	}
	return hash;
} 

int main() {
	string s;
	cin >> s;
	cout << get_hash(s);
	return 0;
}
