/* ******************************************************************
 * title: Insertion Sort List
 * url: https://leetcode.com/problems/insertion-sort-list/
 * date: Fri Nov  4 11:54:09 CST 2016
 * description: 使用插入排序对链表排序
 * general idea: 插入排序啊，可以自己建一个结点其元素没有意义，只表示
 * 链表的头，这样处理起来比较容易，但是记得函数返回之前释放掉那个结点。
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
    ListNode * insertionSortList(ListNode * head) {
        if(head == NULL || head->next == NULL) return head; 
        ListNode * next = head->next;
        ListNode * curr = NULL;
        ListNode * nHead = new ListNode(0);
        nHead->next = head;
        head->next = NULL;
        while(next) {
            curr = next;
            next = curr->next;
            ListNode * p = nHead;
            ListNode * q = p->next;
            while(q) {
                if(curr->val > q->val) {
                    p = q;
                    q = p->next;
                } else {
                    break;
                }
            }
            p->next = curr;
            curr->next = q;
        }
        head = nHead->next;
        delete nHead;
        return head;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    int n, tmp;
    ListNode * head = NULL, * curr = NULL;
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
    curr = s.insertionSortList(head);
    while(curr) {
        cout << curr->val << endl;
        curr = curr->next;
    }
    return 0;
}
