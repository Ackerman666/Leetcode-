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
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur_node = head;
        ListNode* ini = new ListNode() ;
        ListNode* pre_node = ini ;
        //iniッ环常穦list繷
        ini->next = head;
        while(1){
            if(cur_node == nullptr || cur_node->next == nullptr)
                break;
            else{
                ListNode* next_node = cur_node->next;
                ListNode* temp_node = next_node->next;

                //暗竊翴ユ传笆
                pre_node->next = next_node;
                next_node->next = cur_node;
                cur_node->next = temp_node;
                pre_node = cur_node;

                //盢ユ传竊翴
                cur_node = cur_node->next;
            }

        }
        return(ini->next);
    }
};
