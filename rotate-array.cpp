/* ******************************************************************
 * title: Rotate Array
 * url: https://leetcode.com/problems/rotate-array/
 * date: Fri Oct 28 16:47:59 CST 2016
 * description: 给定n个元素的数组，对每个元素顺时针旋转k下得到的目标数组返回。
 * general idea: 显然旋转n的整数倍后得到的数组和没有旋转的数组是一样的，因此
 * 取k = k % n。从最终结果来看，实际上是将数组的前1～n-k个元素平移到数组右
 * 对齐位置，而将n - k + 1 ～ n的元素平移到左对齐位置。这可以通过三次数组反转
 * 操作得到，具体见代码。
 * tags: array  
 *******************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverse(vector<int> & nums, int l, int r) {
        int tmp;
        while(l < r) {
            tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
            l++;
            r--;
        }
    }
    void rotate(vector<int> & nums, int k) {
        int len = (int)nums.size();
        k = k % len;
        if(len < 2 || k == 0) return;
        reverse(nums, 0, len - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, len - 1);
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    int n, tmp, k;
    vector<int> nums;
    cin >> n;
    while(n--) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    cin >> k;
    Solution s;
    s.rotate(nums, k);
    for(size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
