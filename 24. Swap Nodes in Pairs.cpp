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
        //ini永遠都會指向list的頭
        ini->next = head;
        while(1){
            if(cur_node == nullptr || cur_node->next == nullptr)
                break;
            else{
                ListNode* next_node = cur_node->next;
                ListNode* temp_node = next_node->next;

                //做節點交換的動作
                pre_node->next = next_node;
                next_node->next = cur_node;
                cur_node->next = temp_node;
                pre_node = cur_node;

                //到下一個即將交換的節點
                cur_node = cur_node->next;
            }

        }
        return(ini->next);
    }
};
