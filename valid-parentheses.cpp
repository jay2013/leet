/* ******************************************************************
 * title: valid parenthese
 * url: https://leetcode.com/problems/valid-parentheses/
 * date: Thu Oct 27 19:43:39 CST 2016
 * description: 给定一个仅含有'(', ')', '{', '}', '[', ']'字符的串
 * 判断该串是否括号匹配。
 * general idea: 基本的stack使用。
 * tags: stack
 *******************************************************************/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        size_t len = s.length();
        if(len == 0) return true;
        stack<char> st;
        for(size_t i = 0; i < len; ++i) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if(st.empty()) return false;
                if(s[i] == ')' && st.top() == '(') {
                    st.pop();
                } else if(s[i] == '}' && st.top() == '{') {
                    st.pop();
                } else if(s[i] == ']' && st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        if(st.empty()) {
            return true;
        } else {
            return false;
        }
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    string s;
    Solution sl;
    cin >> s;
    cout << sl.isValid(s) << endl;
    return 0;
}
