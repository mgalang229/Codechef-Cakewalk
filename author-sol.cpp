#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		long long n;
		cin >> n;
		// divide 'n' by 10 until it can no longer be divided by it
		long long power10 = 0;
		while (n % 10 == 0) {
			n /= 10;
			power10++;
		}
		// two cases wherein the output will be No:
		// case 1: 
		// if the remaining value of 'n' is NOT a power of two (2)
		
		// case 2: 
		// if the remaining value of 'n' is simply a power of two (2)
		// it means it was not produced as a power of 20
		// example 1:
		// N = 160, yes we can divide it by 10 so now N will be 16
		// 16 is also a power of 2 but we cannot reproduce N using a combination of 20 and 10
		// so that's why we need to check if the no. of trailing zeroes in its binary form is
		// greater than the no. of times we used 10 to divide N
		// example 2:
		// N = 1600000, yes we can divide it by 10 (5 times), so now N is 16
		// 16 is a power of 2, and yes we can reproduce 16 by a combination of 20 and 10
		// i.e., 20 * 20 * 20 * 20 * 10 = 1600000
		// (2 * 10) * (2 * 10) * (2 * 10) * (2 * 10) * 10 = 1600000
		// (2 ^ 4) * (10 ^ 5) = 1600000
		// here the no. of trailing zeroes of 16 is less than the no. of 10 that we used to divide N
		if (__builtin_popcountll(n) != 1) {
			cout << "No";
		} else if (__builtin_ctzll(n) > power10) {
			cout << "No";
		} else {
			cout << "Yes";
		}
		cout << '\n';
	}
	return 0;
}
