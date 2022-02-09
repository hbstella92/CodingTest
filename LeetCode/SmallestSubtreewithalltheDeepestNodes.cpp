#include <iostream>
#include <unordered_map>
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
	unordered_map<TreeNode*, int> m;

	int getHeight(TreeNode* root) {
		if (!root) return 0;
		if (root->left == nullptr && root->right == nullptr) return 1;
		
		m[root->left] = getHeight(root->left);
		m[root->right] = getHeight(root->right);
		m[root] = max(m[root->left], m[root->right]) + 1;
		return m[root];
	}

	TreeNode* dfs(TreeNode* root) {
		if (!root) return nullptr;

		if (m[root->left] < m[root->right]) {
			root = dfs(root->right);
		}
		else if (m[root->left] > m[root->right]) {
			root = dfs(root->left);
		}

		return root;
	}

	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		getHeight(root);
		return dfs(root);
	}
};

void dbg(TreeNode *root) {
	if (!root) return;

	cout << root->val << ' ';
	dbg(root->left);
	dbg(root->right);
}

int main() {
	Solution sol;
	TreeNode *root;
	TreeNode node[10];
	int arr[10] = { 3,5,1,6,2,0,8,7,4 };

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
	root->left->right->left = &node[7];
	root->left->right->right = &node[8];

	TreeNode *output = sol.subtreeWithAllDeepest(root);

	dbg(output);

	return 0;
}