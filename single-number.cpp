/* ******************************************************************
 * title: Single Number
 * url: https://leetcode.com/problems/single-number/
 * date: Fri Oct 28 22:29:09 CST 2016
 * description: 给定数组中除了一个数是仅出现一次外，其他都是成对出现的
 * 要求在O(n)时间O(1)空间内找到那个特别的数并返回。
 * general idea: 利用异或运算的性质，a^a=0;a^0=a;
 * tags: math
 *******************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> & nums) {
        int ans = 0;
        for(size_t i = 0; i < nums.size(); ++i) {
            ans ^= nums[i];
        }
        return ans;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    int n, tmp;
    cin >> n;
    vector<int> v;
    while(n--) {
        cin >> tmp;
        v.push_back(tmp);
    }
    Solution s;
    cout << s.singleNumber(v) << endl;
    return 0;
}
