#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	vector<string> ans;
	int visit[16] = { 0, };

	void dfs(int idx, int cnt, int n, int len) {
		if (cnt == n) {
			bool check = true;
			stack<char> s;
			string candi = "";

			for (int i = 0; i < len; i++) {
				if (visit[i] == 1) {
					s.push('(');
					candi += '(';
				}
				else {
					if (s.empty()) {
						check = false; break;
					}

					char tmp = s.top(); s.pop();
					if (tmp != '(') {
						check = false; break;
					}
					candi += ')';
				}
			}
			if (!s.empty()) check = false;

			if (check) {
				ans.push_back(candi);
			}
			return;
		}

		for (int i = idx; i < len; i++) {
			if (!visit[i]) {
				visit[i] = 1;
			}
			dfs(i + 1, cnt + 1, n, len);
			visit[i] = 0;
		}
	}

	vector<string> generateParenthesis(int n) {
		dfs(0, 0, n, n * 2);
		return ans;
	}
};

int main() {
	Solution sol;
	vector<string> ans = sol.generateParenthesis(3); // ["((()))","(()())","(())()","()(())","()()()"]

	return 0;
}