//the approach here was to basically get the size of linked_list and then by calculating index number of nth end from end , we delete it.
//Slick , simple.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* it = head;
        int count = 0;

        // Calculate the size of the linked list
        while (it != nullptr) {
            count++;
            it = it->next;
        }

        // Calculate the index to delete
        int indexToDelete = count - n;

        // Reset the iterator
        it = head;

        // we traverse to the node before the one to delete
        for (int i = 1; i < indexToDelete; i++) {
            it = it->next;
        }
    

        // Handle the special case when deleting the head node
        if (indexToDelete == 0) {
            ListNode* temp = head; //store head in a seperate var before we cut ties with it
            head = head->next; //this now points to next node or nullptr
            delete temp;
            return head;
        }

        // Remove the nth node from the end
        ListNode* temp = it->next; //store that node, before we cut ties with it. we create a temporary pointer which points to the node we want to remove, else we will lose access to it.
        it->next = it->next->next;
        delete temp;

        return head;
    }
};



//Approach 2 : Tortoise and hare 


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* start = new ListNode();
        start -> next = head; //the dummy variable pointing to head
        ListNode* temp;
        ListNode* fast = start; // a pointer can point to a pointer, so it points to start and that points to head. so fast points to head.
        ListNode* slow = start; 


        for(int i = 1 ; i<=n+1;i++){
            fast = fast->next;
        }

        while(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        
        slow->next = slow->next->next;

        return start->next;
        

        
        
    }
};



