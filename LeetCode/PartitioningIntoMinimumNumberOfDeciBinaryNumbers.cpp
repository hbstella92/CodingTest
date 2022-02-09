#include <iostream>
using namespace std;

class Solution {
public:
	int minPartitions(string n) {
		int n_len = n.length();
		int maxval = 0;

		for (int i = 0; i < n_len; i++) {
			if (maxval == 9) break;
			maxval = (maxval < (n[i] - '0')) ? (n[i] - '0') : maxval;
		}

		return maxval;
	}
};

int main() {
	Solution sol;

	cout << sol.minPartitions("32") << endl; // 3

	return 0;
}