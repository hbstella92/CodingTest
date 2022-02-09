#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string reorderSpaces(string text) {
		vector<string> v;
		int text_len = text.length();
		int space_cnt = 0;
		int word_flag = 0;

		string tmp = "";
		for (int i = 0; i < text_len; i++) {
			if (text[i] == ' ') {
				space_cnt++;

				if (word_flag) {
					v.push_back(tmp);
					word_flag = 0;
					tmp = "";
				}
			}
			else {
				word_flag = 1;
				tmp += text[i];
			}
		}
		if (word_flag) {
			v.push_back(tmp);
		}

		string ans = "";
		int v_sz = v.size();
		int space_sz, remain_space;

		if (v_sz > 1) {
			space_sz = space_cnt / (v_sz - 1);
			remain_space = space_cnt % (v_sz - 1);
		}
		else {
			space_sz = 0;
			remain_space = space_cnt;
		}

		for (int i = 0; i < v_sz; i++) {
			ans += v[i];

			if (i == v_sz - 1) break;
			for (int j = 0; j < space_sz; j++) {
				ans += ' ';
			}
		}
		for (int i = 0; i < remain_space; i++) {
			ans += " ";
		}

		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.reorderSpaces("  this   is  a sentence ") << endl;

	return 0;
}