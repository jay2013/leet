/* ******************************************************************
 * title: Merge Two Sorted Lists
 * url: https://leetcode.com/problems/merge-two-sorted-lists/
 * date: Thu Oct 27 20:14:31 CST 2016
 * description: 归并两个有序链表
 * general idea: 从前往后扫一遍，发现小的元素就往新链表中添加就可以了
 * tags: link-list 
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        ListNode * pre = new ListNode(0);
        ListNode * curr = pre;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        while(l1) {
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;
        }
        while(l2) {
            curr->next = l2;
            l2 = l2->next;
            curr = curr->next;
        }
        curr = pre->next;
        delete pre;
        return curr;
    } 
};

int main() {
    freopen("input.txt", "r", stdin);
    ListNode *h1 = NULL, *h2 = NULL, *curr = NULL;
    int n, tmp;
    cin >> n;
    while(n --) {
        cin >> tmp;
        if(h1 == NULL) {
            h1 = new ListNode(tmp);
            curr = h1;
        } else {
            curr->next = new ListNode(tmp);
            curr = curr->next;
        }
    }
    cin >> n;
    while(n --) {
        cin >> tmp;
        if(h2 == NULL) {
            h2 = new ListNode(tmp);
            curr = h2;
        } else {
            curr->next = new ListNode(tmp);
            curr = curr->next;
        }
    }
    Solution s;
    curr = s.mergeTwoLists(h1, h2);
    while(curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    return 0;
}
