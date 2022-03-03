#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:
	vector<string> printVertically(string s) {
		int s_len = s.length();
		int max_len = count(s.begin(), s.end(), ' ') + 1;
		stringstream ss(s);
		string token = "";
		int token_len = 0, vec_sz = 0;

		while (getline(ss, token, ' ')) {
			token_len = token.length();
			vec_sz = max(vec_sz, token_len);
		}

		vector<string> ans(vec_sz);
		stringstream ss2(s);
		while (getline(ss2, token, ' ')) {
			token_len = token.length();
			for (int i = 0; i < token_len; i++) {
				ans[i] += token[i];
			}
			for (int i = token_len; i < vec_sz; i++) {
				ans[i] += ' ';
			}
		}

		for (int i = 0; i < vec_sz; i++) {
			int j = ans[i].length() - 1;
			while (ans[i][j] == ' ') {
				j--;
			}
			if (j != (ans[i].length() - 1)) ans[i] = ans[i].substr(0, j + 1);
		}

		return ans;
	}
};

int main() {
	Solution sol;
	
	/*
	vector<string> output = sol.printVertically("HOW ARE YOU");
	for (auto i : output) {
		cout << i << ' '; // ["HAY", "ORO", "WEU"]
	} cout << endl;
	*/

	/*
	vector<string> output = sol.printVertically("TO BE OR NOT TO BE");
	for (auto i : output) {
		cout << "(";
		cout << i; // ["TBONTB", "OEROOE", "   T"]
		cout << ") ";
	} cout << "/" << endl;
	*/

	/**/
	vector<string> output = sol.printVertically("CONTEST IS COMING");
	for (auto i : output) {
		cout << i << ' '; // ["CIC", "OSO", "N M", "T I", "E N", "S G", "T"]
	} cout << "/" << endl;
	/**/

	return 0;
}