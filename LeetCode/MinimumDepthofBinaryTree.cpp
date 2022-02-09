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
	int ans = -1;

	void dfs(TreeNode *root, int cur_depth) {
		if (root->left == nullptr && root->right == nullptr) {
			if (ans == -1) {
				ans = cur_depth;
			}

			ans = (ans > cur_depth) ? cur_depth : ans;
			return;
		}

		if (root->left != nullptr) dfs(root->left, cur_depth + 1);
		if (root->right != nullptr) dfs(root->right, cur_depth + 1);
	}

	int minDepth(TreeNode* root) {
		if (root == nullptr) return 0;

		dfs(root, 1);
		return ans;
	}
};

int main() {
	Solution sol;
	TreeNode *root;
	TreeNode node[100];
	int arr[100] = { 3,9,20,15,7 };

	for (int i = 0; i < 5; i++) {
		node[i].val = arr[i];
	}

	root = &node[0];
	root->left = &node[1];
	root->right = &node[2];
	root->right->left = &node[3];
	root->right->right = &node[4];

	cout << sol.minDepth(root) << endl; // 2

	return 0;
}