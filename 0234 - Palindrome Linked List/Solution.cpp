class Solution {
public:
    ListNode*  middleNode(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL)
        {
            fast = fast->next;
            if(fast->next != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

    ListNode* reverseLL(ListNode* prev, ListNode* curr)
    {
        // base case
        if(curr == NULL){
            return prev;
        }

        // 1 case is solved
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

        //RR
        ListNode* recusionAns = reverseLL( prev, curr);
        return recusionAns;

    }

    bool compareList(ListNode* head1, ListNode* head2)
    {
        while(head1!= NULL && head2 != NULL)
        {
            if(head1 -> val != head2 -> val)
            {
                return false;
            }
            else{
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        //break into 2 halves
        ListNode* midNode = middleNode(head);
        ListNode* head2 = midNode->next;
        midNode->next = NULL;

        //reverse the 2nd half

        ListNode* prev = NULL;
        ListNode* curr = head2;
        head2 = reverseLL(prev, curr);

        //compare both the LL
        bool ans = compareList(head, head2);
        return ans;
    }
};
