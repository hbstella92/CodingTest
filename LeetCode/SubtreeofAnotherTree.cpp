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
	vector<int> sub_v;
	int sub_sz;

	void preorder(TreeNode* root, vector<int> &v) {
		if (root == nullptr) {
			v.push_back(-1);
			return;
		}

		v.push_back(root->val);
		preorder(root->left, v);
		preorder(root->right, v);
	}

	bool dfs(TreeNode* root) {
		if (root == nullptr) return false;

		if (dfs(root->left) || dfs(root->right)) return true;

		vector<int> root_v;
		preorder(root, root_v);
		int v_sz = root_v.size();

		if (v_sz != sub_sz) return false;

		for (int i = 0; i < v_sz; i++) {
			if (root_v[i] != sub_v[i]) return false;
		}

		return true;
	}

	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		preorder(subRoot, sub_v);
		sub_sz = sub_v.size();

		if (dfs(root) == true) return true;
		else return false;
	}
};

int main() {
	Solution sol;
	TreeNode *root, *subRoot;
	TreeNode node[2000];
	int arr[2000] = { 3,4,5,1,2,4,1,2 };

	for (int i = 0; i < 8; i++) {
		node[i].val = arr[i];
	}
	root = &node[0];
	root->left = &node[1];
	root->right = &node[2];
	root->left->left = &node[3];
	root->left->right = &node[4];

	subRoot = &node[5];
	subRoot->left = &node[6];
	subRoot->right = &node[7];

	if (sol.isSubtree(root, subRoot) == true) {
		cout << "true\n";
	}
	else {
		cout << "false\n";
	}

	return 0;
}