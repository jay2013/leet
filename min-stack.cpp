/* ******************************************************************
 * title: Min Stack
 * url: https://leetcode.com/problems/min-stack/
 * date: Sat Oct 29 13:25:10 CST 2016
 * description: 设计一个数据结构，要求不仅具备普通栈的功能，
 * 还要能够常数时间查询栈中元素最小值。
 * general idea: 组合数据结构，使用两个栈，一个模拟普通栈的
 * 功能，另一个记录当前栈中元素的一个非递增序列，栈顶始终是
 * 普通栈中元素的最小值。
 * tags: stack 
 *******************************************************************/
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> ele;
    stack<int> mMin;
    MinStack() {
        while(!ele.empty()) ele.pop();
        while(!mMin.empty()) mMin.pop();
    }

    void push(int x) {
        ele.push(x);
        if(mMin.empty() || x <= mMin.top()) mMin.push(x);
    }

    void pop() {
        int tp = ele.top();
        ele.pop();
        if(tp == mMin.top()) mMin.pop();
    }

    int top() {
        return ele.top(); 
    }
    
    int getMin() {
        return mMin.top();
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    return 0;
}
