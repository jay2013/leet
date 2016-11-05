/* ******************************************************************
 * title: First Unique Character in a String 
 * url: https://leetcode.com/problems/first-unique-character-in-a-string/
 * date: Sat Nov  5 23:34:42 CST 2016
 * description: 寻找第一个没有重复出现的字符
 * general idea: hash一遍，再扫一遍
 * tags: string
 *******************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(26, 0);
        for(size_t i = 0; i < s.length(); ++i) {
            v[s[i] - 'a'] ++;
        }
        for(size_t i = 0; i < s.length(); ++i) {
            if(v[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    string t;
    Solution s;
    while(cin >> t) {
        cout << s.firstUniqChar(t) << endl;
    }
    return 0;
}
