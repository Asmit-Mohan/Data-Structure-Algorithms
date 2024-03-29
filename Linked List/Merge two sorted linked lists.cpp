/* Time :- O[min(l1,l2)] Space :- O(1) */

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* ans = new ListNode(-1);
        ListNode* res = ans;
        
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val > l2->val)
            {
                ans->next = l2;
                l2 = l2->next;
            }
            else
            {
                ans->next = l1;
                l1 = l1->next;
            }
            ans = ans->next;
        }
        
        if(l1!=NULL)
        {
            ans->next = l1;
        }
        if(l2!=NULL)
        {
            ans->next = l2;
        }
        ans = NULL;
        return res->next;
    }
};
