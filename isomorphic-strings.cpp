
/* ******************************************************************
 * title: Isomorphic Strings
 * url: https://leetcode.com/problems/isomorphic-strings/
 * date: Thu Nov  3 23:40:31 CST 2016
 * description: 判断两个字符串是否同构
 * general idea: 使用两个hash数组记录两个字符串之间的相互映射关系，如果
 * 后边有字符和前面的映射关系冲突那么就不是同构，否则是同构。需要注意的
 * 是字符串不止有字母，可能还有数字等其他字符！
 * tags: string
 *******************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        vector<int> hashS(300, -1);
        vector<int> hashT(300, -1);
        for(int i = 0; i < n; ++i) {
            if(hashS[s[i]] == -1 && hashT[t[i]] == -1) {
                hashS[s[i]] = t[i];
                hashT[t[i]] = s[i];
            } else if (hashS[s[i]] != t[i]){
                return false;
            }
        }
        return true;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    string s, t;
    Solution sl;
    while(cin  >> s >> t) {
        cout << sl.isIsomorphic(s, t) << endl;
    }
    return 0;
}
