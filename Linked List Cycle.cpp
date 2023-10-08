//We implemented Tortoise and Hare algorithm.
//If we have a cycle , the fast and slow pointers will meet at some point after n or n-1 iterations or so. So we check if they meet or not.  O(n).
// If the last pointer doesn't point to null,  it points back to some node which means cycle. 

//do a simple dry run of This algo to check why it runs on linear time, and why does the fast and slow will ever meet. 


class Solution {
public:
    bool hasCycle(ListNode *head) {

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
        
    }
};