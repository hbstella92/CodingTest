#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	map<string, int> m;

	vector<string> subdomainVisits(vector<string>& cpdomains) {
		vector<string> ans;
		int v_sz = cpdomains.size();

		string num, subdomain;
		int idx; int num_to_int;

		for (int i = 0; i < v_sz; i++) {
			idx = cpdomains[i].find(' ');
			num = cpdomains[i].substr(0, idx);
			num_to_int = atoi(num.c_str());
			subdomain = cpdomains[i].substr(idx + 1);

			m[subdomain] += num_to_int;

			while (1) {
				idx = subdomain.find(".");
				if (idx == string::npos) break;

				subdomain = subdomain.substr(idx + 1);
				m[subdomain] += num_to_int;
			}
		}

		for (auto iter = m.begin(); iter != m.end(); iter++) {
			ans.push_back(to_string(iter->second) + " " + iter->first);
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<string> input = { "9001 discuss.leetcode.com" };

	vector<string> ans = sol.subdomainVisits(input);

	int sz = ans.size();
	for (int i = 0; i < sz; i++) {
		cout << ans[i] << endl;
	}

	return 0;
}