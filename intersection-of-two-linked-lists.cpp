/* ******************************************************************
 * title: Intersection of Two Linked Lists
 * url: https://leetcode.com/problems/intersection-of-two-linked-lists/
 * date: Fri Oct 28 22:01:45 CST 2016
 * description: 两个单链表可能会有一段是共享的，使用O(n)时间O(1)空间寻找
 * 共享的那段的开始结点指针。
 * general idea: 首先计算两个链表的长度，由于共享的那一段长度是一样的，所以
 * 先对齐两个链表，接着去找相交的那个结点。
 * tags: link-list
 *******************************************************************/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
        int lenA = 0, lenB = 0;
        ListNode * curr = headA;
        while(curr) {
            ++lenA;
            curr = curr->next;
        }
        curr = headB;
        while(curr) {
            ++lenB;
            curr = curr->next;
        }
        while(lenA != lenB) {
            if(lenA > lenB) {
                headA = headA->next;
                --lenA;
            } else {
                headB = headB->next;
                --lenB;
            }
        }
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }    
};

int main() {
    // freopen("input.txt", "r", stdin);
    ListNode * headA = new ListNode(1);
    headA->next = new ListNode(2);
    ListNode * headB = new ListNode(3);
    headB->next = new ListNode(4);
    headB->next->next = new ListNode(5);
    headB->next->next->next = headA->next->next = new ListNode(6);
    headA->next->next->next = new ListNode(7);
    Solution s;
    cout << s.getIntersectionNode(headA, headB)->val << endl;
    return 0;
}
