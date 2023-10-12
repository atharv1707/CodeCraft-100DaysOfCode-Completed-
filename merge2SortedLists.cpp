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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }

        // ListNode* res = (l1->val > l2>val) ? l1 : l2; ----->  on the basis of values, this approach assigns values of the nodes to res

         //l1 and l2 are heads of the respective linked lists.
         if(l1->val > l2-> val){ swap(l1,l2);} //here it swaps the pointers , on the basis of values
         //we basically assign the smaller one of two with l1 and other as l2

        ListNode* res = l1; //and we assign res as smaller head
         //then we iterate till we reach null
        while(l1 != NULL && l2 != NULL){
            ListNode* temp = NULL;
            while(l1!= NULL && l1->val <= l2->val){
                temp = l1; //to remember 
                l1 = l1->next;
            }
            temp->next = l2;
            swap(l1,l2); //it means that l1 has turned out to be greater than l2 in our search and we need to swap it
        }
        return res;
        
    }
};