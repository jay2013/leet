/* ******************************************************************
 * title: Length of Last Word
 * url: https://leetcode.com/problems/length-of-last-word/
 * date: Thu Oct 27 21:07:01 CST 2016
 * description: 求一个字符串中最后一个word的长度
 * general idea: 扫一遍
 * tags: string 
 *******************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        size_t len = s.length();
        while(len && s[len - 1] == ' ') --len;
        for(size_t i = 0; i < len; ++i) {
            if(s[i] == ' ') {
                ret = 0;
            } else {
                ++ret;
            }
        }
        return ret;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    string s = "Hello World";
    Solution sl;
    cout << sl.lengthOfLastWord(s) << endl;
    return 0;
}
