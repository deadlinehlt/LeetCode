/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        bool carry_flag = false;
        ListNode *t1 = l1, *t2 = l2;
        int sum;
        
        for(; ; t1 = t1->next, t2 = t2->next){
            sum = carry_flag ? t1->val + t2->val + 1 : t1->val + t2->val;
            t1->val = sum >= 10 ? sum % 10 : sum;
            carry_flag = sum >= 10 ? true : false;
            if(t1->next == NULL || t2->next == NULL) break;
        }
        
        if(t1->next == NULL && t2->next == NULL){
            if(carry_flag){
                ListNode *tmp_node = new ListNode(1);
                t1->next = tmp_node;
            }
            return l1;
        }else if(t1->next == NULL){
            t1->next = t2->next;
        }
        
        t1 = t1->next;
        for(;;t1 = t1->next){
            sum = carry_flag?t1->val + 1:t1->val;
            t1->val = sum >= 10 ? sum % 10 : sum;
            carry_flag = sum >= 10 ? true : false;
            if(t1->next == NULL) break;
        }
        
        if(carry_flag){
            ListNode *tmp_node = new ListNode(1);
            t1->next = tmp_node;
        }
        
        return l1;
    }
};
