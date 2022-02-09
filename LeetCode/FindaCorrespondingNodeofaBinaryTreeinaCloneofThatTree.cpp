#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
		if (original == nullptr) return nullptr;

		if (original == target) return cloned;

		TreeNode *l = getTargetCopy(original->left, cloned->left, target);
		TreeNode *r = getTargetCopy(original->right, cloned->right, target);

		return (l != nullptr) ? l : r;
	}
};

int main() {
	Solution sol;
	TreeNode *root, *clone, *target, *ans;
	TreeNode *node[10];
	int arr[10] = { 7, 4, 3, 6, 19 };

	for (int i = 0; i < 5; i++) {
		node[i]->val = arr[i];
	}

	root = node[0];
	root->left = node[1];
	root->right = node[2];
	root->right->left = node[3];
	root->right->right = node[4];

	clone = root;

	target->val = 3;

	ans = sol.getTargetCopy(root, clone, target);

	return 0;
}