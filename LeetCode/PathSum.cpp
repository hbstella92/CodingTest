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
	TreeNode* root_node;
	bool ans;

	void dfs(TreeNode* root, int curSum, int targetSum) {
		if (ans == true) return;

		if (root->left == nullptr && root->right == nullptr) {
			if (curSum + root->val == targetSum) ans = true;
			return;
		}

		if(root->left != nullptr) dfs(root->left, curSum + root->val, targetSum);
		if (root->right != nullptr) dfs(root->right, curSum + root->val, targetSum);
	}

	bool hasPathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) return false;

		root_node = root;

		if (root->left == nullptr && root->right == nullptr) {
			if (root->val == targetSum) return true;
			else return false;
		}

		ans = false;
		dfs(root, 0, targetSum);
		return ans;
	}
};

int main() {
	Solution sol;
	TreeNode *root;
	TreeNode node[5000];
	int arr[5000] = { 5,4,8,11,13,4,7,2,1 };

	for (int i = 0; i < 9; i++) {
		node[i].val = arr[i];
	}
	root = &node[0];
	root->left = &node[1];
	root->right = &node[2];
	root->left->left = &node[3];
	root->right->left = &node[4];
	root->right->right = &node[5];
	root->left->left->left = &node[6];
	root->left->left->right = &node[7];
	root->right->right->right = &node[8];

	if (sol.hasPathSum(root, 22) == true) { // true
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}