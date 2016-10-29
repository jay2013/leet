/* ******************************************************************
 * title: Pascal's Triangle
 * url: https://leetcode.com/problems/pascals-triangle/
 * date: Sat Oct 29 14:07:21 CST 2016
 * description: 打印帕斯卡三角形前n行
 * general idea: 根据规律后一行是前一行相邻两个元素的和，然后首尾为1.
 * tags: math
 *******************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > vv;
        if(numRows == 0) return vv;
        vector<int> v0;
        v0.push_back(1);
        vv.push_back(v0);
        if(numRows == 1) return vv;
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(1);
        vv.push_back(v1);
        if(numRows == 2) return vv;
        for(int i = 2; i <= numRows - 1; ++i) {
            vector<int> vx = vv[i - 1];
            vector<int> vy; 
            vy.push_back(1);
            for(size_t j = 0; j < vx.size() - 1; ++j) {
                vy.push_back(vx[j] + vx[j+1]);
            }
            vy.push_back(1);
            vv.push_back(vy);
        } 
        cout << "size():" << vv.size() << endl;
        return vv;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    cout << n << endl;
    Solution s;
    vector<vector<int> > vv = s.generate(n);
    for(size_t i = 0; i < vv.size(); ++i) {
        for(size_t j = 0;j < vv[i].size(); ++j) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
