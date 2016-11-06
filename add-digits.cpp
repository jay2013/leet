/* ******************************************************************
 * title: Add Digits
 * url: https://leetcode.com/problems/add-digits/
 * date: Sun Nov  6 13:56:36 CST 2016
 * description: 给定非负数n，重复加数字的每一位直到结果只剩一位。
 * general idea: 题目要求用O(1)时间搞定，初看感觉不太可能，但仔细琢磨
 * 一会儿之后发现所有数加上9之后结果不变，这就意味着可以对9取余得到的
 * 结果和原数是一样的，需要注意的是0和9这两种特殊情况。
 * tags: math
 *******************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        if(num % 9 == 0) return 9;
        return num % 9;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    Solution sl;
    cin >> n;
    cout << sl.addDigits(n) << endl;
    return 0;
}
