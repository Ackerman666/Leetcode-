/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
	
    if(head == NULL)
        return head;

    struct Node *cur_node = head, *next, *copy_node;
    
    while(cur_node != NULL){
        struct Node *node = (struct Node*)malloc(sizeof(struct Node));
        next = cur_node->next;

        node->val = cur_node->val;
        node->next = next;

        cur_node->next  = node;
        cur_node = next;
    }

    struct Node *copy_head =  head->next;
    cur_node = head;

    while(cur_node != NULL){
        
        copy_node = cur_node->next;
        next = copy_node->next;

        if(cur_node->random == NULL)
            copy_node->random = NULL;
        else
            copy_node->random = cur_node->random->next;
        
        if(next != NULL)
            copy_node->next = next->next;
        
        cur_node = next;
    }
    return copy_head;
}
