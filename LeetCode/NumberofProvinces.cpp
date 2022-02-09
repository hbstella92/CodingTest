#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int ans = 0;
	int visit[200] = { 0, };
	int cnt = 0;

	void dfs(vector<vector<int>> &isConnected, int cur, int city_num) {
		if (cnt == city_num) return;

		visit[cur] = 1;
		cnt++;
		int len = isConnected[cur].size();
		for (int j = 0; j < len; j++) {
			if (j == cur) continue;

			if ((!visit[j]) && isConnected[cur][j]) {
				visit[j] = 1;
				dfs(isConnected, j, city_num);
			}
		}
	}

	int findCircleNum(vector<vector<int>>& isConnected) {
		int city_num = isConnected.size();
		int cur = 0;

		while (cnt < city_num) {
			dfs(isConnected, cur, city_num);
			ans++;

			for (int i = 0; i < city_num; i++) {
				if (!visit[i]) {
					cur = i; break;
				}
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;
	vector<vector<int>> input;

	input.push_back({ 1,1,0 });
	input.push_back({ 1,1,0 });
	input.push_back({ 0,0,1 });

	cout << sol.findCircleNum(input) << endl; // 2

	return 0;
}