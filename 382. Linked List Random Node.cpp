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
    ListNode* front;
    Solution(ListNode* head) {
        front = head;
    }

    int getRandom() {
        int record, count = 1;
        ListNode* cur_node = front;
        while(cur_node!=nullptr){
            int r = rand() % (count);
            if(r < 1){                         //³Q¿ï¤¤
                record = cur_node->val;
            }
            count++;
            cur_node = cur_node->next;
        }
        return(record);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
