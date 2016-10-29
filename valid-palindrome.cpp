/* ******************************************************************
 * title: Valid Palindrome
 * url: https://leetcode.com/problems/valid-palindrome/
 * date: Sat Oct 29 14:53:04 CST 2016
 * description: 给定一个字符串，之考虑其中的字符和数字，并且对于字符不
 * 考虑其大小写，判断给定的字符串是否是一个回文串。
 * general idea: 先预处理，将不考虑的东西统统去掉之后，判断处理后的串是否
 * 是一个回文串，双指针判断即可。
 * tags: string
 *******************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for(size_t i = 0; i < s.length(); ++i) {
            if(s[i] <= 'z' && s[i] >= 'a') {
                t += s[i];
            } else if(s[i] <= 'Z' && s[i] >= 'A') {
                t += s[i] + 'a' - 'A';
            } else if(s[i] <= '9' && s[i] >= '0') {
                t += s[i];
            }
        }
        bool ret = true;
        int l = 0;
        int r = t.length() - 1;
        while(l < r) {
            if(t[l] != t[r]) {
                ret = false;
                break;
            }
            ++l;
            --r;
        }
        return ret;
    }    
};

int main() {
    // freopen("input.txt", "r", stdin);
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    Solution s;
    cout << s.isPalindrome(s1) << endl;
    cout << s.isPalindrome(s2) << endl;
    return 0;
}
