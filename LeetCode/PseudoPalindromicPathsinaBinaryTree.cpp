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
	int ans = 0;

	void dfs(TreeNode* root, int cnt[]) {
		if (root->left == nullptr && root->right == nullptr) {
			cnt[root->val] = (cnt[root->val]) ? 0 : 1;

			int odd = 0;
			for (int i = 1; i < 10; i++) {
				if (cnt[i]) odd++;
				if (odd > 1) break;
			}
			if (odd <= 1) ans++;
			cnt[root->val] = (cnt[root->val]) ? 0 : 1;
			return;
		}

		cnt[root->val] = (cnt[root->val]) ? 0 : 1;
		if (root->left) dfs(root->left, cnt);
		if (root->right) dfs(root->right, cnt);
		cnt[root->val] = (cnt[root->val]) ? 0 : 1;
	}

	int pseudoPalindromicPaths(TreeNode* root) {
		int cnt[10] = { 0, };
		dfs(root, cnt);
		return ans;
	}
};

int main() {
	Solution sol;
	TreeNode *root;
	TreeNode node[10];
	//int arr[10] = { 2,3,1,3,1,1 };
	int arr[10] = { 2,1,1,1,3,1 };

	for (int i = 0; i < 6; i++) {
		node[i].val = arr[i];
	}

	/* 2
	root = &node[0];
	root->left = &node[1];
	root->right = &node[2];
	root->left->left = &node[3];
	root->left->right = &node[4];
	root->right->right = &node[5];
	*/

	root = &node[0];
	root->left = &node[1];
	root->right = &node[2];
	root->left->left = &node[3];
	root->left->right = &node[4];
	root->left->right->right = &node[5];

	cout << sol.pseudoPalindromicPaths(root) << endl; // 1

	return 0;
}