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
	int sum = 0;

	TreeNode* convertBST(TreeNode* root) {
		if (!root) return nullptr;

		root->right = convertBST(root->right);

		root->val += sum;
		sum = root->val;

		root->left = convertBST(root->left);
		return root;
	}
};

int main() {
	Solution sol;
	TreeNode *root;
	TreeNode node[10];
	int arr[10] = { 4,1,6,0,2,5,7,3,8 };

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

	sol.convertBST(root);

	return 0;
}