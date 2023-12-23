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
    ListNode* listReverse(ListNode* head) {
        if (!head) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = curr->next;

        while (curr) {
            curr->next = prev;
            prev = curr;
            curr = Next;
            if (Next) {
                Next = Next->next;
            }
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        // finding the middle node
        ListNode* middle = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            middle = middle->next;
            fast = fast->next->next;
        }

        // chopping off the right part
        ListNode* rightHead = middle->next;
        middle->next = NULL;

        // reversing the list
        rightHead = listReverse(rightHead);

        ListNode* l1 = head;
        ListNode* l2 = rightHead;

        // merging the two
        while (l2) {
            ListNode* l1Next = l1->next;
            ListNode* l2Next = l2->next;

            l1->next = l2;
            l2->next = l1Next;

            l1 = l1Next;
            l2 = l2Next;
        }
    }
};
