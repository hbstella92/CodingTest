#include <iostream>
#include <vector>
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
	vector<TreeNode*> candidate;

	void findEvenNode(TreeNode *root) {
		if (root == nullptr) return;

		if (!((root->val) % 2)) {
			candidate.push_back(root);
		}

		findEvenNode(root->left);
		findEvenNode(root->right);
	}

	void dfs(TreeNode *root, int cur_depth, int n_depth) {
		if (root == nullptr) return;
		if (cur_depth > n_depth) return;

		if (cur_depth == n_depth) {
			ans += root->val;
			return;
		}

		dfs(root->left, cur_depth + 1, n_depth);
		dfs(root->right, cur_depth + 1, n_depth);
	}

	int sumEvenGrandparent(TreeNode* root) {
		if (root == nullptr) return 0;

		findEvenNode(root);

		int sz = candidate.size();
		for (int i = 0; i < sz; i++) {
			dfs(candidate[i], 0, 2);
		}

		return ans;
	}
};

int main() {
	Solution sol;
	TreeNode *root;
	TreeNode node[20];
	int arr[20] = { 6,7,8,2,7,1,3,9,1,4,5 };

	for (int i = 0; i < 11; i++) {
		node[i].val = arr[i];
	}

	root = &node[0];

	root->left = &node[1];
	root->right = &node[2];

	root->left->left = &node[3];
	root->left->right = &node[4];
	root->right->left = &node[5];
	root->right->right = &node[6];

	root->left->left->left = &node[7];
	root->left->right->left = &node[8];
	root->left->right->right = &node[9];
	root->right->right->right = &node[10];

	cout << sol.sumEvenGrandparent(root) << endl; // 18

	return 0;
}