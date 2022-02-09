#include <iostream>
#include <vector>
#include <cstdlib>
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
	void fillVector(TreeNode *root, vector<TreeNode*> &v) {
		if (root == nullptr) return;

		fillVector(root->left, v);
		v.push_back(root);
		fillVector(root->right, v);
	}

	TreeNode* balance(vector<TreeNode*> &v, int s, int e) {
		if (s == e) {
			v[s]->left = v[s]->right = nullptr;
			return v[s];
		}

		if (s > e) return nullptr;
		int mid = (s + e) / 2;
		v[mid]->left = balance(v, s, mid - 1);
		v[mid]->right = balance(v, mid + 1, e);
		return v[mid];
	}

	TreeNode* balanceBST(TreeNode* root) {
		vector<TreeNode*> v;
		fillVector(root, v);
		int v_sz = v.size();
		return balance(v, 0, v_sz - 1);
	}
};

void dbg(TreeNode *root) {
	if (root == nullptr) {
		cout << "null" << ' ';
		return;
	}

	dbg(root->left);
	cout << root->val << ' ';
	dbg(root->right);
}

int main() {
	Solution sol;
	TreeNode *root;
	TreeNode node[100];
	int arr[100] = { 1,2,3,4 };

	for (int i = 0; i < 4; i++) {
		node[i].val = arr[i];
	}

	root = &node[0];
	root->right = &node[1];
	root->right->right = &node[2];
	root->right->right->right = &node[3];

	sol.balanceBST(root);

	dbg(root); cout << endl;

	return 0;
}