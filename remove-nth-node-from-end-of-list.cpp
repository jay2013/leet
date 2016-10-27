/* ******************************************************************
 * title: Remove Nth Node From End of List 
 * url: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * date: Thu Oct 27 17:31:20 CST 2016
 * description: 删除一个list中从末尾计数第n个元素，返回操作完毕之后的list
 * general idea: 直接使用一个栈记录所有list中的指针，然后找到待删除的节点，
 * 进行删除操作，需要注意的是如果要删除的元素正好是list的header，则应该更新
 * head
 * tags: stack link-list 
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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * curr = head;
        stack<ListNode *> st;
        while(curr) {
            st.push(curr);
            curr = curr->next;
        }
        while(n-- > 1) {
            st.pop();
        }
        ListNode * nthNode = st.top();
        st.pop();
        if(st.empty()) {
            head = nthNode->next;
        } else {
            curr = st.top();
            curr->next = nthNode->next;
        }
        delete nthNode;
        return head;
    }
};

// 1->2->3->4->5 , n = 2;
int main() {
    freopen("input.txt", "r", stdin);
    int n,m,tmp;
    ListNode *head = NULL, *curr;
    curr = head;
    cin >> n;
    while(n --) {
        cin >> tmp;
        if(head == NULL) {
            curr = new ListNode(tmp);
            head = curr;
        } else {
            curr->next = new ListNode(tmp);
            curr = curr->next;
        }
    }
    cin >> m;
    Solution s;
    curr = head;
    curr = s.removeNthFromEnd(head, m);
    while(curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    return 0;
}
