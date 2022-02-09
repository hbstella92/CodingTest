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
	void dfs(TreeNode *root, vector<int> &v) {
		if (root == nullptr) return;

		dfs(root->left, v);
		v.push_back(root->val);
		dfs(root->right, v);
	}

	void cmpVector(vector<int> &rv1, vector<int> &rv2, vector<int> &ans) {
		int sz1 = rv1.size(), sz2 = rv2.size();
		int i = 0, j = 0;

		while ((i < sz1) && (j < sz2)) {
			if (rv1[i] < rv2[j]) {
				ans.push_back(rv1[i++]);
			}
			else if (rv1[i] > rv2[j]) {
				ans.push_back(rv2[j++]);
			}
			else {
				ans.push_back(rv1[i++]);
				ans.push_back(rv2[j++]);
			}
		}

		for (; i < sz1; i++) {
			ans.push_back(rv1[i]);
		}
		for (; j < sz2; j++) {
			ans.push_back(rv2[j]);
		}
	}

	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int> rv1, rv2, ans;

		dfs(root1, rv1);
		dfs(root2, rv2);

		cmpVector(rv1, rv2, ans);
		return ans;
	}
};

int main() {
	Solution sol;
	TreeNode *root1, *root2;
	TreeNode node[20];
	int arr[20] = { 2,1,4,1,0,3 };

	for (int i = 0; i < 6; i++) {
		node[i].val = arr[i];
	}

	root1 = &node[0];
	root1->left = &node[1];
	root1->right = &node[2];

	root2 = &node[3];
	root2->left = &node[4];
	root2->right = &node[5];

	vector<int> output = sol.getAllElements(root1, root2);

	int sz = output.size();
	for (int i = 0; i < sz; i++) {
		cout << output[i] << ' ';
	} cout << endl;

	return 0;
}