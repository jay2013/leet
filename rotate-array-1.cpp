/* ******************************************************************
 * title: Rotate Array
 * url: https://leetcode.com/problems/rotate-array/
 * date: Fri Oct 28 16:47:59 CST 2016
 * description: 给定n个元素的数组，对每个元素顺时针旋转k下得到的目标数组返回。
 * general idea: 显然旋转n的整数倍后得到的数组和没有旋转的数组是一样的，因此
 * 取k = k % n。对于位置为i的元素，它应该被移到j = (i + k)%n的位置，我们先存下
 * j位置的元素，然后将位置为i的元素放置位置j，紧接着在为位置为j的元素放置进行
 * 处理，这样的方法在理想情况下最好是一个替换一个绕一圈下来正好把每个元素放置
 * 到正确位置，但这种情况仅在n%k != 0的情况下发生。多数情况下那样跳了x次之后
 * 又回到位置i：(i + k * x)%n = i，断言：n%k=0的情况下从i=0,1,...n/x - 1出发正
 * 好将所有的元素覆盖。
 * tags: array  
 *******************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int> & nums, int k) {
        int len = (int)nums.size();
        k = k % len;
        if(len < 2 || k == 0) return;
        int t = 1;
        while((t * k)%len) ++t;
        int round = len / t;
        for(int i = 0; i < round; ++i) {
            int curr = i;
            int pre = nums[i];
            do {
                int next = (curr + k) % len;
                int tmp = nums[next];
                nums[next] = pre;
                pre = tmp;
                curr = next;
            } while(i != curr);
        }
        /* int cnt = 0;
         * for(int start = 0; cnt < len; ++start) {
         *     int curr = start;
         *     int pre = nums[start];
         *     do {
         *         int next = (curr + k) % len;
         *         int tmp = nums[next];
         *         nums[next] = pre;
         *         pre = tmp;
         *         curr = next;
         *         ++cnt;
         *     } while(start != curr);
         * } */
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
