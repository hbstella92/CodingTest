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
	int cnt = 0;

	int kthSmallest(TreeNode* root, int k) {
		if (!root) return -1;

		int l = kthSmallest(root->left, k);
		if (l != -1) return l;

		cnt++;
		if (k == cnt) return root->val;

		int r = kthSmallest(root->right, k);
		if (r != -1) return r;

		return -1;
	}
};

int main() {
	Solution sol;
	TreeNode *root;
	TreeNode node[10];
	int arr[10] = { 3,1,4,2 };

	for (int i = 0; i < 4; i++) {
		node[i].val = arr[i];
	}

	root = &node[0];
	root->left = &node[1];
	root->right = &node[2];
	root->left->right = &node[3];

	cout << sol.kthSmallest(root, 1) << endl; // 1

	return 0;
}