

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum = 0;
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;

        std::unordered_map<int, ListNode*> map;
        map[0] = dummyNode;

        while (head) {
            prefixSum += head->val;

            if (map.find(prefixSum) != map.end()) {
                ListNode* start = map[prefixSum];
                ListNode* temp = start->next;

                int sum = prefixSum;

                while (temp != head) {
                    sum += temp->val;
                    map.erase(sum);
                    temp = temp->next;
                }

                start->next = head->next;
            } else {
                map[prefixSum] = head;
            }

            head = head->next;
        }

        return dummyNode->next;
    }
};
