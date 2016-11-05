/* ******************************************************************
 * title: [hiho program title]
 * url: https://leetcode.com/problems/reverse-vowels-of-a-string/
 * date: Sat Nov  5 11:00:37 CST 2016
 * description: 给定字符串s，反转其中的元音字母。
 * general idea: 双指针反转就可以了，我最初理解为旋转，然后就挂了，不开心！
 * tags: string
 *******************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'o' || ch == 'e' || ch == 'i' || ch == 'u'
            || ch == 'A' || ch == 'O' || ch == 'E' || ch == 'I' || ch == 'U';
    }
public:
    string reverseVowels(string s) {
        char ch;
        int l = 0, r = s.length() - 1;
        while(l < r) {
            while(l < r && !isVowel(s[l])) ++l;
            while(l < r && !isVowel(s[r])) --r;
            ch = s[l];
            s[l] = s[r];
            s[r] = ch;
            l++;
            --r;
        }
        return s;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    string s;
    Solution sl;
    while(cin >> s) {
        cout << sl.reverseVowels(s) << endl;
    }
    return 0;
}
