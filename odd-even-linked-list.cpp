/* ******************************************************************
 * title: Odd Even Linked List
 * url: https://leetcode.com/problems/odd-even-linked-list/
 * date: Fri Nov  4 14:47:27 CST 2016
 * description: 将一个链表中的奇数位逐个拿出放在前面，偶数位数字放在
 * 后边构建一个新的链表并返回。
 * general idea: 就如描述的一样，构造两个链表分别链接原链表中的奇数和
 * 偶数位结点，然后再把偶数位元素构成的链表接到奇数位元素构成的链表后
 * 即可。具体见代码，引入两个val没有任何意义的虚假结点可以使编程难度
 * 变得更简单，但记得操作结束时释放创建的节点。
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
    ListNode * oddEvenList(ListNode * head) {
        ListNode * oddL = new ListNode(0);
        ListNode * evenL = new ListNode(0);
        ListNode * oddTail = oddL;
        ListNode * evenTail = evenL;
        ListNode * curr = head;
        int cnt = 0;
        while(curr) {
            ++cnt;
            if(cnt & 1) {
                oddTail->next = curr;
                curr = curr->next;
                oddTail = oddTail->next;
                oddTail->next = NULL;
            } else {
                evenTail->next = curr;
                curr = curr->next;
                evenTail = evenTail->next;
                evenTail->next = NULL;
            }
        }
        oddTail->next = evenL->next;
        head = oddL->next;
        delete oddL;
        delete evenL;
        return head;
    } 
};

int main() {
    freopen("input.txt", "r", stdin);
    int n, tmp;
    ListNode * head = NULL, * curr = NULL;
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
    Solution s;
    curr = s.oddEvenList(head);
    while(curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}
