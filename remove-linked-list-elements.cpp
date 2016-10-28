/* ******************************************************************
 * title: Remove Linked List Elements
 * url: https://leetcode.com/problems/remove-linked-list-elements/
 * date: Fri Oct 28 11:30:20 CST 2016
 * description: 删除链表中给定元素，返回删除结束的链表。
 * general idea: 扫一遍，发现给定元素，删除即可。
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
    ListNode * removeElements(ListNode * head, int val) {
        ListNode * pre = new ListNode(0);
        pre->next = head;
        ListNode * curr = pre;
        while(curr->next) {
            if(curr->next->val == val) {
                ListNode * tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
            } else {
                curr = curr->next;
            }
        }
        head = pre->next;
        delete pre;
        return head;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    int n,tmp;
    ListNode * head = NULL, *curr = NULL;
    cin >> n;
    while(n --) {
        cin >> tmp;
        if(head == NULL) {
            head = new ListNode(tmp);
            curr = head;
        } else {
            curr->next = new ListNode(tmp);
            curr = curr->next;
        }
    }
    int m;
    cin >> m;
    Solution s;
    curr = head;
    curr = s.removeElements(head, m);
    while(curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    return 0;
}
