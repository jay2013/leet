/* ******************************************************************
 * title: Best Time to Buy and Sell Stock
 * url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * date: Wed Nov  2 15:11:11 CST 2016
 * description: 求n个数中最大差值，任意两个数的差值定义为下标大的数减
 * 下标小的数。
 * general idea: 用一个变量记录已经扫描的数的最小值，然后始终用当前的数减
 * 这个变量并更新答案即可。具体细节看代码吧！
 * tags: O(n) dp
 *******************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
     int maxProfit(vector<int>& prices) {
        int ans = 0;
        if(prices.size() == 0) return ans;
        int mMin = prices[0];
        for(size_t i = 1; i < prices.size(); ++i) {
            if(prices[i] > mMin) ans = max(ans, prices[i] - mMin);
            else mMin = prices[i];
        }
        return ans;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
	int n, tmp;
	vector<int> v;
	cin >> n;
	while(n --) {
		cin >> tmp;
		v.push_back(tmp);
	}
	Solution s;
	cout << s.maxProfit(v) << endl;
    return 0;
}
