#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string ans = "";
		int num_word = strs.size();

		if (num_word == 1) return strs[0];

		string candi = "";
		string cmp_str = strs[0];
		for (int i = 1; i < num_word; i++) {
			int len = (cmp_str.length() > strs[i].length()) ? strs[i].length() : cmp_str.length();

			for (int j = 0; j < len; j++) {
				if (cmp_str[j] == strs[i][j]) {
					candi += strs[i][j];
				}
				else break;
			}

			ans = candi;
			cmp_str = candi;
			candi = "";
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<string> input;

	/*input.push_back("flower");
	input.push_back("flow");
	input.push_back("flight");*/
	/*input.push_back("dog");
	input.push_back("racecar");
	input.push_back("car");*/
	input.push_back("a");

	cout << sol.longestCommonPrefix(input) << '\n';

	return 0;
}