/* ******************************************************************
 * title: integer to roman
 * url: https://leetcode.com/problems/integer-to-roman/
 * date: Sun Oct 23 13:32:15 CST 2016
 * description: 将不超过3999的非零整数转化为对应罗马数字。
 * general idea: 没有思路，学习别人的代码，了解一下转换规则
 * tags: basic coding 
 *******************************************************************/
#include <iostream>
#include <stack>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <string>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

class Solution {
public:
    string intToRoman(int sum) {
        int base[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; 
        string str[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans = "";
        int i = 0;
        while(sum != 0) {
            if(sum >= base[i]) {
                sum -= base[i];
                ans += str[i];
            } else {
                ++i;
            }
        }
        return ans;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    Solution s;
    int n;
    while(cin >> n) {
        cout << n << ":" << s.intToRoman(n) << endl;
    }
    return 0;
}
