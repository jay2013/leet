/* ******************************************************************
 * title: Letter Combinations of a Phone Number
 * url: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * date: Tue Oct 25 22:03:48 CST 2016
 * description: 给你一个数字串，每个数字可能对应多种字母，让你给出这个数字串可能
 * 对应的所有字母串。
 * general idea: 用一个数组记录每个数字可能对应的字母，然后dfs就可以了。
 * tags: dfs 
 *******************************************************************/
#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string map[10];
    set<string> st;
    Solution () {
        map[0] = " ";
        map[1] = " ";
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";
    }
    void solve(string digits, size_t pos, string curr, vector<string> & ans) {
        if(pos == digits.length()) {
            if(st.find(curr) == st.end()) {
                st.insert(curr);
                ans.push_back(curr);
            } 
        } else {
            int digit = digits[pos] - '0';
            for(size_t i = 0; i < map[digit].length(); ++i) {
                if(map[digit][i] != ' ') {
                    solve(digits, pos + 1, curr + map[digit][i], ans);
                } else {
                    solve(digits, pos + 1, curr, ans);
                }
            }
        } 
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) {
            return ans;
        }
        string curr = "";
        solve(digits, 0, curr, ans); 
        st.clear();
        return ans;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    Solution s;
    string ss;
    cin >> ss;
    vector<string> ret = s.letterCombinations(ss);
    for(size_t i = 0; i < ret.size(); ++i) {
        cout << ret[i] << endl;
    }
    return 0;
}
