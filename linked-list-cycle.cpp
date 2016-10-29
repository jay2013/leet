/* ******************************************************************
 * title: Linked List Cycle
 * url: https://leetcode.com/problems/linked-list-cycle/
 * date: Sat Oct 29 15:17:59 CST 2016
 * description: 判断一个链表是否含有环
 * general idea: 首先最自然的想法肯定是hash来做，遇到一个结点就记录下来
 * 如果有环的话，必定会出现hash碰撞，因为有的节点会不止一次访问到。还可以
 * 将此题设想成追赶问题，如果有圈的话，那么跑的快的人一定能和跑的慢的人再
 * 相遇，路程差肯定是环周长的整数倍，可以设计两个指针，一个步速为1,另一个
 * 步速为2,这样可以确保相遇时，跑的快的比跑的慢的恰好多跑一圈。
 * tags: link-list
 *******************************************************************/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode (int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode * head) {
        ListNode * fast = head;
        ListNode * slow = head;
        while(true) {
            if(fast == NULL) return false;
            fast = fast->next;
            if(fast == NULL) return false;
            fast = fast->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    return 0;
}
