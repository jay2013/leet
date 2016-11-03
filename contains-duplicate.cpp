/* ******************************************************************
 * title: Contains Duplicate
 * url: https://leetcode.com/problems/contains-duplicate/
 * date: Thu Nov  3 22:44:01 CST 2016
 * description: check一个vector中是否有重复元素
 * general idea: 最笨的方法当然是对每一个元素都扫描一次数组去确认一下
 * 是否重复，O(n^2), 代码中的方法是使用一个无序map来记录辅助check，
 * 因此扫一遍就可以了，时间复杂度可能是O(nlgn).
 * tags: unordered_map 
 *******************************************************************/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> & nums) {
        unordered_map<int, int> hs;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(hs[nums[i]] == 0) {
                hs[nums[i]] ++;
            } else if (hs[nums[i]] == 1) {
                return true;
            }
        }
        return false;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    return 0;
}
