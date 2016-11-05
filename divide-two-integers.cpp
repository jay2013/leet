/* ******************************************************************
 * title: Divide Two Integers
 * url: https://leetcode.com/problems/divide-two-integers/
 * date: Sat Nov  5 22:17:46 CST 2016
 * description: 不使用乘法、除法和取余操作，为两个整数求除法。
 * general idea: 倍增法求，好像还能进一步优化算法，提升速度。注意溢出，
 * 首先题目中的MAX_INT就是个坑，其次整数边界也要考虑。
 * tags: math
 *******************************************************************/
#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) return INT_MAX;
        if(dividend == 0) return 0;
        int flag = 0;
        if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
            flag = 1;
        } else {
            flag = 0;
        }
        long long Dividend = dividend;
        long long Divisor = divisor;
        if(Dividend < 0) {
            Dividend = -Dividend;
        }
        if(Divisor < 0) {
            Divisor = - Divisor;
        }
        long long ans = 0;
        while(Dividend >= Divisor) {
            long long x = 1, y = Divisor;
            while(Dividend > y + y) {
                x = x + x;
                y = y + y;
            }
            ans += x;
            Dividend -= y;
        }
        if(!flag) ans = - ans;
        if(ans > INT_MAX) return INT_MAX;
        return ans;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    int dividend, divisor;
    Solution sl;
    while(cin >> dividend >> divisor) {
        cout << dividend << " " << divisor << " " << sl.divide(dividend, divisor) << endl;
    }
    return 0;
}
