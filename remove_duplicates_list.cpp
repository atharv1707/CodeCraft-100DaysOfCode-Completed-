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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* current = head;
        while(current && current->next){
            if(current->val == current->next->val){
                //check for duplicates if found, dissolve the duplicate node and keep going till the last one.
                current->next = current->next->next;
            }
            else{
                current = current->next; 
                //if all good, then move to the next node in the list
            }
        }

        return head;
        
    }
};