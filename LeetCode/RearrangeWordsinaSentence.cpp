#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

class Solution {
public:
	string arrangeWords(string text) {
		string ans = "";
		stringstream ss;
		string token = "";
		map<int, string> m;

		text[0] = tolower(text[0]);
		ss << text;
		while (getline(ss, token, ' ')) {
			m[token.length()] += (token + ' ');
		}

		for (auto i : m) {
			ans += i.second;
		}
		ans.pop_back();
		ans[0] = toupper(ans[0]);

		return ans;
	}
};

int main() {
	Solution sol;

	cout << sol.arrangeWords("Leetcode is cool") << endl; // Is cool leetcode

	return 0;
}