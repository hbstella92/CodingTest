#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
	bool canConstruct(string s, int k) {
		int s_len = s.length();
		if (s_len < k) return false;

		int freq[26] = { 0, };
		for (int i = 0; i < s_len; i++) {
			freq[s[i] - 'a']++;
		}

		int odd = 0;
		for (int i = 0; i < 26; i++) {
			odd += (freq[i] % 2);
		}

		return (odd <= k);
	}
};

int main() {
	Solution sol;

	//if (sol.canConstruct("annabelle", 2)) { // true
	if(sol.canConstruct("yzyzyzyzyzyzyzy", 2)) { // true
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}