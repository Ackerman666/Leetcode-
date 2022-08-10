class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *rat = head , *turtle = head;
        bool ans = false;
        if(head==nullptr)
            return(false);
        while(1){
            rat = rat->next;
            if(rat!=nullptr)
                rat = rat->next;
            turtle = turtle->next;
            if(rat==nullptr || turtle==nullptr){
                ans = false;
                break;
            }
            else if(rat==turtle){
                ans = true;
                break;
            }
        }
        return(ans);
    }
};
