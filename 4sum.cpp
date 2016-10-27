/* ******************************************************************
 * title: 4 sum
 * url: https://leetcode.com/problems/4sum/
 * date: Thu Oct 27 16:45:15 CST 2016
 * description: 找出n个数中和为m的所有四元组。
 * general idea: 对数组排序，然后枚举，先选定两个元素之后，在剩下的n-2个
 * 元素中使用双指针求和，时间复杂度为O(n^3). 需要考虑多个细节，比如
 * 数组输入为0个元素时怎么处理，数组有重复元素时，如何去除重复元组。
 * tags: two-pointer
 *******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> & nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ret;
        if(nums.size() < 4) return ret;
        for(size_t i = 0; i < nums.size() - 3; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(size_t j = i + 1; j < nums.size() - 2; ++j) {
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                size_t left = j + 1, right = nums.size() - 1;
                while(left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target) {
                        vector<int> vi;
                        vi.push_back(nums[i]);
                        vi.push_back(nums[j]);
                        vi.push_back(nums[left]);
                        vi.push_back(nums[right]);
                        ret.push_back(vi);
                        while(left < right && nums[left + 1] == nums[left]) ++left;
                        ++left;
                        while(left < right && nums[right - 1] == nums[right]) --right;
                        --right;
                    } else if (sum > target) {
                        --right;
                    } else {
                        ++left;
                    }
                }
            }
        }
        return ret;
    }

};

int main() {
    freopen("input.txt", "r", stdin);
    int n, tmp, target;
    vector<int> nums;
    cin >> n;
    while(n--) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    cin >> target;
    Solution s;
    vector<vector<int> > ret = s.fourSum(nums, target);
    for(size_t i = 0; i < ret.size(); ++i) {
        for(size_t j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
