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

    int getlength(ListNode* head)
    {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
        // int n = getlength(head);
        // ListNode* temp = head;
        // int pos = n/2 +1;
        // int currpos = 1;
        // while(currpos != pos){
        //     temp = temp->next;
        //     currpos++;
        // }
        // return temp;

        //one more way to solve this 
        // while(pos!=1)
        // {
        //     temp= temp->next;
        //     pos--;
        // }
        // return temp;

        // Using Tortoise and Hare Algorithm
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL)
            
        {
             fast = fast ->next;
             if (fast != NULL){
            fast = fast->next;
            slow = slow->next;
             }
        }
        return slow;
    }
};
