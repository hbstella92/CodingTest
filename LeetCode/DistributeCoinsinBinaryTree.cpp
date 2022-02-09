#include <iostream>
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
	int ans = 0;

	int dfs(TreeNode *root) {
		if (!root) return 0;

		int l = dfs(root->left);
		int r = dfs(root->right);
		ans += abs(l) + abs(r);

		return (root->val + l + r - 1);
	}

	int distributeCoins(TreeNode* root) {
		dfs(root);
		return ans;
	}
};

int main() {
	Solution sol;
	TreeNode *root;
	TreeNode node[10];
	int arr[10] = { 3,0,0 };

	for (int i = 0; i < 3; i++) {
		node[i].val = arr[i];
	}

	root = &node[0];
	root->left = &node[1];
	root->right = &node[2];

	cout << sol.distributeCoins(root) << endl; // 2

	return 0;
}