class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        
        //to get the tail
        
        Node *tail = head;
        int length = 1 ;
        while(tail->next){
            tail = tail->next;
            length++;
        }
        
        //to get the k nodes we need
        
        int k_count = 0 ;
        
        Node *iterator = head;
        
        
        //calculating effective rotations
        k = k % length;
        
        
        if (k == 0)
            return head;
        
        while(k_count != k-1 && iterator){
            
            k_count++;
            iterator = iterator->next;
            
        }
        Node *newHead = iterator->next;
        
        iterator->next = nullptr;
        
        tail->next = head;
        return newHead;
    }
};
