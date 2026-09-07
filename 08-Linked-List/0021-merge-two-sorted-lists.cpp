// LeetCode 21: Merge Two Sorted Lists
#include <iostream>

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummy;
        ListNode *current{&dummy};
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        current->next = list1 ? list1 : list2;
        return dummy.next;
    }
};

int main()
{
    ListNode third{4};
    ListNode second{2, &third};
    ListNode first{1, &second};
    ListNode sixth{4};
    ListNode fifth{3, &sixth};
    ListNode fourth{1, &fifth};
    for (ListNode *node{Solution{}.mergeTwoLists(&first, &fourth)}; node; node = node->next)
    {
        cout << node->val << ' ';
    }
    cout << '\n';
}