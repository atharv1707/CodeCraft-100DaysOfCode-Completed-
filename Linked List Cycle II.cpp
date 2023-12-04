//Approach  1 - Brute Force 

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
    ListNode *detectCycle(ListNode *head) {

        unordered_set<ListNode*> track;

        while(head){

            if(track.find(head) != track.end()){
                return head;
            }

            //if not present, then we add this to unordered set and we forward
            track.insert(head);
            head = head->next;

        }

        return nullptr;
        
    }
};


//Approach 2 : slow and fast pointer approach 

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
    ListNode *detectCycle(ListNode *head) {

        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;


        while(fast && fast->next){

            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow){
                break; //cycle detected
            }

            

        }

        if(fast != slow){
            return nullptr;
        }

        //we have to find the start of the cycle
        ListNode* start = head;
        while(start != slow){
            slow = slow->next;
            start = start->next;
        }

        return start;


        
        
    }
};