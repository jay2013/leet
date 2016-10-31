/* ******************************************************************
 * title: Find All Anagrams in a String
 * url: https://leetcode.com/problems/find-all-anagrams-in-a-string/
 * date: Mon Oct 31 11:33:16 CST 2016
 * description: 找出字符串s中p的所有anagrams出现的位置。
 * general idea: 使用一个hash表记录p中每个字符出现的次数。扫描字符串
 * s，hash表记录s中l到i区间字符都是s中的字符的情况下，还需要哪些字符
 * 就意味着出现一次p的anagrams了。需要注意的是怎么维护这个hash表！具体
 * 逻辑感觉还是看代码比较直接。
 * tags: string 
 *******************************************************************/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unsigned hash[26], len = p.length();
        memset(hash, 0, sizeof(hash));
        for(size_t i = 0; i < len; ++i) {
            hash[p[i] - 'a'] ++;
        }
        vector<int> v;
        size_t l = 0;
        for(size_t i = 0; i < s.length(); ++i) {
            if(hash[s[i] - 'a'] == 0) {
                while(l < i  && hash[s[i] - 'a'] == 0) {
                    hash[s[l++] - 'a'] ++;
                }
                if(hash[s[i] - 'a'] == 0) {
                    l = i + 1;
                } else {
                    hash[s[i] - 'a'] --;
                }
            } else {
                hash[s[i] - 'a'] --;
            }  
            if( i - l + 1 == len) {
                v.push_back(l);
            }
        }
        return v;
    }   
};

int main() {
    // string s = "cbaebabacd", p = "abc";
    string s = "abab", p = "ab";
    Solution ss;
    vector<int> v = ss.findAnagrams(s, p);
    for(size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
