#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<int> ans;
	map<int, int> m;
	int maxval = INT_MIN;

	void dfs(TreeNode* root) {
		if (!root) return;

		dfs(root->left);
		dfs(root->right);
		if (root->left) root->val += root->left->val;
		if (root->right) root->val += root->right->val;

		m[root->val]++;
		maxval = max(maxval, m[root->val]);
	}

	vector<int> findFrequentTreeSum(TreeNode* root) {
		dfs(root);

		for (auto i : m) {
			if (i.second == maxval) ans.push_back(i.first);
		}

		return ans;
	}
};

int main() {
	Solution sol;
	TreeNode *root;
	TreeNode node[10];
	int arr[10] = { 5,2,-3 };

	for (int i = 0; i < 3; i++) {
		node[i].val = arr[i];
	}

	root = &node[0];
	root->left = &node[1];
	root->right = &node[2];

	vector<int> output = sol.findFrequentTreeSum(root);
	for (auto i : output) {
		cout << i << ' ';
	} cout << endl;

	return 0;
}