#include <iostream>
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
	int getHeight(TreeNode* root) {
		if (root == nullptr) return 0;

		int left = getHeight(root->left);
		int right = getHeight(root->right);

		return max(left, right) + 1;
	}

	bool dfs(TreeNode* root) {
		if (root == nullptr) return true;

		int left = getHeight(root->left);
		int right = getHeight(root->right);

		if ((abs(left - right) <= 1) && (dfs(root->left) == true) && (dfs(root->right) == true)) return true;
		else return false;
	}

	bool isBalanced(TreeNode* root) {
		if (dfs(root) == true) return true;
		else return false;
	}
};

int main() {
	Solution sol;
	TreeNode* root;
	TreeNode node[5000];
	int arr[5000] = { 3,9,20,15,7 };

	for (int i = 0; i < 5; i++) {
		node[i].val = arr[i];
	}
	root = &node[0];
	root->left = &node[1];
	root->right = &node[2];
	root->right->left = &node[3];
	root->right->right = &node[4];

	if (sol.isBalanced(root) == true) {
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}