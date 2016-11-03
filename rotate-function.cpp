/* ******************************************************************
 * title: Rotate Function
 * url: https://leetcode.com/problems/rotate-function/
 * date: Thu Nov  3 11:26:38 CST 2016
 * description: n个元素的序列，有n个rotation。每个rotation定义一个value
 * 为sum(A[i] * i ), 求最大的value。
 * general idea: 观察容易发现相邻的rotation之间的差值等于前一个rotation
 * 加上所有元素的和然后减去排最前面的元素乘以总元素个数即n。这个发现让我们
 * 能够在已知某个rotation的value后常数时间计算下一个rotation的value，总时间
 * 复杂度为O(n).
 * tags: math 
 *******************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int> & A) {
        if(A.size() <= 1) return 0;
        int sum = 0;
        int fi = 0;
        for(size_t i = 0; i < A.size(); ++i) {
            sum += A[i];
            fi += i * A[i];
        }
        int ans = fi;
        for(size_t i = A.size() - 1; i >= 1; --i) {
            fi = fi + sum - A.size() * A[i];
            ans = max(ans, fi);
        }
        return ans;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    int n, tmp;
    vector<int> A;
    cin >> n;
    while(n--) {
        cin >> tmp;
        A.push_back(tmp);
    }
    Solution s;
    cout << s.maxRotateFunction(A) << endl;
    return 0;
}
