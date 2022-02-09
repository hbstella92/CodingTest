#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int minSwaps(string s) {
		int ans = 0;
		int len = s.length();

		int i = 0, j = len - 1;
		int balance = 0;

		for (int i = 0; i < j; i++) {
			if (s[i] == '[') balance++;
			else balance--;

			if (balance < 0) {
				while (s[j] != '[') j--;
				balance = 1;
				ans++;
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.minSwaps("][][") << endl; // 1

	return 0;
}