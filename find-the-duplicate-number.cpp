/* ******************************************************************
 * title: Find the Duplicate Number
 * url: https://leetcode.com/problems/find-the-duplicate-number/
 * date: Sat Nov  5 15:18:16 CST 2016
 * description: 数组A中有n+1个元素，每个元素均在1～n之间，只有一个元素
 * 是重复出现的，要求用O(1)额外空间，复杂度小于O(n^2)的算法找出重复元素。
 * general idea: 二分查找，最开始也是想了一个O(nlgn)的算法，即先对数组
 * 排序然后扫一遍判断扫到的元素和他前面的那个元素是否一样，如果相同那么
 * 重复元素就找到了，但是题目有提到数组是只读的，不能对数组进行元素调换
 * 因此排序的方法是行不同的。此题可以不同的利用鸽笼原理，二分一个元素n
 * 计数数组中小于$\\frac{n}{2}$的数有多少，等于$\\frac{n}{2}$的数有所少
 * 以及大于$\\frac{n}{2}$的数有多少，然后递归判断就好。
 * tags: binary search
 *******************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int findDuplicate(vector<int> & nums, int l, int r) {
        if(l == r) return l;
        int mid = (l + r) / 2;
        int s = 0, b = 0, e = 0;
        for(size_t i = 0; i < nums.size(); ++i) {
            if(nums[i] < l || nums[i] > r) continue;
            if(nums[i] < mid) {
                s++;
            } else if(nums[i] > mid) {
                b++;
            } else {
                e++;
            }
        }
        if(e >= 2) {
            return mid;
        } else if(s > mid - l) {
            return findDuplicate(nums, l, mid - 1);
        } else {
            return findDuplicate(nums, mid + 1, r);
        }
    } 
public:
    int findDuplicate(vector<int> & nums) {
        int n = nums.size() - 1;
        return findDuplicate(nums, 1, n);
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    vector<int> v;
    int n, tmp;
    cin >> n;
    while(n--) {
        cin >> tmp;
        v.push_back(tmp);
    }
    Solution s;
    cout << s.findDuplicate(v) << endl;
    return 0;
}
