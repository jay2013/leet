/* ******************************************************************
 * title: Unique Binary Search Trees
 * url: https://leetcode.com/problems/unique-binary-search-trees/
 * date: Tue Nov  1 15:07:50 CST 2016
 * description: 给定n，求所有满足二叉搜索树性质且存储数是1...n的树的数目
 * general idea: 这个题目的高级版本昨天已经A了，但是直接拿那个程序估计
 * 会暴内存，修改版即只算数不构造树但还是会超时，需要一个hash表来记录以及
 * 计算出来的结果，避免重复计算。呃，让我想想，似乎可以不用去递归，直接
 * DP就可以计算DP[n] = sum(DP[0]*DP[n-1], DP[1]*DP[n-2], ..., DP[n-1]*DP[0]);
 * 初始条件DP[0] = DP[1] = 1.
 * tags: bin-tree DP  
 *******************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<int> hash;
    int numTrees(int l, int r) {
        if(l >= r) return 1;
        if(hash[r - l + 1]) return hash[r - l + 1]; 
        int ret = 0;
        for(int i = l; i <= r; ++i) {
            int lC = numTrees(l, i-1);
            if(i - l >= 1) hash[i - l] = lC;
            int rC = numTrees(i+1, r);
            if(r - i >= 1) hash[r - i] = rC;
            ret += lC * rC;
        }
        hash[r - l + 1] = ret;
        return ret;
    }
public:
    int numTrees(int n) {
        if(n >= 1) {
            hash.clear();
            for(int i = 0; i <= n; ++i) hash.push_back(0);
            hash[1] = 1;
        }
        return numTrees(1, n);
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    Solution s;
    cout << s.numTrees(n) << endl;
    return 0;
}
