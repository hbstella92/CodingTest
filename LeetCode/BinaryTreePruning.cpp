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
	int check(TreeNode* root, int c)
	{
		if (root != NULL)
		{
			if (root->val == 1)
			{
				c = 1;
				return c;
			}
			c = check(root->left, c);
			c = check(root->right, c);
		}
		return c;
	}
	TreeNode* pruneTree(TreeNode* root)
	{
		if (root != NULL)
		{
			if (check(root, 0) == 0)
			{
				root = NULL;
				return root;
			}
			root->left = pruneTree(root->left);
			root->right = pruneTree(root->right);
		}
		return root;
	}
};

int main() {
	Solution sol;
	TreeNode *root;
	TreeNode node[10];
	int arr[10] = { 1,0,0,1 };

	for (int i = 0; i < 4; i++) {
		node[i].val = arr[i];
	}

	root = &node[0];
	root->right = &node[1];
	root->right->left = &node[2];
	root->right->right = &node[3];

	root = sol.pruneTree(root);

	return 0;
}