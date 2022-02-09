#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ans;
		unordered_map<string, vector<string>> m;
		int sz = strs.size();

		string tmp = "";
		for (int i = 0; i < sz; i++) {
			tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			m[tmp].push_back(strs[i]);
		}

		for (auto iter = m.begin(); iter != m.end(); iter++) {
			ans.push_back(iter->second);
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<string> input;

	input.push_back("eat");
	input.push_back("tea");
	input.push_back("tan");
	input.push_back("ate");
	input.push_back("nat");
	input.push_back("bat");

	vector<vector<string>> output = sol.groupAnagrams(input);
	for (auto i : output) {
		for (auto j : i) {
			cout << j << ' '; // [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]
		} cout << endl;
	} cout << endl;

	return 0;
}