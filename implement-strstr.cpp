/* ******************************************************************
 * title: implement strstr()
 * url: https://leetcode.com/problems/implement-strstr/
 * date: Thu Oct 27 20:24:11 CST 2016
 * description: 寻找一个字符串在另一个字符串中第一次出现的位置。
 * general idea: 暴力去找，需要注意一下边界条件。
 * tags: basic string
 *******************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack == needle) return 0;
        if(needle.length() == 0) return 0;
        if(haystack.length() < needle.length()) return -1;
        for(size_t i = 0; i <= haystack.length() - needle.length(); ++i) {
            if(haystack[i] != needle[0]) continue;
            bool flag = true;
            for(size_t j = 0; j < needle.length(); ++j) {
                if(haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                return i;
            }
        }
        return -1;
    } 
};

int main() {
    freopen("input.txt", "r", stdin);
    string s1, s2;
    cin >> s1 >> s2;
    Solution s;
    cout << s.strStr(s1, s2) << endl;
    return 0;
}
