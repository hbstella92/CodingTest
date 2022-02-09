#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	string frequencySort(string s) {
		string ans = "";
		int s_len = s.length();
		unordered_map<char, int> freq;
		vector<string> bucket(s_len + 1, "");

		for (int i = 0; i < s_len; i++) {
			freq[s[i]]++;
		}

		for (auto i : freq) {
			bucket[i.second].append(i.second, i.first);
		}

		for (int i = s_len; i > 0; i--) {
			if (!bucket[i].empty()) {
				ans += bucket[i];
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;

	//cout << sol.frequencySort("tree") << endl; // eert
	//cout << sol.frequencySort("cccaaa") << endl; // aaaccc
	//cout << sol.frequencySort("Aabb") << endl; // bbAa
	cout << sol.frequencySort("leetcode") << endl; // eeeoltdc

	return 0;
}