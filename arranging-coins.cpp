/* ******************************************************************
 * title: Arranging Coins 
 * url: https://leetcode.com/problems/arranging-coins/
 * date: Sun Nov  6 16:18:34 CST 2016
 * description: n个东西第i行放i个，最多能放多少行。
 * general idea: 抽象出数学形式就是$$\frac{x(x+1)}{x} + y = n, (0 <= y <= x)$$,
 * 可以通过对x二分去求解x。
 * tags: math
 *******************************************************************/
#include <iostream>
using namespace std;

class Solution {
    long long arrangeCoins(long long n, long long l, long long r) {
        if(l == r) return l;
        long long mid = (l + r)/2;
        long long tmp = mid * (mid + 1) / 2;
        if(tmp <= n && tmp >= n - mid) return mid;
        else if(tmp <= n) {
            return arrangeCoins(n, mid + 1, r);
        } else {
            return arrangeCoins(n, l, mid - 1);
        }
    }

public:
    int arrangeCoins(int n) {
        if(n <= 1) return n;
        return arrangeCoins(n, 1, n);
    }
};
int main() {
    freopen("input.txt", "r", stdin);
    return 0;
}
