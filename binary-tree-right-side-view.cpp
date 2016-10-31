/* ******************************************************************
 * title: Binary Tree Right Side View
 * url: https://leetcode.com/problems/binary-tree-right-side-view/
 * date: Mon Oct 31 10:53:08 CST 2016
 * description: 给你一棵二叉树，假定你用这棵树的右侧观察这棵树，打印从
 * 上到下你观测到的每个节点。
 * general idea: 首先层序遍历记录每个结点的层次，然后逆序（层序）每一层
 * 看到的第一个节点就是你看到的。使用一个栈记录层序遍历时从队列依次出来
 * 的结点，这样比较方便处理。
 * tags: bin-tree
 *******************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode * root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<pair<TreeNode *, int> > qu;
        stack<pair<TreeNode *, int> > st;
        stack<pair<TreeNode *, int> > rcd;
        qu.push(make_pair(root, 0));
        TreeNode * curr;
        int lev;
        while(!qu.empty()) {
            pair<TreeNode *, int> pr = qu.front();
            qu.pop();
            st.push(pr);
            curr = pr.first;
            lev = pr.second;
            if(curr->left) qu.push(make_pair(curr->left, lev + 1));
            if(curr->right) qu.push(make_pair(curr->right, lev + 1));
        }
        while(!st.empty()) {
            pair<TreeNode *, int> top = st.top();
            if(rcd.empty() || rcd.top().second != top.second) rcd.push(top); 
            st.pop();
        }
        while(!rcd.empty()) {
            ans.push_back(rcd.top().first->val);
            rcd.pop();
        }
        return ans;
    } 
};

int main() {
    // freopen("input.txt", "r", stdin);
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    Solution s;
    vector<int> v = s.rightSideView(root);
    for(size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    return 0;
}
