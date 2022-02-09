#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string ans = "", tmp = "";
		int len_a = a.length(), len_b = b.length();
		int delta = abs(len_a - len_b);

		while (delta--) {
			tmp += '0';
		}
		if (len_a > len_b) {
			tmp += b;
			len_b = len_a;
			b = tmp;
		}
		else if (len_a < len_b) {
			tmp += a;
			len_a = len_b;
			a = tmp;
		}

		int carry = 0;
		for (int i = len_a - 1; i >= 0; i--) {
			if (a[i] == '1' && b[i] == '1') {
				if (!carry) {
					ans += '0';
					carry++;
				}
				else {
					ans += '1';
				}
			}
			else if (a[i] == '0' && b[i] == '0') {
				if (!carry) {
					ans += '0';
				}
				else {
					ans += '1';
					carry = 0;
				}
			}
			else {
				if (!carry) {
					ans += '1';
				}
				else {
					ans += '0';
				}
			}
		}
		if (carry) ans += '1';

		reverse(ans.begin(), ans.end());

		return ans;
	}
};

int main() {
	Solution sol;
	
	//cout << sol.addBinary("0", "0") << '\n'; // 0
	//cout << sol.addBinary("11", "1") << '\n'; // 100
	//cout << sol.addBinary("1010", "1011") << '\n'; // 10101
	cout << sol.addBinary("100", "110010") << '\n'; // 110110

	return 0;
}