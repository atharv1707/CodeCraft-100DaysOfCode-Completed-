/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        
        Node *prev = NULL;;
        Node *current = head;
        Node *next = NULL;
        
        while(current){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
    
    
    
};


// recursion

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        
        if(!head || !head->next){
            return head;
        }
        
        Node *newNode = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newNode;
        
        
        
        
        
    }
    
};
