/* ******************************************************************
 * title: Reverse String
 * url: https://leetcode.com/problems/reverse-string/
 * date: Sat Nov  5 11:22:10 CST 2016
 * description: 翻转字符串
 * general idea: 倒着扫描字符串，将遇到的字符添加到一个新字符串后就好了
 * tags: string
 *******************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int i  = s.length();
        string t = "";
        while(--i >= 0) t += s[i];
        return t;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    string s;
    Solution sl;
    while(cin >> s) {
        cout << sl.reverseString(s) << endl;
    }
    return 0;
}
