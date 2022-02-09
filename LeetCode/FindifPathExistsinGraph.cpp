#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
		int edges_sz = edges.size();
		queue<int> q;
		vector<vector<int>> map;
		vector<int> visit;

		map.resize(n);
		visit.resize(n, 0);

		for (int i = 0; i < edges_sz; i++) {
			map[edges[i][0]].push_back(edges[i][1]);
			map[edges[i][1]].push_back(edges[i][0]);
		}

		q.push(start);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			if (visit[cur] == 1) continue;
			visit[cur] = 1;

			if (cur == end) return true;

			int cur_sz = map[cur].size();
			for (int i = 0; i < cur_sz; i++) {
				if (visit[map[cur][i]] == 0) {
					q.push(map[cur][i]);
				}
			}
		}

		return false;
	}
};

int main() {
	Solution sol;
	vector<vector<int>> input;

	input.push_back({ 0,1 });
	input.push_back({ 1,2 });
	input.push_back({ 2,0 });

	if (sol.validPath(3, input, 0, 2) == true) {
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}