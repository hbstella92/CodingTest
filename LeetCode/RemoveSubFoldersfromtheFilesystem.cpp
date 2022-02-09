#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> removeSubfolders(vector<string>& folder) {
		vector<string> ans;

		sort(folder.begin(), folder.end());
		int f_sz = folder.size();

		ans.push_back(folder[0]);
		for (int i = 1; i < f_sz; i++) {
			int ans_sz = ans.size();
			string tmp = ans[ans_sz - 1] + '/';
			if (folder[i].substr(0, tmp.length()) != tmp) ans.push_back(folder[i]);
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<string> input;

	/* ["/a", "/c/d", "/c/f"]
	input.push_back("/a");
	input.push_back("/a/b");
	input.push_back("/c/d");
	input.push_back("/c/d/e");
	input.push_back("/c/f");
	*/

	input.push_back("/c");
	input.push_back("/d/c/e");

	vector<string> output = sol.removeSubfolders(input);
	for (auto i : output) {
		cout << i << ' '; // ["/c", "/d/c/e"]
	} cout << endl;

	return 0;
}