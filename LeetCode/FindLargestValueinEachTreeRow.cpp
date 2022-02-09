#include <iostream>
#include <vector>
#include <climits>
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
	int maxval[10000];
	int max_depth = 0;
	vector<int> ans;

	void dfs(TreeNode *root, int depth) {
		if (!root) return;

		maxval[depth] = max(maxval[depth], root->val);
		max_depth = max(max_depth, depth);

		dfs(root->left, depth + 1);
		dfs(root->right, depth + 1);
	}

	vector<int> largestValues(TreeNode* root) {
		if (!root) return ans;

		fill_n(maxval, 10000, INT_MIN);

		dfs(root, 0);
		for (int i = 0; i <= max_depth; i++) {
			ans.push_back(maxval[i]);
		}

		return ans;
	}
};

int main() {
	Solution sol;
	TreeNode *root;
	TreeNode node[10];
	int arr[10] = { 1,3,2,5,3,9 };

	for (int i = 0; i < 6; i++) {
		node[i].val = arr[i];
	}

	root = &node[0];
	root->left = &node[1];
	root->right = &node[2];
	root->left->left = &node[3];
	root->left->right = &node[4];
	root->right->right = &node[5];

	vector<int> output = sol.largestValues(root);

	return 0;
}