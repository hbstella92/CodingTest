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

	void dfs(TreeNode *root, int cur_min, int cur_max) {
		if (!root) {
			ans = max(ans, cur_max - cur_min);
			return;
		}

		cur_min = min(cur_min, root->val);
		cur_max = max(cur_max, root->val);

		dfs(root->left, cur_min, cur_max);
		dfs(root->right, cur_min, cur_max);
	}

	int maxAncestorDiff(TreeNode* root) {
		dfs(root, 0x7fffffff, 0);
		return ans;
	}
};

int main() {
	Solution sol;
	TreeNode *root;
	TreeNode node[10];
	int arr[10] = { 8,3,10,1,6,14,4,7,13 };

	for (int i = 0; i < 9; i++) {
		node[i].val = arr[i];
	}

	root = &node[0];
	root->left = &node[1];
	root->right = &node[2];
	root->left->left = &node[3];
	root->left->right = &node[4];
	root->right->right = &node[5];
	root->left->right->left = &node[6];
	root->left->right->right = &node[7];
	root->right->right->left = &node[8];

	cout << sol.maxAncestorDiff(root) << endl; // 7

	return 0;
}