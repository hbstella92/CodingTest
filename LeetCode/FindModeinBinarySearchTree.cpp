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
	void fillValueInorder(TreeNode* root, vector<int> &v) {
		if (root == nullptr) return;

		fillValueInorder(root->left, v);
		v.push_back(root->val);
		fillValueInorder(root->right, v);
	}

	vector<int> findMode(TreeNode* root) {
		vector<int> value_vector, ans;

		fillValueInorder(root, value_vector);

		int v_sz = value_vector.size();

		if (v_sz == 1) return value_vector;

		int cur_max = 1, real_max = 1;
		for (int i = 0; i < v_sz - 1; i++) {
			cur_max = ((value_vector[i] == value_vector[i + 1]) ? cur_max + 1 : 1);

			if (real_max < cur_max) {
				real_max = cur_max;
			}
		}

		if (real_max == 1) return value_vector;

		cur_max = 1;
		for (int i = 0; i < v_sz - 1; i++) {
			cur_max = ((value_vector[i] == value_vector[i + 1]) ? cur_max + 1 : 1);

			if (cur_max == real_max) ans.push_back(value_vector[i]);
		}

		return ans;
	}
};

int main() {
	Solution sol;
	TreeNode* root;
	TreeNode node[10000];
	vector<int> output;

	root = &node[0];
	root->val = 1;
	root->right = &node[1];
	root->right->val = 2;
	root->right->left = &node[2];
	root->right->left->val = 2;

	output = sol.findMode(root);

	int sz = output.size();
	for (int i = 0; i < sz; i++) {
		cout << output[i] << ' ';
	} cout << endl;

	return 0;
}