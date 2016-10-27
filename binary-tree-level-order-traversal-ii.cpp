/* ******************************************************************
 * title:  Binary Tree Level Order Traversal II
 * url: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
 * date: Thu Oct 27 22:29:00 CST 2016
 * description: 将一棵二叉树从底到根从左到右的顺序打印出来。
 * general idea: 使用一个队列辅助对整棵树进行层序遍历，然后将遍历的每个结点
 * 及其深度记录下来存入一个栈中，然后逐个出栈时记录每一层元素。
 * tags: bin-tree stack queue
 *******************************************************************/
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode * root) {
        vector<vector<int> > ret;
        if(root == NULL) return ret; 
        queue<pair<TreeNode *, int> > qu;
        stack<pair<TreeNode *, int> > st;
        qu.push(make_pair(root, 1));
        while(!qu.empty()) {
            pair<TreeNode *, int> pr = qu.front();
            qu.pop();
            st.push(pr);
            TreeNode * curr = pr.first;
            int dpth = pr.second;
            if(curr->left != NULL) {
                qu.push(make_pair(curr->left, dpth + 1));
            }
            if(curr->right != NULL) {
                qu.push(make_pair(curr->right, dpth + 1));
            }
        }
        vector<int> v;
        int dp = -1;
        while(!st.empty()) {
            pair<TreeNode *, int> pr = st.top();
            st.pop();
            if(pr.second != dp) {
                if(!v.empty()) {
                    ret.push_back(v);
                }
                v.clear();
                dp = pr.second;
            }
            v.insert(v.begin(), pr.first->val);
            // v.push_back(pr.first->val);
        }
        if(!v.empty()) {
            ret.push_back(v);
        }
        return ret;
    } 
};

int main() {
    // freopen("input.txt", "r", stdin);
    TreeNode * root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution s;
    vector<vector<int> > ret = s.levelOrderBottom(root);
    for(size_t i = 0; i < ret.size(); ++i) {
        for(size_t j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
