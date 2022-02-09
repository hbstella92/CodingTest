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
	int ans = 0;

	void dfs(TreeNode *root, int target) {
		if (root == nullptr) return;

		if (root->val >= target) {
			ans++;
			target = root->val;
		}

		dfs(root->left, target);
		dfs(root->right, target);
	}

	int goodNodes(TreeNode* root) {
		dfs(root, root->val);
		return ans;
	}
};

int main() {
	Solution sol;
	TreeNode *root;
	TreeNode node[10];
	int arr[10] = { 3,1,4,3,1,5 };

	for (int i = 0; i < 6; i++) {
		node[i].val = arr[i];
	}

	root = &node[0];
	root->left = &node[1];
	root->right = &node[2];
	root->left->left = &node[3];
	root->right->left = &node[4];
	root->right->right = &node[5];

	cout << sol.goodNodes(root) << endl; // 4

	return 0;
}