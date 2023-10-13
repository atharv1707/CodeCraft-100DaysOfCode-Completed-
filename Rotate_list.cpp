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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;

        int length = 1; // Initialize length to 1 since there's at least one node (head)
        ListNode* tail = head;

        // Calculate the length of the linked list and find the tail
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // Adjust k if it's greater than or equal to the length of the list
        k = k % length;
        if (k == 0) return head; // No rotation needed

        // Find the new head and new tail after rotation
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        tail ->next = head;
        head = newHead; //circular linked list, we assign the new head and it makes the circle and it looks still the same, don't look at it in a linear manner. 

        return head;
    }
};
