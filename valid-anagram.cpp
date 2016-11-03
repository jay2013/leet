/* ******************************************************************
 * title: Valid Anagram
 * url: https://leetcode.com/problems/valid-anagram/
 * date: Thu Nov  3 22:26:36 CST 2016
 * description: check两个字符串是否互为anagram.
 * general idea: 用hash记录前一个字符串中各字符多少，然后对第二个字符串
 * 进行消去，能消完自然就是anagram了。
 * tags: string
 *******************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return 0;
        vector<int> hash(26, 0);
        for(size_t i = 0; i < s.size(); ++i) {
            hash[s[i] - 'a'] ++;
        }
        for(size_t i = 0; i < t.size(); ++i) {
            if(hash[t[i] - 'a']) {
                hash[t[i] - 'a'] --;
            } else {
                return false;
            }
        }
        return true;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;
    Solution sl;
    cout << sl.isAnagram(s, t) << endl;
    return 0;
}
