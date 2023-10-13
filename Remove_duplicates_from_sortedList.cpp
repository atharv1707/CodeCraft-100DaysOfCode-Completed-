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

        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* current  = head;


        while(current){
            //as long as current node is not null pointer
            bool isDuplicate = false;

            while(current -> next && current->val == current->next->val){
                //as long as the next node to current node is not a null poitner.
                isDuplicate = true;
                current = current->next;
            }

            if(isDuplicate){
                //time to skip the duplicates
                prev -> next = current->next;
            }
            else{
                prev = prev->next;

            }

            current = current -> next;
        }

        return dummy->next;

        
        
    }
};