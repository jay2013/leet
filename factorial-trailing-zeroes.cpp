/* ******************************************************************
 * title: Factorial Trailing Zeroes
 * url: https://leetcode.com/problems/factorial-trailing-zeroes/
 * date: Fri Oct 28 21:12:19 CST 2016
 * description: 给整数n，求n!的末尾有多少个0.
 * general idea: n!=1*2*...*n,统计1～n中2的因子有x个，5的因子
 * 有y个，则n！就有min(x,y)个0在末尾，进一步分析可以发现x始终要比
 * y大，即min(x,y)=y,因此只需要统计因子5出现个数就可以。
 * tags: math
 *******************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int y = 0;
        while(n) {
            y += n / 5;
            n /= 5;
        }
        return y;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    Solution s;
    cout << s.trailingZeroes(n) << endl;
    return 0;
}
