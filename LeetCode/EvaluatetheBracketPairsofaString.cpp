#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string evaluate(string s, vector<vector<string>>& knowledge) {
		int s_len = s.length();
		int v_sz = knowledge.size();
		string ans = "", key = "";

		unordered_map<string, string> m;
		for (int i = 0; i < v_sz; i++) {
			int v_ssz = knowledge[i].size();
			m.insert({ knowledge[i][0], knowledge[i][1] });
		}

		bool is_key = false;
		for (int i = 0; i < s_len; i++) {
			if (s[i] == '(') {
				is_key = true;
				continue;
			}
			else if (s[i] == ')') {
				bool have_key = false;

				if (m.find(key) != m.end()) {
					ans += m[key];
					have_key = true;
				}

				is_key = false;
				key = "";
				if (!have_key) ans += '?';
				continue;
			}

			if (is_key) key += s[i];
			else ans += s[i];
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<vector<string>> input;

	input.push_back({ "name", "bob" });
	input.push_back({ "age", "two" });

	cout << sol.evaluate("(name)is(age)yearsold", input) << endl; // bobistwoyearsold

	return 0;
}