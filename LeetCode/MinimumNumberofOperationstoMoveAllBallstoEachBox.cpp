#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> minOperations(string boxes) {
		int b_len = boxes.length();
		vector<int> ans;
		vector<int> idx;

		for (int i = 0; i < b_len; i++) {
			if (boxes[i] == '1') {
				idx.push_back(i);
			}
		}

		int idx_sz = idx.size();

		for (int i = 0; i < b_len; i++) {
			int sum = 0;

			for (int j = 0; j < idx_sz; j++) {
				sum += abs(i - idx[j]);
			}

			ans.push_back(sum);
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<int> ans = sol.minOperations("110");
	int ans_sz = ans.size();

	for (int i = 0; i < ans_sz; i++) {
		cout << ans[i] << " ";
	} cout << endl;

	return 0;
}