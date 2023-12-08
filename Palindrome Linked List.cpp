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
    ListNode* reverseList(ListNode* head){

        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while(current){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;

    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;


        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseList(slow);

        while(secondHalf){
            if(head->val != secondHalf->val){
                return false;
            }

            head = head->next;
            secondHalf = secondHalf ->next;
        }

        return true;





        
    }
};