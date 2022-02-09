#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
		string ret = "";
		int len_s = s.length();

		if (len_s < k) {
			for (int i = len_s - 1; i >= 0; i--) {
				ret += s[i];
			}

			return ret;
		}

		char tmp[10001];
		int moc = len_s / k;
		int remain = len_s % k;
		int rev = 1;
		for (int i = 0; i < moc; i++) {
			for (int j = 0; j < k; j++) {
				if (rev == 1) {
					tmp[k - 1 - j] = s[i * k + j];
				}
				else {
					tmp[j] = s[i*k + j];
				}
			}

			tmp[k] = '\0';
			ret += tmp;
			rev = rev ? 0 : 1;
		}

		if (!rev) {
			for (int i = k * moc; i < len_s; i++) {
				ret += s[i];
			}
		}
		else {
			for (int i = len_s - 1; i >= k * moc; i--) {
				ret += s[i];
			}
		}

		return ret;
	}
};

int main() {
	Solution sol;
	
	string str = sol.reverseStr("hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl", 39);
	cout << str << '\n';

	return 0;
}