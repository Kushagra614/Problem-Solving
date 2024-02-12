class Solution {
public:
    ListNode* reverseListRecusrion(ListNode* prev, ListNode* curr)
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
        ListNode* recusionAns = reverseListRecusrion( prev, curr);
        return recusionAns;
    }
    ListNode* reverseList(ListNode* &head) {
        //make 2 pointers
        ListNode* prev = NULL;
        ListNode* curr = head;
        
    //     // loop
    //     while(curr != NULL){
    //         ListNode* next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;

    //     }
    //     // update head
    //     head = prev;
    //     return prev;
    
return reverseListRecusrion( prev, curr);
    }
};
