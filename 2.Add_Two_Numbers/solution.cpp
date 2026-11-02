// Definition for singly-linked list.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <queue>
using namespace std;

class Solution
{

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *lRes = new ListNode();

        ListNode *p1 = l1;
        ListNode *p2 = l2;

        ListNode *pRes = lRes;

        int carry = 0;
        while (p1 != nullptr || p2 != nullptr)
        {
            int v1 = p1 == nullptr ? 0 : p1->val;
            int v2 = p2 == nullptr ? 0 : p2->val;

            int val = (v1 + v2 + carry) % 10;
            carry = (v1 + v2 + carry) / 10;

            pRes->val = val;

                        if (p1 != nullptr)
            {

                if (p1->next == nullptr)
                    p1 = nullptr;
                else
                    p1 = p1->next;
            }
            if (p2 != nullptr)
            {
                if (p2->next == nullptr)
                    p2 = nullptr;
                else
                    p2 = p2->next;
            }
            
            if (p1 == nullptr && p2 == nullptr && carry == 0) break;

            pRes->next = new ListNode();
            pRes = pRes->next;
        }

        if (carry != 0)
            pRes->val = carry;

        return lRes;
    }
};