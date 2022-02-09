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
	int ans = 0, max_depth = 0;
	vector<int> v;

	void dfs(TreeNode *root, int depth) {
		if ((root->left == nullptr) && (root->right == nullptr)) {
			if (max_depth < depth) {
				max_depth = depth;
				v.clear();
				v.push_back(root->val);
			}
			else if (max_depth == depth) {
				v.push_back(root->val);
			}
			return;
		}

		if (root->left != nullptr) dfs(root->left, depth + 1);
		if (root->right != nullptr) dfs(root->right, depth + 1);
	}

	int deepestLeavesSum(TreeNode* root) {
		if (root == nullptr) return 0;

		dfs(root, 0);

		int v_sz = v.size();
		for (int i = 0; i < v_sz; i++) {
			ans += v[i];
		}

		return ans;
	}
};

int main() {
	Solution sol;
	TreeNode *root;
	TreeNode node[100];
	int arr[100] = { 1,2,3,4,5,6,7,8 };

	for (int i = 0; i < 8; i++) {
		node[i].val = arr[i];
	}

	root = &node[0];
	
	root->left = &node[1];
	root->right = &node[2];

	root->left->left = &node[3];
	root->left->right = &node[4];
	root->right->right = &node[5];

	root->left->left->left = &node[6];
	root->right->right->right = &node[7];

	cout << sol.deepestLeavesSum(root) << endl; // 15

	return 0;
}