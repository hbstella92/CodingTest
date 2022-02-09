#include <iostream>
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
	int cur_sum = 0;

	void dfs(TreeNode *root) {
		if (root == nullptr) return;

		dfs(root->right);
		root->val += cur_sum;
		cur_sum = root->val;
		dfs(root->left);
	}

	TreeNode* bstToGst(TreeNode* root) {
		dfs(root);

		return root;
	}
};

int main() {
	Solution sol;
	TreeNode *root, *ans;
	TreeNode node[20];
	int arr[20] = { 4,1,6,0,2,5,7,3,8 };

	for (int i = 0; i < 9; i++) {
		node[i].val = arr[i];
	}

	root = &node[0];

	root->left = &node[1];
	root->right = &node[2];

	root->left->left = &node[3];
	root->left->right = &node[4];
	root->right->left = &node[5];
	root->right->right = &node[6];

	root->left->right->right = &node[7];
	root->right->right->right = &node[8];

	ans = sol.bstToGst(root); // [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

	return 0;
}