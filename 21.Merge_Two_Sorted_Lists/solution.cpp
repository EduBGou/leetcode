// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *x1 = list1;
        ListNode *x2 = list2;
        ListNode *res = new ListNode();
        ListNode *current = res;

        while (1)
        {
            if (x1 == nullptr && x2 == nullptr)
                return res->next;

            if (x2 == nullptr && x1 != nullptr)
            {
                current->next = x1;
                x1 = x1->next;
                current = current->next;
                continue;
            }

            if (x1 == nullptr && x2 != nullptr || x1->val > x2->val)
            {
                current->next = x2;
                x2 = x2->next;
                current = current->next;
                continue;
            }

            current->next = x1;
            x1 = x1->next;
            current = current->next;
        }
    }
};