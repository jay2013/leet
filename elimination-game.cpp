/* ******************************************************************
 * title: Elimination Game
 * url: https://leetcode.com/problems/elimination-game/
 * date: Wed Nov  2 23:42:17 CST 2016
 * description: 1...n,n个数从左边往右边每隔一个数删掉一个数，删到最右边
 * 以后再从右边往左边开始每隔一个删一个数，问最后删掉的那个数。
 * general idea: 每一轮后数之间的gap变大一倍，因此只要记住第一个数就可以
 * 记住整个一轮的所有数了，O(lgn)时间可以求出最后被删的数。
 * tags: math
 *******************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int lastRemainning(int n) {
        if(n == 1) return 1;
        int f = 1;
        int gap = 1;
        int isltor = 1;
        while(n != 1) {
            if(isltor) {
                f = f + gap;
            } else {
                if(n % 2) {
                    f = f + gap;
                } else {
                    f = f;
                }
            } 
            n /= 2;
            isltor = (isltor + 1)%2;
            gap *= 2;
        }
        return f;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    Solution s;
    cout << s.lastRemainning(n) << endl;
    return 0;
}
