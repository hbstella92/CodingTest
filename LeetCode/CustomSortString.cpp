#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string customSortString(string order, string s) {
		string ans = "", diff = "";

		int o_len = order.length(); int s_len = s.length();
		int idx[26] = { 0, };

		int j = 0;
		for (int i = 0; i < o_len; i++) {
			while ((j = s.find(order[i], j)) != string::npos) {
				ans += order[i];
				j++;
				if (j >= s_len) break;
			}
			j = 0;
		}

		for (int i = 0; i < s_len; i++) {
			if (order.find(s[i]) == string::npos) {
				diff += s[i];
			}
		}
		sort(diff.begin(), diff.end());
		ans += diff;

		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.customSortString("cba", "abcd") << endl; // cbad

	return 0;
}