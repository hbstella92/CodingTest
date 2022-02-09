#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int minFlips(string target) {
		int ans = 0;
		int len = target.length();

		if (target[0] == '1') ans++;
		for (int i = 0; i < len - 1; i++) {
			if (target[i] != target[i + 1]) {
				ans++;
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.minFlips("10111") << endl; // 3

	return 0;
}