/* ******************************************************************
 * title: Partition List 
 * url: https://leetcode.com/problems/partition-list/
 * date: Sat Nov  5 11:55:01 CST 2016
 * description: 将一个链表中小于x的元素按序抽取出来放前面，剩下的元素
 * 放后面得到一个新链表返回。
 * general idea: 将小元素抽取出来放小链表上，大元素抽取出来放大链表上，
 * 然后拼接两个链表就可以了。
 * tags: link-list 
 *******************************************************************/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode * partition(ListNode * head, int x) {
        ListNode * small = new ListNode(0);
        ListNode * big = new ListNode(0);
        ListNode * stail = small;
        ListNode * btail = big;
        ListNode * curr = head;
        while(curr) {
            if(curr->val < x) {
                stail->next = curr;
                curr = curr->next;
                stail = stail->next;
                stail->next = NULL;
            } else {
                btail->next = curr;
                curr = curr->next;
                btail = btail->next;
                btail->next = NULL;
            }
        }
        stail->next = big->next;
        head = small->next;
        delete small;
        delete big;
        return head;
    } 
};

int main() {
    freopen("input.txt", "r", stdin);
    ListNode * head = NULL, * curr = NULL;
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
    int x;
    cin >> x;
    Solution s;
    curr = s.partition(head, x);
    while(curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}
