/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head == NULL) return NULL;
        //fast and slow pointers
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!= NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow)
            {
                fast = head;

                while(fast!=slow)
                {
                slow = slow->next;
                fast = fast->next;
                }
                return fast;
                

            }
        }
        return NULL;
    }
};