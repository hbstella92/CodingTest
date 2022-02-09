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

	int setDepth(TreeNode* root) {
		if (!root) return 0;

		int l = setDepth(root->left);
		int r = setDepth(root->right);
		m[root] = max(l, r) + 1;
		return m[root];
	}

	int dfs(TreeNode *root) {
		if (root->left == nullptr && root->right == nullptr) {
			return root->val;
		}
		else if (root->left == nullptr) return dfs(root->right);
		else if (root->right == nullptr) return dfs(root->left);

		if (m[root->left] >= m[root->right]) {
			return dfs(root->left);
		}
		else return dfs(root->right);
	}

	int findBottomLeftValue(TreeNode* root) {
		setDepth(root);
		return dfs(root);
	}
};

int main() {
	Solution sol;
	TreeNode *root;
	TreeNode node[10];
	int arr[10] = { 2,1,3 };

	for (int i = 0; i < 3; i++) {
		node[i].val = arr[i];
	}

	root = &node[0];
	root->left = &node[1];
	root->right = &node[2];

	cout << sol.findBottomLeftValue(root) << endl; // 1

	return 0;
}