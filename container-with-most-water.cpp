/* ******************************************************************
 * title: Container With Most Water 
 * url: https://leetcode.com/problems/container-with-most-water/
 * date: Sun Oct 23 12:58:00 CST 2016
 * description: 给你n个数表示(i, ai)到(i, 0)的线，让你找两个数，使得对应
 * 线和x轴构成的二维容器可以存放最多的水.
 * general idea: 由于没有时间限制的说明，最初我使用暴力枚举的方法O(n^2)
 * 的算法TLE了，后来发现从两头往中间边扫边缩，可是将时间复杂度优化到O(n).
 * tags: special trics.
 *******************************************************************/
#include <iostream>
#include <stack>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <string>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
		int mArea = 0;
        int l = 0, r = height.size() - 1;
        while(l < r) {
            mArea  = max(mArea, min(height[l], height[r]) * (r - l));
            if(height[l] <= height[r]) {
                int k = l + 1;
                while(k < r && height[k] < height[l]) ++k;
                l = k;
            } else {
                int k = r - 1;
                while(k > l && height[k] < height[r]) --k;
                r = k;
            }
        }
		// for(size_t i = 0; i < height.size() - 1; ++i) {
        //     for(size_t j = i + 1; j < height.size(); ++j) {
        //        int tmp = min(height[i], height[j]) * (j - i);
        //        mArea = max(mArea, tmp);
        //     }
		// }
        return mArea;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    Solution s;
    vector<int> h;
    int tmp;
    while (cin >> tmp) {
        h.push_back(tmp);
    }
    cout << s.maxArea(h) << endl;
    return 0;
}
