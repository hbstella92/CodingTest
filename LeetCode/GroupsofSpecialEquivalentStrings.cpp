#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	int numSpecialEquivGroups(vector<string>& words) {
		set<pair<string, string>> s;
		int w_sz = words.size();
		int word_len = words[0].length();

		string odd = "", even = "";
		for (int i = 0; i < w_sz; i++) {
			odd = even = "";
			for (int j = 0; j < word_len; j++) {
				if (j % 2) {
					odd += words[i][j];
				}
				else {
					even += words[i][j];
				}
			}
			sort(odd.begin(), odd.end());
			sort(even.begin(), even.end());
			s.insert(make_pair(odd, even));
		}

		return s.size();
	}
};

int main() {
	Solution sol;
	vector<string> input = { "abcd","cdab","cbad","xyzz","zzxy","zzyx" };

	cout << sol.numSpecialEquivGroups(input) << endl; // 3

	return 0;
}