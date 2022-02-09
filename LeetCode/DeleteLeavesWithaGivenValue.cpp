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
	TreeNode* removeLeafNodes(TreeNode* root, int target) {
		if (root->left) root->left = removeLeafNodes(root->left, target);
		if (root->right) root->right = removeLeafNodes(root->right, target);

		if ((root->left == nullptr) && (root->right == nullptr) && (root->val == target)) return nullptr;

		return root;
	}
};

int main() {
	Solution sol;
	TreeNode *root;
	TreeNode node[10];
	int arr[10] = { 1,2,3,2,2,4 };

	for (int i = 0; i < 6; i++) {
		node[i].val = arr[i];
	}

	root = &node[0];
	root->left = &node[1];
	root->right = &node[2];
	root->left->left = &node[3];
	root->right->left = &node[4];
	root->right->right = &node[5];

	sol.removeLeafNodes(root, 2);

	return 0;
}