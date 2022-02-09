#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> path;

	void dfs(vector<vector<int>> &graph, int src, int dst) {
		path.push_back(src);

		if (src == dst) {
			ans.push_back(path);
		}

		int g_sz = graph[src].size();
		for (int i = 0; i < g_sz; i++) {
			dfs(graph, graph[src][i], dst);
		}

		path.pop_back();
	}

	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		int sz = graph.size();
		dfs(graph, 0, sz - 1);

		return ans;
	}
};

int main() {
	Solution sol;
	vector<vector<int>> input, output;

	input.push_back({ 1,2 });
	input.push_back({ 3 });
	input.push_back({ 3 });
	input.push_back({ });

	output = sol.allPathsSourceTarget(input);

	int sz = output.size();
	for (int i = 0; i < sz; i++) {
		int ssz = output[i].size();
		for (int j = 0; j < ssz; j++) {
			cout << output[i][j] << " "; // [[0, 1, 3], [0, 2, 3]]
		} cout << endl;
	} cout << endl;

	return 0;
}