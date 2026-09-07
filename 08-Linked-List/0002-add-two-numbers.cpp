// LeetCode 2: Add Two Numbers
#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int value = 0, ListNode *nextNode = nullptr) : val(value), next(nextNode) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy;
        ListNode *tail{&dummy};
        int carry{};

        while (l1 || l2 || carry)
        {
            const int total{(l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry};
            carry = total / 10;
            tail->next = new ListNode(total % 10);
            tail = tail->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummy.next;
    }
};

int main()
{
    ListNode third{3};
    ListNode second{4, &third};
    ListNode first{2, &second};
    ListNode sixth{4};
    ListNode fifth{6, &sixth};
    ListNode fourth{5, &fifth};
    for (ListNode *node{Solution{}.addTwoNumbers(&first, &fourth)}; node; node = node->next)
    {
        cout << node->val << ' ';
    }
    cout << '\n';
}