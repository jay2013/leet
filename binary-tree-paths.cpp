/* ******************************************************************
 * title: Binary Tree Paths
 * url: https://leetcode.com/problems/binary-tree-paths/
 * date: Sun Nov  6 14:48:47 CST 2016
 * description: 搜集一棵二叉树从root到leaf的所有路径。
 * general idea: bfs或者dfs同时记录路径即可。
 * tags: bin-tree bfs
 *******************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode * root) {
        vector<string> ret;
        if(root == NULL) return ret;
        queue<pair<TreeNode *, string> > qu;
        ostringstream oss;
        oss << root->val;
        qu.push(make_pair(root, oss.str()));
        while(!qu.empty()) {
            pair<TreeNode *, string > top = qu.front();
            qu.pop();
            if(top.first->left == NULL && top.first->right == NULL) {
                ret.push_back(top.second);
            } else {
                if(top.first->left != NULL) {
                    ostringstream osl;
                    osl << "->" << top.first->left->val;
                    qu.push(make_pair(top.first->left, top.second + osl.str()));
                } 
                if(top.first->right != NULL) {
                    ostringstream osr;
                    osr << "->" << top.first->right->val;
                    qu.push(make_pair(top.first->right, top.second + osr.str()));
                } 
            }
        }
        return ret;
    } 
};

int main() {
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    Solution sl;
    vector<string> ret = sl.binaryTreePaths(root);
    for(size_t i = 0; i < ret.size(); ++i) {
        cout << ret[i] << endl;
    }
    return 0;
}
