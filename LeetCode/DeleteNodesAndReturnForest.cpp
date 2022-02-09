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
	vector<TreeNode*> ans;
	int v_sz;

	void dfs(TreeNode* &root, vector<int> &to_delete) {
		if (!root) return;

		dfs(root->left, to_delete);
		dfs(root->right, to_delete);

		for (int i = 0; i < v_sz; i++) {
			if (root->val == to_delete[i]) {
				if (root->left) ans.push_back(root->left);
				if (root->right) ans.push_back(root->right);
				root = nullptr;
				delete root;
				return;
			}
		}
	}

	vector<TreeNode*> delNodes(TreeNode *root, vector<int> &to_delete) {
		v_sz = to_delete.size();
		dfs(root, to_delete);
		if (root) ans.push_back(root);
		return ans;
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
	int arr[10] = { 1,2,3,4,5,6,7 };
	vector<int> input = { 3,5 };

	for (int i = 0; i < 7; i++) {
		node[i].val = arr[i];
	}

	root = &node[0];
	root->left = &node[1];
	root->right = &node[2];
	root->left->left = &node[3];
	root->left->right = &node[4];
	root->right->left = &node[5];
	root->right->right = &node[6];

	vector<TreeNode*> output = sol.delNodes(root, input);
	int sz = output.size();

	for (int i = 0; i < sz; i++) {
		cout << output[i]->val << " ";
	} cout << endl;

	return 0;
}