/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        //usign fast and slow pointers
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* ans = NULL;

        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
            return slow;

        // ListNode* curr = head;
        // int count = 0;
        // while(curr!= NULL)
        // {
        //  count++;
        //  curr = curr->next;
        // }

        // int h = count/2;
        // curr = head;
        // for(int i = 0; i<h; i++)
        // {
        //     curr = curr->next;
        // }

        // return curr;
        
    }
};