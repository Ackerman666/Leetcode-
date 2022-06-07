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
        //ini�û����|���Vlist���Y
        ini->next = head;
        while(1){
            if(cur_node == nullptr || cur_node->next == nullptr)
                break;
            else{
                ListNode* next_node = cur_node->next;
                ListNode* temp_node = next_node->next;

                //���`�I�洫���ʧ@
                pre_node->next = next_node;
                next_node->next = cur_node;
                cur_node->next = temp_node;
                pre_node = cur_node;

                //��U�@�ӧY�N�洫���`�I
                cur_node = cur_node->next;
            }

        }
        return(ini->next);
    }
};
