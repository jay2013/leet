/* ******************************************************************
 * title: 3Sum Closest
 * url: https://leetcode.com/problems/3sum-closest/
 * date: Tue Oct 25 21:09:51 CST 2016
 * description: 求数组中3个数的和，使得和与target的绝对值尽可能小。 
 * general idea: 暴力枚举所有可能的三个数的和然后和target比较是一种方法，但时间复杂度
 * 可能超过限制。下面的代码的思路是实现使用O(nlgn)的时间对数组进行一次排序，对排好序
 * 的数组使用two-pointer可以将时间复杂度优化到O(n^2).
 * tags: basic two-pointer
 *******************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> & nums, int target) {
        sort(nums.begin(), nums.end());
        int left, right;
        int ans = abs(nums[0] + nums[1] + nums[2] - target);
        int ret = nums[0] + nums[1] + nums[2];
        for (size_t i = 0; i < nums.size() - 2; ++i) {
            left = i + 1;
            right = nums.size() - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target) {
                    return target;
                } 
                if (abs(sum - target) < ans) {
                    ans = abs(sum - target);
                    ret = sum;
                } 
                if (sum > target) {
                    --right;
                } else {
                    ++ left;
                }
            }
        }
        return ret;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    vector<int> v;
    int n;
    cin >> n;
    while(n --) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    int m;
    cin >> m;
    Solution s;
    cout << s.threeSumClosest(v, m) << endl;
    return 0;
}
