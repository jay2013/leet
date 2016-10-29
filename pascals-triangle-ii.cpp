/* ******************************************************************
 * title: Pascal's Triangle II
 * url: https://leetcode.com/problems/pascals-triangle-ii/
 * date: Sat Oct 29 14:32:43 CST 2016
 * description: 打印帕斯卡三角形第k行
 * general idea: 根据组合数学知识知：C(k,0), C(k,1), C(k,2), ... , C(k,k).
 * tags: math
 *******************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        if(rowIndex < 0) return ret;
        long long rcd = 1;
        ret.push_back(rcd);
        int up = rowIndex, low = 1;
        while(up >= 1) {
            rcd = rcd * up / low;
            ret.push_back((int)rcd);
            up --;
            low ++;
        }
        return ret;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    Solution s;
    vector<int> r = s.getRow(n);
    for(size_t i = 0; i < r.size(); ++i) {
        cout << r[i] << " ";
    }
    cout << endl;
    return 0;
}
