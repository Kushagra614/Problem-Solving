class Solution {
public:

        int getLength(ListNode* head)
        {
            ListNode* temp = head;
            int len = 0;
            while(temp !=NULL)
            {
                len++;
                temp= temp->next;
            }
            return len;
        }
        ListNode* reverseKGroup(ListNode* head, int k) {
        // Base case
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        // Solving 1 case
        int pos = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = curr->next;

        int len = getLength(head);
        if(len<k){
            return head;
        }
        while(pos<k)
        {
            // nextNode = curr->next;
             nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            pos++;
        } 
         
        ListNode* ans = NULL;
        if(nextNode!=NULL){
         ans = reverseKGroup(nextNode, k);

        //now joining the grp to each other
        head->next = ans;
        

        }
        return prev;
    }
    
};
