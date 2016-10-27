/* ******************************************************************
 * title: Remove Duplicates from Sorted List
 * url: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 * date: Thu Oct 27 21:31:24 CST 2016
 * description: 去掉链表中的重复元素
 * general idea: 扫一遍，维持pre和curr两个指针。
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
    ListNode * deleteDuplicates(ListNode * head) {
        if(head == NULL) return NULL;
        ListNode * pre = head;
        ListNode * curr = head->next;
        while(curr) {
            if(curr->val == pre->val) {
                pre->next = curr->next;
                delete curr;
                curr = curr->next;
            } else {
                pre = curr;
                curr = pre->next;
            }
        }
        return head;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    ListNode * head  = NULL, *curr = NULL;
    int n, tmp;
    cin >> n;
    while(n--) {
        cin >> tmp;
        if(head == NULL) {
            head = new ListNode(tmp);
            curr = head;
        } else {
            curr->next = new ListNode(tmp);
            curr = curr->next;
        }
    } 
    Solution s;
    curr = head;
    curr = s.deleteDuplicates(head);
    while(curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    return 0;
}
