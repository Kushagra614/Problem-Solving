class Solution {
public:
    bool hasCycle(ListNode *head) {
        //use a map 
        map<ListNode*,bool>table;
        ListNode* temp = head;
        while(temp!=NULL){
            if(table[temp] == false)
            {
                table[temp] = true;
                
            }
            else{
                //cycle exits
                return true;
            }
            temp = temp->next;
        }
        //loop not present
        return false;

    }
};
