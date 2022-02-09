#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
		vector<vector<string>> ans;
		int sz = products.size();
		int w_len = searchWord.length();

		sort(products.begin(), products.end());

		int same_idx[1000] = { 0, }; int num = 0;
		for (int i = 0; i < sz; i++) {
			int cnt = 0;

			for (int j = 0; j < w_len; j++) {
				if (searchWord[j] == products[i][j]) {
					cnt++;
				}
				else break;
			}
			same_idx[num++] = cnt;
		}
		
		for (int i = 0; i < w_len; i++) {
			vector<string> tmp;
			int count = 0;

			for (int j = 0; j < sz; j++) {
				if (count == 3) break;
				if (same_idx[j] > i) {
					tmp.push_back(products[j]);
					count++;
				}
			}

			ans.push_back(tmp);
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<string> input = { "mobile", "mouse", "moneypot", "monitor", "mousepad" };

	vector<vector<string>> ans = sol.suggestedProducts(input, "mouse");
	for (auto i : ans) {
		for (auto j : i) {
			cout << j << ' '; // [["mobile", "moneypot", "monitor"], ["mobile", "moneypot", "monitor"], ["mouse", "mousepad"], ["mouse", "mousepad"], ["mouse", "mousepad"]
		} cout << endl;
	} cout << endl;

	return 0;
}