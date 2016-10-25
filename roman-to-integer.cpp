/* ******************************************************************
 * title: roman to interger
 * url: https://leetcode.com/problems/roman-to-integer/
 * date: Tue Oct 25 09:57:47 CST 2016
 * description: 给定合法的罗马数字，转成十进制整数。
 * general idea: 学习别人的思路咯！
 * tags: unordered_map 
 *******************************************************************/
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution { public:
    int romanToInt(string s) {
        unordered_map<char, int> m({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}});
        int ans = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            int val = m[s[i]];
            if(i == s.size() - 1 || m[s[i + 1]] <= m[s[i]]) ans += val;
            else ans -= val;
        }
        return ans;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    Solution s;
    string lm;
    cin >> lm;
    cout << s.romanToInt(lm) << endl;
    return 0;
}
