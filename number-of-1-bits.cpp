/* ******************************************************************
 * title: Number of 1 Bits
 * url: https://leetcode.com/problems/number-of-1-bits/
 * date: Fri Oct 28 11:38:32 CST 2016
 * description: 求一个无符号整数的二进制表示中有多少个1
 * general idea: 不断右移位操作，然后将得到的数和1按位与，如果大于0,则意味
 * 着一位是1,累加器加1即可。
 * tags: basic
 *******************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(n) {
            if(n & 1) {
                ++ret;
            }
            n >>= 1;
        }
        return ret;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    uint32_t n;
    cin >> n;
    Solution s;
    cout << s.hammingWeight(n) << endl;
    return 0;
}
